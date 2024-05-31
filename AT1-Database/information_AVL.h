#ifndef INFORMATION_AVL_H
#define INFORMATION_AVL_H

#include "passport_AVL.h"

/*
*  This file contains all the function prototypes implemeted in information_BST.c and inforamtion_AVL.c to retrieve and print the data
*  And also functions prototypes to add nodes in BST and linked list (Pair1) or AVL and arrays (Pair2)
*  The delete main function uses some helper functions for better organisation
*/

void search_passport_by_number_pair2(PassportAVL* tree);

void display_passport_history_pair2(PassportAVL* tree);

void find_passports_by_nationality_pair2(PassportAVL* tree);

void add_passport_record_pair2(PassportAVL* tree);

void delete_passport_record_pair2(PassportAVL* tree);

void delete_leaf_node_AVL(PassportAVL* tree, AVLNodePtr node);
void delete_node_with_one_child_AVL(PassportAVL* tree, AVLNodePtr node);
void delete_node_with_two_child_AVL(PassportAVL* tree, AVLNodePtr node);
AVLNodePtr find_parent_AVL(AVLNodePtr root, AVLNodePtr node);
AVLNodePtr find_inorder_successor_AVL(AVLNodePtr root, AVLNodePtr node);
void copy_passport_data_AVL(AVLNodePtr destination, AVLNodePtr source);
void balance_tree_check(PassportAVL* tree, AVLNodePtr* node);

void count_nodes_AVL(AVLNodePtr root, int* total, int* left, int* right);

#endif