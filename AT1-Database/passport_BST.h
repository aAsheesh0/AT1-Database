#ifndef PASSPORT_H
#define PASSPORT_H
#include "country_LIST.h"

// Define the structure for BST Passport Node
struct PassportNode {
    char passport_number[20];
    char first_name[50];
    char last_name[50];
    char nationality[100];
    char date_of_birth[20];
    char purpose_of_visit[100];
    char visa_type[50];
    struct CountryNode* countries_visited; // Pointer to the head of the linked list of countries
    struct PassportNode* left;
    struct PassportNode* right;
};

// Defining a typedef for the BST Passport Node Pointer
typedef struct PassportNode* PassportNodePtr;

// Defining the structure for the entire BST
typedef struct bst {
    PassportNodePtr root;
} PassportBST;

// Function declarations
PassportNodePtr init_passport(char passport_number[], char first_name[], char last_name[], char nationality[], char date_of_birth[], char purpose_of_visit[], char visa_type[]);
void insert_passport_node(PassportBST* tree, PassportNodePtr newNode);
PassportNodePtr search_passport_node(PassportNodePtr root, char passport_number[]);
void inorder_passport_traversal(PassportNodePtr root);
void free_passport_tree(PassportNodePtr root);
void test_bst_operations();
int tree_height_BST(PassportNodePtr root);

#endif