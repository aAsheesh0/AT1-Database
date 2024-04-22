#define _CRT_SECURE_NO_WARNINGS
#include "information.h"
#include "passport_AVL.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void search_passport_by_number_pair1(PassportBST tree) {
    char passportNumber[20];
    printf("\nEnter passport number to search for: ");
    scanf("%s", passportNumber);

    while (tree.root != NULL) {
        int comparisonResult = strcmp(passportNumber, tree.root->passport_number);
        if (comparisonResult == 0) {
            printf("Valid Passport!\n");
            printf("Passport Number: %s\n", tree.root->passport_number);
            printf("First Name: %s\n", tree.root->first_name);
            printf("Last Name: %s\n", tree.root->last_name);
            printf("Nationality: %s\n", tree.root->nationality);
            printf("Date of Birth: %s\n", tree.root->date_of_birth);

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

void search_passport_by_number_pair2(PassportAVL* tree) {
    if (tree == NULL || tree->root == NULL) {
        printf("Passport database is empty.\n");
        return;
    }

    char passportNumber[20];
    printf("\nEnter passport number to search for: ");
    scanf("%s", passportNumber);

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

    start = clock();
    insert_passport_node(tree, new_passport);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to add passport record: %f seconds.\n", cpu_time_used);
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

    start = clock();
    insert_AVL_node(tree, new_passport);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to add passport record to AVL: %.30f seconds.\n", cpu_time_used);
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
    
    if (node_to_delete->left == NULL && node_to_delete->right == NULL) {
        delete_node_BST(tree, node_to_delete);
        printf("Record with Passport number %s deleted successfully 1!\n", passport_number);
    }
    else if (node_to_delete->left == NULL || node_to_delete->right == NULL) {
        delete_node_with_one_child_BST(tree, node_to_delete);
        printf("Record with Passport number %s deleted successfully 2!\n", passport_number);
    }
    else {
        PassportNodePtr successor = find_inorder_successor_BST(tree->root,node_to_delete);

        copy_passport_data_BST(node_to_delete, successor);

        // Checking if successor has children
        if ((successor->left != NULL && successor->right == NULL) || (successor->left == NULL && successor->right != NULL)) {
            delete_node_with_one_child_BST(tree, successor);
        }
        else {
            delete_node_BST(tree, successor);
        }
        printf("Record with Passport number %s deleted successfully 3!\n", passport_number);
    }
}

void delete_node_BST(PassportBST* tree, PassportNodePtr node) {
    if (node == NULL) {
        return;
    }

    if (node == tree->root) {
        if (tree->root->left == NULL && tree->root->right == NULL) {
            free(tree->root);
            tree->root = NULL;
        }
        else if (tree->root->left == NULL) {
            PassportNodePtr temp = tree->root;
            tree->root = tree->root->right;
            free(temp);
        }
        else if (tree->root->right == NULL) {
            PassportNodePtr temp = tree->root;
            tree->root = tree->root->left;
            free(temp);
        }
    }
    else {
        PassportNodePtr parent = find_parent_BST(tree->root, node->passport_number);
        if (parent != NULL) {
            if (parent->left == node) {
                parent->left = NULL;
            }
            else {
                parent->right = NULL;
            }
            free(node);
        }
    }
}

void delete_node_with_one_child_BST(PassportBST* tree, PassportNodePtr node) {
    if (node == NULL) {
        return;
    }

    PassportNodePtr child = (node->left != NULL) ? node->left : node->right;

    if (node == tree->root) {
        tree->root = child;
    }
    else {
        PassportNodePtr parent = find_parent_BST(tree->root, node->passport_number);
        if (parent != NULL) {
            if (parent->left == node) {
                parent->left = child;
            }
            else {
                parent->right = child;
            }
        }
    }
    free(node);
}

PassportNodePtr find_parent_BST(PassportNodePtr root, char passport_number[]) {
    if (root == NULL || (root->left == NULL && root->right == NULL)) {
        return NULL;
    }
    
    if ((root->left != NULL && strcmp(root->left->passport_number, passport_number) == 0) ||
        (root->right != NULL && strcmp(root->right->passport_number, passport_number) == 0)) {
        return root;
    }

    PassportNodePtr parent = find_parent_BST(root->left, passport_number);
    if (parent == NULL) {
        parent = find_parent_BST(root->right, passport_number);
    }
    return parent;
}

PassportNodePtr find_inorder_successor_BST(PassportNodePtr root, PassportNodePtr node) {
    PassportNodePtr successor = node->right;

    if (node->right != NULL) {
        successor = node->right;
        while (successor->left != NULL) {
            successor = successor->left;
        }
        printf("Successor is: %s\n", successor->passport_number);
        return successor;
    }

    while (root != NULL) {
        if (strcmp(node->passport_number, root->passport_number) < 0) {
            successor = root;
            root = root->left;
        }
        else if (strcmp(node->passport_number, root->passport_number) > 0) {
            root = root->right;
        }
        else {
            if (root->right != NULL) {
                successor = root->right;
                while (successor->left != NULL) {
                    successor = successor->left;
                }
            }
        }
        break;
    }
    printf("Successor is: %s\n", successor->passport_number);
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

    if (node_to_delete->left == NULL && node_to_delete->right == NULL) {
        delete_node_AVL(tree, node_to_delete);
        printf("Record with Passport number %s deleted successfully 1!\n", passport_number);
    }
    else if (node_to_delete->left == NULL || node_to_delete->right == NULL) {
        delete_node_with_one_child_AVL(tree, node_to_delete);
        printf("Record with Passport number %s deleted successfully 2!\n", passport_number);
    }
    else {
        AVLNodePtr successor = find_inorder_successor_AVL(tree->root, node_to_delete);

        copy_passport_data_AVL(node_to_delete, successor);

        // Checking if successor has children
        if ((successor->left != NULL && successor->right == NULL) || (successor->left == NULL && successor->right != NULL)) {
            delete_node_with_one_child_AVL(tree, successor);
        }
        else {
            delete_node_AVL(tree, successor);
        }
        printf("Record with Passport number %s deleted successfully 3!\n", passport_number);
    }
}

void delete_node_AVL(PassportAVL* tree, AVLNodePtr node) {
    if (node == NULL) {
        return;
    }
    
    if (node == tree->root) {
        if (tree->root->left == NULL && tree->root->right == NULL) {
            free(tree->root);
            tree->root = NULL;
        }
        else if (tree->root->left == NULL) {
            AVLNodePtr temp = tree->root;
            tree->root = tree->root->right;
            free(temp);
        }
        else if (tree->root->right == NULL) {
            AVLNodePtr temp = tree->root;
            tree->root = tree->root->left;
            free(temp);
        }
        balance_tree_check(tree, NULL);
    }
    else {
        AVLNodePtr parent = find_parent_AVL(tree->root, node->passport_number);
        if (parent != NULL) {
            if (parent->left == node) {
                parent->left = NULL;
            }
            else {
                parent->right = NULL;
            }
            balance_tree_check(tree, node);
            free(node);
        }
    }
}

void delete_node_with_one_child_AVL(PassportAVL* tree, AVLNodePtr node) {
    if (node == NULL) {
        return;
    }

    AVLNodePtr child = (node->left != NULL) ? node->left : node->right;

    if (node == tree->root) {
        tree->root = child;
    }
    else {
        AVLNodePtr parent = find_parent_AVL(tree->root, node->passport_number);
        if (parent != NULL) {
            if (parent->left == node) {
                parent->left = child;
            }
            else {
                parent->right = child;
            }
            balance_tree_check(tree, node);
        }
    }
    free(node);
}

AVLNodePtr find_parent_AVL(AVLNodePtr root, char passport_number[]) {
    if (root == NULL || (root->left == NULL && root->right == NULL)) {
        return NULL;
    }

    if ((root->left != NULL && strcmp(root->left->passport_number, passport_number) == 0) ||
        (root->right != NULL && strcmp(root->right->passport_number, passport_number) == 0)) {
        return root;
    }

    AVLNodePtr parent = find_parent_AVL(root->left, passport_number);
    if (parent == NULL) {
        parent = find_parent_AVL(root->right, passport_number);
    }

    return parent;
}

AVLNodePtr find_inorder_successor_AVL(AVLNodePtr root) {
    AVLNodePtr current = root;

    // Go to the leftmost node in the right subtree
    while (current != NULL && current->left != NULL) {
        current = current->left;
    }

    return current;
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

void balance_tree_check(PassportAVL* tree, AVLNodePtr root) {
    if (tree == NULL || root == NULL) {
        return;
    }

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = get_balance(root);
    // If the node becomes unbalanced, perform rotations
    if (balance > 1) {
        if (get_balance(root->left) >= 0) {
            // Left Left Case
            printf("Left Left Case\n");
            root = rotate_right(root, tree);
        }
        else {
            // Left Right Case
            printf("Left Right Case\n");
            root->left = rotate_left(root->left, tree);
            root = rotate_right(root, tree);
        }
    }
    else if (balance < -1) {
        if (get_balance(root->right) <= 0) {
            // Right Right Case
            printf("Right Right Case\n");
            root = rotate_left(root, tree);
        }
        else {
            // Right Left Case
            printf("Right Left Case\n");
            root->right = rotate_right(root->right, tree);
            root = rotate_left(root, tree);
        }
    }

    if (root == tree->root) {
        tree->root = root;
    }
}