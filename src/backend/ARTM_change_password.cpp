#include <iostream>
#include <cstring>

#include "../../include/ATM.h"
#include "../../include/UI.h"

using namespace std;

void ATM::change_password()
{
    while (true)
    {
        ui.changePSW.change_PSW_init();
        string new_password;
        cin >> new_password;
        if (new_password == "0")
        {
            return;
        }

        // 判断密码长度
        if (new_password.size() != 6)
        {
            ui.changePSW.newPSW_error();
            ui.back();
            continue;
        }
        bool new_password_legal = true;
        //判断是否全为数字
        for (int i = 0; i < new_password.length(); i++)
        {
            if (!isdigit(new_password[i]))
            {
                ui.changePSW.newPSW_error();
                ui.back();
                new_password_legal = false;
                break;
            }
        }
        if (!new_password_legal)
        {
            continue;
        }

        //二次确认密码
        ui.changePSW.PSW_confirm();
        string confirm_password;
        cin >> confirm_password;
        if (confirm_password == "0")
        {
            return;
        }
        if (confirm_password != new_password)
        {
            ui.changePSW.second_error();
            ui.back();
            continue;
        }

        password_ = new_password;

        //记录用户操作并保存
        save(file_line_);
        log("更改密码");

        ui.changePSW.PSW_change_succeeded();
        ui.back();
        return;
    }
}