#ifndef INFORMATION_H
#define INFORMATION_H

#include "passport_BST.h"
#include "passport_AVL.h"

void search_passport_by_number_pair1(PassportBST tree);
void search_passport_by_number_pair2(PassportAVL* tree);

void display_passport_history_pair1(PassportBST tree);
void display_passport_history_pair2(PassportAVL* tree);

void find_passports_by_nationality_pair1(PassportBST tree);
void find_passports_by_nationality_pair2(PassportAVL* tree);

void add_passport_record_pair1(PassportBST* tree);
void add_passport_record_pair2(PassportAVL* tree);

void delete_passport_record_pair1(PassportBST* tree);
void delete_passport_record_pair2(PassportAVL* tree);

void delete_node_BST(PassportBST* tree, PassportNodePtr node);
void delete_node_with_one_child_BST(PassportBST* tree, PassportNodePtr node);
PassportNodePtr find_parent_BST(PassportNodePtr root, char passport_number[]);
PassportNodePtr find_inorder_successor_BST(PassportNodePtr root, PassportNodePtr node);
void copy_passport_data_BST(PassportNodePtr destination, PassportNodePtr source);

void delete_leaf_node_AVL(PassportAVL* tree, AVLNodePtr node);
void delete_node_with_one_child_AVL(PassportAVL* tree, AVLNodePtr node);
void delete_node_with_two_child_AVL(PassportAVL* tree, AVLNodePtr node);
AVLNodePtr find_parent_AVL(AVLNodePtr root, AVLNodePtr node);
AVLNodePtr find_inorder_successor_AVL(AVLNodePtr root, AVLNodePtr node);
void copy_passport_data_AVL(AVLNodePtr destination, AVLNodePtr source);
void balance_tree_check(PassportAVL* tree, AVLNodePtr* node);

#endif