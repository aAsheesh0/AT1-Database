#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "country.h"

struct CountryNode* init_country_node(char country[]) {
    struct CountryNode* new_node = (struct CountryNode*)malloc(sizeof(struct CountryNode));
    if (new_node == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    strcpy(new_node->country, country);
    new_node->next = NULL;
    return new_node;
}

void insert_country_node(struct CountryNode** head, char country[]) {
    struct CountryNode* new_node = init_country_node(country);
    if (*head == NULL) {
        *head = new_node;
    }
    else {
        struct CountryNode* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
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