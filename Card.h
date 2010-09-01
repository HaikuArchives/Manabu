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

#ifndef _CARD_H_
#define _CARD_H_

#include <libxml/parser.h>

#include <stdint.h>

class Card {
public:
					Card();
					Card(xmlChar* id, xmlChar* front, xmlChar* back,
						xmlChar* backExample);
	virtual			~Card();

	void			SetId(xmlChar* id);
	int32_t			GetId(xmlChar** id);

	void			SetFront(xmlChar* front);
	int32_t			GetFront(xmlChar** front);

	void			SetBack(xmlChar* back);
	int32_t			GetBack(xmlChar** back);

	void			SetBackExample(xmlChar* backExample);
	int32_t			GetBackExample(xmlChar** backExample);

	void			DumpToStdout();
private:
	xmlChar*		fId;
	xmlChar*		fFront;
	xmlChar*		fBack;
	xmlChar*		fBackExample;
};


#endif
