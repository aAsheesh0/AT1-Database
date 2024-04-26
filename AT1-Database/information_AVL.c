#define _CRT_SECURE_NO_WARNINGS
#include "information.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Functions implementation for the PAIR-2: AVL and Arrays
// 1. Retrieving a passport details by its number
// 2. Retrieving history of a passport holder i.e. countries visited and number of times and also purpose of visit
// 3. Finding all the passports in the dataset containing that nationality
// 4. Adding a passport into the structure with all the fields
// 5. Deleting a passport and its history from the structure and doing rotations if necessary

void search_passport_by_number_pair2(PassportAVL* tree) {
    if (tree == NULL || tree->root == NULL) {
        printf("Passport database is empty.\n");
        return;
    }

    char passportNumber[20];
    printf("\nEnter passport number to search for: ");
    scanf("%s", passportNumber);

    //clock_t start = clock();

    AVLNodePtr current_node = tree->root;
    while (current_node != NULL) {
        int comparison_result = strcmp(passportNumber, current_node->passport_number);
        if (comparison_result == 0) {
            printf("Valid Passport!\n");
            printf("Passport Number: %s\n", current_node->passport_number);
            printf("First Name: %s\n", current_node->first_name);
            printf("Last Name: %s\n", current_node->last_name);
            printf("Nationality: %s\n", current_node->nationality);
            printf("Date of Birth: %s\n", current_node->date_of_birth);

            //clock_t end = clock();
            //double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
            //printf("Time taken: %.1000lf seconds\n", time_taken);

            return;
        }
        else if (comparison_result < 0) {
            current_node = current_node->left;
        }
        else {
            current_node = current_node->right;
        }
    }
    printf("Passport not found.\n");
}

