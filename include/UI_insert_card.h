#ifndef UI_INSERT_CARD_H
#define UI_INSERT_CARD_H

#include "colorSet.h"

using namespace std;

class UI_insert_card
{
public:
    void welcome();
    void input_card_number();
    void input_password();
    void error_account();
    void error_password(const int timesLeft);
    void card_locked();
};

#endif