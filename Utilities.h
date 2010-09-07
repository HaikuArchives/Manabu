/*
 * Copyright (c) 2010, Bryce Groff.
 * Distributed under the terms of the MIT license.
 *
 * Authors:
 *              Bryce Groff <brycegroff@gmail.com>
 */

#ifndef UTILITIES_H_
#define UTILITIES_H_


#include "Card.h"
#include "PileManager.h"

#include <libxml/xmlmemory.h>
#include <libxml/parser.h>
#include <libxml/tree.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <list>
using namespace std;

void ParseDeckFile(const char* filename, PileManager *manager);

#endif
