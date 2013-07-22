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


#include "libdevcpp.h"
#include "mainwindow.h"
#include <QTranslator>
#include <QLocale>
#include <QLibraryInfo>

int main (int argn, char * argv[])
{
    debug("Jouez !");
    //Début

    //Arguments et usage
    ////{

        if (argn != 1)
        {
            usage(argv[0],"");
            return EXIT_FAILURE;
        }

    ////}

    //Initialisation
    ////{

        QApplication a(argn, argv);
        QString locale = QLocale::system().name();
	    QTranslator translator;
	    translator.load(QString("qt_") + locale, QLibraryInfo::location(QLibraryInfo::TranslationsPath));
	    a.installTranslator(&translator);
        
        Ihm::MainWindow w;

    ////}

    //Corp
    ////{

        w.show();

    ////}

    //Destructeur
    ////{



    ////}

    //FIN
    //debug(" => MAIN...[FIN DU MACH]");
    //debug("*Exit\n  ");
    return a.exec();
}
