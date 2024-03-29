#ifndef PASSPORT_H
#define PASSPORT_H

#include "country.h"

// Structure for PassportNode
typedef struct PassportNode {
    char* PassportNumber;
    char* FirstName;
    char* LastName;
    char* Nationality;
    char* DateOfBirth;
    char* PurposeOfVisit;
    char* VisaType;
    CountryListNode* countries_visited; // Pointer to the head of the linked list of countries visited
    struct PassportNode* left;
    struct PassportNode* right;
} PassportNode;

// Function prototypes for BST operations
PassportNode* create_passport_node(char* PassportNumber, char* FirstName, char* LastName, char* Nationality, char* DateOfBirth, char* PurposeOfVisit, char* VisaType);
PassportNode* insert_passport_node(PassportNode* root, PassportNode* node);
PassportNode* search_passport_node(PassportNode* root, char* PassportNumber);
void inorder_traversal(PassportNode* root);
void destroy_passport_tree(PassportNode* root);

// Getter functions
char* get_passport_number(PassportNode* node);
char* get_first_name(PassportNode* node);
char* get_last_name(PassportNode* node);
char* get_nationality(PassportNode* node);
char* get_date_of_birth(PassportNode* node);
char* get_purpose_of_visit(PassportNode* node);
char* get_visa_type(PassportNode* node);

// Setter functions
void set_passport_number(PassportNode* node, char* PassportNumber);
void set_first_name(PassportNode* node, char* FirstName);
void set_last_name(PassportNode* node, char* LastName);
void set_nationality(PassportNode* node, char* Nationality);
void set_date_of_birth(PassportNode* node, char* DateOfBirth);
void set_purpose_of_visit(PassportNode* node, char* PurposeOfVisit);
void set_visa_type(PassportNode* node, char* VisaType);

#endif /* PASSPORT_H */