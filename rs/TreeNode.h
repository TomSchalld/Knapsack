//
// Created by tscha on 30/10/2016.
//

#ifndef KNAPSACK_TREENODE_H
#define KNAPSACK_TREENODE_H


#include <ostream>

class TreeNode {

public:
    int getTotalCost() const;

    void setTotalCost(int totalCost);

    int getCost() const;

    void setCost(int cost);

    int getWeight() const;

    void setWeight(int weight);

    double getCostWeightRatio() const;

    void setCostWeightRatio(double costWeightRatio);

    bool isTaken() const;

    void setTaken(bool taken);

    int getTreeLevel() const;

    void setTreeLevel(int treeLevel);

    TreeNode *getLeftChild() const;

    void setLeftChild(TreeNode *leftChild);

    TreeNode *getRightChild() const;

    void setRightChild(TreeNode *rightChild);

    bool hasLeaves() const;

    void setLeaves(bool leaves);

    TreeNode();

    virtual ~TreeNode();

    bool operator<(const TreeNode &rhs) const;

    bool operator>(const TreeNode &rhs) const;

    bool operator<=(const TreeNode &rhs) const;

    bool operator>=(const TreeNode &rhs) const;

    static bool compareRatio( TreeNode *a,  TreeNode *b);
    friend std::ostream &operator<<(std::ostream &os, const TreeNode &node);

private:
    int totalCost;
    int cost;
    int weight;
    double costWeightRatio;
    bool taken;
    bool leaves;
    int treeLevel;
    TreeNode * leftChild;
    TreeNode * rightChild;
    TreeNode(int totalCost, int cost, int weight, double costWeightRatio, bool taken, int treeLevel,
             TreeNode *leftChild, TreeNode *rightChild);
    void Init();
};


#endif //KNAPSACK_TREENODE_H
