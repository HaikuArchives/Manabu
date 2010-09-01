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

#include <libxml/parser.h>

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Card::Card()
	:
	fId(NULL),
	fFront(NULL),
	fBack(NULL),
	fBackExample(NULL)
{

}


Card::Card(xmlChar* id, xmlChar* front, xmlChar* back, xmlChar* backExample)
	:
	fId(id),
	fFront(front),
	fBack(back),
	fBackExample(backExample)
{

}


Card::~Card()
{
	xmlFree(fFront);
	xmlFree(fBack);
	xmlFree(fBackExample);
}


void
Card::SetId(xmlChar* id)
{
	fId = id;
}


int32_t
Card::GetId(xmlChar** id)
{
	if (fId == NULL)
		return -1;
	*id = fId;
	return 1;
}


void
Card::SetFront(xmlChar* front)
{
	fFront = front;
}


int32_t
Card::GetFront(xmlChar** front)
{
	if (fFront == NULL)
		return -1;
	*front = fFront;
	return 1;
}


void
Card::SetBack(xmlChar* back)
{
	fBack = back;
}


int32_t
Card::GetBack(xmlChar** back)
{
	if (fBack == NULL)
		return -1;
	*back = fBack;
	return 1;
}


void
Card::SetBackExample(xmlChar* backExample)
{
	fBackExample = backExample;
}


int32_t
Card::GetBackExample(xmlChar** backExample)
{	
	if (fBackExample == NULL)
		return -1;
	*backExample = fBackExample;
	return 1;

}


void
Card::DumpToStdout()
{
	printf("-- Card --\n");
	printf("-- Front        > %s\n", fFront);
	printf("-- Back         > %s\n", fBack);
	printf("-- Back Example > %s\n", fBackExample);
}


