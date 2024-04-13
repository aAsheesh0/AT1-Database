#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "country_ARRAY.h"

void init_country_array(struct CountryArray* countryArray) {
    countryArray->count = 0;
    for (int i = 0; i < MAX_COUNTRIES; i++) {
        countryArray->countries[i][0] = '\0';
        countryArray->numVisits[i] = 0;
    }
}

void insert_country_array(struct CountryArray* countryArray, char country[], int num_visits) {
    // Check if the country already exists in the array
    for (int i = 0; i < countryArray->count; i++) {
        if (strcmp(countryArray->countries[i], country) == 0) {
            countryArray->numVisits[i] += num_visits;
            return;
        }
    }

    // Country doesn't exist, add it to the array
    if (countryArray->count < MAX_COUNTRIES) {
        strcpy(countryArray->countries[countryArray->count], country);
        countryArray->numVisits[countryArray->count] = num_visits;
        countryArray->count++;

        // Sort the array alphabetically
        for (int i = 0; i < countryArray->count - 1; i++) {
            for (int j = 0; j < countryArray->count - i - 1; j++) {
                if (strcmp(countryArray->countries[j], countryArray->countries[j + 1]) > 0) {
                    // Swap countries
                    char temp_country[100];
                    strcpy(temp_country, countryArray->countries[j]);
                    strcpy(countryArray->countries[j], countryArray->countries[j + 1]);
                    strcpy(countryArray->countries[j + 1], temp_country);

                    // Swap num_visits
                    int temp_visits = countryArray->numVisits[j];
                    countryArray->numVisits[j] = countryArray->numVisits[j + 1];
                    countryArray->numVisits[j + 1] = temp_visits;
                }
            }
        }
    }
    else {
        printf("Error: Maximum number of countries reached.\n");
    }
}