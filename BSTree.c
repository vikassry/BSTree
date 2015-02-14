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