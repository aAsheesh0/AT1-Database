#ifndef COUNTRY_LIST_H
#define COUNTRY_LIST_H

// Define the structure for country Node
struct CountryNode {
    char country[50];
    int num_visits; // Number of visits to this country
    struct CountryNode* next;
};

// Function declarations
struct CountryNode* init_country_node(char country[], int numVisits);
void insert_country_node(struct CountryNode** head, char country[], int num_visits);
void free_country_list(struct CountryNode* head);

#endif