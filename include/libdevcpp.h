/** Titre
 *      @project Design Pattern Composite - TP04 C++
 *      @class libdevcpp
 *      @description Boîte à outils
 *      
 *      @author Copyright 2009 Antoine GREA <grea09@gmail.com>
 *      
 *      This program is free software; you can redistribute it and/or modify
 *      it under the terms of the GNU General Public License as published by
 *      the Free Software Foundation; either version 2 of the License, or
 *      (at your option) any later version.
 *      
 *      This program is distributed in the hope that it will be useful,
 *      but WITHOUT ANY WARRANTY; without even the implied warranty of
 *      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *      GNU General Public License for more details.
 *      
 *      You should have received a copy of the GNU General Public License
 *      along with this program; if not, write to the Free Software
 *      Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 *      MA 02110-1301, USA.
 */

#ifndef _INCLUDED_LIBDEVC_H
#define _INCLUDED_LIBDEVC_H

//#define DEBUG
//#define DEBUG_SUB

//	Include librairies système
///////////////////////////////////////////////////////////////////////{
//*/
#include <iostream> // Revoyez le C++ si vous savez pas c'est quoi
#include <string> // Obligatoire pour pouvoir utiliser les objets string
#include <vector> // Y a pas plus fort !
#include <algorithm> // pour des algos
//*/

// Qt

#include <QtGui/QMainWindow>
#include <QtGui/QApplication>

// Librairie C (eh ouai on se passe plus de ses habitudes)
/*
#include <stdlib.h> // Pour time et EXIT
#include <string.h> // Pour asprintf
#include <assert.h> // Pour assert
#include <time.h> // Pour la date
#include <signal.h> // Une utilité de la prog système
*/

#ifndef EXIT_SUCCESS
#define EXIT_SUCCESS 0
#endif

#ifndef EXIT_FAILURE
#define EXIT_FAILURE 1
#endif

#define ENTER -1

using namespace std;
//template <typename Type>

//#include "Date.h" // Une classe Date perso

///////////////////////////////////////////////////////////////////////}


//	Foctions utiles
///////////////////////////////////////////////////////////////////////{

#define max(a,b) ((a>b)?(a):(b))

#define min(a,b) ((a<b)?(a):(b))

#define borne(x,inf,sup) max((inf),min((sup),(x)))

#define usage(prog,expr)					\
	cout << "usage:" << prog << expr << endl

#define fori(i,length) for(int i(0); i<length;i++)

#define fort(increment, somme, condition_de_fin, inc_somme)		\
				for((increment)=((somme)=0);(condition_de_fin);(somme)+=(inc_somme)+0*(increment)++)


///////////////////////////////////////////////////////////////////////}


//	Définitions des constantes
///////////////////////////////////////////////////////////////////////{

// Échapement VT10 pour le style

#define RESET "\033[0m"
#define HIGHT "\033[1m"
#define ERROR_STYLE "\033[1;31m"
#define SUCCESS_STYLE "\033[1;32m"
#define CLS "\033[2J"
#define UNDER "\033[4m"

///////////////////////////////////////////////////////////////////////}


//	Définition des lignes de traces (modifiées)
///////////////////////////////////////////////////////////////////////{


/* extention de debug.h par Antoine GREA*/

# ifdef DEBUG
#define debug(expr) 								\
	cerr << HIGHT << __FILE__ << ", " << __FUNCTION__ << ":" << __LINE__ << " " << __STRING(expr) << RESET << endl

#define debugcode(expr) expr

#define debugV(expr) 								\
	cerr << HIGHT << __FILE__ << ", " << __FUNCTION__ << ":" << __LINE__ << " " << __STRING(expr) << " = " << (expr) << RESET << endl

#ifdef DEBUG_SUB

#  define debugsub(sig) 								\
	cerr << (((sig))?(((sig)==ENTER)?"":ERROR_STYLE):SUCCESS_STYLE) \
	 << __FILE__\
	 << ":" \
	 << __LINE__ \
	 << (((sig)==ENTER)?" -> ":" <- ") \
	 << __FUNCTION__ \
	 << (((sig))?(((sig)==ENTER)?"...":"...[fail]"):"...[done]") \
	 << RESET \
	 << endl
#else
#define debugsub(sig) ((void) 0)
#endif

#  else
/* pas de debugage */
#define debug(expr) ((void) 0)
#define debugcode(expr) ((void) 0)
#define debugV(expr) ((void) 0)
#define debugsub(sig) ((void) 0)
#endif



///////////////////////////////////////////////////////////////////////}



#endif
