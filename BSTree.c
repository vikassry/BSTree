#include <stdio.h>
#include <stdlib.h>
#include "BSTree.h"


BSTree createBSTree(void){
	return (BSTree){NULL,0};
}

Node *createNode(int data){
	Node *node = calloc(1,sizeof(Node));
	node->data = data;
	return node;	
}

void lookPlaceAndInsert(nodePtr *node, nodePtr item){
	if(*node==NULL){
		*node = item; return; 
	}
	(item->data < (*node)->data) ? lookPlaceAndInsert(&(*node)->left, item)
	: lookPlaceAndInsert(&(*node)->right, item);
}

int insert(BSTree *t, int data){
	Node *item = createNode(data);
	lookPlaceAndInsert(&t->root, item);
	return ++t->count;
}


Node *searchElement(Node *node, int item){
	return (node->data == item) ? node : (node->left && item < node->data) ? 
	searchElement(node->left, item) : (node->right && item > node->data) ? 
	searchElement(node->right, item) : NULL;
}

Node *find(BSTree t, int item){
	return (!t.root) ? NULL : searchElement(t.root, item);
}

Node *searchparent(Node *root, int item){
	return (root->data == item) ? NULL : ((root->right && root->right->data==item) || (root->left && root->left->data==item)) 
	? root :(root->left && item < root->data) ? searchparent(root->left, item) 
	: (root->right && item > root->data) ? searchparent(root->right, item) : NULL;
}


Node *findParent(BSTree t, int item){
	return (!t.root) ? NULL : searchparent(t.root, item);
}


Node *del(BSTree *t, nodePtr *node){
	nodePtr result;
	if(!*node) return NULL;
	// if(item < (*node)->data)
	// 	(*node)->left = del(&(*node)->left, item);
	// else if(item > (*node)->data)
	// 	(*node)->right = del(&(*node)->right, item);
	// else{
		if((*node)->left == NULL && (*node)->right == NULL){
			result = *node;
			free(*node);
			*node = NULL;
		}
	// 	else if((*node)->left == NULL && (*node)->right){
	// 		result = *node;
	// 		free(*node);
	// 		*node = (*node)->right;
	// 	}
	// }
	return result;
}


Node* Delete(BSTree *t, int item){
	if(!t->root) return NULL;
	t->count -= 1;
	// return del(t, &dest);
}

