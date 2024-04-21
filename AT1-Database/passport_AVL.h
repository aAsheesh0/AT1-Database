// Defining the structure for the entire BST
#ifndef PASSPORT_AVL_H
#define PASSPORT_AVL_H
#include "country_ARRAY.h"
//#include "country_LIST.h"

struct AVLNode {
    char passport_number[20];
    char first_name[50];
    char last_name[50];
    char nationality[100];
    char date_of_birth[20];
    char purpose_of_visit[100];
    char visa_type[50];
    //struct CountryNode* countries_visited; // Pointer to the head of the linked list of countries
    struct CountryArray countries_visited; // Array of countries visited
    struct AVLNode* left;
    struct AVLNode* right;
    int height;
};

// Defining a typedef for the AVL Node Pointer
typedef struct AVLNode* AVLNodePtr;

// Defining the structure for the entire AVL
typedef struct avl {
    AVLNodePtr root;
    int rotation_count;
} PassportAVL;

//prototypes
AVLNodePtr init_AVL_node(char passport_number[], char first_name[], char last_name[], char nationality[], char date_of_birth[], char purpose_of_visit[], char visa_type[]);
int height(AVLNodePtr node);
int tree_height_AVL(AVLNodePtr node);
int get_balance(AVLNodePtr node);
AVLNodePtr rotate_right(AVLNodePtr y, PassportAVL* tree);
AVLNodePtr rotate_left(AVLNodePtr x, PassportAVL* tree);
void insert_AVL_node(PassportAVL* tree, AVLNodePtr new_node);
AVLNodePtr insert_AVL_node_recursive(AVLNodePtr node, AVLNodePtr newNode, PassportAVL* tree);
AVLNodePtr search_AVL_node(AVLNodePtr node, char passport_number[]);
void inorder_AVL_traversal(AVLNodePtr node);
void free_AVL_tree(AVLNodePtr node);
void test_AVL_operations();
void test_AVL_rotations();

#endif