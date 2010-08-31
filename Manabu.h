/*
 * Copyright (c) 2010, Bryce Groff.
 * Distributed under the terms of the MIT license.
 *
 * Authors:
 *              Bryce Groff <brycegroff@gmail.com>
 */

#ifndef MANABU_H_
#define MANABU_H_

#include <Application.h>
#include <Catalog.h>
#include <Window.h>

class Manabu : public BApplication {
public:
                                        Manabu();
                                        ~Manabu();

        virtual void    ReadyToRun();
        virtual bool    QuitRequested();
private:
        BWindow*                fMainWindow;
};

#endif
