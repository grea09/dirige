/** Title
 *      @project DiRIGe
 *      @class Node
 *      @description : Une node représente un noeud dans un gaphe. Un graphe est composé de nodes.
 *	@author Alex-Mehdi ZAHID
 */

#include <iostream>
#include "node.h"
#include "minimalcostfunction.h"
#include "libdevcpp.h"

using namespace Algorithm;

//Builder
//{
    Node::Node() : state_(UNLABELED), cost_(new MinimalCostFunction()), weight_(0), angle_(0), antecedent_(NULL)
    {          
        coordX_ = 0;
        coordY_ = 0;
		
        parent_ = NULL;
        leftSibling_ = NULL;
        rightSibling_ = NULL;
        children_ = NULL;
        rank_ = 0;

    }
    
    Node::Node( int x, int y ) : state_(UNLABELED), cost_(NULL), weight_(0), angle_(0),antecedent_(NULL)
    {
        coordX_ = x;
        coordY_ = y;

        parent_ = NULL;
        leftSibling_ = NULL;
        rightSibling_ = NULL;
        children_ = NULL;
        rank_ = 0;
    }
    
    Node::Node( QPoint point ) : state_(UNLABELED), cost_(NULL), weight_(0), angle_(0),antecedent_(NULL)
    {
        coordX_ = point.x();
        coordY_ = point.y();

        parent_ = NULL;
        leftSibling_ = NULL;
        rightSibling_ = NULL;
        children_ = NULL;
        rank_ = 0;
    }
//}

//Destroyer
//{
    Node::~Node()
    {
        if( cost_ != NULL )
            delete cost_;
            //PENSER à DETRUIRE DES TRUCS SI NEW
    }
//{

//Operator
//{
    double Node::operator()( int i, int j, double crossedCostEndNode)
    {
        weight_ = this->cost_->calculateCost(i,j,crossedCostEndNode);//On stocke le poid pour aller plus vite dans le calcul du cout minimum.
        return weight_;
    }
//}

//Accessor
//{
    int Node::getCoordX() const
    {
        return coordX_;
    }
    int Node::getCoordY() const
    {
        return coordY_;
    }
    Node* Node::getAntecedent() const
    {
        return antecedent_;
    }
    Node* Node::getLeftMostSibling()
    {
        if(this == NULL)
                return NULL;

        Node* temp = this;
        while(temp->leftSibling_){
                temp = temp->leftSibling_;
        }
        return temp;
    }
    Node* Node::getRightMostSibling()
    {
        if(this == NULL)
                return NULL;

        Node* temp = this;
        while(temp->rightSibling_)
                temp = temp->rightSibling_;
        return temp;
    }
//}

//Mutator
//{
    void Node::setNodeCost( Cost* cost )
    {
        cost_ = cost;
    }
//}

//Processing
//{
bool Node::addChild(Node *node)
{
        if(children_ != NULL)
                children_->addSibling(node);
        else
        {
                children_ = node;
                node->parent_ = this;
                rank_ = 1;
        }

        return true;
}

bool Node::addSibling(Node *node)
{
        Node* temp = getRightMostSibling();
        if(temp == NULL)
                return false;

        temp->rightSibling_ = node;
        node->leftSibling_ = temp;
        node->parent_ = this->parent_;
        node->rightSibling_ = NULL;

        if(parent_)
                parent_->rank_++;

        return true;
}

bool Node::remove()
{
        if(parent_)
        {
                parent_->rank_--;
                if(leftSibling_)
                        parent_->children_ = leftSibling_;
                else if(rightSibling_)
                        parent_->children_ = rightSibling_;
                else
                        parent_->children_ = NULL;
        }

        if(leftSibling_)
                leftSibling_->rightSibling_ = rightSibling_;
        if(rightSibling_)
                rightSibling_->leftSibling_ = leftSibling_;

        leftSibling_ = NULL;
        rightSibling_ = NULL;
        parent_ = NULL;

        return true;
}
//}
