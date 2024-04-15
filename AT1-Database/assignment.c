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
    /*printf("Testing Binary Search Tree (BST) operations:\n");
    test_bst_operations();

    // Performs linked list operations testing
    printf("\nTesting Linked List operations:\n");
    test_linked_list_operations();

    // Performs AVL rotations testing
    printf("\nTesting AVL rotations:\n");
    test_AVL_rotations();

    // Performs AVL operations testing
    printf("\nTesting AVL operations:\n");
    test_AVL_operations();

    // Performs Array operations testing
    printf("\nTesting Array operations:\n");
    test_array_operations();*/

    // Start measuring time
    clock_t start = clock();

    // Read data from travelers_data.csv, using BST and Linked List
    //read_travelers_data_pair1("travelers_data.csv", &root);

    // Read data from travelers_data.csv, using AVL and Linked List
    read_travelers_data_pair2("travelers_data.csv", &root);

    // Stop measuring time
    clock_t end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to read and structure data: %f seconds\n", cpu_time_used);

    while (choice != 5) {
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
            //search_passport_by_number_pair1(root);
            search_passport_by_number_pair2(root);
            break;
        case 2:
            //display_passport_history_pair1(root);
            display_passport_history_pair2(root);
            break;
        case 3:
            //find_passports_by_nationality_pair1(root);
            find_passports_by_nationality_pair2(root);
            break;
        case 4:
            //add_passport_record_pair1(&root);
            add_passport_record_pair2(&root);
            break;
        case 5:
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid choice. Please enter a number from 1 to 5.\n");
            break;
        }
    }

    // Free memory allocated for BST
    //free_passport_tree(root);
    free_AVL_tree(root);

    return 0;
}