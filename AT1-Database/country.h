#ifndef COUNTRY_H
#define COUNTRY_H

// Define the structure for country Node
struct CountryNode {
    char country[50];
    int numVisits; // Number of visits to this country
    struct CountryNode* next;
};

// Function declarations
struct CountryNode* init_country_node(char country[], int numVisits);
void insert_country_node(struct CountryNode** head, char country[], int numVisits);
void free_country_list(struct CountryNode* head);
void test_linked_list_operations();

#endif