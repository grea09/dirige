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

#include "mainwindow.h"

using namespace Ihm;

/*! Titre
	\project DiRIGe
	\class MainWindow
	\ingroup Ihm
	\brief Une classe pour la gestion et l'affichage des menu et barre d'outils
	\author Copyright 2010 Antoine GRÉA <grea09@gmail.com>
	\sa {Ihm}
 */

//Constants
//{
	
	const QString MainWindow::Title = "DiRIGe";
	const QString MainWindow::FileNameDef = "sans-titre.png";
	
	const QSize MainWindow::IconSize = QSize(24,24);
	
//}

//Builders
//{
	
	MainWindow::MainWindow(QWidget* parent)
		: QMainWindow(parent)
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
	
	ToolBarFile* MainWindow::getToolBarFile()
	{
		debugsub(ENTER);
		debugsub(EXIT_SUCCESS);
		return toolBarFile_;
	}
	
	ToolBarDraw* MainWindow::getToolBarDraw()
	{
		debugsub(ENTER);
		debugsub(EXIT_SUCCESS);
		return toolBarDraw_;
	}
	
	ToolBarZoom* MainWindow::getToolBarZoom()
	{
		debugsub(ENTER);
		debugsub(EXIT_SUCCESS);
		return toolBarZoom_;
	}
	
	ToolBarRobot* MainWindow::getToolBarRobot()
	{
		debugsub(ENTER);
		debugsub(EXIT_SUCCESS);
		return toolBarRobot_;
	}
	
	ToolBarColor* MainWindow::getToolBarColor()
	{
		debugsub(ENTER);
		debugsub(EXIT_SUCCESS);
		return toolBarColor_;
	}
	
//}

//Setters
//{
	
	
	
//}

