#include <iostream>

#include "../../include/UI_deposit.h"
#include "../../include/colorSet.h"

using namespace std;

void UI_deposit::deposit_init()
{
    system("cls");
    cout << YELLOW << "\n存款:\n请输入存款金额(100的整数倍)或输入0返回：" << RESET << flush;
}

void UI_deposit::amount_not_supported()
{
    cout << RED << "存款金额应为100的正整数倍！"
         << RESET << endl;
}

void UI_deposit::deposit_succeeded()
{
    cout << GREEN << "存款成功！"
         << RESET << endl;
}