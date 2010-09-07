/*
 * Copyright (c) 2010, Bryce Groff.
 * Distributed under the terms of the MIT license.
 *
 * Authors:
 *              Bryce Groff <brycegroff@gmail.com>
 */
 
#ifndef MANABU_WINDOW_H_
#define MANABU_WINDOW_H_

#include <FilePanel.h>
#include <Menu.h>
#include <MenuItem.h>
#include <Window.h>
#include <View.h>
 
class ManabuWindow : public BWindow
{
public:
                                        ManabuWindow();
        virtual                 ~ManabuWindow();
        
        virtual void    MessageReceived(BMessage* message);
        virtual bool    QuitRequested();

private:
        void                    _Init();
        void                    _CreateGUI();
        BMenu*                  _CreateMainMenu();

        BView*                  fMainView;

        BMenu*                  fFileMenu;
        BMenuItem*              fNewPlaylistMI;
        BMenuItem*              fAddToLibraryMI;
        BMenuItem*              fQuitMI;
        
        BFilePanel*             fAddLibraryFP;

};

#endif
