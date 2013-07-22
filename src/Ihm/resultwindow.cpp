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

#include "resultwindow.h"

using namespace Ihm;

/*! Titre
	\project DiRIGe
	\class ResultWindow
	\ingroup Ihm
	\brief Une classe pour la gestion et l'affichage du résultat
	\author Copyright 2010 Antoine GRÉA <grea09@gmail.com>
	\sa {Ihm}
 */

//Constants
//{
	
	const QString ResultWindow::Title = QString::fromUtf8("Résultat");
	const QString ResultWindow::FileNameDef = "sans-titre.png";
	
	const QSize ResultWindow::IconSize = QSize(24,24);
	
//}

//Builders
//{
	
	ResultWindow::ResultWindow(QPixmap pixmap, QPoint* start, QPoint* end, QColor resultColor, QWidget* parent)
		: QMainWindow(parent)
	{
		debugsub(ENTER);
		
		
		build(pixmap,start,end,resultColor);
		
		debugsub(EXIT_SUCCESS);
	}
	
//}

//Destroyers
//{
	
	
	
//{

//Getters
//{
	
	QToolBar* ResultWindow::getToolBarFile()
	{
		debugsub(ENTER);
		debugsub(EXIT_SUCCESS);
		return toolBarFile_;
	}
	
	
	ToolBarZoom* ResultWindow::getToolBarZoom()
	{
		debugsub(ENTER);
		debugsub(EXIT_SUCCESS);
		return toolBarZoom_;
	}
	
	
//}

//Setters
//{
	
	
	
//}

