#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "country_ARRAY.h"

void init_country_array(struct CountryArray* country_array) {
    country_array->count = 0;
    for (int i = 0; i < MAX_COUNTRIES; i++) {
        country_array->countries[i][0] = '\0';
        country_array->numVisits[i] = 0;
    }
}

void insert_country_array(struct CountryArray* country_array, char country[], int num_visits) {
    // Check if the country already exists in the array
    for (int i = 0; i < country_array->count; i++) {
        if (strcmp(country_array->countries[i], country) == 0) {
            country_array->numVisits[i] += num_visits;
            return;
        }
    }

    // Country doesn't exist, add it to the array
    if (country_array->count < MAX_COUNTRIES) {
        strcpy(country_array->countries[country_array->count], country);
        country_array->numVisits[country_array->count] = num_visits;
        country_array->count++;

        // Sort the array alphabetically
        for (int i = 0; i < country_array->count - 1; i++) {
            for (int j = 0; j < country_array->count - i - 1; j++) {
                if (strcmp(country_array->countries[j], country_array->countries[j + 1]) > 0) {
                    // Swap countries
                    char temp_country[100];
                    strcpy(temp_country, country_array->countries[j]);
                    strcpy(country_array->countries[j], country_array->countries[j + 1]);
                    strcpy(country_array->countries[j + 1], temp_country);

                    // Swap num_visits
                    int temp_visits = country_array->numVisits[j];
                    country_array->numVisits[j] = country_array->numVisits[j + 1];
                    country_array->numVisits[j + 1] = temp_visits;
                }
            }
        }
    }
    else {
        printf("Error: Maximum number of countries reached.\n");
    }
}