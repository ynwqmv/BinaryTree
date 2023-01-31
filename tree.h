#ifndef TREE_H
#define TREE_H

#include <fstream>
#include "C:/Users/qumar/OneDrive/Desktop/json-develop (1)/json-develop/single_include/nlohmann/json.hpp"

#include <QMessageBox>
using json = nlohmann::json;
#include <QDebug>
class Tree
{
public:
    int data;
    Tree* left;
    Tree* right;
    Tree(int value) : data(value), left(nullptr), right(nullptr){}
};

class createTree
{
public:
    createTree();
    ~createTree();

    void insert(int data);

    void clear();

    void print();

    void addJson();

private:
    void insertHelper(Tree *&node, int data);
    void addJsonHelper(json& object, Tree* node);

    void clearHelper(Tree*& node);
    void printHelper(Tree* node);


    Tree* mRoot;
};

#endif // TREE_H
