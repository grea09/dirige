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

#ifndef DEF_MAIN_WINDOW_H
#define DEF_MAIN_WINDOW_H

#include "libdevcpp.h"
//~ #include "plugininterface.h"
#include "pluginwidget.h"
#include "resultwindow.h"
#include "menu.h"
#include "toolbarfile.h"
#include "toolbardraw.h"
#include "toolbarzoom.h"
#include "toolbarrobot.h"
#include "toolbarcolor.h"
#include <QScrollArea>
#include <QLabel>
#include <QString>
#include <QMainWindow>
#include <QInputDialog>
#include <QCloseEvent>

#include "pluginwidget.h"
#define PluginType Bitmap::PluginWidget


namespace Ihm
{
	
	class Menu;
	
	class ResultWindow;
	
	class MainWindow : public QMainWindow
	{
		Q_OBJECT
		
		public :
		//Attributes
		//{
			
			//Constants
			//{
				
				static const QString Title;
				static const QString FileNameDef;
				
				static const QSize IconSize;
				
			//}
			
		//}
		
		//Builders
		//{
			
			MainWindow(QWidget* parent = NULL);
			
		//}
		
		//Destroyers
		//{
			
			//~ ~MainWindow();
			
		//}
		
		//Methods
		//{
			
			//Getters
			//{
				
				ToolBarColor* getToolBarColor();
				ToolBarFile* getToolBarFile();
				ToolBarDraw* getToolBarDraw();
				ToolBarZoom* getToolBarZoom();
				ToolBarRobot* getToolBarRobot();
				
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
				
				void newFile();
				void open();
				void save();
				void saveAs();
				void closeCurrentFile(QCloseEvent * event = NULL);
				void closeEvent (QCloseEvent * event);
				
				void closeToolbar ( QAction* action );
				
				void run();
				
				void aboutDirige();
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
				
				Menu* menu_;
				
				ResultWindow* result_;
				
				ToolBarColor* toolBarColor_;
				ToolBarFile* toolBarFile_;
				ToolBarDraw* toolBarDraw_;
				ToolBarZoom* toolBarZoom_;
				ToolBarRobot* toolBarRobot_;
				
				//~ QScrollArea* scrollArea_;
				PluginType pluginInterface_;
				
				QStatusBar* statusBar_;
				
				QString fileName_;
				
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


