#include <iostream>

#include "../../include/UI_inquiry.h"
#include "../../include/colorSet.h"

using namespace std;

void UI_inquiry::run(double balance)
{
    system("cls");
    cout << YELLOW << "\n您的账户余额为：" << balance << " 元。" << RESET << endl;
}