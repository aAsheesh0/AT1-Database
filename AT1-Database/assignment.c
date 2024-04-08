#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "read.h"
#include "information.h"

int main() {
    struct PassportNode* root = NULL;
    int choice = 0;
    double cpu_time_used;

    // Performs BST operations testing
    printf("Testing Binary Search Tree (BST) operations:\n");
    test_bst_operations();

    // Performs linked list operations testing
    printf("\nTesting Linked List operations:\n");
    test_linked_list_operations();

    // Performs AVL operations testing
    printf("\nTesting AVL operations:\n");
    test_AVL_operations();

    // Start measuring time
    clock_t start = clock();

    // Read data from travelers_data.csv
    read_travelers_data("travelers_data.csv", &root);

    // Stop measuring time
    clock_t end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to read and structure data: %f seconds\n", cpu_time_used);

    /*while (choice != 5) {
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
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid choice. Please enter a number from 1 to 5.\n");
            break;
        }
    }*/

    // Free memory allocated for BST
    free_passport_tree(root);

    return 0;
}