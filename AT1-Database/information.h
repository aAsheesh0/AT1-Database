#ifndef INFORMATION_H
#define INFORMATION_H

#include "passport.h"

void search_passport_by_number(struct PassportNode* root);
void find_passports_by_nationality(struct PassportNode* root);
void add_passport_record(struct PassportNode** root);
void display_passport_history(struct PassportNode* root);

#endif