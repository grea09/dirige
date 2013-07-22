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

#ifndef DEF_TOOLBAR_DRAW_H
#define DEF_TOOLBAR_DRAW_H

#include "libdevcpp.h"
#include <QToolBar>
#include <QAction>
#include <QActionGroup>
#include <QSpinBox>
#include <QHBoxLayout>

namespace Ihm
{
	class ToolBarDraw : public QToolBar
	{
		Q_OBJECT
		
		public :
		//Attributes
		//{
			
			//Constants
			//{
				
				static const int SizeSpinBoxMax;
				static const int SizeSpinBoxMin;
				static const int SizeSpinBoxDef;
				static const QString SizeSpinBoxSuffix;
				
				
				static const QSize FixedSize;
				
			//}
			
		//}
		
		//Builders
		//{
			
			ToolBarDraw(QWidget* parent = NULL);
			
		//}
		
		//Destroyers
		//{
			
			//~ ~ToolBarDraw();
			
		//}
		
		//Methods
		//{
			
			//Getters
			//{
				QAction* getActionRun();
				QAction* getActionStart();
				QAction* getActionEnd();
				
				QAction* getActionEllipse();
				QAction* getActionRectangle();
				QAction* getActionLine();
				QAction* getActionHandFree();
				QAction* getActionErraser();
				QActionGroup* getActionGroupDraw();
				
				QAction* getActionFill();

                                int getSizeSpinBox();
				
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
				
				void setSize(int size);
				
		//}
		
		//Signals
		//{
			
			signals:
				
				void sizeChanged(int size);
				
		//}
			
		protected :
		//Attributes
		//{
			
			//Variables
			//{
				
				QAction* actionRun_;
				QAction* actionStart_;
				QAction* actionEnd_;
				
				QSpinBox* sizeSpinBox_;
				QAction* actionEllipse_;
				QAction* actionRectangle_;
				QAction* actionLine_;
				QAction* actionHandFree_;
				QAction* actionErraser_;
				QActionGroup* actionGroupDraw_;
				
				QAction* actionFill_;
				
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


