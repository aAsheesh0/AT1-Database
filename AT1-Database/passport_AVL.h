#ifndef PASSPORT_AVL_H
#define PASSPORT_AVL_H
#include "country_ARRAY.h"

struct AVLNode {
    char passport_number[20];
    char first_name[50];
    char last_name[50];
    char nationality[100];
    char date_of_birth[20];
    char purpose_of_visit[100];
    char visa_type[50];
    struct CountryArray countries_visited; // Array of countries visited
    struct AVLNode* left;
    struct AVLNode* right;
    int height; 
};

//prototypes
struct AVLNode* init_AVL_node(char passport_number[], char first_name[], char last_name[], char nationality[], char date_of_birth[], char purpose_of_visit[], char visa_type[]);
int height(struct AVLNode* node);
int get_balance(struct AVLNode* node);
struct AVLNode* rotate_right(struct AVLNode* y);
struct AVLNode* rotate_left(struct AVLNode* x);
struct AVLNode* insert_AVL_node(struct AVLNode* node, struct AVLNode* newNode);
struct AVLNode* search_AVL_node(struct AVLNode* node, char passport_number[]);
void inorder_AVL_traversal(struct AVLNode* node);
void free_AVL_tree(struct AVLNode* node);
void test_AVL_operations();

#endif