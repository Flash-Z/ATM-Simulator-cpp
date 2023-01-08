#include <iostream>

#include "../../include/UI_insert_card.h"
#include "../../include/colorSet.h"

using namespace std;

void UI_insert_card::welcome()
{
    system("cls");
    cout << YELLOW << "\n"
         << "**********************************\n"
         << "*      欢迎使用xxx银行ATM机      *\n"
         << "*      请输入您的卡号和密码      *\n"
         << "*           或输入0返回          *\n"
         << "**********************************" << RESET << endl;
}

void UI_insert_card::input_card_number()
{
    cout << YELLOW << "卡号: " << RESET << flush;
}

void UI_insert_card::input_password()
{
    cout << YELLOW << "密码: " << RESET << flush;
}

void UI_insert_card::error_account()
{
    cout << RED << "未找到该卡号，请重新输入！" << RESET << endl;
}

void UI_insert_card::error_password(const int timesLeft)
{
    cout << RED
         << "密码错误！\n"
         << "剩余 " << timesLeft << " 次尝试机会\n"
         << "之后您的银行卡将被锁定" << RESET << endl;
}

void UI_insert_card::card_locked()
{
    cout << RED
         << "您的银行卡已被锁定\n"
         << "请联系银行工作人员处理" << RESET << endl;
}