void find_passports_by_nationality_pair2(PassportAVL* tree) {
    if (tree == NULL || tree->root == NULL) {
        printf("No passport records found.\n");
        return;
    }

    char nationality[100];
    printf("\nEnter nationality to search for: ");
    scanf(" %[^\n]", nationality);

    int found = 0;

    AVLNodePtr stack[100];
    int top = -1;
    AVLNodePtr current = tree->root;

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

void add_passport_record_pair2(PassportAVL* tree) {
    if (tree == NULL) {
        printf("Error: Invalid AVL tree pointer.\n");
        return;
    }

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
    AVLNodePtr new_passport = init_AVL_node(passport_number, first_name, last_name, nationality,
        date_of_birth, purpose_of_visit, visa_type);

    while (1) {
        printf("Enter country visited: ");
        scanf("%s", country);
        printf("Enter number of visits: ");
        scanf("%d", &num_visits);

        insert_country_array(&(new_passport->countries_visited), country, num_visits);

        printf("Do you want to add another country? (y/n): ");
        char choice;
        scanf(" %c", &choice);
        if (choice != 'y' && choice != 'Y') {
            break;
        }
    }

    //start = clock();
    insert_AVL_node(tree, new_passport);
    //end = clock();
    //cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    //printf("Time taken to add passport record to AVL: %.30f seconds.\n", cpu_time_used);
}

void display_passport_history_pair2(PassportAVL* tree) {
    char passport_number[20];
    printf("\nEnter passport number to see the history: ");
    scanf("%s", passport_number);

    //clock_t start, end;
    //double total_time = 0.0;
    //int num_repetitions = 100;

    //for (int i = 0; i < num_repetitions; i++) {
        //start = clock(); // Start measuring time

    AVLNodePtr passport = search_AVL_node(tree->root, passport_number);

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

    for (int i = 0; i < passport->countries_visited.count; i++) {
        printf("| %-12s | %-16d |\n", passport->countries_visited.countries[i], passport->countries_visited.numVisits[i]);
    }
    printf("\n");
    //}

    //double average_time = total_time / num_repetitions;
    //printf("Average time taken for AVL search: %f seconds\n", average_time);
}

void delete_passport_record_pair2(PassportAVL* tree) {
    char passport_number[20];
    printf("Enter the Passport number to Delete: ");
    scanf("%s", passport_number);

    if (tree == NULL || tree->root == NULL) {
        printf("Tree is Empty!\n");
        return;
    }

    AVLNodePtr node_to_delete = search_AVL_node(tree->root, passport_number);

    if (node_to_delete == NULL) {
        printf("No Record with %s number found to Delete!\n", passport_number);
        return;
    }

    // Case1: Leaf node to be deleted
    if (node_to_delete->left == NULL && node_to_delete->right == NULL) {
        delete_leaf_node_AVL(tree, node_to_delete);
        printf("Record with Passport number %s deleted successfully!\n", passport_number);
    }
    // Case2: Node with one child to be deleted
    else if (node_to_delete->left == NULL || node_to_delete->right == NULL) {
        delete_node_with_one_child_AVL(tree, node_to_delete);
        printf("Record with Passport number %s deleted successfully!\n", passport_number);
    }
    // Case3: Node with two child to be deleted
    else {
        delete_node_with_two_child_AVL(tree, node_to_delete);
        printf("Record with Passport number %s deleted successfully!\n", passport_number);
    }
}

void delete_leaf_node_AVL(PassportAVL* tree, AVLNodePtr node) {
    AVLNodePtr parent = find_parent_AVL(tree->root, node);

    if (parent != NULL) {
        if (parent->left == node) {
            parent->left = NULL;
        }
        else {
            parent->right = NULL;
        }
        balance_tree_check(tree, &parent);
        parent = find_parent_AVL(tree->root, parent);
        while (parent != NULL) {
            balance_tree_check(tree, &parent);
            parent = find_parent_AVL(tree->root, parent);
        }
    }
    else {
        free(node);
        tree->root = NULL;
    }
    //free(node);
}

void delete_node_with_one_child_AVL(PassportAVL* tree, AVLNodePtr node) {
    AVLNodePtr parent = find_parent_AVL(tree->root, node);
    AVLNodePtr child = (node->left != NULL) ? node->left : node->right;

    if (parent == NULL) {
        tree->root = child;
    }
    else {
        if (parent->left == node) {
            parent->left = child;
        }
        else {
            parent->right = child;
        }
        balance_tree_check(tree, &parent);
        parent = find_parent_AVL(tree->root, parent);
        while (parent != NULL) {
            balance_tree_check(tree, &parent);
            parent = find_parent_AVL(tree->root, parent);
        }
    }
    free(node);
}

void delete_node_with_two_child_AVL(PassportAVL* tree, AVLNodePtr node) {
    AVLNodePtr successor = find_inorder_successor_AVL(tree->root, node);
    AVLNodePtr parent = find_parent_AVL(tree->root, successor);

    copy_passport_data_AVL(node, successor);
    if (successor->left == NULL && successor->right == NULL) {
        delete_leaf_node_AVL(tree, successor);
        balance_tree_check(tree, &parent);
        parent = find_parent_AVL(tree->root, parent);
        while (parent != NULL) {
            balance_tree_check(tree, &parent);
            parent = find_parent_AVL(tree->root, parent);
        }
    }
    else {
        delete_node_with_one_child_AVL(tree, successor);
        balance_tree_check(tree, &parent);
        parent = find_parent_AVL(tree->root, parent);
        while (parent != NULL) {
            balance_tree_check(tree, &parent);
            parent = find_parent_AVL(tree->root, parent);
        }
    }
}

AVLNodePtr find_parent_AVL(AVLNodePtr root, AVLNodePtr node) {
    if (root == NULL || (root == node)) {
        return NULL;
    }

    if ((root->left == node) || (root->right == node)) {
        return root;
    }

    AVLNodePtr left_parent = find_parent_AVL(root->left, node);
    AVLNodePtr right_parent = find_parent_AVL(root->right, node);

    return (left_parent != NULL) ? left_parent : right_parent;
}

AVLNodePtr find_inorder_successor_AVL(AVLNodePtr root, AVLNodePtr node) {
    if (root == NULL || node == NULL) {
        return NULL;
    }
    AVLNodePtr successor = NULL;

    if (node->right != NULL) {
        successor = node->right;
        while (successor->left != NULL) {
            successor = successor->left;
        }
    }
    else {
        AVLNodePtr current = root;
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

void copy_passport_data_AVL(AVLNodePtr destination, AVLNodePtr source) {
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

void balance_tree_check(PassportAVL* tree, AVLNodePtr* rootPtr) {
    if (tree == NULL || *rootPtr == NULL) {
        return;
    }
    AVLNodePtr root = *rootPtr;

    root->height = 1 + max(height(root->left), height(root->right));
    //printf("\nRotation Check!\n");
    //printf("Height is: %d\n", root->height);
   
    int balance = get_balance(root);
    //printf("Balance is: %d\n", balance);

    // If the node becomes unbalanced, perform rotations
    if (balance > 1) {
        if (get_balance(root->left) >= 0) {
            // Left Left Case
            //printf("Left Left Case\n");
            *rootPtr = rotate_right(root, tree);
        }
        else {
            // Left Right Case
            //printf("Left Right Case\n");
            root->left = rotate_left(root->left, tree);
            *rootPtr = rotate_right(root, tree);
        }
    }
    else if (balance < -1) {
        if (get_balance(root->right) <= 0) {
            // Right Right Case
            //printf("Right Right Case\n");
            *rootPtr = rotate_left(root, tree);
        }
        else {
            // Right Left Case
            //printf("Right Left Case\n");
            root->right = rotate_right(root->right, tree);
            *rootPtr = rotate_left(root, tree);
        }
    }

    AVLNodePtr parent = find_parent_AVL(tree->root, root);
    if (parent != NULL) {
        if (parent->left == root) {
            parent->left = *rootPtr;
        }
        else {
            parent->right = *rootPtr;
        }
    }
    else {
        tree->root = *rootPtr;
    }

    //printf("Current root node: %s\n", tree->root->passport_number);
}

void count_nodes_AVL(AVLNodePtr root, int* total, int* left, int* right) {
    if (root == NULL) {
        return;
    }

    (*total)++;

    count_nodes_AVL(root->left, total, left, right);

    count_nodes_AVL(root->right, total, left, right);

    if (root->left != NULL) {
        (*left)++;
    }
    if (root->right != NULL) {
        (*right)++;
    }
}
