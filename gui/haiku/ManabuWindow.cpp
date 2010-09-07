/*
 * Copyright (c) 2010, Bryce Groff.
 * Distributed under the terms of the MIT license.
 *
 * Authors:
 *              Bryce Groff <brycegroff@gmail.com>
 */
 
#include "ManabuWindow.h"

#include <Application.h>
#include <Box.h>
#include <FilePanel.h>
#include <GridLayout.h>
#include <GroupLayout.h>
#include <GroupView.h>
#include <LayoutBuilder.h>
#include <MenuItem.h>
#include <MenuBar.h>
#include <Menu.h>
#include <SplitView.h>
#include <Window.h>
#include <View.h>

#include <stdio.h>
#include <stdlib.h>

#define TR_CONTEXT "MainWindow"

enum {
        MSG_QUIT                                = 'quit',
        MSG_NEW_PLAYLIST                        = 'nwpl',
        MSG_ADD_LIBRARY                         = 'adlb',
};

ManabuWindow::ManabuWindow()
        : BWindow(BRect(30, 30, 900, 600), "Manabu",
                B_TITLED_WINDOW, B_AUTO_UPDATE_SIZE_LIMITS)
{       
        _Init();
}


ManabuWindow::~ManabuWindow()
{
}

void
ManabuWindow::MessageReceived(BMessage* message)
{
        switch (message->what) {
			case MSG_QUIT:
            	QuitRequested();
				break;
			case MSG_NEW_PLAYLIST:
				printf("New Play List\n");
				be_app->PostMessage(MSG_NEW_PLAYLIST);
				break;
            case MSG_ADD_LIBRARY:
            {
				BMessenger target(this);
				fAddLibraryFP = new BFilePanel(B_OPEN_PANEL, &target,
					NULL, B_DIRECTORY_NODE);
				fAddLibraryFP->Show();
				break;
            }
			case B_REFS_RECEIVED:
				break;
			default:
				BWindow::MessageReceived(message);
				break;
        }
}


bool
ManabuWindow::QuitRequested()
{
        be_app->PostMessage(B_QUIT_REQUESTED);
        Hide();
        return false;
}

// #pragma mark - Private Methods


void
ManabuWindow::_Init()
{
        _CreateGUI();
}


void
ManabuWindow::_CreateGUI()
{
        SetLayout(new BGroupLayout(B_HORIZONTAL));
        
        BGridLayout* rootLayout = new BGridLayout();
        BView* rootView = new BView("root view", 0, rootLayout);
        AddChild(rootView);
        rootView->SetViewColor(ui_color(B_PANEL_BACKGROUND_COLOR));
        rootView->SetExplicitMinSize(BSize(800, 500));
        
        // add the main view
        BGridLayout* mainLayout = new BGridLayout();
        BView* mainView = new BView("main view", 0, mainLayout);

        BSplitView* mainGroup = new BSplitView(B_HORIZONTAL);
        mainGroup->SetName("Main Group");
        mainLayout->AddView(mainGroup);
        BLayoutBuilder::Split<>(mainGroup)
                .Add(new BBox(BRect(0,0,1,1)))
                .Add(new BBox(BRect(0,0,1,1)));
                
		// add the menu, as well as the controller
        rootView->AddChild(_CreateMainMenu());
        rootLayout->AddView(mainView, 0, 1);
}

BMenu*
ManabuWindow::_CreateMainMenu()
{
        BMenuBar* menuBar = new BMenuBar(Bounds(), "root menu");
        
        fFileMenu = new BMenu("File");
        fNewPlaylistMI = new BMenuItem("New Playlist",
                new BMessage(MSG_NEW_PLAYLIST), 'N');
        fAddToLibraryMI = new BMenuItem("Add to Library",
                new BMessage(MSG_ADD_LIBRARY), 'A');
        fQuitMI = new BMenuItem("Quit", new BMessage(MSG_QUIT), 'Q');
        
        fFileMenu->AddItem(fNewPlaylistMI);
        fFileMenu->AddSeparatorItem();
        fFileMenu->AddItem(fAddToLibraryMI);
        fFileMenu->AddSeparatorItem();
        fFileMenu->AddItem(fQuitMI);
        menuBar->AddItem(fFileMenu);
        
        return menuBar;
}
