#include "country.h"
#include <stdlib.h>
#include <string.h>

// Function to create a new node for the linked list of countries visited
CountryListNode* create_country_node(char* country_name, int num_visits) {
    CountryListNode* newNode = (CountryListNode*)malloc(sizeof(CountryListNode));
    if (newNode) {
        newNode->country_name = strdup(country_name);
        newNode->num_visits = num_visits;
        newNode->next = NULL;
    }
    return newNode;
}

// Function to append a node to the end of the linked list
void append_country_node(CountryListNode** head, char* country_name, int num_visits) {
    CountryListNode* newNode = create_country_node(country_name, num_visits);
    if (newNode == NULL) {
        printf("Memory allocation failed. Unable to append node.\n");
        return;
    }
    if (*head == NULL) {
        *head = newNode;
    }
    else {
        CountryListNode* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to search for a node in the linked list by country name
CountryListNode* search_country_node(CountryListNode* head, char* country_name) {
    CountryListNode* current = head;
    while (current != NULL) {
        if (strcmp(current->country_name, country_name) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL; // Country not found
}

// Function to delete a node from the linked list by country name
void delete_country_node(CountryListNode** head, char* country_name) {
    CountryListNode* current = *head;
    CountryListNode* prev = NULL;

    // Find the node with the given country name
    while (current != NULL && strcmp(current->country_name, country_name) != 0) {
        prev = current;
        current = current->next;
    }

    // If country name not found
    if (current == NULL) {
        printf("Country not found in the list. Unable to delete node.\n");
        return;
    }

    // Update pointers to remove the node from the list
    if (prev == NULL) {
        *head = current->next;
    }
    else {
        prev->next = current->next;
    }

    // Free memory allocated for the node
    free(current->country_name);
    free(current);
}

// Function to print the linked list
void print_country_list(CountryListNode* head) {
    CountryListNode* current = head;
    while (current != NULL) {
        printf("Country: %s, Number of Visits: %d\n", current->country_name, current->num_visits);
        current = current->next;
    }
}

// Function to deallocate memory for the linked list
void destroy_country_list(CountryListNode** head) {
    CountryListNode* current = *head;
    while (current != NULL) {
        CountryListNode* temp = current;
        current = current->next;
        free(temp->country_name);
        free(temp);
    }
    *head = NULL; // Set head to NULL after destruction
}