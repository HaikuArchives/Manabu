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
#include <libxml/encoding.h>
#include <libxml/xmlwriter.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <list>
using namespace std;

#define MY_ENCODING "ISO-8859-1"

void
ParseDeckFile(const char* filename, PileManager* manager)
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
    if (root == NULL)
        return;

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

			content = xmlGetProp(cur_node, (xmlChar*)"pile");
            if (content != NULL) {
				int32_t pile = 0;
				sscanf ((char*)content, "%i", &pile);
				card->SetPileNumber(pile);
            } else {
				card->SetPileNumber(5);
			}

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

            }
            manager->AddToPile(card, card->PileNumber());
        }
    }
    xmlFreeDoc(doc);
    xmlCleanupParser();
}

void 
WriteDeckFile(const char* filename, PileManager* manager)
{
	int rc;
	xmlTextWriterPtr writer;
	xmlChar *tmp;

	writer = xmlNewTextWriterFilename(filename, 0);
	if (writer == NULL) {
		printf("testXmlwriterFilename: Error creating the xml writer\n");
		return;
	}
	rc = xmlTextWriterStartDocument(writer, NULL, MY_ENCODING, NULL);
    if (rc < 0) {
        printf
            ("testXmlwriterFilename: Error at xmlTextWriterStartDocument\n");
        return;
    }

	rc = xmlTextWriterSetIndentString(writer, (xmlChar*)"\t");
    if (rc < 0) {
        printf
            ("testXmlwriterFilename: Error at xmlTextWriterSetIndentString\n");
        return;
    }


    rc = xmlTextWriterStartElement(writer, BAD_CAST "deck");
    if (rc < 0) {
        printf
            ("testXmlwriterFilename: Error at xmlTextWriterStartElement\n");
        return;
    }

    rc = xmlTextWriterWriteFormatElement(writer, BAD_CAST "name",
                                         "%s", manager->Name());
    if (rc < 0) {
        printf
            ("testXmlwriterFilename: Error at xmlTextWriterWriteFormatElement\n");
        return;
    }
	
	int32_t id = 0;
        for (int32_t i = 1; i <= manager->MaxPile(); i++) {
		list<Card*>* curDeck;
		manager->GetPile(&curDeck, i);
  		for (list<Card*>::iterator it = curDeck->begin(); it != curDeck->end(); it++, id++) {
			Card* card = *it;
    		rc = xmlTextWriterStartElement(writer, BAD_CAST "card");
   			if (rc < 0) {
    		    printf
    		        ("testXmlwriterFilename: Error at xmlTextWriterStartElement\n");
    		    return;
    		}

		    rc = xmlTextWriterWriteFormatAttribute(writer, BAD_CAST "id",
                                     "%i", id);
		    if (rc < 0) {
        		printf
        	    	("testXmlwriterFilename: Error at xmlTextWriterWriteAttribute\n");
        		return;
    		}

		    rc = xmlTextWriterWriteFormatAttribute(writer, BAD_CAST "pile",
                                     "%i", i);
		    if (rc < 0) {
        		printf
        	    	("testXmlwriterFilename: Error at xmlTextWriterWriteAttribute\n");
        		return;
    		}
			card->GetFront(&tmp);
   			rc = xmlTextWriterWriteFormatElement(writer, BAD_CAST "front",
                                         "%s", tmp);
    		if (rc < 0) {
        		printf
           		("testXmlwriterFilename: Error at xmlTextWriterWriteFormatElement\n");
        		return;
    		}

			card->GetBack(&tmp);
   			rc = xmlTextWriterWriteFormatElement(writer, BAD_CAST "back",
                                         "%s", tmp);
    		if (rc < 0) {
        		printf
           		("testXmlwriterFilename: Error at xmlTextWriterWriteFormatElement\n");
        		return;
    		}

			rc = xmlTextWriterEndElement(writer);
   			if (rc < 0) {
    		    printf
    		        ("testXmlwriterFilename: Error at xmlTextWriterStartElement\n");
    		    return;
    		}
		}
	}

    rc = xmlTextWriterEndDocument(writer);
    if (rc < 0) {
        printf
            ("testXmlwriterFilename: Error at xmlTextWriterEndDocument\n");
        return;
    }

    xmlFreeTextWriter(writer);
}



