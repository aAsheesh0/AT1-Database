#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "read.h"
#include "information.h"

void Database_BST() {
    PassportNodePtr root = NULL;
    PassportBST tree = { root };

    int choice = 0;
    double cpu_time_used;
    int Tree_height;

    // Performs BST  and Linked List operations testing
    /*printf("Testing Binary Search Tree (BST) operations:\n");
    test_bst_operations();

    printf("\nTesting Linked List operations:\n");
    test_linked_list_operations();*/

    // Start measuring time
    clock_t start = clock();

    // Read data from travelers_data.csv, using BST and Linked List
    read_travelers_data_pair1("travelers_data.csv", &tree);
    //inorder_passport_traversal(tree.root);

    // Stop measuring time
    clock_t end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to read and structure data: %f seconds\n", cpu_time_used);

    Tree_height = tree_height_BST(tree.root);
    printf("Height of the tree is: %d\n", Tree_height);

    while (choice != 6) {
        printf("\nPassport Database Operations (BST)\n");
        printf("1. Search for a Passport Details by Passport Number\n");
        printf("2. Display Passport History\n");
        printf("3. Find Passport Records by Nationality\n");
        printf("4. Add a Passport to the Record\n");
        printf("5. Delete a Passport from the Record\n");
        printf("6. Exit Database.\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid choice. Please enter a number from 1 to 5.\n");
            while (getchar() != '\n');
            continue; // For restarting
        }

        switch (choice) {
        case 1:
            search_passport_by_number_pair1(tree);
            break;
        case 2:
            display_passport_history_pair1(tree);
            break;
        case 3:
            find_passports_by_nationality_pair1(tree);
            break;
        case 4:
            add_passport_record_pair1(&tree);
            break;
        case 5:
            delete_passport_record_pair1(&tree);
            //inorder_passport_traversal(tree.root);
            break;
        case 6:
            printf("Exiting Database . . . \n\n");
            break;
        default:
            printf("Invalid choice. Please enter a number from 1 to 5.\n");
            break;
        }
    }

    // Free memory allocated for BST
    free_passport_tree(tree.root);
    
}

void Database_AVL() {
    PassportAVL tree = { NULL , 0};
    
    int choice = 0;
    double cpu_time_used;
    int Tree_height;

    // Performs AVL operations, rotations and array operations testing
    /*printf("\nTesting AVL rotations:\n");
    test_AVL_rotations();

    printf("\nTesting AVL operations:\n");
    test_AVL_operations();

    printf("\nTesting Array operations:\n");
    test_array_operations();*/

    // Start measuring time
    clock_t start = clock();

    // Read data from travelers_data.csv, using AVL and Linked List
    read_travelers_data_pair2("travelers_data.csv", &tree);
    //inorder_AVL_traversal(tree.root);

    // Stop measuring time
    clock_t end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to read and structure data: %f seconds\n", cpu_time_used);
    
    Tree_height = tree_height_AVL(tree.root);
    printf("Height of the tree is: %d\n", Tree_height);
    printf("Number of rotations during structuring: %d\n", tree.rotation_count);

    while (choice != 6) {
        printf("\nPassport Database Operations (AVL)\n");
        printf("1. Search for a Passport Details by Passport Number\n");
        printf("2. Display Passport History\n");
        printf("3. Find Passport Records by Nationality\n");
        printf("4. Add a Passport to the Record\n");
        printf("5. Delete a Passport from the Record\n");
        printf("6. Exit Database.\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid choice. Please enter a number from 1 to 5.\n");
            while (getchar() != '\n');
            continue; // For restarting
        }
        
        switch (choice) {
        case 1:
            search_passport_by_number_pair2(&tree);
            break;
        case 2:
            display_passport_history_pair2(&tree);
            break;
        case 3:
            find_passports_by_nationality_pair2(&tree);
            break;
        case 4:
            add_passport_record_pair2(&tree);
            break;
        case 5:
            //printf("Current root node: %s\n", tree.root->passport_number);
            delete_passport_record_pair2(&tree);
            //inorder_AVL_traversal(tree.root);
            break;
        case 6:
            printf("Exiting Database . . . \n\n");
            break;
        default:
            printf("Invalid choice. Please enter a number from 1 to 5.\n");
            break;
        }
    }

    // Free memory allocated for AVL
    free_AVL_tree(tree.root);
}


int main() {
    int choice;

    while (1) {
        printf("--- Select Database Type ---\n");
        printf("1. BST and Linked List Database\n");
        printf("2. AVL and Array Database\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid choice. Please enter 1 or 2.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
        case 1:
            Database_BST();
            break;
        case 2:
            Database_AVL();
            break;
        case 3:
            printf("Exiting program...\n");
            return 0;
        default:
            printf("Invalid choice. Please enter 1 or 2.\n");
            break;
        }
    }

    return 0;
}