#ifndef COUNTRY_H
#define COUNTRY_H

// Define the structure for country Node
struct CountryNode {
    char country[50];
    struct CountryNode* next;
};

// Function declarations
struct CountryNode* init_country_node(char country[]);
void insert_country_node(struct CountryNode** head, char country[]);
void sort_countries(struct CountryNode** head);
void free_country_list(struct CountryNode* head);

#endif