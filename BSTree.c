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

void findPlaceAndInsert(nodePtr *node, nodePtr item){
	if(*node==NULL){
		*node = item; return; 
	}
	if(item->data < (*node)->data)
		findPlaceAndInsert(&(*node)->left, item);
	else
		findPlaceAndInsert(&(*node)->right, item);
}

int insert(BSTree *t, int data){
	Node *item = createNode(data);
	findPlaceAndInsert(&t->root, item);
	return ++t->count;
}

Node *find(BSTree t, int item){
	return NULL;
}