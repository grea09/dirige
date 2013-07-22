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

#ifndef DEF_TOOLBAR_FILE_H
#define DEF_TOOLBAR_FILE_H

#include "libdevcpp.h"
#include <QToolBar>
#include <QAction>

namespace Ihm
{
	class ToolBarFile : public QToolBar
	{
		Q_OBJECT
		
		public :
		//Attributes
		//{
			
			//Constants
			//{
				
				
				static const QSize FixedSize;
				
			//}
			
		//}
		
		//Builders
		//{
			
			ToolBarFile(QWidget* parent = NULL);
			
		//}
		
		//Destroyers
		//{
			
			//~ ~ToolBarFile();
			
		//}
		
		//Methods
		//{
			
			//Getters
			//{
				
				QAction* getActionNew();
				QAction* getActionOpen();
				QAction* getActionSave();
				
				
				
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
				
				QAction* actionNew_;
				QAction* actionOpen_;
				QAction* actionSave_;
				
				
				
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


