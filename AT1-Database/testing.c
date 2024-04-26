#include <stdio.h>
#include "passport_BST.h"
#include "passport_AVL.h"
#include "country_LIST.h"
#include "country_ARRAY.h"

/* Some Hard-coded Testing operations used */

void test_bst_operations() {
    PassportBST tree = { NULL };

    // Insert some passport nodes
    PassportNodePtr passport1 = init_passport("A38223", "John", "Doe", "USA", "1990-01-01", "Tourism", "Tourist");
    insert_country_node(&(passport1->countries_visited), "Canada", 3);
    insert_passport_node(&tree, passport1);

    PassportNodePtr passport2 = init_passport("D422456", "Alice", "Smith", "UK", "1985-05-15", "Business", "Business");
    insert_country_node(&(passport2->countries_visited), "France", 2);
    insert_passport_node(&tree, passport2);

    PassportNodePtr passport3 = init_passport("G431789", "Bob", "Johnson", "Canada", "1978-09-20", "Study", "Student");
    insert_country_node(&(passport3->countries_visited), "Germany", 1);
    insert_passport_node(&tree, passport3);

    PassportNodePtr passport4 = init_passport("B38223", "John", "Doe", "USA", "1990-01-01", "Tourism", "Tourist");
    insert_country_node(&(passport4->countries_visited), "Thailand", 3);
    insert_country_node(&(passport4->countries_visited), "Argentina", 2); // Inserting another country with smaller alphabet
    insert_passport_node(&tree, passport4);


    // Print the inorder traversal of the BST
    printf("Inorder traversal of BST:\n");
    inorder_passport_traversal(tree.root);

    // Free memory allocated for the BST
    free_passport_tree(tree.root);
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
        printf("%s - Visits: %d\n", current->country, current->num_visits);
        current = current->next;
    }

    // Free memory allocated for the linked list
    free_country_list(head);
}

void test_AVL_operations() {
    PassportAVL tree = { NULL };

    AVLNodePtr passport1 = init_AVL_node("F10101", "John", "Doe", "USA", "1990-01-01", "Tourism", "Tourist");
    insert_country_array(&(passport1->countries_visited), "Canada", 3);
    insert_AVL_node(&tree, passport1);

    AVLNodePtr passport2 = init_AVL_node("A10101", "Kayla", "Smith", "UK", "1985-05-15", "Business", "Business");
    insert_country_array(&(passport2->countries_visited), "France", 2);
    //insert_country_node(&(passport2->countries_visited), "France", 2);
    insert_AVL_node(&tree, passport2);

    AVLNodePtr passport3 = init_AVL_node("C431789", "Bob", "Johnson", "Canada", "1978-09-20", "Study", "Student");
    insert_country_array(&(passport3->countries_visited), "Germany", 1);
    //insert_country_node(&(passport3->countries_visited), "Germany", 1);
    insert_AVL_node(&tree, passport3);

    AVLNodePtr passport4 = init_AVL_node("E38223", "John", "Doe", "USA", "1990-01-01", "Tourism", "Tourist");
    insert_country_array(&(passport4->countries_visited), "India", 3);
    insert_country_array(&(passport4->countries_visited), "Australia", 2); // Inserting another country with smaller alphabet
    insert_country_array(&(passport4->countries_visited), "Argentina", 4); // Inserting another country with smaller alphabet
    //insert_country_node(&(passport4->countries_visited), "India", 3);
    //insert_country_node(&(passport4->countries_visited), "Australia", 2); // Inserting another country with smaller alphabet
    //insert_country_node(&(passport4->countries_visited), "Argentina", 4); // Inserting another country with smaller alphabet
    insert_AVL_node(&tree, passport4);

    AVLNodePtr passport5 = init_AVL_node("D431789", "Bob", "Johnson", "Canada", "1978-09-20", "Study", "Student");
    insert_country_array(&(passport5->countries_visited), "Germany", 1);
    //insert_country_node(&(passport5->countries_visited), "Germany", 1);
    insert_AVL_node(&tree, passport5);

    printf("Inorder traversal of AVL tree:\n");
    inorder_AVL_traversal(tree.root);

    free_AVL_tree(tree.root);
}

void test_AVL_rotations() {
    PassportAVL tree = { NULL };

    // Insert nodes into the AVL tree
    insert_AVL_node(&tree, init_AVL_node("A10101", "John", "Doe", "USA", "1990-01-01", "Tourism", "Tourist"));

    insert_AVL_node(&tree, init_AVL_node("B10101", "John", "Doe", "USA", "1990 - 01 - 01", "Tourism", "Tourist"));

    insert_AVL_node(&tree, init_AVL_node("C10101", "John", "Doe", "USA", "1990 - 01 - 01", "Tourism", "Tourist"));

    insert_AVL_node(&tree, init_AVL_node("D10101", "John", "Doe", "USA", "1990 - 01 - 01", "Tourism", "Tourist"));

    // Print the AVL tree after rotations
    printf("Inorder traversal of AVL tree after rotations:\n");
    inorder_AVL_traversal(tree.root);

    // Free memory allocated for the AVL tree
    free_AVL_tree(tree.root);
}

void test_array_operations() {
    struct CountryArray country_array;
    init_country_array(&country_array);

    // Insert into the array
    insert_country_array(&country_array, "France", 2);
    insert_country_array(&country_array, "Germany", 5);
    insert_country_array(&country_array, "Canada", 3);
    insert_country_array(&country_array, "USA", 1);
    insert_country_array(&country_array, "Australia", 2);

    // Testing the results.
    printf("Countries with number of visits (Array):\n");
    for (int i = 0; i < country_array.count; i++) {
        printf("%s - Visits: %d\n", country_array.countries[i], country_array.numVisits[i]);
    }
}