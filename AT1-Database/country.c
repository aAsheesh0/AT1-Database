#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "country.h"

struct CountryNode* init_country_node(char country[], int numVisits) {
    struct CountryNode* newNode = (struct CountryNode*)malloc(sizeof(struct CountryNode));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    strcpy(newNode->country, country);
    newNode->numVisits = numVisits;
    newNode->next = NULL;
    return newNode;
}

void insert_country_node(struct CountryNode** head, char country[], int num_visits) {
    // Create a new country node
    struct CountryNode* new_node = (struct CountryNode*)malloc(sizeof(struct CountryNode));
    if (new_node == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    strcpy(new_node->country, country);
    new_node->numVisits = num_visits;
    new_node->next = NULL;

    // If the list is empty or the new node should be inserted at the beginning
    if (*head == NULL || strcmp(country, (*head)->country) < 0 || (strcmp(country, (*head)->country) == 0 && num_visits > (*head)->numVisits)) {
        new_node->next = *head;
        *head = new_node;
    }
    else {
        struct CountryNode* current = *head;
        // Traverse the list to find the appropriate position to insert the new node
        while (current->next != NULL && (strcmp(country, current->next->country) > 0 || (strcmp(country, current->next->country) == 0 && num_visits <= current->next->numVisits))) {
            current = current->next;
        }
        // Insert the new node
        new_node->next = current->next;
        current->next = new_node;
    }
}

void free_country_list(struct CountryNode* head) {
    struct CountryNode* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}