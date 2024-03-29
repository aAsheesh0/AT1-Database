#include "passport.h"
#include <stdlib.h>
#include <string.h>

// Function to create a new PassportNode
PassportNode* create_passport_node(char* PassportNumber, char* FirstName, char* LastName, char* Nationality, char* DateOfBirth, char* PurposeOfVisit, char* VisaType) {
    PassportNode* newNode = (PassportNode*)malloc(sizeof(PassportNode));
    if (newNode) {
        // Allocate memory for strings and copy their values
        newNode->PassportNumber = strdup(PassportNumber);
        newNode->FirstName = strdup(FirstName);
        newNode->LastName = strdup(LastName);
        newNode->Nationality = strdup(Nationality);
        newNode->DateOfBirth = strdup(DateOfBirth);
        newNode->PurposeOfVisit = strdup(PurposeOfVisit);
        newNode->VisaType = strdup(VisaType);
        newNode->countries_visited = NULL; // Initialize countries visited list to NULL
        newNode->left = newNode->right = NULL;
    }
    return newNode;
}

// Function to insert a node into the BST
PassportNode* insert_passport_node(PassportNode* root, PassportNode* node) {
    if (root == NULL) {
        return node;
    }

    // Compare passport numbers for insertion
    int cmp = strcmp(node->PassportNumber, root->PassportNumber);
    if (cmp < 0) {
        root->left = insert_passport_node(root->left, node);
    }
    else if (cmp > 0) {
        root->right = insert_passport_node(root->right, node);
    }

    return root;
}

// Function to search for a node in the BST by passport number
PassportNode* search_passport_node(PassportNode* root, char* PassportNumber) {
    if (root == NULL || strcmp(root->PassportNumber, PassportNumber) == 0) {
        return root;
    }

    // Compare passport numbers for search
    int cmp = strcmp(PassportNumber, root->PassportNumber);
    if (cmp < 0) {
        return search_passport_node(root->left, PassportNumber);
    }
    else {
        return search_passport_node(root->right, PassportNumber);
    }
}

// Function for inorder traversal of the BST
void inorder_traversal(PassportNode* root) {
    if (root != NULL) {
        inorder_traversal(root->left);
        printf("Passport Number: %s\n", root->PassportNumber);
        // Print other details as needed
        inorder_traversal(root->right);
    }
}

// Function to deallocate memory for the BST
void destroy_bst(PassportNode* root) {
    if (root != NULL) {
        destroy_bst(root->left);
        destroy_bst(root->right);
        // Free allocated memory for strings
        free(root->PassportNumber);
        free(root->FirstName);
        free(root->LastName);
        free(root->Nationality);
        free(root->DateOfBirth);
        free(root->PurposeOfVisit);
        free(root->VisaType);
        // Destroy the linked list of countries visited
        destroy_country_list(&(root->countries_visited));
        free(root);
    }
}

// Getter functions
char* get_passport_number(PassportNode* node) {
    return node->PassportNumber;
}

char* get_first_name(PassportNode* node) {
    return node->FirstName;
}

char* get_last_name(PassportNode* node) {
    return node->LastName;
}

char* get_nationality(PassportNode* node) {
    return node->Nationality;
}

char* get_date_of_birth(PassportNode* node) {
    return node->DateOfBirth;
}

char* get_purpose_of_visit(PassportNode* node) {
    return node->PurposeOfVisit;
}

char* get_visa_type(PassportNode* node) {
    return node->VisaType;
}

// Setter functions
void set_passport_number(PassportNode* node, char* PassportNumber) {
    free(node->PassportNumber);
    node->PassportNumber = strdup(PassportNumber);
}

void set_first_name(PassportNode* node, char* FirstName) {
    free(node->FirstName);
    node->FirstName = strdup(FirstName);
}

void set_last_name(PassportNode* node, char* LastName) {
    free(node->LastName);
    node->LastName = strdup(LastName);
}

void set_nationality(PassportNode* node, char* Nationality) {
    free(node->Nationality);
    node->Nationality = strdup(Nationality);
}

void set_date_of_birth(PassportNode* node, char* DateOfBirth) {
    free(node->DateOfBirth);
}