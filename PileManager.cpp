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


#include "PileManager.h"

#include <stdint.h>

#include <list>
using namespace std;

PileManager::PileManager()
	:
	fMaxPile(5)
{
	fPiles = new list<Card*>[fMaxPile];
}


PileManager::PileManager(int32_t maxPile)
	:
	fMaxPile(maxPile)
{
	fPiles = new list<Card*>[fMaxPile];
}


PileManager::~PileManager()
{
}


int32_t
PileManager::AddToPile(Card* card, int32_t pileNumber)
{
	int32_t pileNum = pileNumber - 1;
	if (pileNum >= fMaxPile)
		pileNum = fMaxPile - 1;
	if (pileNum < 0)
		pileNum = 0;

	card->SetPileNumber(pileNum+1);
	fPiles[pileNum].push_back(card);
	return pileNum;
}

int32_t
PileManager::GetPile(list<Card*>** pile, int32_t pileNumber)
{
	int32_t pileNum = pileNumber - 1;
	if (pileNum >= fMaxPile)
		pileNum = fMaxPile - 1;
	if (pileNum < 0)
		pileNum = 0;

	*pile = &fPiles[pileNum];
	return pileNum;
}


