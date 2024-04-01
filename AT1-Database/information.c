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
            printf("Purpose of Visit: %s\n", root->purpose_of_visit);
            printf("Visa Type: %s\n", root->visa_type);

            printf("\nCountries Visited:\n");
            struct CountryNode* countryPtr = root->countries_visited;
            while (countryPtr != NULL) {
                printf("%s\t| %d\n", countryPtr->country, countryPtr->numVisits);
                countryPtr = countryPtr->next;
            }

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
