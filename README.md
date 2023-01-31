# BinaryTree
Binary Tree implementations | C++
![1_CMGFtehu01ZEBgzHG71sMg](https://user-images.githubusercontent.com/112755279/215258560-4a11c8ef-76c0-4dc7-85db-8c920fb01ffd.png)
![image](https://user-images.githubusercontent.com/112755279/215840851-f715049a-f3ed-4479-b4f2-92024afe83c8.png)
![image](https://user-images.githubusercontent.com/112755279/215841044-1d09eae6-de0e-4091-846c-43dce8152e2e.png)

## Output
![image](https://user-images.githubusercontent.com/112755279/215841185-b71f66d5-610c-4dd3-b12e-faaae6f3fcf2.png)

## Create Node

```cpp
struct Node
{
	int data;    // data for tree
	Node* left;  // left child 
	Node* right; // right child
 
};
```

## Add Data
```cpp
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
```

## Deallocate Memory
```cpp
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
```
## Print Tree
```cpp
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
```

## Search Function Implementation
```cpp
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
```

## Check if tree is balanced
```cpp
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
```
## Export Tree in JSON
* using nlohmann/json - https://github.com/nlohmann/json
```cpp
void pushJson(Node* node, json& jsonData) {
	if (node == nullptr) {
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
```

## main()
```cpp
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
	freeTree(root);
	return 0;
}
```

# Output
 ![image](https://user-images.githubusercontent.com/112755279/215259133-7f240c6b-439a-47a5-8951-db3049639960.png)

