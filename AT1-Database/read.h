#ifndef READ_H
#define READ_H
#include "passport_BST.h"
#include "passport_AVL.h"
#include "country_ARRAY.h"
#include "country_LIST.h"

// Function declaration
void read_travelers_data_pair1(const char* filename, PassportBST* tree);
void read_travelers_data_pair2(const char* filename, PassportAVL* tree);

#endif