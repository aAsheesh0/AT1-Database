#ifndef INFORMATION_H
#define INFORMATION_H

#include "passport_BST.h"
#include "passport_AVL.h"

void search_passport_by_number_pair1(PassportBST tree);
void search_passport_by_number_pair2(PassportAVL* tree);
void find_passports_by_nationality_pair1(PassportBST tree);
void find_passports_by_nationality_pair2(PassportAVL* tree);
void add_passport_record_pair1(PassportBST* tree);
void add_passport_record_pair2(PassportAVL* tree);
void display_passport_history_pair1(PassportBST tree);
void display_passport_history_pair2(PassportAVL* tree);

#endif