//Processing
//{
	
	void ResultWindow::build(QPixmap pixmap, QPoint* start, QPoint* end, QColor resultColor)
	{
		debugsub(ENTER);
		
		fileName_ = FileNameDef;
		QToolBar* toolBarFile_ = new QToolBar(this);
		
		actionSave_ = new QAction(QIcon(":/images/save.png"),"Enregistrer la carte", toolBarFile_);
		actionSave_->setIconVisibleInMenu(true);
		actionSave_->setObjectName(QString::fromUtf8("actionSave_"));
		actionSave_->setShortcut(QKeySequence::Save);
#ifndef QT_NO_TOOLTIP
		actionSave_->setToolTip("Enregistrer la carte");
#endif // QT_NO_TOOLTIP
		
		actionSaveAs_ = new QAction(QIcon(":/images/save-as.png"),"Enregistrer sous ...",toolBarFile_);
		actionSaveAs_->setIconVisibleInMenu(true);
		actionSaveAs_->setObjectName(QString::fromUtf8("actionSaveAs_"));
		actionSaveAs_->setShortcut(QKeySequence::SaveAs);
		
		actionClose_ = new QAction(QIcon(":/images/color-delete.png"),"Fermer le document",this);
		actionClose_->setIconVisibleInMenu(true);
		actionClose_->setObjectName(QString::fromUtf8("actionClose_"));
		actionClose_->setShortcut(QKeySequence::Close);
		
		actionQuit_ = new QAction(QIcon(":/images/quit.png"),"Quitter",this);
		actionQuit_->setIconVisibleInMenu(true);
		actionQuit_->setObjectName(QString::fromUtf8("actionQuit_"));
		actionQuit_->setShortcut(Qt::CTRL + Qt::Key_Q);
		
		toolBarFile_->addAction(actionSave_);
		toolBarFile_->addAction(actionSaveAs_);
		
		
		//~ QToolBar* toolBarColor_ = new QToolBar(this);
		//~ 
		//~ actionColor_ = new QAction(QIcon(":/images/color.png"),"Couleur du chemin", toolBarFile_);
		//~ actionColor_->setIconVisibleInMenu(true);
		//~ actionColor_->setObjectName(QString::fromUtf8("actionColor_"));
		//~ actionColor_->setShortcut(QKeySequence::Save);
//~ #ifndef QT_NO_TOOLTIP
		//~ actionColor_->setToolTip("Couleur du chemin");
//~ #endif // QT_NO_TOOLTIP
		//~ 
		//~ toolBarColor_->addAction(actionColor_);
		
		toolBarZoom_ = new ToolBarZoom(this);
		
		menu_ = new QMenuBar(this);
		
		QMenu* menuFile = new QMenu(menu_);
		menuFile->setTitle("&Fichier");
		menuFile->addAction(actionSave_);
		menuFile->addAction(actionSaveAs_);
                menuFile->addAction(actionQuit_);
		
		QMenu* menuView = new QMenu(menu_);
		menuView->setTitle("&Affichage");
		menuView->addAction(toolBarZoom_->getActionZoomPlus());
		menuView->addAction(toolBarZoom_->getActionZoomDef());
		menuView->addAction(toolBarZoom_->getActionZoomMinus());
		//~ menuView->addSeparator();
		//~ menuView->addAction(actionColor_);
		
		debug();
		menu_->addMenu(menuFile);
		menu_->addMenu(menuView);
		debug();
		QScrollArea* scrollArea_ = new QScrollArea(this);
		scrollArea_->setAlignment(Qt::AlignCenter);
		debug();
		//~ ICI pour le plugin
		pluginInterface_ = new PluginType(scrollArea_);
		pluginInterface_->setMap(pixmap);
		pluginInterface_->setStartPoint(start);
		pluginInterface_->setEndPoint(end);
		pluginInterface_->setResultColor(resultColor);
		pluginInterface_->setParent(scrollArea_);
		pluginInterface_->setDrawFigure(PluginType::VOID);
		scrollArea_->setWidget(pluginInterface_);
		debug();
		
		connect(actionSave_,SIGNAL(triggered()),this,SLOT(save()));
		
		connect(actionSaveAs_,SIGNAL(triggered()),this,SLOT(saveAs()));
		
		connect(actionClose_,SIGNAL(triggered()),this,SLOT(closeCurrentFile()));
		
		connect(actionQuit_,SIGNAL(triggered()),this,SLOT(quit()));
		
		connect(toolBarZoom_,SIGNAL(zoomChanged(float)),pluginInterface_,SLOT(setZoomValue(float)));
		debug();
		this->setDocumentMode ( true );
		this->setIconSize ( IconSize );
		
		this->addToolBar(Qt::TopToolBarArea,toolBarFile_);
		//~ this->addToolBar(Qt::TopToolBarArea,toolBarColor_);
		this->addToolBar(Qt::TopToolBarArea,toolBarZoom_);
		
		this->setMenuBar ( menu_ );
		
		this->setCentralWidget ( (QWidget*)scrollArea_ );
		
		//~ this->setStatusBar(statusBar_);
		debug();
		this->setWindowTitle(Title + " - " + fileName_);
		this->setWindowIcon(QIcon(":/images/dirige.svg"));
		
		
		debugsub(EXIT_SUCCESS);
	}
	
	
	void ResultWindow::save()
	{
		debugsub(ENTER);
		if(fileName_ != FileNameDef && pluginInterface_ != NULL)
		{
			debug();
			pluginInterface_->saveMap(fileName_);
		}
		else if(pluginInterface_ != NULL)
		{
			debug();
			this->saveAs();
		}
		debugsub(EXIT_SUCCESS);
	}
	
	void ResultWindow::saveAs()
	{
		debugsub(ENTER);
		if( pluginInterface_ )
		{
			QString fileName = QFileDialog::getSaveFileName(this,"Sauvegarder " + fileName_, "", "Tous les fichiers (*);;BitMap (*.bmp);;Portable Network Graphics (*.png);;Joint Photographic Experts Group (*.jpg);;Graphics Interchange Format (*.gif)");
			if (!fileName.isEmpty()) 
			{
				if (pluginInterface_) 
				{
					//~ QMessageBox::warning(this, "Sauvegarder " + fileName_, QString::fromUtf8("L'image n'a pas pu être sauvegardé. Le format cible doit être \".bmp\" ou \".png\"."), QMessageBox::Cancel);
					pluginInterface_->saveMap(fileName);
				}
				fileName_ = fileName;
			}
		}
		this->setWindowTitle(Title + " - " + fileName_);
		debugsub(EXIT_SUCCESS);
	}
	
    void ResultWindow::closeCurrentFile(QCloseEvent * event)
	{
		debugsub(ENTER);
		
		switch (QMessageBox::question(this, "Fermer le document", "Voulez-vous enregistrer avant de fermer ?", QMessageBox::Save | QMessageBox::Discard | QMessageBox::Abort ) )
		{
			case QMessageBox::Save :
				save();
			case QMessageBox::Discard :
				//~ delete pluginInterface_;
				event->accept();
			break;
			default : 
				event->ignore();
			break;
		}
		this->setWindowTitle(Title );
		debugsub(EXIT_SUCCESS);
	}
	
	void ResultWindow::closeEvent (QCloseEvent * event)
	{
		debugsub(ENTER);
		closeCurrentFile(event);
		debugsub(EXIT_SUCCESS);
	}
	
	
	void ResultWindow::run()
	{
		debugsub(ENTER);
		if (dynamic_cast<MainWindow*>(parentWidget()))
		{
			MainWindow* parent = dynamic_cast<MainWindow*>(parentWidget());
			pluginInterface_->setRobotParameters(parent->getToolBarRobot()->getCostHalfTurn(),parent->getToolBarRobot()->getRotation(),parent->getToolBarRobot()->getWidth(),parent->getToolBarColor()->getcolorCost());
			pluginInterface_->run();
		}
		debugsub(EXIT_SUCCESS);
	}
	
//}

//Operators
//{
	
	
	
//}

//Display
//{
	
	
	
//}
