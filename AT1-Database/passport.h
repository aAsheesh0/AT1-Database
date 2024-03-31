#ifndef PASSPORT_H
#define PASSPORT_H
#include "country.h"

// Define the structure for Passport Node
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

// Function declarations
struct PassportNode* init_passport(char passport_number[], char first_name[], char last_name[], char nationality[], char date_of_birth[], char purpose_of_visit[], char visa_type[]);
void insert_passport_node(struct PassportNode** root, struct PassportNode* newNode);
struct PassportNode* search_passport_node(struct PassportNode* root, char passport_number[]);
void inorderPassportTraversal(struct PassportNode* root);
void freePassportTree(struct PassportNode* root);
void test_bst_operations();

#endif