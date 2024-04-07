#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "read.h"
#include "passport.h"

void read_travelers_data(const char* filename, struct PassportNode** root) {
    FILE* file;
    fopen_s(&file, filename, "r");
    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    char line[1024];
    int rows_read = 0;

    char passport_number[20];
    char first_name[50];
    char last_name[50];
    char nationality[100];
    char date_of_birth[20];
    char purpose_of_visit[100];
    char visa_type[50];
    char country[50];
    int num_visits;

    // Skip the first line (header) of the CSV file
    if (fgets(line, sizeof(line), file) == NULL) {
        fclose(file);
        return; // If there's nothing to read, just return
    }

    while (fgets(line, sizeof(line), file)) {
        // Parse the CSV line
        char* token;
        char* saveptr;

        token = strtok_s(line, ",", &saveptr);
        strncpy(passport_number, token, sizeof(passport_number) - 1);
        passport_number[sizeof(passport_number) - 1] = '\0';

        token = strtok_s(NULL, ",", &saveptr);
        strncpy(first_name, token, sizeof(first_name) - 1);
        first_name[sizeof(first_name) - 1] = '\0';

        token = strtok_s(NULL, ",", &saveptr);
        strncpy(last_name, token, sizeof(last_name) - 1);
        last_name[sizeof(last_name) - 1] = '\0';

        token = strtok_s(NULL, ",", &saveptr);
        strncpy(nationality, token, sizeof(nationality) - 1);
        nationality[sizeof(nationality) - 1] = '\0';

        token = strtok_s(NULL, ",", &saveptr);
        strncpy(date_of_birth, token, sizeof(date_of_birth) - 1);
        date_of_birth[sizeof(date_of_birth) - 1] = '\0';

        token = strtok_s(NULL, ",", &saveptr);
        strncpy(purpose_of_visit, token, sizeof(purpose_of_visit) - 1);
        purpose_of_visit[sizeof(purpose_of_visit) - 1] = '\0';

        token = strtok_s(NULL, ",", &saveptr);
        strncpy(visa_type, token, sizeof(visa_type) - 1);
        visa_type[sizeof(visa_type) - 1] = '\0';

        token = strtok_s(NULL, ",", &saveptr);
        strncpy(country, token, sizeof(country) - 1);
        country[sizeof(country) - 1] = '\0';

        token = strtok_s(NULL, ",", &saveptr);
        num_visits = atoi(token); // Convert NumberOfVisits to integer

        // Check if passport already exists in the BST
        struct PassportNode* existing_passport = search_passport_node(*root, passport_number);
        if (existing_passport == NULL) {
            // Create a new passport node
            struct PassportNode* new_passport = init_passport(passport_number, first_name, last_name, nationality, date_of_birth, purpose_of_visit, visa_type);
            // Insert the passport node into the BST
            insert_passport_node(root, new_passport);
            // Insert the visited country into the linked list
            insert_country_node(&(new_passport->countries_visited), country, num_visits);
        }
        else {
            // Passport already exists, just insert the visited country into the existing passport's linked list
            insert_country_node(&(existing_passport->countries_visited), country, num_visits);
        }

        rows_read++;
    }

    fclose(file);
}
