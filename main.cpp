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

#include "config.h"

#include "Card.h"
#include "PileManager.h"
#include "Utilities.h"

#ifdef HAIKU_BUILD
#include "gui/haiku/Manabu.h"
#endif

#include <libxml/xmlmemory.h>
#include <libxml/parser.h>
#include <libxml/tree.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <list>
using namespace std;

#define NUM_PILES 5

int
main(int argc, char* argv[])
{
#ifdef COMMAND_LINE
	list<Card*>*	onDeck;
	xmlChar* 		tmp;
	char			input[100];
	int32_t 		end, pileNum, size;

	PileManager manager(5);

	if (argc >= 2)
		ParseDeckFile(argv[1], &manager);

	for (;;) {
		printf("Enter deck number you would like to practice [1-%i]: ", NUM_PILES);
		fgets(input, 100, stdin);
		end = strlen(input);
		input[end - 1] = '\0';
		end = sscanf(input, "%i", &pileNum);
		if (end != 1) {
			printf("The pile entered was incorrect\n");
			continue;
		}
		manager.GetPile(&onDeck, pileNum);
		if (onDeck->empty()) {
			printf("The chosen deck does not contain any cards. Please choose another.\n");
			continue;
		}
		size = onDeck->size();
		for (int32_t i = 0; i < size; i++) {
			Card* card = onDeck->front();
			onDeck->pop_front();
			card->GetFront(&tmp);
			printf("Front: %s\n", tmp);
			printf("Back: ");
			fgets(input, 100, stdin);
			end = strlen(input);
			input[end - 1] = '\0';
			card->GetBack(&tmp);
			if (strcasecmp(input, "q") == 0)
				break;		
			if (strcasecmp(input, (char*)tmp) == 0) {
				printf("Correct!\n");
				manager.AddToPile(card, card->PileNumber() - 1);
			}
			else {
				printf("Sorry that is incorrect, the correct answer is: %s\n", tmp);
				manager.AddToPile(card, card->PileNumber() + 1);
			}
		}
	}

	for (int32_t i = 0; i < NUM_PILES; i++) {
		manager.GetPile(&onDeck, i+1);		
		for (list<Card*>::iterator it = onDeck->begin(); it != onDeck->end(); it++) {
			Card* card = *it;
			delete card;
		}
	}
#endif

#ifdef HAIKU_BUILD
	Manabu app;
	app.Run();

	return EXIT_SUCCESS;
#endif
}



