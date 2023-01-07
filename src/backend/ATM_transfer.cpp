#include <iostream>
#include <cstring>
#include <fstream>

#include "../../include/ATM.h"
#include "../../include/UI.h"

using namespace std;

void ATM::transfer()
{
    while (true)
    {
        ui.transfer.transfer_amount();

        //用户输入金额
        double amount;
        cin >> amount;

        if (amount == 0)
        {
            return;
        }

        // 如果用户输入的金额不是最多两位小数的正数，则不允许转账
        if ((amount * 100 - (int)(amount * 100)) != 0 || amount < 0)
        {
            ui.transfer.amount_error();
            ui.back();
            continue;
        }

        // 如果用户的余额不足，则不允许转账
        if (amount > balance_)
        {
            ui.transfer.insufficient_balance();
            ui.back();
            continue;
        }

        while(true)
        {        
            ui.transfer.transfer_target();
            string target_account;
            cin >> target_account;
            if (target_account == "0")
            {
                return;
            }

            //检查是否为自己的账户
            if(target_account == account_number_){
                ui.transfer.own_account();
                ui.back();
                continue;
            }

            // 确认转入账户
            ui.transfer.transfer_confirm();
            string confirm_account;
            cin >> confirm_account;
            if (confirm_account == "0")
            {
                continue;
            }
            
            // 如果转入账户两次输入不一致，则不允许转账
            if (target_account != confirm_account)
            {
                ui.transfer.account_confirm_failure();
                ui.back();
                continue;
            }

            bool account_found = false;
            //用于接收目标用户数据
            string t_account, t_user_name, t_user_ID, t_password;
            int t_input_error_times, t_is_locked, t_daily_withdraw;
            double t_balance;
            //记录目标用户数据位置
            int t_line = 0;
            fstream target_user_file(user_data_file_, ios::in | ios::out);
            //检查文件是否打开成功
            if (target_user_file.is_open())
            {
                //逐行读取用户数据
                while (target_user_file >> t_account >> t_user_name >> t_user_ID >> t_password >> t_balance >> t_input_error_times >> t_daily_withdraw >> t_is_locked)
                {
                    t_line++;
                    if (t_account == target_account)
                    {
                        account_found = true;
                        target_user_file.close();
                        t_balance += amount;
                        string stemp = t_account + " " + t_user_name + " " + t_user_ID + " " + t_password + " " + to_string(t_balance) + " " + to_string(t_input_error_times) + " " + to_string(t_daily_withdraw) + " " + to_string(t_is_locked);
                        save(t_line, stemp);
                        break;
                    }
                }
            }
            else{
                ui.file_open_failure();
                ui.back();
                abort();
            }

            //判断是否找到目标账号
            if (!account_found)
            {
                ui.transfer.transfer_account_error();
                ui.back();
                continue;
            }

            // 扣除用户的余额
            balance_ -= amount;

            // 将用户的操作保存并写入日志
            save(file_line_);
            log("转账：" + to_string(amount) + " 元 至卡号：" + target_account);

            ui.transfer.transfer_succeeded();
            ui.back();
            return;
        }
    }
}