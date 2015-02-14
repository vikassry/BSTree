#include <stdio.h>
#include "BSTree.h"
#include "expr_assert.h"


void test_createBSTree_creates_a_tree_with_NULL_root(){
	BSTree tree = createBSTree();
	assert(tree.root == NULL);
	assert(tree.count == 0);
}

void test_insert_inserts_5_as_root_of_the_tree_when_root_is_NULL_and_returns_1(){
	BSTree t = createBSTree();
	insert(&t, 4);
	assert(t.root->data == 4);
	assert(t.count == 1);
}

void test_insert_inserts_at_left_when_root_5_and_2_sent_to_insert_and_returns_2_as_number_of_nodes_in_the_tree(){
	BSTree t = createBSTree();
	insert(&t, 5);
	assert(t.root->data == 5);
	insert(&t, 4);
	assertEqual(t.root->left->data, 4);
	assertEqual(t.count, 2);
}

void test_insert_inserts_at_right_when_root_5_and_6_sent_to_insert_and_returns_number_of_nodes_in_the_tree(){
	BSTree t = createBSTree();
	insert(&t, 5);
	assert(t.root->data == 5);
	assert(insert(&t, 6) == 2);	
	assertEqual(t.root->right->data, 6);
	assertEqual(t.count, 2);
}

void test_insert_inserts_at_right_when_root_5_and_8_is_sent_as_other_bigger_element_to_insert(){
	BSTree t = createBSTree();
	insert(&t, 6);
	assert(t.root->data == 6);
	assert(insert(&t, 7) == 2);	
	insert(&t, 4); insert(&t, 8); 
	insert(&t, 1); insert(&t, 3);
	assertEqual(t.root->left->data, 4);
	assertEqual(t.root->right->data, 7);
	assertEqual(t.root->right->right->data, 8);
	assert(t.root->left->left->data == 1);
	assertEqual(t.root->left->left->right->data, 3);
}

	// void test_find_returns_null_when_element_is_not_found(){
		
	// }