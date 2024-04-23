#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "passport_AVL.h"

AVLNodePtr init_AVL_node(char passport_number[], char first_name[], char last_name[], char nationality[], char date_of_birth[], char purpose_of_visit[], char visa_type[]) {
    AVLNodePtr newNode = (AVLNodePtr)malloc(sizeof(struct AVLNode));
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
    init_country_array(&(newNode->countries_visited)); // initialising array of countries
    //newNode->countries_visited = NULL;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;
    //newNode->rotation_count = 0;
    return newNode;
}

int height(AVLNodePtr node) {
    if (node == NULL)
        return 0;
    return node->height;
}

int get_balance(AVLNodePtr node) {
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

int tree_height_AVL(AVLNodePtr node) {
    if (node == NULL)
        return 0;
    int left_height = tree_height_AVL(node->left);
    int right_height = tree_height_AVL(node->right);
    //printf("Node: %s, Left height: %d, Right height: %d\n", node->passport_number, left_height, right_height);

    return 1 + ((left_height > right_height) ? left_height : right_height);
}

AVLNodePtr rotate_right(AVLNodePtr y, PassportAVL* tree) {
    AVLNodePtr x = y->left;
    AVLNodePtr T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + ((height(y->left) > height(y->right)) ? height(y->left) : height(y->right));
    x->height = 1 + ((height(x->left) > height(x->right)) ? height(x->left) : height(x->right));

    tree->rotation_count++;
    return x;
}

AVLNodePtr rotate_left(AVLNodePtr x, PassportAVL* tree) {
    AVLNodePtr y = x->right;
    AVLNodePtr T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + ((height(x->left) > height(x->right)) ? height(x->left) : height(x->right));
    y->height = 1 + ((height(y->left) > height(y->right)) ? height(y->left) : height(y->right));

    tree->rotation_count++;
    return y;
}

void insert_AVL_node(PassportAVL* tree, AVLNodePtr new_node) {
    if (tree == NULL || new_node == NULL) {
        return;
    }

    if (tree->root == NULL) {
        tree->root = new_node;
    }
    else {
        tree->root = insert_AVL_node_recursive(tree->root, new_node, tree);
    }
}

AVLNodePtr insert_AVL_node_recursive(AVLNodePtr node, AVLNodePtr newNode, PassportAVL* tree) {
    if (node == NULL) {
        return newNode;
    }

    if (strcmp(newNode->passport_number, node->passport_number) < 0) {
        //printf("\nInserted on left!\n");
        node->left = insert_AVL_node_recursive(node->left, newNode, tree);
    }
    else if (strcmp(newNode->passport_number, node->passport_number) > 0) {
        //printf("\nInserted on right!\n");
        node->right = insert_AVL_node_recursive(node->right, newNode, tree);
    }
    else {
        return node;
    }

    node->height = 1 + ((height(node->left) > height(node->right)) ? height(node->left) : height(node->right));

    int balance = get_balance(node);

    if (balance > 1 && strcmp(newNode->passport_number, node->left->passport_number) < 0) {
        printf("\nBefore right rotation:\n");
        inorder_AVL_traversal(node);
        printf("\n");
        return rotate_right(node, tree);
    }

    if (balance < -1 && strcmp(newNode->passport_number, node->right->passport_number) > 0) {
        printf("\nBefore left rotation:\n");
        inorder_AVL_traversal(node);
        printf("\n");
        return rotate_left(node, tree);
    }

    if (balance > 1 && strcmp(newNode->passport_number, node->left->passport_number) > 0) {
        printf("\nBefore left-right rotation:\n");
        inorder_AVL_traversal(node);
        printf("\n");
        node->left = rotate_left(node->left, tree);
        return rotate_right(node, tree);
    }

    if (balance < -1 && strcmp(newNode->passport_number, node->right->passport_number) < 0) {
        printf("\nBefore right-left rotation:\n");
        inorder_AVL_traversal(node);
        printf("\n");
        node->right = rotate_right(node->right, tree);
        return rotate_left(node, tree);
    }

    return node;
}

AVLNodePtr search_AVL_node(AVLNodePtr node, char passport_number[]) {
    if (node == NULL || strcmp(node->passport_number, passport_number) == 0) {
        return node;
    }

    if (strcmp(node->passport_number, passport_number) < 0) {
        return search_AVL_node(node->right, passport_number);
    }

    return search_AVL_node(node->left, passport_number);
}

void inorder_AVL_traversal(AVLNodePtr node) {
    if (node != NULL) {
        inorder_AVL_traversal(node->left);
        printf("Passport Number: %s\n", node->passport_number);
        printf("Countries Visited:\n");
        for (int i = 0; i < node->countries_visited.count; i++) {
            printf("%s - Visits: %d\n", node->countries_visited.countries[i], node->countries_visited.numVisits[i]);
        }
        inorder_AVL_traversal(node->right);
    }
}

void free_AVL_tree(AVLNodePtr node) {
    if (node != NULL) {
        free_AVL_tree(node->left);
        free_AVL_tree(node->right);
        free(node);
    }
}