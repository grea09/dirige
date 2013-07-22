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

#include "menu.h"

using namespace Ihm;

/*! Titre
	\project DiRIGe
	\class Menu
	\ingroup Ihm
	\brief Un menu pour la fenêtre principale
	\author Copyright 2010 Antoine GRÉA <grea09@gmail.com>
	\sa MainWindow, {Ihm}
 */

//Constants
//{
	
	
	
//}

//Builders
//{
	
	Menu::Menu(QMainWindow* parent)
		: QMenuBar(parent), parent_((MainWindow*)parent)
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
	
	QAction* Menu::getActionSaveAs()
	{
		
		return actionSaveAs_;
		
	}
	
	QAction* Menu::getActionClose()
	{
		
		return actionClose_;
		
	}
	
	QAction* Menu::getActionQuit()
	{
		
		return actionQuit_;
		
	}
	
	QActionGroup* Menu::getActionGroupToolBar()
	{
		
		return actionGroupToolBar_;
		
	}
	
	QAction* Menu::getActionColor()
	{
		
		return actionColor_;
		
	}
	
	QAction* Menu::getActionHelp()
	{
		
		return actionHelp_;
		
	}
	
	QAction* Menu::getActionAboutDirige()
	{
		
		return actionAboutDirige_;
		
	}
	
//}

//Setters
//{
	
	
	
//}

