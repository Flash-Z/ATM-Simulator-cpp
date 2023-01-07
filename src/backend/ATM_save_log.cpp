#include <iostream>
#include <fstream>
#include <cstring>

#include "../../include/ATM.h"
#include "../../include/UI.h"

using namespace std;

void ATM::save(int line, string stemp)
{
    //打开文件
    fstream outfile(user_data_file_, ios::out | ios::in);
    //判断文件是否打开
    if(!outfile.is_open())
    {
        ui.file_open_failure();
        abort();
    }

    //判断stemp长度以检测是否有stemp传入，决定是否生成stemp
    if (stemp.length() < 20)
    {
        stemp = account_number_ + " " + user_name_ + " " + user_ID_ + " " + password_ + " " + to_string(balance_) + " " +
                to_string(input_error_times_) + " " + to_string(daily_withdraw_) + " " + to_string(is_locked_);
    }

    string new_flie = "", temp_line;
    int current_line = 0;

    while (!outfile.eof())
    {
        current_line++;
        getline(outfile, temp_line);
        if (temp_line.length() < 20)
        {
            continue;
        }
        // 读取所有数据并更新当前用户数据
        if (current_line != line)
        {
            new_flie += (temp_line + "\n");
        }
        else
        {
            new_flie += (stemp + "\n");
        }
    }
    outfile.close();

    fstream utfile(user_data_file_, ios::out | ios::trunc);
    //判断文件是否打开
    if(!utfile.is_open())
    {
        ui.file_open_failure();
        abort();
    }
    //写入新数据
    utfile.seekp(0, ios::beg);
    utfile.write(new_flie.data(), new_flie.length());
    utfile.close();
}

void ATM::log(string logs)
{
    // 当前时间
    time_t current_time = time(NULL);
    string current_time_str = ctime(&current_time);
    // 去除末尾的换行符
    current_time_str = current_time_str.substr(0, current_time_str.size() - 1);

    // 构造日志信息
    string log_message = "[" + current_time_str + "] 卡号：" + account_number_ + " " + logs;

    // 写入日志
    fstream outfile(log_file_, ios::app);
    //判断文件是否打开
    if(!outfile.is_open())
    {
        ui.file_open_failure();
        abort();
    }
    outfile << log_message << endl;
    outfile.close();
}