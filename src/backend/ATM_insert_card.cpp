#include <iostream>
#include <cstring>

#include "../../include/ATM.h"
#include "../../include/UI.h"

using namespace std;

bool ATM::insert_card()
{  
    ui.welcome.welcome();

    string card_number, password;
    ui.welcome.input_card_number();

    cin >> card_number;

    if (card_number == "0")
    {
        return false;
    }
    fstream user_file(user_data_file_, ios::in | ios::out);
    //检测文件是否打开成功
    if (user_file.is_open())
    {
        // 循环读取文件中的每一行
        while (user_file >> account_number_ >> user_name_ >>
               user_ID_ >> password_ >> balance_ >> input_error_times_ >> daily_withdraw_ >> is_locked_)
        {
            file_line_++;
            
            if (card_number == account_number_)
            {
                if (is_locked_ == 1)
                {
                    file_line_ = 0;
                    user_file.close();
                    ui.welcome.card_locked();
                    ui.back();
                    return false;
                }
                while (true)
                {
                    ui.welcome.input_password();
                    cin >> password;
                    if (password == "0")
                    {
                        user_file.close();
                        save(file_line_);
                        file_line_ = 0;
                        return false;
                    }
                    if (password == password_)
                    {
                        user_file.close();
                        input_error_times_ = 0;
                        save(file_line_);
                        log("登录成功");
                        return true;
                    }
                    else
                    {
                        ++input_error_times_;
                        if (input_error_times_ == 3)
                        {
                            is_locked_ = 1;
                            user_file.close();
                            save(file_line_);
                            log("卡被锁定");
                            file_line_ = 0;
                            ui.welcome.card_locked();
                            ui.back();
                            return false;
                        }
                        save(file_line_);
                        ui.welcome.error_password(3 - input_error_times_);
                    }
                }
            }
        }
        user_file.close();
        save(file_line_);
        ui.welcome.error_account();
        ui.back();
        return false;
    }
    else{
        ui.file_open_failure();
        ui.back();
        abort();
    }
}