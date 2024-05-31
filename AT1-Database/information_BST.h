#ifndef INFORMATION_BST_H
#define INFORMATION_BST_H

#include "passport_BST.h"

/*
*  This file contains all the function prototypes implemeted in information_BST.c and inforamtion_AVL.c to retrieve and print the data
*  And also functions prototypes to add nodes in BST and linked list (Pair1) or AVL and arrays (Pair2)
*  The delete main function uses some helper functions for better organisation
*/

void search_passport_by_number_pair1(PassportBST tree);

void display_passport_history_pair1(PassportBST tree);

void find_passports_by_nationality_pair1(PassportBST tree);

void add_passport_record_pair1(PassportBST* tree);

void delete_passport_record_pair1(PassportBST* tree);

void delete_leaf_node_BST(PassportBST* tree, PassportNodePtr node);
void delete_node_with_one_child_BST(PassportBST* tree, PassportNodePtr node);
void delete_node_with_two_child_BST(PassportBST* tree, PassportNodePtr node);
PassportNodePtr find_parent_BST(PassportNodePtr root, PassportNodePtr node);
PassportNodePtr find_inorder_successor_BST(PassportNodePtr root, PassportNodePtr node);
void copy_passport_data_BST(PassportNodePtr destination, PassportNodePtr source);

void count_nodes_BST(PassportNodePtr root, int* total, int* left, int* right);

#endif