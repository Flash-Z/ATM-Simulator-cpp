#ifndef UI_WELCOME_H
#define UI_WELCOME_H

#include "colorSet.h"

using namespace std;

class UI_welcome
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