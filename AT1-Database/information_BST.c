#define _CRT_SECURE_NO_WARNINGS
#include "information.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Functions implementation for the PAIR-1: BST and Linked List
// 1. Retrieving a passport details by its number
// 2. Retrieving history of a passport holder i.e. countries visited and number of times and also purpose of visit
// 3. Finding all the passports in the dataset containing that nationality
// 4. Adding a passport into the structure with all the fields
// 5. Deleting a passport and its history from the structure

void search_passport_by_number_pair1(PassportBST tree) {
    char passportNumber[20];
    printf("\nEnter passport number to search for: ");
    scanf("%s", passportNumber);

    //clock_t start = clock();

    while (tree.root != NULL) {
        int comparisonResult = strcmp(passportNumber, tree.root->passport_number);
        if (comparisonResult == 0) {
            printf("Valid Passport!\n");
            printf("Passport Number: %s\n", tree.root->passport_number);
            printf("First Name: %s\n", tree.root->first_name);
            printf("Last Name: %s\n", tree.root->last_name);
            printf("Nationality: %s\n", tree.root->nationality);
            printf("Date of Birth: %s\n", tree.root->date_of_birth);

            //clock_t end = clock();
            //double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
            //printf("Time taken: %.1000lf seconds\n", time_taken);

            return;
        }
        else if (comparisonResult < 0) {
            tree.root = tree.root->left;
        }
        else {
            tree.root = tree.root->right;
        }
    }
    printf("Passport not found.\n");
}

void find_passports_by_nationality_pair1(PassportBST tree) {
    char nationality[100];
    printf("\nEnter nationality to search for: ");
    scanf(" %[^\n]", nationality);

    if (tree.root == NULL) {
        printf("No passport records found.\n");
        return;
    }

    int found = 0;

    PassportNodePtr stack[100];
    int top = -1;
    PassportNodePtr current = tree.root;

    while (current != NULL || top != -1) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }

        current = stack[top--];

        if (strcmp(current->nationality, nationality) == 0) {
            printf("Passport Number: %s\n", current->passport_number);
            found = 1;
        }

        current = current->right;
    }

    if (!found) {
        printf("No passport records found for nationality: %s\n", nationality);
    }
}

void add_passport_record_pair1(PassportBST* tree) {
    char passport_number[20];
    char first_name[50];
    char last_name[50];
    char nationality[100];
    char date_of_birth[20];
    char purpose_of_visit[100];
    char visa_type[50];
    char country[50];
    int num_visits;
    clock_t start, end;
    double cpu_time_used;

    // Prompt the user to enter passport details
    printf("\nEnter new passport number: ");
    scanf("%s", passport_number);

    printf("Enter first name: ");
    scanf("%s", first_name);

    printf("Enter last name: ");
    scanf("%s", last_name);

    printf("Enter nationality: ");
    scanf("%s", nationality);

    printf("Enter date of birth (YYYY-MM-DD): ");
    scanf("%s", date_of_birth);

    printf("Enter usual purpose of visit: ");
    scanf("%s", purpose_of_visit);

    printf("Enter visa type: ");
    scanf("%s", visa_type);

    // Create a new passport node
    PassportNodePtr new_passport = init_passport(passport_number, first_name, last_name, nationality,
        date_of_birth, purpose_of_visit, visa_type);

    while (1) {
        printf("Enter country visited: ");
        scanf("%s", country);
        printf("Enter number of visits: ");
        scanf("%d", &num_visits);

        insert_country_node(&(new_passport->countries_visited), country, num_visits);
        
        printf("Do you want to add another country? (y/n): ");
        char choice;
        scanf(" %c", &choice);
        if (choice != 'y' && choice != 'Y') {
            break;
        }
    }

    //start = clock();
    insert_passport_node(tree, new_passport);
    //end = clock();
    //cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    //printf("Time taken to add passport record: %f seconds.\n", cpu_time_used);
}

void display_passport_history_pair1(PassportBST tree) {
    char passport_number[20];
    printf("\nEnter passport number to see the history: ");
    scanf("%s", passport_number);

    //clock_t start, end;
    //double total_time = 0.0;
    //int num_repetitions = 100;

    //for (int i = 0; i < num_repetitions; i++) {
        //start = clock(); // Start measuring time

        PassportNodePtr passport = search_passport_node(tree.root, passport_number);

        //end = clock(); // Stop measuring time
        //double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
        //total_time += time_taken;
        if (passport == NULL) {
            printf("Passport with number %s not found.\n", passport_number);
            return;
        }

        printf("Passportholder visits on %s visa:\n", passport->visa_type);
        printf("\n| Country      | Number of Visits |\n");
        printf("|--------------|------------------|\n");

        struct CountryNode* country_ptr = passport->countries_visited;
        while (country_ptr != NULL) {
            printf("| %-12s | %-16d |\n", country_ptr->country, country_ptr->num_visits);
            country_ptr = country_ptr->next;
        }
        printf("\n");
    //}

    //double average_time = total_time / num_repetitions;
    //printf("Average time taken for BST search: %f seconds\n", average_time);
}