//Processing
//{
	
	void MainWindow::build()
	{
		debugsub(ENTER);
		
		fileName_ = FileNameDef;
		debug();
		toolBarFile_ = new ToolBarFile(this);
		toolBarDraw_ = new ToolBarDraw(this);
		toolBarZoom_ = new ToolBarZoom(this);
		toolBarRobot_ = new ToolBarRobot(this);
		toolBarColor_ = new ToolBarColor(this);
		debug();
		
		menu_ = new Menu(this);

		QScrollArea* scrollArea_ = new QScrollArea(this);
		scrollArea_->setAlignment(Qt::AlignCenter);
		debug();
		//~ ICI pour le plugin
		pluginInterface_.setParent(scrollArea_);
		pluginInterface_.setDrawFigure(PluginType::HANDFREE);
		
		scrollArea_->setWidget(&pluginInterface_);
		
		//~ statusBar_ = new QStatusBar(this);
		
		connect(toolBarFile_->getActionNew(),SIGNAL(triggered()),this,SLOT(newFile()));
		connect(toolBarFile_->getActionOpen(),SIGNAL(triggered()),this,SLOT(open()));
		connect(toolBarFile_->getActionSave(),SIGNAL(triggered()),this,SLOT(save()));
		connect(menu_->getActionSaveAs(),SIGNAL(triggered()),this,SLOT(saveAs()));
        connect(menu_->getActionClose(),SIGNAL(triggered()),this,SLOT(closeCurrentFile()));
		connect(menu_->getActionQuit(),SIGNAL(triggered()),this,SLOT(close()));
		
		connect(toolBarDraw_->getActionRun(),SIGNAL(triggered()),this,SLOT(run()));
		
		connect(toolBarDraw_->getActionGroupDraw(),SIGNAL(triggered(QAction*)),&pluginInterface_,SLOT(setDrawFigure(QAction*)));
		connect(toolBarDraw_->getActionFill(),SIGNAL(triggered(bool)),&pluginInterface_,SLOT(setBooleanFill(bool)));
		connect(toolBarDraw_,SIGNAL(sizeChanged(int)),&pluginInterface_,SLOT(setSizePen(int)));
		
		connect(toolBarZoom_,SIGNAL(zoomChanged(float)),&pluginInterface_,SLOT(setZoomValue(float)));
		
		
		connect(toolBarColor_,SIGNAL(colorIt(QColor)),&pluginInterface_,SLOT(setColorPen(QColor)));
		debug();
		connect(menu_->getActionColor(),SIGNAL(triggered()),&pluginInterface_,SLOT(setResultColor()));
		connect(menu_->getActionGroupToolBar(),SIGNAL(triggered(QAction*)),this,SLOT(closeToolbar(QAction*)));
		
		connect(menu_->getActionAboutDirige(),SIGNAL(triggered()),this,SLOT(aboutDirige()));
		
		toolBarDraw_->setSize(ToolBarDraw::SizeSpinBoxDef);
		
		this->setDocumentMode ( true );
		this->setIconSize ( IconSize );
		
		this->addToolBar(Qt::TopToolBarArea,toolBarFile_);
		this->addToolBar(Qt::TopToolBarArea,toolBarDraw_);
		this->addToolBar(Qt::TopToolBarArea,toolBarZoom_);
		this->addToolBar(Qt::RightToolBarArea,toolBarRobot_);
		this->addToolBar(Qt::LeftToolBarArea,toolBarColor_);
		debug();
		this->setMenuBar ( menu_ );
		
		this->setCentralWidget ( (QWidget*)scrollArea_ );
		
		//~ this->setStatusBar(statusBar_);
		
		this->setWindowTitle(Title + " - " + fileName_);
		this->setWindowIcon(QIcon(":/images/dirige.png"));
		
		
		debugsub(EXIT_SUCCESS);
	}
	
	void MainWindow::newFile()
	{
		//~ QInputDialog* newFileDialog = new QInputDialog(this);
		//~ debugV(newFileDialog-> intValue());
		QCloseEvent* event = new QCloseEvent();
		closeCurrentFile(event);
		if (event-> isAccepted())
		{
			bool widthTest;
			bool heightTest;
			int widthTemp = QInputDialog::getInt(this,"Nouveau fichier","Largeur",600,0,6000,1,&widthTest);
			if(widthTest)
			{
				int heightTemp = QInputDialog::getInt(this,"Nouveau fichier","Hauteur",600,0,6000,1,&heightTest);
				if(heightTest)
				{
					QPixmap pixmap(widthTemp, heightTemp);
					pixmap.fill(Qt::white);
					pluginInterface_.setMap(pixmap);
					fileName_ = FileNameDef;
					this->setWindowTitle(Title + " - " + fileName_);
					connect(toolBarDraw_->getActionGroupDraw(),SIGNAL(triggered(QAction*)),&pluginInterface_,SLOT(setDrawFigure(QAction*)));
					connect(toolBarDraw_->getActionFill(),SIGNAL(triggered(bool)),&pluginInterface_,SLOT(setBooleanFill(bool)));

					connect(toolBarZoom_,SIGNAL(zoomChanged(float)),&pluginInterface_,SLOT(setZoomValue(float)));
					connect(toolBarDraw_,SIGNAL(sizeChanged(int)),&pluginInterface_,SLOT(setSizePen(int)));

					connect(toolBarColor_,SIGNAL(colorIt(QColor)),&pluginInterface_,SLOT(setColorPen(QColor)));

					pluginInterface_.setSizePen(toolBarDraw_->getSizeSpinBox());
			   }
			}
		}
		pluginInterface_.repaint();
		pluginInterface_.update();
	}
	
	
	void MainWindow::open()
	{
		debugsub(ENTER);
		
		QString fileName = qApp->applicationDirPath();
		QCloseEvent* event = new QCloseEvent();
		closeCurrentFile(event);
		if (event-> isAccepted())
		{
			fileName = QFileDialog::getOpenFileName(this, QString::fromUtf8("Ouvrir Image"), "", "Bitmap (*.bmp);;Portable Network Graphics(*.png)");
	
		
			if (!fileName.isEmpty())
			{
				fileName_ = fileName;
				QPixmap* newMap = new QPixmap();
				if (!newMap->load(fileName))
				{
					QMessageBox::warning(this, QString::fromUtf8("Echec de l'ouverture"), QString::fromUtf8("L'image ne peut pas être chargée. Vérifiez que l'encodage est bien BMP ou PNG."), QMessageBox::Cancel);
					return;
				}
				else
				{
					pluginInterface_.loadMap(fileName_);
					//~ delete toolBarColor_;
					//~ delete toolBarRobot_;
					//~ toolBarColor_ = new ToolBarColor(this);
					//~ toolBarRobot_ = new ToolBarRobot(this);
					toolBarZoom_->setZoom();
				}
			}
			this->setWindowTitle(Title + " - " + fileName_);
		}
		
		debugsub(EXIT_SUCCESS);
	}
	
	void MainWindow::save()
	{
		debugsub(ENTER);
		if(fileName_ != FileNameDef )
		{
			debug();
			pluginInterface_.saveMap(fileName_);
		}
		else
		{
			debug();
			this->saveAs();
		}
		debugsub(EXIT_SUCCESS);
	}
	
	void MainWindow::saveAs()
	{
		debugsub(ENTER);

		QString fileName = QFileDialog::getSaveFileName(this,"Sauvegarder " + fileName_, "", "BitMap (*.bmp);;Portable Network Graphics (*.png)");
		if (!fileName.isEmpty()) 
		{
			//~ QMessageBox::warning(this, "Sauvegarder " + fileName_, QString::fromUtf8("L'image n'a pas pu être sauvegardé. Le format cible doit être \".bmp\" ou \".png\"."), QMessageBox::Cancel);
			pluginInterface_.saveMap(fileName);
			fileName_ = fileName;
		}
		this->setWindowTitle(Title + " - " + fileName_);
		debugsub(EXIT_SUCCESS);
	}
	
	void MainWindow::closeCurrentFile(QCloseEvent * event)
	{
		debugsub(ENTER);
		if(pluginInterface_.getMap().width() != 0 && pluginInterface_.getMap().height() != 0)
		{
			switch (QMessageBox::question(this, "Fermer le document", "Voulez-vous enregistrer avant de fermer ?", QMessageBox::Save | QMessageBox::Discard | QMessageBox::Abort ) )
			{
				case QMessageBox::Save :
						save();
				case QMessageBox::Discard :
						pluginInterface_.setMap(QPixmap(0,0));
						if (event)
						{
							event->accept();
						}
				break;
				default :
						if (event)
						{
							event->ignore();
						}
						
				break;
			}
		}
		pluginInterface_.repaint();
		pluginInterface_.update();
		this->setWindowTitle(Title );
		debugsub(EXIT_SUCCESS);
	}
	
	void MainWindow::closeEvent (QCloseEvent * event)
	{
		debugsub(ENTER);
		closeCurrentFile(event);
		debugsub(EXIT_SUCCESS);
	}
	
	
	void MainWindow::closeToolbar(QAction* action)
	{
		debugsub(ENTER);
		if (action->objectName() == "actionToolBarFile_")
		{
			toolBarFile_->setVisible(!(toolBarFile_->isVisible()));
		}
		else if (action->objectName() == "actionToolBarDraw_")
		{
			toolBarDraw_->setVisible(!(toolBarDraw_->isVisible()));
		}
		else if (action->objectName() == "actionToolBarZoom_")
		{
			toolBarZoom_->setVisible(!(toolBarZoom_->isVisible()));
		}
		else if (action->objectName() == "actionToolBarRobot_")
		{
			toolBarRobot_->setVisible(!(toolBarRobot_->isVisible()));
		}
		else if (action->objectName() == "actionToolBarColor_")
		{
			toolBarColor_->setVisible(!(toolBarColor_->isVisible()));
		}
		
		debugsub(EXIT_SUCCESS);
	}
	
	void MainWindow::run()
	{
		debugsub(ENTER);
		ResultWindow* result = new ResultWindow(pluginInterface_.getMap(),pluginInterface_.getStartPoint(),pluginInterface_.getEndPoint(),pluginInterface_.getResultColor(),this);
		result->run();
		result->show();
		debugsub(EXIT_SUCCESS);
	}
	
	void MainWindow::aboutDirige()
	{
		
		QMessageBox::about(this,QString::fromUtf8("À propos de DIRiGe"),
		QString::fromUtf8(
		"\tLe projet DIRiGe est un calculateur de chemin pour un robot dans un environement donné. \nCopyright 2010 Antoine GRÉA <grea09@gmail.com>, Alex-Medi ZAHID, Blon THO\n\n\tThis program is free software; you can redistribute it and/or modifyit under the terms of the GNU General Public License as published bythe Free Software Foundation; either version 2 of the License, or(at your option) any later version.\n\tThis program is distributed in the hope that it will be useful,but WITHOUT ANY WARRANTY; without even the implied warranty ofMERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See theGNU General Public License for more details.You should have received a copy of the GNU General Public Licensealong with this program; if not, write to the Free SoftwareFoundation, Inc., 51 Franklin Street, Fifth Floor, Boston,MA 02110-1301, USA."
		)
		);
		
	}
	
//}

//Operators
//{
	
	
	
//}

//Display
//{
	
	
	
//}
