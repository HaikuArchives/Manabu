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
ParseDeckFile(const char* filename, list<Card*> *cards)
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
		if ( cur_node->type == XML_ELEMENT_NODE
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
			}
			cards->push_back(card);
		}
	}
	xmlFreeDoc(doc);
	xmlCleanupParser();
}

int
main(int argc, char* argv[])
{
	list<Card*> cards;
	xmlChar* 	tmp;
	char		input[100];

	if (argc >= 2)
		ParseDeckFile(argv[1], &cards);
	
	for (list<Card*>::iterator it = cards.begin(); it != cards.end(); it++) {
		Card* card = *it;
		card->GetFront(&tmp);
		printf("Front: %s\n", tmp);
		printf("Back: ");
		fgets(input, 100, stdin);
		int32_t end = strlen(input);
		input[end - 1] = '\0';
		card->GetBack(&tmp);
		if (strcasecmp(input, "q") == 0)
			break;		
		if (strcasecmp(input, (char*)tmp) == 0)
			printf("Correct!\n");
		else
			printf("Sorry that is incorrect, the correct answer is: %s\n", tmp);
	}

	for (list<Card*>::iterator it = cards.begin(); it != cards.end(); it++) {
		Card* card = *it;
		delete card;
	}
}



