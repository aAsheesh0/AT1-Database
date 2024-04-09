#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "passport_BST.h"

struct PassportNode* init_passport(char passport_number[], char first_name[], char last_name[], char nationality[], char date_of_birth[], char purpose_of_visit[], char visa_type[]) {
    struct PassportNode* new_node = (struct PassportNode*)malloc(sizeof(struct PassportNode));
    if (new_node == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    strcpy(new_node->passport_number, passport_number);
    strcpy(new_node->first_name, first_name);
    strcpy(new_node->last_name, last_name);
    strcpy(new_node->nationality, nationality);
    strcpy(new_node->date_of_birth, date_of_birth);
    strcpy(new_node->purpose_of_visit, purpose_of_visit);
    strcpy(new_node->visa_type, visa_type);
    new_node->countries_visited = NULL;
    new_node->left = NULL;
    new_node->right = NULL; 
    return new_node;
}

void insert_passport_node(struct PassportNode** root, struct PassportNode* new_node) {
    if (*root == NULL) {
        *root = new_node;
    }
    else {
        if (strcmp(new_node->passport_number, (*root)->passport_number) < 0) {
            insert_passport_node(&((*root)->left), new_node);
        }
        else {
            insert_passport_node(&((*root)->right), new_node);
        }
    }
}

struct PassportNode* search_passport_node(struct PassportNode* root, char passport_number[]) {
    if (root == NULL || strcmp(root->passport_number, passport_number) == 0) {
        return root;
    }
    if (strcmp(passport_number, root->passport_number) < 0) {
        return search_passport_node(root->left, passport_number);
    }
    else {
        return search_passport_node(root->right, passport_number);
    }
}

void inorder_passport_traversal(struct PassportNode* root) {
    if (root != NULL) {
        inorder_passport_traversal(root->left);
        struct CountryNode* countryPtr = root->countries_visited;
        while (countryPtr != NULL) {
            countryPtr = countryPtr->next;
        }
        printf("Passport Number: %s, First Name: %s.\n", root->passport_number, root->first_name);
        inorder_passport_traversal(root->right);
    }
}

void free_passport_tree(struct PassportNode* root) {
    if (root != NULL) {
        free_passport_tree(root->left);
        free_passport_tree(root->right);
        free_country_list(root->countries_visited);
        free(root);
    }
}