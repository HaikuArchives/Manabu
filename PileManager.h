/*
 * Copyright (c) 2010, Bryce Groff.
 * Distributed under the terms of the MIT license.
 *
 * Authors:
 *              Bryce Groff <brycegroff@gmail.com>
 */

#ifndef PILE_MANAGER_H_
#define PILE_MANAGER_H_

#include "Card.h"

#include <stdint.h>
#include <string.h>
#include <libxml/parser.h>

#include <list>
using namespace std;

class PileManager {
public:
                                PileManager();
                                PileManager(int32_t maxPile);

	virtual			~PileManager();

	int32_t			AddToPile(Card* card, int32_t pileNumber);
	int32_t			GetPile(list<Card*>** pile, int32_t pileNumber);
        int32_t			MaxPile() { return fMaxPile; }
        xmlChar*                Name() { return fName; }
        void                    SetName(xmlChar* name);
private:
        list<Card*>*            fPiles;
        int32_t                 fMaxPile;
        xmlChar*                fName;
};

#endif