void delete_passport_record_pair1(PassportBST* tree) {
    char passport_number[20];
    printf("Enter the Passport number to Delete: ");
    scanf("%s", passport_number);

    if (tree == NULL || tree->root == NULL) {
        printf("Tree is Empty!\n");
        return;
    }

    PassportNodePtr node_to_delete = search_passport_node(tree->root, passport_number);

    if (node_to_delete == NULL) {
        printf("No Record with %s number found to Delete!\n", passport_number);
        return;
    }
    
    // Case1: Leaf node to be deleted
    if (node_to_delete->left == NULL && node_to_delete->right == NULL) {
        delete_leaf_node_BST(tree, node_to_delete);
        printf("Record with Passport number %s deleted successfully!\n", passport_number);
    }
    // Case2: Node with one child to be deleted
    else if (node_to_delete->left == NULL || node_to_delete->right == NULL) {
        delete_node_with_one_child_BST(tree, node_to_delete);
        printf("Record with Passport number %s deleted successfully!\n", passport_number);
    }
    // Case3: Node with two child to be deleted
    else {
        delete_node_with_two_child_BST(tree, node_to_delete);
        printf("Record with Passport number %s deleted successfully!\n", passport_number);
    }
}

void delete_leaf_node_BST(PassportBST* tree, PassportNodePtr node) {
    PassportNodePtr parent = find_parent_BST(tree->root, node);

    if (parent != NULL) {
        if (parent->left == node) {
            parent->left = NULL;
        }
        else {
            parent->right = NULL;
        }
    }
    else {
        free(node);
        tree->root = NULL;
    }
}

void delete_node_with_one_child_BST(PassportBST* tree, PassportNodePtr node) {
    PassportNodePtr parent = find_parent_BST(tree->root, node);
    PassportNodePtr child = (node->left != NULL) ? node->left : node->right;

    if (parent==NULL) {
        tree->root = child;
    }
    else {
        if (parent->left == node) {
            //printf("\nParent is: %s\n", parent->passport_number);
            //printf("Child is: %s\n\n", child->passport_number);
            parent->left = child;
        }
        else {
            //printf("\nParent is: %s\n", parent->passport_number);
            //printf("\Child is: %s\n", child->passport_number);
            parent->right = child;
        }
    }
    free(node);
}

void delete_node_with_two_child_BST(PassportBST* tree, PassportNodePtr node) {
    PassportNodePtr successor = find_inorder_successor_BST(tree->root, node);
    PassportNodePtr parent = find_parent_BST(tree->root, successor);

    copy_passport_data_BST(node, successor);
    if (successor->left == NULL && successor->right == NULL) {
        delete_leaf_node_BST(tree, successor);
    }
    else {
        delete_node_with_one_child_BST(tree, successor);
    }
}

PassportNodePtr find_parent_BST(PassportNodePtr root, PassportNodePtr node) {
    if (root == NULL || (root == node)) {
        return NULL;
    }
    
    if ((root->left == node)||(root->right == node)) {
        return root;
    }

    PassportNodePtr left_parent = find_parent_BST(root->left, node);
    PassportNodePtr right_parent = find_parent_BST(root->right, node);

    return (left_parent != NULL) ? left_parent : right_parent;
}

PassportNodePtr find_inorder_successor_BST(PassportNodePtr root, PassportNodePtr node) {
    if (root == NULL || node == NULL) {
        return NULL;
    }
    PassportNodePtr successor = NULL;

    if (node->right != NULL) {
        successor = node->right;
        while (successor->left != NULL) {
            successor = successor->left;
        }
    }
    else {
        PassportNodePtr current = root;
        while (current != NULL) {
            if (node->passport_number < current->passport_number) {
                successor = current;
                current = current->left;
            }
            else if (node->passport_number > current->passport_number) {
                current = current->right;
            }
            else {
                break;
            }
        }
    }
    //printf("Successor is: %s\n", successor->passport_number);
    return successor;
}

void copy_passport_data_BST(PassportNodePtr destination, PassportNodePtr source) {
    if (destination == NULL || source == NULL) {
        return;
    }

    strcpy(destination->passport_number, source->passport_number);
    strcpy(destination->first_name, source->first_name);
    strcpy(destination->last_name, source->last_name);
    strcpy(destination->nationality, source->nationality);
    strcpy(destination->date_of_birth, source->date_of_birth);
    strcpy(destination->purpose_of_visit, source->purpose_of_visit);
    strcpy(destination->visa_type, source->visa_type);

    destination->countries_visited = source->countries_visited;
}

void count_nodes_BST(PassportNodePtr root, int* total, int* left, int* right) {
    if (root == NULL) {
        return;
    }

    (*total)++;

    count_nodes_BST(root->left, total, left, right);

    count_nodes_BST(root->right, total, left, right);

    if (root->left != NULL) {
        (*left)++;
    }
    if (root->right != NULL) {
        (*right)++;
    }
}