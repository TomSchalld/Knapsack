//
// Created by tscha on 30/10/2016.
//

#include "TreeNode.h"

int TreeNode::getTotalCost() const {
    return totalCost;
}

void TreeNode::setTotalCost(int totalCost) {
    TreeNode::totalCost = totalCost;
}

int TreeNode::getCost() const {
    return cost;
}

void TreeNode::setCost(int cost) {
    TreeNode::cost = cost;
}

int TreeNode::getWeight() const {
    return weight;
}

void TreeNode::setWeight(int weight) {
    TreeNode::weight = weight;
}

double TreeNode::getCostWeightRatio() const {
    return costWeightRatio;
}

void TreeNode::setCostWeightRatio(double costWeightRatio) {
    TreeNode::costWeightRatio = costWeightRatio;
}

bool TreeNode::isTaken() const {
    return taken;
}

void TreeNode::setTaken(bool taken) {
    TreeNode::taken = taken;
}

int TreeNode::getTreeLevel() const {
    return treeLevel;
}

void TreeNode::setTreeLevel(int treeLevel) {
    TreeNode::treeLevel = treeLevel;
}


TreeNode *TreeNode::getLeftChild() const {
    return leftChild;
}

void TreeNode::setLeftChild(TreeNode *leftChild) {
    TreeNode::leftChild = leftChild;
}

TreeNode *TreeNode::getRightChild() const {
    return rightChild;
}

void TreeNode::setRightChild(TreeNode *rightChild) {
    TreeNode::rightChild = rightChild;
}

TreeNode::TreeNode() {
    this->Init();
}

TreeNode::TreeNode(int totalCost, int cost, int weight, double costWeightRatio, bool taken, int treeLevel,
                   TreeNode *leftChild, TreeNode *rightChild) : totalCost(totalCost), cost(cost), weight(weight),
                                                                costWeightRatio(costWeightRatio), taken(taken),
                                                                treeLevel(treeLevel), leftChild(leftChild),
                                                                rightChild(rightChild) {}

void TreeNode::Init() {
    this->totalCost = 0;
    this->cost = 0;
    this->weight = 0;
    this->costWeightRatio = 0.0;
    this->taken = false;
    this->treeLevel = -1;
    this->leftChild = nullptr;
    this->rightChild = nullptr;
}

TreeNode::~TreeNode() {
    this->Init();
}

bool TreeNode::hasLeaves() const {
    return leaves;
}

void TreeNode::setLeaves(bool leaves) {
    TreeNode::leaves = leaves;
}
