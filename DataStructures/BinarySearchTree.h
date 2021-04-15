#pragma once
#include "Product.h"
#include "TreeNode.h"

class BinarySearchTree {
public:
	BinarySearchTree() {
		root = NULL;
	}
	~BinarySearchTree() {
		destroyTree(root);
	}
	void retrieveProduct(Product& item, bool& found) const {
		retrieveProduct(root, item, found);
	}
	void insertProduct(Product item) {
		insertProduct(root, item);
	}
	void deleteProduct(int code) {
		deleteProduct(root, code);
	}
	void printPreOrder() const {
		printPreOrder(root);
	}
	void printPostOrder() const {
		printPostOrder(root);
	}
	void printInOrder() const {
		printInOrder(root);
	}
	bool isEmpty() const;
	bool isFull() const;
private:
	void destroyTree(TreeNode*& tree);
	void retrieveProduct(TreeNode* tree, Product& item, bool& found) const;
	void insertProduct(TreeNode*& tree, Product item);
	void deleteProduct(TreeNode*& tree, int item);
	void deleteNode(TreeNode*& tree);
	void getSuccessor(TreeNode* tree, Product& data);
	void printTree(TreeNode* tree) const;
	void printPreOrder(TreeNode* tree)  const;
	void printInOrder(TreeNode* tree)   const;
	void printPostOrder(TreeNode* tree) const;
	TreeNode* root;
};
