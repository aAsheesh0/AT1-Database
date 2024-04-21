#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "read.h"
#include "information.h"

int main() {
    PassportNodePtr root = NULL;
    PassportBST tree = { root };
    //PassportAVL tree = { NULL , 0};
    
    int choice = 0;
    double cpu_time_used;
    int Tree_height;

    // Performs BST operations testing
    printf("Testing Binary Search Tree (BST) operations:\n");
    test_bst_operations();

    // Performs linked list operations testing
    printf("\nTesting Linked List operations:\n");
    test_linked_list_operations();

    // Performs AVL rotations testing
    //printf("\nTesting AVL rotations:\n");
    /*test_AVL_rotations();

    // Performs AVL operations testing
    printf("\nTesting AVL operations:\n");
    test_AVL_operations();

    // Performs Array operations testing
    printf("\nTesting Array operations:\n");
    test_array_operations();*/

    // Start measuring time
    clock_t start = clock();

    // Read data from travelers_data.csv, using BST and Linked List
    read_travelers_data_pair1("travelers_data.csv", &tree);
    //inorder_passport_traversal(tree.root);

    // Read data from travelers_data.csv, using AVL and Linked List
    //read_travelers_data_pair2("travelers_data.csv", &tree);

    // Stop measuring time
    clock_t end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to read and structure data: %f seconds\n", cpu_time_used);
    
    Tree_height = tree_height_BST(tree.root);
    //Tree_height = tree_height_AVL(tree.root);
    printf("Height of the tree is: %d\n", Tree_height);
    //printf("Number of rotations during structuring: %d\n", tree.rotation_count);

    while (choice != 6) {
        printf("\nPassport Database Operations\n");
        printf("1. Search for a Passport Details by Passport Number\n");
        printf("2. Display Passport History\n");
        printf("3. Find Passport Records by Nationality\n");
        printf("4. Add a Passport to the Record\n");
        printf("5. Delete a Passport from the Record\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid choice. Please enter a number from 1 to 5.\n");
            while (getchar() != '\n');
            continue; // For restarting
        }
        
        switch (choice) {
        case 1:
            search_passport_by_number_pair1(tree);
            //search_passport_by_number_pair2(&tree);
            break;
        case 2:
            display_passport_history_pair1(tree);
            //display_passport_history_pair2(&tree);
            break;
        case 3:
            find_passports_by_nationality_pair1(tree);
            //find_passports_by_nationality_pair2(&tree);
            break;
        case 4:
            add_passport_record_pair1(&tree);
            //add_passport_record_pair2(&tree);
            break;
        case 5:
            delete_passport_record_pair1(&tree);
            break;
        case 6:
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid choice. Please enter a number from 1 to 5.\n");
            break;
        }
    }

    // Free memory allocated for BST
    free_passport_tree(tree.root);
    // Free memory allocated for AVL
    //free_AVL_tree(tree.root);

    return 0;
}