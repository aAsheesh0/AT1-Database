#ifndef COUNTRY_ARRAY_H
#define COUNTRY_ARRAY_H

#define MAX_COUNTRIES 100

struct CountryArray {
    char countries[MAX_COUNTRIES][100];
    int numVisits[MAX_COUNTRIES];
    int count;
};

// Function declarations
void init_country_array(struct CountryArray* country_array);
void insert_country_array(struct CountryArray* country_array, char country[], int num_visits);
void test_array_operations();

#endif