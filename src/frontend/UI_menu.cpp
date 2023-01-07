#include <iostream>

#include "../../include/UI_menu.h"
#include "../../include/colorSet.h"

using namespace std;

void UI_menu::menu()
{
    system("cls");
    cout << YELLOW << "\n"
         << "******************************\n"
         << "*  主菜单:                   *\n"
         << "*    1 - 查询余额            *\n"
         << "*    2 - 取款                *\n"
         << "*    3 - 存款                *\n"
         << "*    4 - 转账                *\n"
         << "*    5 - 修改密码            *\n"
         << "*    6 - 退卡                *\n"
         << "*    请输入对应数字进行操作  *\n"
         << "******************************" << RESET << endl;
}