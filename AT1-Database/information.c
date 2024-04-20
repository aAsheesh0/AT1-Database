#define _CRT_SECURE_NO_WARNINGS
#include "information.h"
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