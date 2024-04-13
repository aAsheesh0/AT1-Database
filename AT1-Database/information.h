#ifndef INFORMATION_H
#define INFORMATION_H

#include "passport_BST.h"
#include "passport_AVL.h"

void search_passport_by_number_pair1(struct PassportNode* root);
void search_passport_by_number_pair2(struct AVLNode* root);
void find_passports_by_nationality(struct PassportNode* root);
void add_passport_record_pair1(struct PassportNode** root);
void add_passport_record_pair2(struct AVLNode** root);
void display_passport_history_pair1(struct PassportNode* root);
void display_passport_history_pair2(struct AVLNode* root);

#endif