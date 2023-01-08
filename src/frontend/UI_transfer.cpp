#include <iostream>

#include "../../include/UI_Transfer.h"
#include "../../include/colorSet.h"

using namespace std;

void UI_transfer::transfer_target()
{
    cout << YELLOW << "请输入您要转入的卡号：" << RESET << flush;
}

void UI_transfer::transfer_amount()
{
    system("cls");
    cout << YELLOW << "\n转账：\n请输入转账金额或输入0返回：" << RESET << flush;
}

void UI_transfer::transfer_confirm()
{
    cout << YELLOW << "请再次输入您要转入的卡号：" << RESET << flush;
}

void UI_transfer::transfer_account_error()
{
    cout << RED << "不存在此卡号！\n"<< RESET;
}

void UI_transfer::insufficient_balance()
{
    cout << RED << "余额不足！\n" << RESET;
}

void UI_transfer::transfer_succeeded()
{
    cout << GREEN << "转账成功！\n"<< RESET;
}

void UI_transfer::account_confirm_failure()
{
    cout << RED << "两次输入卡号不匹配！\n" << RESET;
}

void UI_transfer::amount_error()
{
    cout << RED << "请输入大于0且至多含两位小数的金额！\n" << RESET;
}

void UI_transfer::own_account()
{
    cout << RED << "不能转入您自己的账户！\n" << RESET;
}