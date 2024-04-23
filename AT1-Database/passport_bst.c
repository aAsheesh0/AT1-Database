#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "passport_BST.h"

PassportNodePtr init_passport(char passport_number[], char first_name[], char last_name[], char nationality[], char date_of_birth[], char purpose_of_visit[], char visa_type[]) {
    PassportNodePtr new_node = (PassportNodePtr)malloc(sizeof(struct PassportNode));
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

void insert_passport_node(PassportBST* tree, PassportNodePtr new_node) {
    if (tree == NULL) {
        printf("BST is not Initialised.\n");
        return;
    }

    if (tree->root == NULL) {
        tree->root = new_node;
    }
    else {
        PassportNodePtr current = tree->root;
        PassportNodePtr parent = NULL;

        while (current != NULL) {
            parent = current;
            if (strcmp(new_node->passport_number, current->passport_number) < 0) {
                current = current->left;
            }
            else {
                current = current->right;
            }
        }

        if (strcmp(new_node->passport_number, parent->passport_number) < 0) {
            parent->left = new_node;
        }
        else {
            parent->right = new_node;
        }
    }
}

PassportNodePtr search_passport_node(PassportNodePtr root, char passport_number[]) {
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

void inorder_passport_traversal(PassportNodePtr root) {
    if (root != NULL) {
        inorder_passport_traversal(root->left);
        printf("Passport Number: %s\n", root->passport_number);
        //printf("Passport Number: %s, First Name: %s\n", root->passport_number, root->first_name);
        struct CountryNode* countryPtr = root->countries_visited;
        while (countryPtr != NULL) {
            printf("Country: %s, Visits: %d\n", countryPtr->country, countryPtr->num_visits);
            countryPtr = countryPtr->next;
        }
        inorder_passport_traversal(root->right);
    }
}

void free_passport_tree(PassportNodePtr root) {
    if (root != NULL) {
        free_passport_tree(root->left);
        free_passport_tree(root->right);
        free_country_list(root->countries_visited);
        free(root);
    }
}

int tree_height_BST(PassportNodePtr root) {
    if (root == NULL)
        return 0;
    int left_height = tree_height_BST(root->left);
    int right_height = tree_height_BST(root->right);
    //printf("Node: %s, Left height: %d, Right height: %d\n", root->passport_number, left_height, right_height);
    
    return 1 + ((left_height > right_height) ? left_height : right_height);
}