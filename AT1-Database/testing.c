#include <stdio.h>
#include "passport_BST.h"
#include "passport_AVL.h"
#include "country.h"

void test_bst_operations() {
    struct PassportNode* root = NULL;

    // Insert some passport nodes
    struct PassportNode* passport1 = init_passport("A38223", "John", "Doe", "USA", "1990-01-01", "Tourism", "Tourist");
    insert_country_node(&(passport1->countries_visited), "Canada", 3);
    insert_passport_node(&root, passport1);

    struct PassportNode* passport2 = init_passport("D422456", "Alice", "Smith", "UK", "1985-05-15", "Business", "Business");
    insert_country_node(&(passport2->countries_visited), "France", 2);
    insert_passport_node(&root, passport2);

    struct PassportNode* passport3 = init_passport("G431789", "Bob", "Johnson", "Canada", "1978-09-20", "Study", "Student");
    insert_country_node(&(passport3->countries_visited), "Germany", 1);
    insert_passport_node(&root, passport3);

    struct PassportNode* passport4 = init_passport("B38223", "John", "Doe", "USA", "1990-01-01", "Tourism", "Tourist");
    insert_country_node(&(passport4->countries_visited), "Australia", 3);
    insert_country_node(&(passport4->countries_visited), "Argentina", 2); // Inserting another country with smaller alphabet
    insert_passport_node(&root, passport4);


    // Print the inorder traversal of the BST
    printf("Inorder traversal of BST:\n");
    inorder_passport_traversal(root);

    // Free memory allocated for the BST
    free_passport_tree(root);
}

void test_linked_list_operations() {
    // Create a linked list
    struct CountryNode* head = NULL;

    // Insert some countries into the linked list for separate testing
    insert_country_node(&head, "France", 2);
    insert_country_node(&head, "Germany", 1);
    insert_country_node(&head, "Canada", 3);

    // Print the sorted countries with number of visits
    printf("Sorted countries with number of visits:\n");
    struct CountryNode* current = head;
    while (current != NULL) {
        printf("%s - Visits: %d\n", current->country, current->numVisits);
        current = current->next;
    }

    // Free memory allocated for the linked list
    free_country_list(head);
}

void test_AVL_operations() {
    struct AVLNode* root = NULL;

    struct AVLNode* passport1 = init_AVL_node("D10101", "John", "Doe", "USA", "1990-01-01", "Tourism", "Tourist");
    insert_country_node(&(passport1->countries_visited), "Canada", 3);
    root = insert_AVL_node(root, passport1);

    struct AVLNode* passport2 = init_AVL_node("A422456", "Kayla", "Smith", "UK", "1985-05-15", "Business", "Business");
    insert_country_node(&(passport2->countries_visited), "France", 2);
    root = insert_AVL_node(root, passport2);

    struct AVLNode* passport3 = init_AVL_node("C431789", "Bob", "Johnson", "Canada", "1978-09-20", "Study", "Student");
    insert_country_node(&(passport3->countries_visited), "Germany", 1);
    root = insert_AVL_node(root, passport3);

    struct AVLNode* passport4 = init_AVL_node("X38223", "John", "Doe", "USA", "1990-01-01", "Tourism", "Tourist");
    insert_country_node(&(passport4->countries_visited), "Australia", 3);
    insert_country_node(&(passport4->countries_visited), "Argentina", 2); // Inserting another country with smaller alphabet
    root = insert_AVL_node(root, passport4);

    printf("Inorder traversal of AVL tree:\n");
    inorder_AVL_traversal(root);

    free_AVL_tree(root);
}