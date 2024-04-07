#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "read.h"
#include "passport.h"
#include "information.h"

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

int main() {
    struct PassportNode* root = NULL;
    int choice = 0;

    // Perform BST operations testing
    /*printf("Testing Binary Search Tree (BST) operations:\n");
    test_bst_operations();

    // Perform linked list operations testing
    printf("\nTesting Linked List operations:\n");
    test_linked_list_operations();*/

    // Read data from travelers_data.csv
    read_travelers_data("travelers_data.csv", &root);

    while (choice != 5){
        printf("\nPassport Database Operations\n");
        printf("1. Search for a Passport Details by Passport Number\n");
        printf("2. Display Passport History\n");
        printf("3. Find Passport Records by Nationality\n");
        printf("4. Add a Passport Record\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid choice. Please enter a number from 1 to 5.\n");
            while (getchar() != '\n');
            continue; // For restarting
        }
        
        switch (choice) {
        case 1:
            search_passport_by_number(root);
            break;
        case 2:
            display_passport_history(root);
            break;
        case 3:
            find_passports_by_nationality(root);
            break;
        case 4:
            add_passport_record(&root);
            break;
        case 5:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice. Please enter a number from 1 to 5.\n");
            break;
        }
    }

    // Free memory allocated for BST
    free_passport_tree(root);

    return 0;
}