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

#include "toolbarfile.h"

using namespace Ihm;

/*! Titre
	\project DiRIGe
	\class ToolBarFile
	\ingroup Ihm
	\brief Une barre d'outil pour la gestion des fichiers
	\author Copyright 2010 Antoine GRÉA <grea09@gmail.com>
	\sa Menu, MainWindows, {Ihm}
 */

//Constants
//{
	
	const QSize ToolBarFile::FixedSize = QSize(32,32 * 4);
	
//}

//Builders
//{
	
	ToolBarFile::ToolBarFile(QWidget* parent)
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
	
	QAction* ToolBarFile::getActionNew()
	{
		debugsub(ENTER);
		
		return actionNew_;
		
		debugsub(EXIT_SUCCESS);
	}
	
	QAction* ToolBarFile::getActionOpen()
	{
		debugsub(ENTER);
		
		return actionOpen_;
		
		debugsub(EXIT_SUCCESS);
	}
	
	QAction* ToolBarFile::getActionSave()
	{
		debugsub(ENTER);
		
		return actionSave_;
		
		debugsub(EXIT_SUCCESS);
	}
	
	
	
//}

//Setters
//{
	
	
	
//}

//Processing
//{
	
	void ToolBarFile::build()
	{
		debugsub(ENTER);
		
		actionNew_ = new QAction(QIcon(":/images/new.png"),"Nouvelle carte", this);
		actionNew_->setIconVisibleInMenu(true);
		actionNew_->setObjectName(QString::fromUtf8("actionNew_"));
		actionNew_->setShortcut(QKeySequence::New);
#ifndef QT_NO_TOOLTIP
		actionNew_->setToolTip("Une nouvelle carte");
#endif // QT_NO_TOOLTIP
		
		actionOpen_ = new QAction(QIcon(":/images/open.png"),"Ouvrir une carte", this);
		actionOpen_->setIconVisibleInMenu(true);
		actionOpen_->setObjectName(QString::fromUtf8("actionOpen_"));
		actionOpen_->setShortcut(QKeySequence::Open);
#ifndef QT_NO_TOOLTIP
		actionOpen_->setToolTip("Ouvrir une carte");
#endif // QT_NO_TOOLTIP
		
		actionSave_ = new QAction(QIcon(":/images/save.png"),"Enregistrer la carte", this);
		actionSave_->setIconVisibleInMenu(true);
		actionSave_->setObjectName(QString::fromUtf8("actionSave_"));
		actionSave_->setShortcut(QKeySequence::Save);
#ifndef QT_NO_TOOLTIP
		actionSave_->setToolTip("Enregistrer la carte");
#endif // QT_NO_TOOLTIP
		
		
		
		this->addAction(actionNew_);
		this->addAction(actionOpen_);
		this->addAction(actionSave_);
		
		
		//~ this->setFixedSize(FixedSize);
		this->setObjectName(QString::fromUtf8("Fichier"));
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
