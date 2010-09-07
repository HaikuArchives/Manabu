/*
* Copyright (c) <2010> <Bryce Groff>
* 
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
* 
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
* 
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
* THE SOFTWARE.
*/

#include "Card.h"
#include "PileManager.h"
#include "Utilities.h"

#include <libxml/xmlmemory.h>
#include <libxml/parser.h>
#include <libxml/tree.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <list>
using namespace std;

void 
        ParseDeckFile(const char* filename, PileManager *manager)
{
    xmlNode *cur_node, *child_node;
    xmlChar *content;

    xmlDocPtr doc;
    doc = xmlParseFile(filename);

    if (doc == NULL)
        printf("error: could not parse file file.xml\n");

    /*Get the root element node */
    xmlNode *root = NULL;
    root = xmlDocGetRootElement(doc);
    for(cur_node = root->children; cur_node != NULL; cur_node = cur_node->next)
    {
        if (cur_node->type == XML_ELEMENT_NODE
            && !xmlStrcmp(cur_node->name, (const xmlChar *)"name"))
        {
            content = xmlNodeGetContent(cur_node);
            if (content != NULL)
                manager->SetName(content);
        }
        if (cur_node->type == XML_ELEMENT_NODE
            && !xmlStrcmp(cur_node->name, (const xmlChar *)"card"))
        {
            Card* card = new Card();
            content = xmlGetProp(cur_node, (xmlChar*)"id");
            if (content != NULL)
                card->SetId(content);

            for(child_node = cur_node->children; child_node != NULL; child_node = child_node->next)
            {
                if (!xmlStrcmp(child_node->name, (const xmlChar *)"front")) {
                    content = xmlNodeGetContent(child_node);
                    if (content != NULL)
                        card->SetFront(content);
                }
                if (!xmlStrcmp(child_node->name, (const xmlChar *)"back")) {
                    content = xmlNodeGetContent(child_node);
                    if (content != NULL)
                        card->SetBack(content);
                }
                if (!xmlStrcmp(child_node->name, (const xmlChar *)"back_example")) {
                    content = xmlNodeGetContent(child_node);
                    if (content != NULL)
                        card->SetBackExample(content);
                }
                if (!xmlStrcmp(child_node->name, (const xmlChar *)"pile")) {
                    content = xmlNodeGetContent(child_node);
                    if (content != NULL)
                        card->SetPileNumber((int32_t)content); // THIS OBVIOUSLY DOES NOT WORK
                }
            }
            card->SetPileNumber(5);
            manager->AddToPile(card, 5);
        }
    }
    xmlFreeDoc(doc);
    xmlCleanupParser();
}
