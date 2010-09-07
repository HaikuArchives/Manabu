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
	int32_t			GetMaxPile() { return fMaxPile; }
        void                    SetName(xmlChar* name) { fName = name; }
        xmlChar*                Name() { return fName; }
private:
        list<Card*>*            fPiles;
        int32_t                 fMaxPile;
        xmlChar*                fName;
};

#endif

