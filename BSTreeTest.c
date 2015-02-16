#include <stdio.h>
#include <stdlib.h>
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
	free(t.root);
}

void test_insert_inserts_at_left_when_root_5_and_2_sent_to_insert_and_returns_2_as_number_of_nodes_in_the_tree(){
	BSTree t = createBSTree();
	insert(&t, 5);
	assert(t.root->data == 5);
	insert(&t, 4);
	assertEqual(t.root->left->data, 4);
	assertEqual(t.count, 2);
	free(t.root);
}

void test_insert_inserts_at_right_when_root_5_and_6_sent_to_insert_and_returns_number_of_nodes_in_the_tree(){
	BSTree t = createBSTree();
	insert(&t, 5);
	assert(t.root->data == 5);
	assert(insert(&t, 6) == 2);	
	assertEqual(t.root->right->data, 6);
	assertEqual(t.count, 2);
	free(t.root);
}

void test_insert_inserts_at_right_when_root_5_and_8_is_sent_as_other_bigger_element_to_insert(){
	BSTree t = createBSTree();
	insert(&t, 6);
	assert(t.root->data == 6);
	assert(insert(&t, 7) == 2);	
	insert(&t, 4); insert(&t, 8); 
	insert(&t, 1); insert(&t, 3);insert(&t, 5);
	
	assertEqual(t.root->left->data, 4);
	assertEqual(t.root->right->data, 7);
	assertEqual(t.root->right->right->data, 8);
	assertEqual(t.root->left->left->data, 1);
	assertEqual(t.root->left->right->data, 5);
	assertEqual(t.root->left->left->right->data, 3);
	assert(t.count == 7);
	free(t.root);
}

void test_find_returns_NULL_when_tree_is_empty(){
	BSTree t = createBSTree();
	assert(find(t, 1)==NULL);	
}

void test_find_returns_null_when_element_is_not_found(){
	BSTree t = createBSTree();
	insert(&t, 2);
	assert(find(t, 1)==NULL);
	free(t.root);
}

void test_find_returns_root_when_root_data_6_is_passed_to_find(){
	BSTree t = createBSTree(); Node *result;
	insert(&t, 6); insert(&t, 7);
	result = find(t, 6);
	assertEqual(result->data ,6);
	assert(t.root == result);
	assert(t.count==2);
	free(t.root);
}

void test_find_returns_node_with_data_5_when_5_is_passed_to_find(){
	BSTree t = createBSTree(); Node *result;
	insert(&t, 7); insert(&t, 8); insert(&t, 3);
	insert(&t, 6); insert(&t, 9); insert(&t, 5); insert(&t, 4);
	assert(t.count==7);
	result = find(t, 5);
	assertEqual(result->data ,5);
	assert(t.root->left->right->left == result);
	free(t.root);
}

void test_find_Parent_returns_NULL_when_tree_is_empty(){
	BSTree t = createBSTree();
	assert(findParent(t, 6) == NULL);
}

void test_find_Parent_returns_the_parent_node_of_given_element(){
	BSTree t = createBSTree();
	insert(&t, 6); insert(&t, 5); insert(&t, 7);
	assert(findParent(t, 7)->data == 6);
	assert(findParent(t, 5)->data == 6);
	free(t.root);
}

void test_find_Parent_returns_NULL_when_it_is_asked_to_find_roots_parent(){
	BSTree t = createBSTree();
	insert(&t, 6);
	assert(findParent(t, 6) == NULL);
	free(t.root);
}

void test_find_Parent_returns_node_when_it_is_asked_to_find_roots_parent(){
	BSTree t = createBSTree(); Node *result;
	insert(&t, 10); insert(&t, 15); insert(&t, 6);
	insert(&t, 7); insert(&t, 12); insert(&t, 4);  insert(&t, 1);
	result = findParent(t, 1);
	assert(result->data == 4);
	assert(t.root->left->left == result);
	free(t.root);
}

void test_Delete_returns_NULL_when_tree_is_empty(){
	BSTree t = createBSTree();
	assert(Delete(&t, 2) == NULL);
}

void test_deletes_the_root(){
	BSTree t = createBSTree(); 
	Node *result; insert(&t, 7);
	assert(Delete(&t, 7)->data == 7);
	assert(t.root == NULL);
}

void test_Deletes_the_leaf_node_and_returns_reference_of_the_leaf_node(){
	BSTree t = createBSTree(); Node *result;
	insert(&t, 7); insert(&t, 8); insert(&t, 3);
	assert(t.count==3);
	assert(t.root->left->data == 3);
	result = Delete(&t, 3);

	assert(t.root->left == NULL);
	assertEqual(result->data, 3);
	assertEqual(t.count,2);
	free(t.root);
}

void test_Deletes_the_node_with_only_right_child_returns_reference_of_the_deleted_element(){
	BSTree t = createBSTree(); Node *result;
	insert(&t, 7); insert(&t, 8); insert(&t, 3); insert(&t, 4);
	assert(t.count==4);
	assert(t.root->left->right->data == 4);
	result = Delete(&t, 4);
	
	assert(t.root->left->right == NULL);
	assertEqual(result->data, 4);
	assertEqual(t.count,3);
	free(t.root);
}

void test_Deletes_the_node_with_only_left_child_returns_reference_of_the_deleted_element(){
	BSTree t = createBSTree(); Node *result;
	insert(&t, 7); insert(&t, 8); insert(&t, 3); insert(&t, 1);
	assert(t.root->left->left->data == 1);
	result = Delete(&t, 1);
	
	assert(t.root->left->left == NULL);
	assertEqual(result->data,1);
	assertEqual(t.count,3);
	free(t.root);
}