//Processing
//{
	
	void Menu::build()
	{
		debugsub(ENTER);
		
		menuFile_ = new QMenu(this);
		menuFile_->setTitle("&Fichier");
			actionSaveAs_ = new QAction(QIcon(":/images/save-as.png"),"Enregistrer sous ...",menuFile_);
			actionSaveAs_->setIconVisibleInMenu(true);
			actionSaveAs_->setObjectName(QString::fromUtf8("actionSaveAs_"));
			actionSaveAs_->setShortcut(QKeySequence::SaveAs);
			
			actionClose_ = new QAction(QIcon(":/images/color-delete.png"),"Fermer le document",menuFile_);
			actionClose_->setIconVisibleInMenu(true);
			actionClose_->setObjectName(QString::fromUtf8("actionClose_"));
			actionClose_->setShortcut(QKeySequence::Close);
			
			actionQuit_ = new QAction(QIcon(":/images/quit.png"),"Quitter",menuFile_);
			actionQuit_->setIconVisibleInMenu(true);
			actionQuit_->setObjectName(QString::fromUtf8("actionQuit_"));
			actionQuit_->setShortcut(Qt::CTRL + Qt::Key_Q);
			
			menuFile_->addAction(parent_->getToolBarFile()->getActionNew());
			menuFile_->addAction(parent_->getToolBarFile()->getActionOpen());
			menuFile_->addSeparator();
			menuFile_->addAction(parent_->getToolBarFile()->getActionSave());
			menuFile_->addAction(actionSaveAs_);
			menuFile_->addSeparator();
			menuFile_->addAction(actionClose_);
			menuFile_->addAction(actionQuit_);
		
		menuEdit_ = new QMenu(this);
		menuEdit_->setTitle(QString::fromUtf8("Édit&er"));
			menuEdit_->addAction(parent_->getToolBarDraw()->getActionEllipse());
			menuEdit_->addAction(parent_->getToolBarDraw()->getActionRectangle());
			menuEdit_->addAction(parent_->getToolBarDraw()->getActionLine());
			menuEdit_->addAction(parent_->getToolBarDraw()->getActionHandFree());
			menuEdit_->addAction(parent_->getToolBarDraw()->getActionErraser());
			//~ menuEdit_->addSeparator();
			menuEdit_->addAction(parent_->getToolBarDraw()->getActionFill());
			//~ menuEdit_->addAction(parent_->getToolBarDraw()->getActionColor());
			menuEdit_->addSeparator();
			menuEdit_->addAction(parent_->getToolBarDraw()->getActionStart());
			menuEdit_->addAction(parent_->getToolBarDraw()->getActionEnd());
			menuEdit_->addAction(parent_->getToolBarDraw()->getActionRun());
			
		menuView_ = new QMenu(this);
		menuView_->setTitle("&Affichage");
			menuToolBar_ = new QMenu(menuView_);
			menuToolBar_->setTitle(QString::fromUtf8("&Barre d'outils"));
				
				actionGroupToolBar_ = new QActionGroup(menuToolBar_);
				actionGroupToolBar_->setExclusive(false);
				
				actionToolBarFile_ = new QAction(QIcon(":/images/save-as.png"),"Fichier",actionGroupToolBar_);
				actionToolBarFile_->setIconVisibleInMenu(true);
				actionToolBarFile_-> setCheckable(true);
				actionToolBarFile_->setObjectName(QString::fromUtf8("actionToolBarFile_"));
				
				actionToolBarDraw_ = new QAction(QIcon(":/images/handfree.png"),"Dessin",actionGroupToolBar_);
				actionToolBarDraw_->setIconVisibleInMenu(true);
				actionToolBarDraw_-> setCheckable(true);
				actionToolBarDraw_->setObjectName(QString::fromUtf8("actionToolBarDraw_"));
				
				actionToolBarZoom_ = new QAction(QIcon(":/images/zoom-def.png"),"Zoom",actionGroupToolBar_);
				actionToolBarZoom_->setIconVisibleInMenu(true);
				actionToolBarZoom_-> setCheckable(true);
				actionToolBarZoom_->setObjectName(QString::fromUtf8("actionToolBarZoom_"));
				
				actionToolBarRobot_ = new QAction(QIcon(":/images/nxt.svg"),QString::fromUtf8("Paramètres du robot"),actionGroupToolBar_);
				actionToolBarRobot_->setIconVisibleInMenu(true);
				actionToolBarRobot_-> setCheckable(true);
				actionToolBarRobot_->setObjectName(QString::fromUtf8("actionToolBarRobot_"));
				
				actionToolBarColor_ = new QAction(QIcon(":/images/color-edit.png"),"Palette de couleurs",actionGroupToolBar_);
				actionToolBarColor_->setIconVisibleInMenu(true);
				actionToolBarColor_-> setCheckable(true);
				actionToolBarColor_->setObjectName(QString::fromUtf8("actionToolBarColor_"));
				
				actionGroupToolBar_->addAction(actionToolBarFile_);
				actionGroupToolBar_->addAction(actionToolBarDraw_);
				actionGroupToolBar_->addAction(actionToolBarZoom_);
				actionGroupToolBar_->addAction(actionToolBarRobot_);
				actionGroupToolBar_->addAction(actionToolBarColor_);
				
				menuToolBar_->addAction(actionToolBarFile_);
				menuToolBar_->addAction(actionToolBarDraw_);
				menuToolBar_->addAction(actionToolBarZoom_);
				menuToolBar_->addAction(actionToolBarRobot_);
				menuToolBar_->addAction(actionToolBarColor_);
				
			menuView_->addMenu(menuToolBar_);
			menuView_->addAction(parent_->getToolBarZoom()->getActionZoomPlus());
			menuView_->addAction(parent_->getToolBarZoom()->getActionZoomMinus());
			menuView_->addAction(parent_->getToolBarZoom()->getActionZoomDef());
			
			
			
		menuOption_ = new QMenu(this);
		menuOption_->setTitle("&Options");
			actionColor_ = new QAction(QIcon(":/images/color.png"),"Couleur du chemin",menuOption_);
			actionColor_->setIconVisibleInMenu(true);
			actionColor_->setObjectName(QString::fromUtf8("actionColor_"));
			menuOption_->addAction(actionColor_);
		
		menuHelp_ = new QMenu(this);
		menuHelp_->setTitle("Aide");
			actionHelp_ = new QAction(QIcon(":/images/help.png"),"Aide",menuHelp_);
			actionHelp_->setIconVisibleInMenu(true);
			actionHelp_->setObjectName(QString::fromUtf8("actionHelp_"));
			actionHelp_->setShortcut(QKeySequence::HelpContents);
			QMainWindow* helpWindow = new QMainWindow(menuHelp_);
			helpWindow->setWindowTitle("Aide de DiRIGe");
			QScrollArea* scrollHelp = new QScrollArea(helpWindow);
			QLabel* label = new QLabel(QString::fromUtf8("<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0 Transitional//EN\">\n<HTML>\n<HEAD>\n\t<META HTTP-EQUIV=\"CONTENT-TYPE\" CONTENT=\"text/html; charset=utf-8\">\n\t<TITLE></TITLE>\n\t<META NAME=\"GENERATOR\" CONTENT=\"OpenOffice.org 3.1  (Linux)\">\n\t<META NAME=\"AUTHOR\" CONTENT=\"Blon THO\">\n\t<META NAME=\"CREATED\" CONTENT=\"20100323;21130100\">\n\t<META NAME=\"CHANGEDBY\" CONTENT=\"Blon THO\">\n\t<META NAME=\"CHANGED\" CONTENT=\"20100323;22494200\">\n\t<STYLE TYPE=\"text/css\">\n\t<!--\n\t\t@page { margin: 2cm }\n\t\tP { text-indent: 1.2cm; margin-bottom: 0.21cm; text-align: justify; page-break-before: auto }\n\t\tH1 { margin-bottom: 0.21cm; text-align: center }\n\t\tH1.western { font-family: \"Arial\", sans-serif; font-size: 20pt }\n\t\tH1.cjk { font-family: \"MS Mincho\"; font-size: 16pt }\n\t\tH1.ctl { font-family: \"Tahoma\"; font-size: 16pt }\n\t\tH2 { text-indent: 1cm; margin-bottom: 0.21cm; text-align: left }\n\t\tH2.western { font-family: \"Arial\", sans-serif; font-size: 14pt; font-style: italic }\n\t\tH2.cjk { font-family: \"MS Mincho\"; font-size: 14pt; font-style: italic }\n\t\tH2.ctl { font-family: \"Tahoma\"; font-size: 14pt; font-style: italic }\n\t-->\n\t</STYLE>\n</HEAD>\n<BODY LANG=\"fr-FR\" DIR=\"LTR\">\n<P ALIGN=CENTER STYLE=\"text-indent: 0cm; margin-top: 0.42cm; page-break-after: avoid\">\n<FONT FACE=\"Arial, sans-serif\"><FONT SIZE=5><B>DiRIGe</B></FONT></FONT></P>\n<H1 CLASS=\"western\">Mode d'emploi</H1>\n<P>DiRIGe est une application libre et gratuite. Elle permet de\ntrouver le chemin le plus court entre deux points pour un robot dans\nun environnement donné. Cet environnement pourra être dessiné avec\ncette application, ou modifié à partir d'un fichier image (BMP)\nexistant. Le logiciel offre à l'utilisateur plusieurs options de\ndessin comme le choix de la forme à dessiner et de sa couleur.\nEnsuite, il est possible de définir les paramètres du robot pour\nque l'algorithme puisse trouver le chemin le plus court que le robot\naura à parcourir.</P>\n<P ALIGN=LEFT STYLE=\"text-indent: 0cm; margin-bottom: 0cm\"><I>Conseil\n: il est recommandé d'enregistrer constamment l'image éditée car\nil n'existe pas de fonction «&nbsp;Retour en arrière&nbsp;» !</I></P>\n<H2 CLASS=\"western\">Vue générale à l'ouverture</H2>\n<P ALIGN=LEFT STYLE=\"text-indent: 0cm; margin-bottom: 0cm; page-break-before: auto\"></P>\n<H2 CLASS=\"western\">Espace sur lequel l'utilisateur pourra éditer\nl'environnement</H2>\n<P ALIGN=LEFT STYLE=\"text-indent: 0cm; margin-bottom: 0cm; page-break-before: auto\"></P>\n<H2 CLASS=\"western\">Vue générale des options de fichiers</H2>\n<P ALIGN=LEFT STYLE=\"text-indent: 0cm; margin-bottom: 0cm; page-break-before: auto\"></P>\n<H2 CLASS=\"western\">Vue générale des options de dessin disponibles</H2>\n<P ALIGN=LEFT STYLE=\"text-indent: 0cm; margin-bottom: 0cm; page-break-before: auto\"></P>\n<H2 CLASS=\"western\">Vue générale des options de couleurs.</H2>\n<P ALIGN=LEFT STYLE=\"text-indent: 0cm; margin-bottom: 0cm; page-break-before: auto\"></P>\n<H2 CLASS=\"western\">Vue générale des paramètres attribuables au\nrobot.</H2>\n<P ALIGN=LEFT STYLE=\"text-indent: 0cm; margin-bottom: 0cm; page-break-before: auto\"></P>\n<H2 CLASS=\"western\">Barre d'outils</H2>\n<P ALIGN=LEFT STYLE=\"text-indent: 0cm; margin-bottom: 0cm; page-break-before: auto\"></P>\n<H1 CLASS=\"western\">Options de fichier</H1>\n<H2 CLASS=\"western\"> Une nouvelle carte</H2>\n<P>Cette option permettra à l'utilisateur d'ouvrir un nouvel\nenvironnement vierge (blanc).</P>\n<P>Il sera demandé à l'utilisateur d'enregistrer l'environnement\ncourant ou non. Si l'utilisateur souhaite enregistrer son image avant\nd'ouvrir un nouvel environnement, une fenêtre s'ouvrira pour lui\ndemander de choisir l'emplacement du fichier. \n</P>\n<P ALIGN=LEFT STYLE=\"text-indent: 0cm; margin-bottom: 0cm; page-break-before: auto\"></P>\n<P>Ensuite l'application demandera à l'utilisateur d'entrer la\ntaille du nouvel environnement.</P>\n<P ALIGN=LEFT STYLE=\"text-indent: 0cm; margin-bottom: 0cm; page-break-before: auto\"></P>\n<H2 CLASS=\"western\"> Ouvrir une carte</H2>\n<P>Cette option permet à l'utilisateur d'ouvrir un environnement à\npartir d'un fichier image BMP existant.</P>\n<P ALIGN=LEFT STYLE=\"text-indent: 0cm; margin-bottom: 0cm\"><I>Remarque\n: les couleurs existantes sur l'image chargée devront être définies\nmanuellement par l'utilisateur (se référer à la section «&nbsp;Options\nde couleurs&nbsp;»).</I></P>\n<P>Il sera demandé à l'utilisateur d'enregistrer l'environnement\ncourant ou non. Si l'utilisateur souhaite enregistrer son image avant\nd'ouvrir un nouvel environnement, une fenêtre s'ouvrira pour lui\ndemander de choisir l'emplacement du fichier.</P>\n<P ALIGN=LEFT STYLE=\"text-indent: 0cm; margin-bottom: 0cm; page-break-before: auto\"></P>\n<P>Ensuite l'application demandera à l'utilisateur de spécifier\nl'emplacement du fichier image BMP à ouvrir.</P>\n<H2 CLASS=\"western\"> Enregistre la carte</H2>\n<P>Cette option permet à l'utilisateur d'enregistrer l'environnement\nsur lequel il est en train de travailler en un fichier image BMP.</P>\n<P ALIGN=LEFT STYLE=\"text-indent: 0cm; margin-bottom: 0cm\"><I>Remarque\n: aucun paramètre du robot défini ni les couleurs choisies ne\nseront enregistrés.</I></P>\n<H1 CLASS=\"western\">Options de dessin</H1>\n<H2 CLASS=\"western\">Dessiner avec le curseur</H2>\n<P>Cette option permet à l'utilisateur de dessiner librement sur\nl'espace de travail. Lorsqu'il cliquera sur le bouton gauche de la\nsouris sur l'environnement, un point à l'emplacement du curseur sera\ndessiné. Si le bouton gauche de la souris n'est pas relâché,\nl'application continuera de dessiner derrière le curseur. \n</P>\n<H2 CLASS=\"western\">Taille du stylo</H2>\n<P>Cette «&nbsp;spinbox&nbsp;» (zone de sélection numérique)\npermet à l'utilisateur de modifier la taille de dessin du stylo en\npixel. Plus la taille est petite, plus les points dessinés seront\npetits.</P>\n<H2 CLASS=\"western\">Tracer une ellipse</H2>\n<P>Cette option permet de dessiner une ellipse. Dès que le clic\ngauche de la souris est enclenché sur l'environnement, l'emplacement\ndu curseur sera choisi comme centre de l'ellipse. Ensuite, sans\nrelâcher le bouton gauche de la souris, en bougeant le curseur\nl'utilisateur va définir la taille de l'ellipse. Une première\napproche de l'ellipse qui sera dessinée est faite avec des\npointillés. Lorsque le bouton gauche sera relâché, l'ellipse sera\ndessinée sur la carte.</P>\n<P ALIGN=LEFT STYLE=\"text-indent: 0cm; margin-bottom: 0cm\"><I>Remarque\n: la taille du stylo est prise en compte pour le contour de\nl'ellipse.</I></P>\n<H2 CLASS=\"western\">Tracer un rectangle</H2>\n<P>Cette option permet de dessiner un rectangle. Dès que le clic\ngauche de la souris est enclenché sur l'environnement, l'emplacement\ndu curseur sera choisi comme un premier sommet du rectangle. Ensuite,\nsans relâcher le bouton gauche de la souris, en bougeant le curseur\nl'utilisateur va définir la taille du rectangle. Une première\napproche du rectangle qui sera dessiné est faite avec des\npointillés. Lorsque le bouton gauche sera relâché, le rectangle\nsera dessiné sur la carte.</P>\n<P ALIGN=LEFT STYLE=\"text-indent: 0cm; margin-bottom: 0cm\"><I>Remarque\n: la taille du stylo est prise en compte pour le contour du\nrectangle.</I></P>\n<H2 CLASS=\"western\">Tracer une ligne</H2>\n<P>Cette option permet de dessiner une ligne. Dès que le clic gauche\nde la souris est enclenché sur l'environnement, l'emplacement du\ncurseur sera choisi comme un premier sommet de la ligne. Ensuite,\nsans relâcher le bouton gauche de la souris, en bougeant le curseur\nl'utilisateur va définir l'autre sommet de la ligne. Une première\napproche de la ligne qui sera dessinée est faite avec des\npointillés. Lorsque le bouton gauche sera relâché, la ligne sera\ndessinée sur la carte.</P>\n<P ALIGN=LEFT STYLE=\"text-indent: 0cm; margin-bottom: 0cm\"><I>Remarque\n: la taille du stylo est prise en compte pour la ligne.</I></P>\n<H2 CLASS=\"western\"> Effacer avec le curseur</H2>\n<P>Cette option permet d'effacer une zone de l'environnement. Cette\nzone est représentée par un carré  et définie en fonction de la\ntaille du stylo. Un carré en pointillés sous le curseur indiquera\nla zone dans laquelle le contenu de la carte sera effacé. Lorsque\nl'utilisateur clique sur le bouton gauche de la souris, la zone\nsituée dans le carré en pointillés sera effacée.</P>\n<P ALIGN=LEFT STYLE=\"text-indent: 0cm; margin-bottom: 0cm\"><I>Remarque\n: dans une zone noire, les pointillés ne pourront pas être\nvisibles.</I></P>\n<H2 CLASS=\"western\"> Zoom arrière</H2>\n<P>Cette option permet de faire un zoom arrière de 50% sur\nl'environnement.</P>\n<H2 CLASS=\"western\"> Rétablir l'échelle</H2>\n<P>Cette option permet de mettre le zoom à 100% c'est à dire à\nl'échelle réelle de la carte.</P>\n<H2 CLASS=\"western\"> Zoom avant</H2>\n<P>Cette option permet de faire un zoom avant de 50% sur\nl'environnement.</P>\n<H2 CLASS=\"western\"> Taille du zoom</H2>\n<P>Cette «&nbsp;spinbox&nbsp;» (zone de sélection numérique)\npermet à l'utilisateur de modifier la taille du zoom sur\nl'environnement. Plus la valeur sera petite, plus le zoom sera\nreculé.</P>\n<H2 CLASS=\"western\"> Remplir les prochaines formes</H2>\n<P>Cette option permet de déterminer si l'ellipse ou le rectangle\nque l'utilisateur va dessiner sera rempli ou non.</P>\n<H2 CLASS=\"western\"> Placer le point de départ</H2>\n<P>Cette option permet à l'utilisateur de placer le point de départ\ndu robot sur l'environnement. Il lui suffira ensuite de cliquer sur\nle bouton gauche de la souris à l'emplacement choisi dans\nl'environnement pour définir la position du point de départ.</P>\n<H2 CLASS=\"western\">Placer le point d'arrivée</H2>\n<P>Cette option permet à l'utilisateur de placer le point d'arrivée\ndu robot à atteindre sur l'environnement. Il lui suffira ensuite de\ncliquer sur le bouton gauche de la souris à l'emplacement choisi\ndans l'environnement pour définir la position du point d'arrivée.</P>\n<H1 CLASS=\"western\">Options de couleur</H1>\n<H2 CLASS=\"western\">Ajouter une nouvelle couleur</H2>\n<P>Cette option permet d'ajouter une couleur de dessin. Lorsque\nl'utilisateur enclenchera cette option, une nouvelle fenêtre\napparaîtra pour lui demander de choisir une couleur.</P>\n<P ALIGN=LEFT STYLE=\"text-indent: 0cm; margin-bottom: 0cm; page-break-before: auto\"></P>\n<P>Lorsque l'utilisateur confirmera son choix (appui sur le bouton\nOK), une nouvelle boîte de couleur apparaîtra.</P>\n<P ALIGN=LEFT STYLE=\"text-indent: 0cm; margin-bottom: 0cm; page-break-before: auto\"></P>\n<H2 CLASS=\"western\"> Supprimer toutes les couleurs</H2>\n<P>Cette option permet de supprimer toutes les couleurs définies par\nl'utilisateur. Une confirmation lui sera demandée avant d'effectuer\nla suppression.</P>\n<P ALIGN=LEFT STYLE=\"text-indent: 0cm; margin-bottom: 0cm; page-break-before: auto\"></P>\n<H2 CLASS=\"western\">Choix de la couleur</H2>\n<P>Lorsque l'utilisateur cliquera sur cette case de couleur, le stylo\nprendra cette couleur pour les prochaines formes dessinées.</P>\n<H2 CLASS=\"western\">Passante</H2>\n<P>Cette option détermine le comportement que le robot aura sur les\nformes de cette couleur dans l'environnement. Si l'option est cochée,\nle robot pourra franchir cette couleur, sinon il ne pourra pas.</P>\n<H2 CLASS=\"western\">Valeur d'obstacle de la couleur</H2>\n<P>Cette spinbox (zone de sélection numérique) permet de définir\nsi le robot sera accéléré (inférieure à 100%), ralenti\n(supérieure à 100%) ou sans modification (égale à 100%). Cette\nvaleur pourra aussi être définie avec la barre de sélection en\nchangeant la position du curseur sur la barre.</P>\n<H2 CLASS=\"western\">Modifier la couleur</H2>\n<P>Cette option permet à l'utilisateur de modifier la couleur\nchoisie en lui demandant de la choisir à nouveau dans la nouvelle\nfenêtre.</P>\n<P ALIGN=LEFT STYLE=\"text-indent: 0cm; margin-bottom: 0cm\"><I>Remarque\n: les formes dessinées avec la couleur précédente ne changeront\npas de couleur.</I></P>\n<H2 CLASS=\"western\">Suppression de la couleur</H2>\n<P>Cette option permet de supprimer la couleur en question.</P>\n<P ALIGN=LEFT STYLE=\"text-indent: 0cm; margin-bottom: 0cm\"><I>Remarque\n: les formes dessinées avec la couleur ne seront pas effacées.</I></P>\n<H1 CLASS=\"western\">Paramètres attribuables du robot</H1>\n<H2 CLASS=\"western\">Taille du robot</H2>\n<P>Cette spinbox (zone de sélection numérique) permet de définir\nla taille du robot en pixel. Cela aura un impact sur le chemin à\nemprunter si le robot est trop grand pour passer par de petits\nchemins. Cette valeur pourra aussi être définie avec la barre de\nsélection en changeant la position du curseur sur la barre.</P>\n<H2 CLASS=\"western\">Angle initial du robot</H2>\n<P>Cette spinbox (zone de sélection numérique) permet de définir\nl'angle initial du robot en degré. Cela aura un impact sur le chemin\nà emprunter dès le départ. Cette valeur pourra aussi être définie\navec  la <FONT COLOR=\"#800000\">???????????????? </FONT><FONT COLOR=\"#000000\">en</FONT>\nla tournant.</P>\n<H2 CLASS=\"western\">Coût de demi-tour</H2>\n<P>Cette spinbox (zone de sélection numérique) permet de définir\nle coût que le robot prendra pour faire un tour sur lui-même. Cela\naura un impact sur le chemin à emprunter si trop de virages sont\nnécessaires. Cette valeur pourra aussi être définie avec la barre\nde sélection en changeant la position du curseur sur la barre.</P>\n<P ALIGN=LEFT STYLE=\"text-indent: 0cm; margin-bottom: 0cm; page-break-before: auto\">\n<BR>\n</P>\n<P>Barre d'outils : faire pour chaque option encore ou alors les\nincorporer dans chaque option concernée vue précédemment ?</P>\n</BODY>\n</HTML>"),scrollHelp);
			label->setMaximumWidth(512);
			label->setWordWrap(true);
			scrollHelp->setWidget(label);
			helpWindow->setCentralWidget(scrollHelp);
			helpWindow->setWindowIcon(QIcon(":/images/dirige.png"));
			
			connect(actionHelp_,SIGNAL(triggered()),helpWindow,SLOT(show()));
			
			actionAboutDirige_ = new QAction(QIcon(":/images/dirige.svg"),QString::fromUtf8("À propos de DiRIGe"),menuHelp_);
			actionAboutDirige_->setIconVisibleInMenu(true);
			actionAboutDirige_->setObjectName(QString::fromUtf8("actionAboutDirige_"));
			
			
			
			menuHelp_->addAction(actionHelp_);
			menuHelp_->addAction(actionAboutDirige_);
		
		this->addMenu(menuFile_);
		this->addMenu(menuEdit_);
		this->addMenu(menuView_);
		this->addMenu(menuOption_);
		this->addMenu(menuHelp_);
		
		
		debugsub(EXIT_SUCCESS);
	}
	
//}

//Operators
//{
	
	
	
//}

//Display
//{
	
	
	
//}
