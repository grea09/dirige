/****************************************************************************
**
** Copyright 2010 Antoine GRÉA <grea09@gmail.com>
**
** $QT_BEGIN_LICENSE:LGPL$
**      This program is free software; you can redistribute it and/or modify
**      it under the terms of the GNU General Public License as published by
**      the Free Software Foundation; either version 2 of the License, or
**      (at your option) any later version.
**      
**      This program is distributed in the hope that it will be useful,
**      but WITHOUT ANY WARRANTY; without even the implied warranty of
**      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**      GNU General Public License for more details.
**      
**      You should have received a copy of the GNU General Public License
**      along with this program; if not, write to the Free Software
**      Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
**      MA 02110-1301, USA.
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef DEF_MENU_H
#define DEF_MENU_H

#include "libdevcpp.h"
#include "mainwindow.h"
#include <QMenuBar>

namespace Ihm
{
	class MainWindow;
	
	class Menu : public QMenuBar
	{
		Q_OBJECT
		
		public :
		//Attributes
		//{
			
			//Constants
			//{
				
				
				
				
			//}
			
		//}
		
		//Builders
		//{
			
			Menu(QMainWindow* parent = NULL);
			
		//}
		
		//Destroyers
		//{
			
			//~ ~Menu();
			
		//}
		
		//Methods
		//{
			
			//Getters
			//{
				
				QAction* getActionSaveAs();
				QAction* getActionClose();
				QAction* getActionQuit();
				
				QActionGroup* getActionGroupToolBar();
				
				QAction* getActionColor();
				
				QAction* getActionHelp();
				QAction* getActionAboutDirige();
				
			//}
			
			//Setters
			//{
				
				
				
			//}
			
			//Processing
			//{
				
				
				
			//}
			
			//Operators
			//{
				
				
				
			//}
			
			//Display
			//{
				
				
				
			//}
			
		//}
		
		//Slots
		//{
			
			public slots:
				
				
				
		//}
		
		//Signals
		//{
			
			signals:
				
				
		//}
			
		protected :
		//Attributes
		//{
			
			//Variables
			//{
				
				QMenu* menuFile_;
				QMenu* menuEdit_;
				QMenu* menuView_;
				QMenu* menuToolBar_;
				QMenu* menuOption_;
				QMenu* menuHelp_;
				
				//~ Les actions qui ne sont pas dans les toolbars
				QAction* actionSaveAs_;
				QAction* actionClose_;
				QAction* actionQuit_;
				
				QAction* actionToolBarFile_;
				QAction* actionToolBarDraw_;
				QAction* actionToolBarZoom_;
				QAction* actionToolBarRobot_;
				QAction* actionToolBarColor_;
				QActionGroup* actionGroupToolBar_;
				
				QAction* actionColor_;
				
				QAction* actionHelp_;
				QAction* actionAboutDirige_;
				
				MainWindow* parent_;
				
			//}
			
		//}
		
		//Methods
		//{
			//Processing
			//{
				
				void build();
				
			//}
		//}
	};
}

#endif


