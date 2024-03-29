#ifndef COUNTRY_H
#define COUNTRY_H

// Structure for a node in the linked list of countries visited
typedef struct CountryListNode {
    char* country_name;
    int num_visits;
    struct CountryListNode* next;
} CountryListNode;

// Function prototypes for country list operations
CountryListNode* create_country_node(char* country_name, int num_visits);
void append_country_node(CountryListNode** head, char* country_name, int num_visits);
CountryListNode* search_country_node(CountryListNode* head, char* country_name);
void delete_country_node(CountryListNode** head, char* country_name);
void print_country_list(CountryListNode* head);
void destroy_country_list(CountryListNode** head);

#endif /* COUNTRY_H */