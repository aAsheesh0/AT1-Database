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

void insert_country_node(struct CountryNode** head, char country[], int numVisits) {
    struct CountryNode* newNode = init_country_node(country, numVisits);
    if (*head == NULL) {
        *head = newNode;
    }
    else {
        struct CountryNode* temp = *head;
        while (temp->next != NULL) {
            if (strcmp(temp->country, country) == 0) {
                temp->numVisits += numVisits; // Increment numVisits if country already exists
                free(newNode); // Free newNode as country already exists
                return;
            }
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void sort_countries(struct CountryNode** head) {
    if (*head == NULL || (*head)->next == NULL) {
        return;
    }

    struct CountryNode* current = *head;
    struct CountryNode* index = NULL;
    char temp[100];

    while (current != NULL) {
        index = current->next;
        while (index != NULL) {
            if (strcmp(current->country, index->country) > 0) {
                strcpy(temp, current->country);
                strcpy(current->country, index->country);
                strcpy(index->country, temp);
            }
            index = index->next;
        }
        current = current->next;
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