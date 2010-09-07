/*
 * Copyright (c) 2010, Bryce Groff.
 * Distributed under the terms of the MIT license.
 *
 * Authors:
 *              Bryce Groff <brycegroff@gmail.com>
 */

#include "Manabu.h"
#ifdef HAIKU_BUILD

#include "ManabuWindow.h"

#include <Application.h>
#include <Locale.h>

#include <stdio.h>
#include <stdlib.h>


Manabu::Manabu()
        : BApplication("application/x-vnd.Manabu")
{
        fMainWindow = new ManabuWindow();
}

Manabu::~Manabu()
{
}

bool
Manabu::QuitRequested()
{
        if (fMainWindow->Lock()) {
                fMainWindow->Quit();
                fMainWindow = NULL;
        }

        return true;
}

void
Manabu::ReadyToRun()
{
        if (fMainWindow)
                fMainWindow->Show();
}

int
main(int argc, char* argv[])
{
        Manabu app;
        app.Run();
        
        return EXIT_SUCCESS;
}

#endif