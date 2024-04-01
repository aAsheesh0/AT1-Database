#define _CRT_SECURE_NO_WARNINGS
#include "information.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void search_passport_by_number(struct PassportNode* root) {
    char passportNumber[20];
    printf("Enter passport number to search for: ");
    scanf("%s", passportNumber);

    while (root != NULL) {
        int comparisonResult = strcmp(passportNumber, root->passport_number);
        if (comparisonResult == 0) {
            printf("Valid Passport!\n");
            printf("Passport Number: %s\n", root->passport_number);
            printf("First Name: %s\n", root->first_name);
            printf("Last Name: %s\n", root->last_name);
            printf("Nationality: %s\n", root->nationality);
            printf("Date of Birth: %s\n", root->date_of_birth);

            return;
        }
        else if (comparisonResult < 0) {
            root = root->left;
        }
        else {
            root = root->right;
        }
    }

    printf("Passport not found.\n");
}

void find_passports_by_nationality(struct PassportNode* root) {
    char nationality[100];
    printf("Enter nationality to search for: ");
    scanf("%s", nationality);

    if (root == NULL) {
        printf("No passport records found.\n");
        return;
    }

    int found = 0;

    struct PassportNode* stack[100];
    int top = -1;
    struct PassportNode* current = root;

    while (current != NULL || top != -1) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }

        current = stack[top--];

        if (strcmp(current->nationality, nationality) == 0) {
            printf("Passport Number: %s\n", current->passport_number);
            found = 1;
        }

        current = current->right;
    }

    if (!found) {
        printf("No passport records found for nationality: %s\n", nationality);
    }
}