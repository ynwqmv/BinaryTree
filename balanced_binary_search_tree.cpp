#include <iostream>
#include <algorithm>
#include <vector>
#include <nlohmann/json.hpp>
#include <fstream>

using namespace std;
using json = nlohmann::json;



struct Node
{
	int data;    // data for tree
	Node* left;  // left child 
	Node* right; // right child
 
};


Node* addNode(Node* node, int data)
{
	if (node == nullptr) 
	{ 
		Node* newNode = new Node();
		newNode->data = data;
		newNode->left = nullptr;
		newNode->right = nullptr;
		return newNode;
	}

	if (data < node->data)
	{
 		node->left = addNode(node->left, data);
	}
	else if (data > node->data)
	{
     	node->right = addNode(node->right, data);
	}

	return node;
}

vector<int> treeElem;

// adding sorted data into binary tree
void pushData(Node* node)
{
	if (node == nullptr)
	{
		return; 
	}

	pushData(node->left);
	treeElem.push_back(node->data);
	pushData(node->right);
}



void freeTree(Node* node)
{
	if (node == nullptr)
	{
		return;
	}

	freeTree(node->left);
	freeTree(node->right);
	
	delete node;
	node = nullptr;
}

void print(Node* node)
{
	if (node == nullptr)
	{
		return;
	}

	print(node->left);
	cout << node->data << " ";
	print(node->right);
}

bool search(Node* node, int data)
{
	if (node == nullptr)	{ return false; }
	if (node->data == data) { return true; }
	

	else if (data <= node->data)
	{
		return search(node->left, data);
	}
	else
	{
		return search(node->right, data);
	}

}


 
void pushJson(Node* node, json& jsonData) {
	if (node == nullptr || jsonData == nullptr) {
		return;
	}
	 
	jsonData["data"] = node->data;
	if (node->left) {
		jsonData["left"] = json::object();
		pushJson(node->left, jsonData["left"]);
	}
	if (node->right) {
		jsonData["right"] = json::object();
		pushJson(node->right, jsonData["right"]);
	}
}


bool checkHeightBalance(Node* root, int* height) {
	// Check for emptiness
	int leftHeight = 0, rightHeight = 0;

	int l = 0, r = 0;

	if (root == NULL) {
		*height = 0;	
		return 1;
	}

	l = checkHeightBalance(root->left, &leftHeight);
	r = checkHeightBalance(root->right, &rightHeight);

	*height = (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;

	if (std::abs(leftHeight - rightHeight >= 2))
		return 0;

	else
		return l && r;
}

void file(json& jsonData, const char* path)
{
	if (jsonData == nullptr)
	{
		return;
	}
	ofstream out(path);
	if (out.is_open())
	{
		out << jsonData.dump();
		cout << "\nData was exported in output.json\n";
	}
	else
	{
		cout << "\nCouldn't open file\n";
		out.close();
	}
	
}

int main()
{
	int height = 0;
	json jsonData;
	 
	Node* root = nullptr;
	
	root = addNode(root, 28);
	root = addNode(root, 29);
	root = addNode(root, 30);
	root = addNode(root, 31);
	root = addNode(root, 32);
	root = addNode(root, 33);
	root = addNode(root, 34);
	 
	cout << endl;
	pushData(root);
	for (auto v : treeElem)
	{
		cout << v << " ";
	}
	cout << endl;
	 
	
	cout << search(root, 201);
	cout << endl;

	print(root);
	pushJson(root, jsonData);
	cout << endl;
	cout << jsonData.dump(4);
	cout << endl;

	 
	if (checkHeightBalance(root, &height))
		cout << "The tree is balanced";
	else
		cout << "The tree is not balanced";
	file(jsonData, "some_path_here");
	freeTree(root);
	return 0;
}

 
