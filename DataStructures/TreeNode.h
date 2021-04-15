#include "Product.h"
#ifndef TREENODE_H 
#define TREENODE_H

struct TreeNode
{
	Product product;
	TreeNode* left;
	TreeNode* right;
};

#endif