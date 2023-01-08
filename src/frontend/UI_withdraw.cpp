#include <iostream>

#include "../../include/UI_withdraw.h"
#include "../../include/colorSet.h"

using namespace std;

void UI_withdraw::withdraw_init()
{
    system("cls");
    cout << YELLOW << "\n取款:\n请输入取款金额(100的整数倍)或输入0返回：" << RESET << flush;
}

void UI_withdraw::insufficient_balance()
{
    cout << RED << "余额不足！"
         << RESET << endl;
}

void UI_withdraw::amount_dily_limited(const double amount)
{
    cout << RED
         << "单日最大取款金额受限！"
         << "您今日还可以取款 " << RESET << GREEN << amount << RESET << RED << " 元"
         << RESET << endl;
}

void UI_withdraw::amount_not_supported()
{
    cout << RED << "取款金额应为100的正整数倍！"
         << RESET << endl;
}

void UI_withdraw::withdraw_succeeded()
{
    cout << GREEN << "取款成功！"
         << RESET << endl;
}

void UI_withdraw::single_time_limited(const long long singleAmount)
{
    cout << RED << "单次最大取款金额受限！\n您最多可每次取款 " << singleAmount << " 元" << RESET << endl;
}