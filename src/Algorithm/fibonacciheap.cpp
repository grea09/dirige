/** Titre
 *      @project DiRIGe
 *      @class FibonacciHeap
 *      @description : Cette classe représente un tas de Fibonacci. Dijkstra travaillera sur ce tas
 *      qui sera construit à partir de du vector de vector de Node
 *	@author Alex-Mehdi ZAHID
 */
#include <iostream>
#include "fibonacciheap.h"

using namespace Algorithm;

//Builder
//{
FibonacciHeap::FibonacciHeap()
{
        minRoot_ = NULL;
}

FibonacciHeap::FibonacciHeap(Node *root)
{
        this->minRoot_ = root;
        minRoot_->parent_ = NULL;
        minRoot_->children_ = NULL;
        minRoot_->leftSibling_ = NULL;
        minRoot_->rightSibling_ = NULL;
        minRoot_->rank_ = 0;
}
//}

//Destroyer
//{
FibonacciHeap::~FibonacciHeap()
{
        delete[] rootListByRank_;
}
//{

//Processing
//{
bool FibonacciHeap::isEmpty()
{
        return (minRoot_ == NULL);
}
bool FibonacciHeap::insertVertex(Node * node)
{
        if(node == NULL)
                return false;

        if(minRoot_ == NULL)
                minRoot_ = node;
        else
        {
                minRoot_->addSibling(node);
                if(minRoot_->weight_ > node->weight_)
                        minRoot_ = node;
        }

        return true;
}

Node* FibonacciHeap::findMin()
{
        return minRoot_;
}

Node* FibonacciHeap::deleteMin()
{
        Node *temp = minRoot_->children_->getLeftMostSibling();
        Node *nextTemp = NULL;

        // Adding children_ to root list
        while(temp != NULL)
        {
                nextTemp = temp->rightSibling_; // Save next Sibling
                temp->remove();
                minRoot_->addSibling(temp);
                temp = nextTemp;
        }

        // Select the left-most sibling of minRoot_
        temp = minRoot_->getLeftMostSibling();

        // Remove minRoot_ and set it to any sibling, if there exists one
        if(temp == minRoot_)
        {
                if(minRoot_->rightSibling_)
                        temp = minRoot_->rightSibling_;
                else
                {
                        // Heap is obviously empty
                        Node* out = minRoot_;
                        minRoot_->remove();
                        minRoot_ = NULL;
                        return out;
                }
        }
        Node* out = minRoot_;

        minRoot_->remove();

        minRoot_ = temp;

        // Initialize list of roots
        for(int i=0; i<100; i++)
                rootListByRank_[i] = NULL;

        while(temp)
        {
                // Check if weight_ of current vertex is smaller than the weight_ of minRoot_
                if(temp->weight_ < minRoot_->weight_)
                {
                        minRoot_ = temp;
                }

                nextTemp = temp->rightSibling_;
                link(temp);
                temp = nextTemp;

        }
        return out;
}

bool FibonacciHeap::link(Node* root)
{
        // Insert Vertex into root list
        if(rootListByRank_[root->rank_] == NULL)
        {
                rootListByRank_[root->rank_] = root;
                return false;
        }
        else
        {
                // Link the two roots
                Node* linkVertex = rootListByRank_[root->rank_];
                rootListByRank_[root->rank_] = NULL;

                if(root->weight_ < linkVertex->weight_ || root == minRoot_)
                {
                        linkVertex->remove();
                        root->addChild(linkVertex);
                        if(rootListByRank_[root->rank_] != NULL)
                                link(root);
                        else
                                rootListByRank_[root->rank_] = root;
                }
                else
                {
                        root->remove();
                        linkVertex->addChild(root);
                        if(rootListByRank_[linkVertex->rank_] != NULL)
                                link(linkVertex);
                        else
                                rootListByRank_[linkVertex->rank_] = linkVertex;
                }
                return true;
        }
}


void FibonacciHeap::decreaseWeight(double delta, Node* vertex)
{
        vertex->weight_ = delta;
        if(vertex->parent_ != NULL) // The vertex has a parent__
        {
                // Remove vertex and add to root list
                vertex->remove();
                minRoot_->addSibling(vertex);
        }
        // Check if weight_ is smaller than the weight_ of minRoot_
        if(vertex->weight_ < minRoot_->weight_)
                minRoot_ = vertex;
}
//}

