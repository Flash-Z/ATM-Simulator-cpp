#include <iostream>

#include "../../include/UI_changePSW.h"
#include "../../include/colorSet.h"

using namespace std;

void UI_changePSW::change_PSW_init()
{
    system("cls");
    cout << YELLOW << "\n更改密码：\n请输入新密码或输入0返回：" << RESET << flush;
}

void UI_changePSW::PSW_confirm()
{
    cout << YELLOW << "请再次输入新密码：" << RESET << flush;
}

void UI_changePSW::newPSW_error()
{
    cout << RED << "新密码格式错误！\n密码只能包含6位数字\n"
         << RESET;
}

void UI_changePSW::second_error()
{
    cout << RED << "两次密码输入不匹配！\n"
         << RESET << flush;
}

void UI_changePSW::PSW_change_succeeded()
{
    cout << GREEN << "密码修改成功！\n"
         << RESET;
}