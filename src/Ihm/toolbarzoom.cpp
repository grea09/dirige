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

#include "toolbarzoom.h"

using namespace Ihm;

/*! Titre
	\project DiRIGe
	\class ToolBarZoom
	\ingroup Ihm
	\brief Une classe pour zoomer
	\author Copyright 2010 Antoine GRÉA <grea09@gmail.com>
	\sa MainWindow, Menu, {Ihm}
 */

//Constants
//{
	
	
	const int ToolBarZoom::ZoomSpinBoxMax = 1000;
	const int ToolBarZoom::ZoomSpinBoxMin = 50;
	const int ToolBarZoom::ZoomSpinBoxDef = 100;
	const int ToolBarZoom::ZoomInc = 50;
	const QString ToolBarZoom::ZoomSpinBoxSuffix = "%";
	
	const QSize ToolBarZoom::FixedSize = QSize(32,32 * 7);
	
//}

//Builders
//{
	
	ToolBarZoom::ToolBarZoom(QWidget* parent)
		: QToolBar(parent)
	{
		debugsub(ENTER);
		
		build();
		
		debugsub(EXIT_SUCCESS);
	}
	
//}

//Destroyers
//{
	
	
	
//{

//Getters
//{
	
	
	QAction* ToolBarZoom::getActionZoomPlus()
	{
		debugsub(ENTER);
		
		
		
		debugsub(EXIT_SUCCESS);
		return actionZoomPlus_;
	}
	
	QAction* ToolBarZoom::getActionZoomMinus()
	{
		debugsub(ENTER);
		
		
		
		debugsub(EXIT_SUCCESS);
		return actionZoomMinus_;
	}
	
	QAction* ToolBarZoom::getActionZoomDef()
	{
		debugsub(ENTER);
		
		
		
		debugsub(EXIT_SUCCESS);
		return actionZoomDef_;
	}
	
//}

//Setters
//{
	
	
	void ToolBarZoom::zoomIn()
	{
		debugsub(ENTER);
		debugV(zoomSpinBox_->value());
		debugV(ZoomInc);
		setZoom(zoomSpinBox_->value()+ZoomInc);
		
		debugsub(EXIT_SUCCESS);
	}
	
	void ToolBarZoom::zoomOut()
	{
		debugsub(ENTER);
		debugV(zoomSpinBox_->value());
		debugV(ZoomInc);
		setZoom(zoomSpinBox_->value()-ZoomInc);
		
		debugsub(EXIT_SUCCESS);
	}
	
	void ToolBarZoom::setZoom(int zoom)
	{
		debugsub(ENTER);
		
		zoomSpinBox_->setValue(borne(zoom,ZoomSpinBoxMin,ZoomSpinBoxMax));
		emit zoomChanged(((float)borne(zoom,ZoomSpinBoxMin,ZoomSpinBoxMax)/(float)100));
		
		debugsub(EXIT_SUCCESS);
	}
	
//}

//Processing
//{
	
	void ToolBarZoom::build()
	{
		debugsub(ENTER);
		
		
		actionZoomPlus_ = new QAction(QIcon(":/images/zoom-plus.png"),"Zoom +",this);
		actionZoomPlus_->setIconVisibleInMenu(true);
		actionZoomPlus_->setObjectName(QString::fromUtf8("actionZoomPlus_"));
		actionZoomPlus_->setShortcut(QKeySequence::ZoomIn);
#ifndef QT_NO_TOOLTIP
		actionZoomPlus_->setToolTip("Zoomer");
#endif // QT_NO_TOOLTIP
		
		actionZoomMinus_ = new QAction(QIcon(":/images/zoom-minus.png"),"Zoom -",this);
		actionZoomMinus_->setIconVisibleInMenu(true);
		actionZoomMinus_->setObjectName(QString::fromUtf8("actionZoomMinus_"));
		actionZoomMinus_->setShortcut(QKeySequence::ZoomOut);
#ifndef QT_NO_TOOLTIP
		actionZoomMinus_->setToolTip(QString::fromUtf8("Dézoomer"));
#endif // QT_NO_TOOLTIP
		
		actionZoomDef_ = new QAction(QIcon(":/images/zoom-def.png"),QString::fromUtf8("Zoom par défaut"),this);
		actionZoomDef_->setIconVisibleInMenu(true);
		actionZoomDef_->setObjectName(QString::fromUtf8("actionZoomDef_"));
		actionZoomDef_->setShortcut(Qt::CTRL + Qt::Key_0);
#ifndef QT_NO_TOOLTIP
		actionZoomDef_->setToolTip(QString::fromUtf8("Zoom par défaut"));
#endif // QT_NO_TOOLTIP
		
		
		zoomSpinBox_ = new QSpinBox(this);
		zoomSpinBox_->setRange ( ZoomSpinBoxMin, ZoomSpinBoxMax );
		zoomSpinBox_->setValue ( ZoomSpinBoxDef );
		zoomSpinBox_->setSuffix ( ZoomSpinBoxSuffix );
		
		
		connect(actionZoomPlus_,SIGNAL(triggered()),this,SLOT(zoomIn()));
		connect(actionZoomMinus_,SIGNAL(triggered()),this,SLOT(zoomOut()));
		connect(actionZoomDef_,SIGNAL(triggered()),this,SLOT(setZoom()));
                connect(zoomSpinBox_,SIGNAL(valueChanged(int)),this,SLOT(setZoom(int)));
		
		
		
		//~ Pour l'ordre modifiez ici
		
		this->addAction(actionZoomMinus_);
		this->addAction(actionZoomDef_);
		this->addAction(actionZoomPlus_);
		this->addWidget(zoomSpinBox_);
		
		//~ this->setFixedSize(FixedSize);
		this->setObjectName(QString::fromUtf8("Zoom"));
		this->setVisible(true);
		debugsub(EXIT_SUCCESS);
	}
	
//}

//Operators
//{
	
	
	
//}

//Display
//{
	
	
	
//}
