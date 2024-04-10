#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "passport_AVL.h"

struct AVLNode* init_AVL_node(char passport_number[], char first_name[], char last_name[], char nationality[], char date_of_birth[], char purpose_of_visit[], char visa_type[]) {
    struct AVLNode* newNode = (struct AVLNode*)malloc(sizeof(struct AVLNode));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    strcpy(newNode->passport_number, passport_number);
    strcpy(newNode->first_name, first_name);
    strcpy(newNode->last_name, last_name);
    strcpy(newNode->nationality, nationality);
    strcpy(newNode->date_of_birth, date_of_birth);
    strcpy(newNode->purpose_of_visit, purpose_of_visit);
    strcpy(newNode->visa_type, visa_type);
    //init_country_array(&(newNode->countries_visited)); // initialising array of countries
    newNode->countries_visited = NULL;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}

int height(struct AVLNode* node) {
    if (node == NULL)
        return 0;
    return node->height;
}

int get_balance(struct AVLNode* node) {
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

struct AVLNode* rotate_right(struct AVLNode* y) {
    struct AVLNode* x = y->left;
    struct AVLNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + ((height(y->left) > height(y->right)) ? height(y->left) : height(y->right));
    x->height = 1 + ((height(x->left) > height(x->right)) ? height(x->left) : height(x->right));

    return x;
}

struct AVLNode* rotate_left(struct AVLNode* x) {
    struct AVLNode* y = x->right;
    struct AVLNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + ((height(x->left) > height(x->right)) ? height(x->left) : height(x->right));
    y->height = 1 + ((height(y->left) > height(y->right)) ? height(y->left) : height(y->right));

    return y;
}

struct AVLNode* insert_AVL_node(struct AVLNode* node, struct AVLNode* newNode) {
    if (node == NULL) {
        return newNode;
    }

    if (strcmp(newNode->passport_number, node->passport_number) < 0) {
        node->left = insert_AVL_node(node->left, newNode);
    }
    else if (strcmp(newNode->passport_number, node->passport_number) > 0) {
        node->right = insert_AVL_node(node->right, newNode);
    }
    else {
        return node;
    }

    node->height = 1 + ((height(node->left) > height(node->right)) ? height(node->left) : height(node->right));

    int balance = get_balance(node);

    if (balance > 1 && strcmp(newNode->passport_number, node->left->passport_number) < 0) {
        printf("Before right rotation:\n");
        inorder_AVL_traversal(node);
        printf("\n");
        return rotate_right(node);
    }

    if (balance < -1 && strcmp(newNode->passport_number, node->right->passport_number) > 0) {
        printf("Before left rotation:\n");
        inorder_AVL_traversal(node);
        printf("\n");
        return rotate_left(node);
    }

    if (balance > 1 && strcmp(newNode->passport_number, node->left->passport_number) > 0) {
        printf("Before left-right rotation:\n");
        inorder_AVL_traversal(node);
        printf("\n");
        node->left = rotate_left(node->left);
        return rotate_right(node);
    }

    if (balance < -1 && strcmp(newNode->passport_number, node->right->passport_number) < 0) {
        printf("Before right-left rotation:\n");
        inorder_AVL_traversal(node);
        printf("\n");
        node->right = rotate_right(node->right);
        return rotate_left(node);
    }

    return node;
}

struct AVLNode* search_AVL_node(struct AVLNode* node, char passport_number[]) {
    if (node == NULL || strcmp(node->passport_number, passport_number) == 0) {
        return node;
    }

    if (strcmp(node->passport_number, passport_number) < 0) {
        return search_AVL_node(node->right, passport_number);
    }

    return search_AVL_node(node->left, passport_number);
}

void inorder_AVL_traversal(struct AVLNode* node) {
    if (node != NULL) {
        inorder_AVL_traversal(node->left);
        printf("Passport Number: %s\n", node->passport_number);
        /*printf("Countries Visited:\n");
        for (int i = 0; i < node->countries_visited.count; i++) {
            printf("%s - Visits: %d\n", node->countries_visited.countries[i], node->countries_visited.numVisits[i]);
        }*/
        inorder_AVL_traversal(node->right);
    }
}

void free_AVL_tree(struct AVLNode* node) {
    if (node != NULL) {
        free_AVL_tree(node->left);
        free_AVL_tree(node->right);
        free(node);
    }
}