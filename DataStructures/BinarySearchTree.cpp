#include "BinarySearchTree.h"
#include "Product.h"

void BinarySearchTree::destroyTree(TreeNode*& tree)
{
    //PostOrder
    if (tree != NULL)
    {
        destroyTree(tree->left);
        destroyTree(tree->right);
        delete tree;
    }
}

bool BinarySearchTree::isEmpty() const {
    return root == NULL;
}

bool BinarySearchTree::isFull() const {
    TreeNode* location;
    try {
        location = new TreeNode;
        delete location;
        return false;
    }
    catch (std::bad_alloc exception) {
        return true;
    }
}

void BinarySearchTree::retrieveProduct(TreeNode* tree,
    Product& product, bool& found) const {
    if (tree == NULL) {
        found = false;
    }
    else if (product.getCode() < tree->product.getCode()) {
        retrieveProduct(tree->left, product, found);
    }
    else if (product.getCode() > tree->product.getCode()) {
        retrieveProduct(tree->right, product, found);
    }
    else {
        product = tree->product;
        found = true;
    }
}

void BinarySearchTree::insertProduct(TreeNode*& tree, Product product) {
    if (tree == NULL) {
        tree = new TreeNode;
        tree->left = NULL;
        tree->right = NULL;
        tree->product = product;
    }
    else if (product.getCode() < tree->product.getCode()) {
        insertProduct(tree->left, product);
    }
    else {
        insertProduct(tree->right, product);
    }
}

void BinarySearchTree::deleteProduct(TreeNode*& tree, int aluno) {
    if (aluno < tree->product.getCode())
        deleteProduct(tree->left, aluno);
    else if (aluno > tree->product.getCode())
        deleteProduct(tree->right, aluno);
    else if (aluno == tree->product.getCode())
        deleteNode(tree);
}

void BinarySearchTree::deleteNode(TreeNode*& tree) {
    Product data;
    TreeNode* tempPointer;
    tempPointer = tree;
    if (tree->left == NULL) {
        tree = tree->right;
        delete tempPointer;
    }
    else if (tree->right == NULL) {
        tree = tree->left;
        delete tempPointer;
    }
    else {
        getSuccessor(tree, data);
        tree->product = data;
        deleteProduct(tree->right, data.getCode());
    }
}

void BinarySearchTree::getSuccessor(TreeNode* tree, Product& data) {
    tree = tree->right;
    while (tree->left != NULL)
        tree = tree->left;
    data = tree->product;
}

void BinarySearchTree::printTree(TreeNode* tree) const {

}

void BinarySearchTree::printPreOrder(TreeNode* tree) const {
    if (tree != NULL) {
        std::cout << tree->product.getName() << " , ";
        printPreOrder(tree->left);
        printPreOrder(tree->right);
    }
}

void BinarySearchTree::printPostOrder(TreeNode* tree) const {
    if (tree != NULL) {
        printPostOrder(tree->left);
        printPostOrder(tree->right);
        std::cout << tree->product.getName() << " , ";
    }
}

void BinarySearchTree::printInOrder(TreeNode* tree) const {
    if (tree != NULL) {
        printInOrder(tree->left);
        std::cout << tree->product.getName() << " , ";
        printInOrder(tree->right);
    }
}