#include "tree.h"

createTree::createTree() : mRoot(nullptr){}


createTree::~createTree()
{
    clear();
}

//! insert data in tree using recursion
void createTree::insert(int data)
{
    insertHelper(mRoot,data);
}

//! memory deallocation using recursion
void createTree::clear()
{
    clearHelper(mRoot);
}

//! prints data to console
void createTree::print()
{
    printHelper(mRoot);
}

//! exports tree in json format file
void createTree::addJson()
{
    json jsonData;
    addJsonHelper(jsonData,mRoot);
    //![PATH]
    std::ofstream outFile("C:/Users/qumar/OneDrive/Desktop/tree_data.json");
    if (outFile.is_open())
    {
        outFile << jsonData.dump(4);
    }else
    {
        qDebug() << "Couldn't open file!";
    }
    outFile.close();
}



void createTree::insertHelper(Tree *&node, int data)
{
    if (node == nullptr) //! if node is nullptr, create new node with data
    {
        node = new Tree(data);
        return;
    }

    if (data < node->data) //! if data less than node data, insert data in left using recursion
    {
        insertHelper(node->left, data);
    }else //! else in right using recursion
    {
        insertHelper(node->right, data);
    }
}

//! helper for json export
void createTree::addJsonHelper(json& object, Tree* node)
{
    if(node == nullptr)
    {
        return;
    }

    json nodeData;
    nodeData["data"] = node->data;
    addJsonHelper(nodeData["left"], node->left);
    addJsonHelper(nodeData["right"], node->right);

    object.push_back(nodeData);

}

void createTree::clearHelper(Tree*& node)
{
    if (!node)
    {
        return;
    }

    clearHelper(node->left);
    clearHelper(node->right);
    delete node;

    node = nullptr;
}

void createTree::printHelper(Tree* node)
{
    if(!node)
    {
        return;
    }

    printHelper(node->left);
    qDebug() << node->data << " ";
    printHelper(node->right);
}
