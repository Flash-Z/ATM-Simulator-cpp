/************************************
*                                   *
*   APP: ATM Simulator              *
*   Version: 4.0                    *
*   Copyright ©️ Fri 07 2023 Aoxinag.*
*   All rights reserved.            *
*   Contact: 2643467090@qq.com      *
*                                   *
*************************************/

#include <iostream>
#include <windows.h>

#include "../include/ATM.h"

using namespace std;

int main()
{
    SetConsoleOutputCP(65001);
    // 记录用户是否登录
    bool is_logged_in = false;
    // 用户数据文件名
    const char *user_data_file = "./data/user_data.txt";
    // 日志文件名
    const char *log_file = "./data/log.txt";
    // 创建ATM实例
    ATM atm(user_data_file, log_file);

    while (true)
    {
        while (is_logged_in == false)
        {  
            //插卡
            is_logged_in = atm.insert_card();
        }
        while (is_logged_in == true)
        {
            // 显示欢迎词及提示信息
            atm.ui.menu.menu();

            // 读取用户的输入
            int operation;
            cout << "操作：";
            cin >> operation;

            // 根据用户的输入执行相应的操作
            switch (operation)
            {
            case 1:
                atm.inquiry();
                break;
            case 2:
                atm.withdraw();
                break;
            case 3:
                atm.deposit();
                break;
            case 4:
                atm.transfer();
                break;
            case 5:
                atm.change_password();
                break;
            case 6:
                atm.file_line_ = 0;
                atm.log("退出登录");
                is_logged_in = false;
                break;
            }
        }
    }
}