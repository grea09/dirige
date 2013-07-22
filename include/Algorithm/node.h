/** Titre
 *      @project DiRIGe
 *      @class Node
 *      @description : Une node représente un noeud dans un gaphe. Un graphe est composé de nodes.
 *	@author Alex-Mehdi ZAHID
 */

#ifndef NODE_H
#define NODE_H

#include <QPoint>
#include <cstdlib>
#include "cost.h"
namespace Algorithm
{
	class Cost;
	
	//Comment : permet de donne un état à la node lors de l'exécution de Dijkstra
	//Par défaut, une node est UNLABELED. Lorsque la node à été parcourru, elle prend l'état
	//LABELED, et lorsque l'on liste le fils de la node, elle est SCANNED.
	enum State
	{
		LABELED, UNLABELED, SCANNED
	};
	
	
	class Node
	{
		friend class Dijkstra;
		friend class MinimalCostFunction;
		friend class BasicDirectionCostFunction;
		friend class FibonacciHeap;
	
		public :
		//Builder
			Node();
			Node( int x, int y );
			Node( QPoint point );
	
		//Destroyer
		~Node();
	
		//Operator
		double operator()( int i, int j, double crossedCostEndNode );
	
		//Method
			//Accessor
			int getCoordX() const;
			int getCoordY() const;
			Node* getAntecedent() const;                
			Node* getLeftMostSibling();
			Node* getRightMostSibling();
	
			//Mutator
			void setNodeCost( Cost* cost);
	
			//Processing
			//Comment : ces fonctions permettent de gérer le tas de Fibonacci.
			bool addChild(Node * node);
			bool addSibling(Node * node);
			bool remove();
	
		private :
		//Attribute
			//Inconstant
			int coordX_;
			int coordY_;
			//Comment : indique l'état du noeud.
			State state_;
			//Comment : foncteur permettant de calculer le coût associé au déplacement.
			Cost* cost_;
			//Comment : on stock le poids associé, pour augmenter la rapidité de Dijkstra. Le poids représent la clé
			//de la node dans le tas de Fibonacci.
			double weight_;
			//Comment : on stock l'angle par lequel on a accédé à la node pour augmenter la rapidité de Dijkstra.
			double angle_;
			//Comment : donne le noeud antécendant pour reconstuire le chemin..
			Node* antecedent_;
	
			//Variable propre à l'utilisation du tas de Fibonacci.
			//Comment : indique la node parent.
			Node* parent_;
			//Comment : indique la node soeur gauche.
			Node* leftSibling_;
			//Comment : indique la node soeur droite.
			Node* rightSibling_;
			//Comment : indique un pointeur sur une liste chainé de node fille.
			Node* children_;
			//Comment : indique le nombre de fille.
			int rank_;
	};
}

#endif // NODE_H
