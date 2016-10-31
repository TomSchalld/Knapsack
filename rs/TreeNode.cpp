//
// Created by tscha on 30/10/2016.
//

#include "TreeNode.h"


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


TreeNode::TreeNode() {
    this->Init();
}



void TreeNode::Init() {
    this->totalCostLeft = 0;
    this->totalCostRight = 0;
    this->cost = 0;
    this->weight = 0;
    this->costWeightRatio = 0.0;
    this->taken = false;
    this->leaves = false;
    this->treeLevel = -1;
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

bool TreeNode::operator<(const TreeNode &rhs) const {
    return costWeightRatio < rhs.costWeightRatio;
}

bool TreeNode::operator>(const TreeNode &rhs) const {
    return rhs < *this;
}

bool TreeNode::operator<=(const TreeNode &rhs) const {
    return !(rhs < *this);
}

bool TreeNode::operator>=(const TreeNode &rhs) const {
    return !(*this < rhs);
}

std::ostream &operator<<(std::ostream &os, const TreeNode &node) {
    os << "totalCostLeft: " << node.totalCostLeft<< "totalCostRight: " << node.totalCostRight << " cost: " << node.cost << " weight: " << node.weight
       << " costWeightRatio: " << node.costWeightRatio << " taken: " << node.taken << " leaves: " << node.leaves
       << " treeLevel: " << node.treeLevel;
    return os;
}

bool TreeNode::compareRatio(TreeNode *a, TreeNode *b) {
    return a->getCostWeightRatio() > b->getCostWeightRatio();
}

int TreeNode::getTotalCostLeft() const {
    return totalCostLeft;
}

void TreeNode::setTotalCostLeft(int totalCostLeft) {
    TreeNode::totalCostLeft = totalCostLeft;
}

int TreeNode::getTotalCostRight() const {
    return totalCostRight;
}

void TreeNode::setTotalCostRight(int totalCostRight) {
    TreeNode::totalCostRight = totalCostRight;
}

TreeNode *TreeNode::getChildNode() const {
    return childNode;
}

void TreeNode::setChildNode(TreeNode *childNode) {
    TreeNode::childNode = childNode;
    if(this->childNode!= nullptr){
        this->setLeaves(true);
    }
}
