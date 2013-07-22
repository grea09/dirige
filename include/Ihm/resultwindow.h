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

#ifndef DEF_RESULT_WINDOW_H
#define DEF_RESULT_WINDOW_H

#include "libdevcpp.h"
#include "plugininterface.h"
#include "pluginwidget.h"
#include "mainwindow.h"
#include "toolbarfile.h"
#include "toolbarzoom.h"
#include <QScrollArea>
#include <QLabel>
#include <QString>
#include <QMainWindow>
#include <QInputDialog>

#define PluginType Bitmap::PluginWidget


namespace Ihm
{
	
	class MainWindow;
	
	class ResultWindow : public QMainWindow
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
			
			ResultWindow(QPixmap pixmap, QPoint* start, QPoint* end, QColor resultColor, QWidget* parent = NULL);
			
		//}
		
		//Destroyers
		//{
			
			//~ ~ResultWindow();
			
		//}
		
		//Methods
		//{
			
			//Getters
			//{
				
				QToolBar* getToolBarFile();
				//~ QToolBar* getToolBarColor();
				ToolBarZoom* getToolBarZoom();
				
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
				
				void save();
				void saveAs();
				void closeCurrentFile(QCloseEvent * event);
				void closeEvent(QCloseEvent * event);
				
				void run();
				
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
				
				QToolBar* toolBarFile_;
				//~ QToolBar* toolBarColor_;
				ToolBarZoom* toolBarZoom_;
				
				QAction* actionSave_;
				QAction* actionSaveAs_;
				QAction* actionClose_;
				QAction* actionQuit_;
				//~ QAction* actionColor_;
				
				QMenuBar* menu_;
				
				PluginType* pluginInterface_;
				
				QString fileName_;
				
			//}
			
		//}
		
		//Methods
		//{
			//Processing
			//{
				
				void build(QPixmap pixmap, QPoint* start, QPoint* end, QColor resultColor);
				
			//}
		//}
	};
}

#endif


