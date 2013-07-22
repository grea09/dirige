/** Titre
 *      @project DiRIGe
 *      @class FibonacciHeap
 *      @description : Cette classe représente un tas de Fibonacci. Dijkstra travaillera sur ce tas
 *      qui sera construit à partir de du vector de vector de Node
 *	@author Alex-Mehdi ZAHID
 */

#ifndef FIBONACCIHEAP_H
#define FIBONACCIHEAP_H

#include "node.h"

namespace Algorithm
{
	class FibonacciHeap
	{
	    public :
	
	        //Builder
	        FibonacciHeap();
	        FibonacciHeap(Node *root);
	
	        //Destroyer
	        ~FibonacciHeap();
	
	        //Methode
	        bool isEmpty();
	        bool insertVertex(Node * node);
	        void decreaseWeight(double delta, Node* vertex);
	        Node* findMin();
	        Node* deleteMin();
	
	    private :
	        //Attribute
	            //Inconstant
	            Node* rootListByRank_[1000];// width*height au max mais 1000 c'est largement suffisant.
	            Node* minRoot_;
	
	        //Methode
	        bool link(Node* root);
	};
}
#endif // FIBONACCIHEAP_H
