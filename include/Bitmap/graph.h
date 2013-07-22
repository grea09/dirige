/** Titre
 *      @project DiRIGe
 *      @class Graph
 *      @description : Classe faisant la liason entre une image au format BMP avec le module de Dikstra
 *      Elle convertie une QImage en un tableau de nodes et inversement.
 *	@author Alex-Mehdi ZAHID
 */

#ifndef GRAPH_H
#define GRAPH_H

#include <cstdlib>
#include <QImage>
#include <vector>
#include <algorithm>

#include "node.h"
#include "pointexception.h"
#include "nopathexception.h"

namespace Bitmap
{
	class Graph
	{
		public :
		//Builder
			Graph();
			Graph(QImage* map, QPoint startNode, QPoint endNode);

		//Destroyer
			~Graph();

		//Method
			//Accesseur
			QImage* getMap() const;
			int getMapWitdh() const;
			int getMapHeight() const;
			std::vector< std::vector<Algorithm::Node*> > getGraph();
			Algorithm::Node* getStartNode() const;
			Algorithm::Node* getEndNode() const;

			//Mutateur
			void setMap(QImage* map);
			void setGraph(std::vector< std::vector<Algorithm::Node*> > graph);

			//Processing
			//Comment : cette fonction permet d'attribuer à chaque node une fonction de cout.
			void setNodeCostFunction(std::vector<ColorCost> palette, int costFunctionType);
			//Comment : cette fonction permet de mettre à jour l'image reçu.
			//On tracera dans cette image le chemin trouvé par Dijkstra à partir d'un tableau de node.
			//~ void drawPath();
			//Comment : cette fonction va rechercher points start et end.
			//~ void findKeyPoint();

		private :
		//Attribute
			//Inconstant
			//Comment : pointeur vers une image au format PNG
			QImage* map_;
			//Comment : on stock les dimensions de la map
			int width_;
			int height_;
			//Comment : tableau de node construit à partir de l'image BMP
			std::vector< std::vector<Algorithm::Node*> > graph_;

			//Comment : node de départ
			Algorithm::Node* startNode_;
			//Comment : node d'arrivvé
			Algorithm::Node* endNode_;
	};
}

#endif // GRAPH_H



