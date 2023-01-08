#ifndef ATM_H
#define ATM_H

#include <iostream>
#include <cstring>
#include <fstream>

#include "UI.h"
using namespace std;

class ATM
{
public:
    // 初始化用户文件地址
    ATM(const string &user_data_file, const string &log_file);
    // 用户插卡
    bool insert_card();
    // 取款
    void withdraw();
    // 存款
    void deposit();
    // 转账
    void transfer();
    // 修改密码
    void change_password();
    // 用户文件保存
    void save(int line, string stemp = "");
    // 保存日志
    void log(string logs);
    // 余额查询
    void inquiry();
    // 创建ui实例
    UI ui;
    // 记录用户数据在文件中的行数
    int file_line_ = 0;

private:
    // 记录是否锁卡，非0为锁卡
    int is_locked_;
    // 输入密码错误次数
    int input_error_times_;
    // 单次取款最大金额
    int SINGLE_LIMIT = 4000;
    // 记录每日存款金额
    int daily_withdraw_;
    // 每日取款最大金额
    int DAILY_LIMIT = 8000;
    // 银行卡号
    string account_number_;
    // 密码
    string password_;
    // 余额
    double balance_;
    // 日志文件
    string log_file_;
    // 数据文件
    string user_data_file_;
    // 用户姓名
    string user_name_;
    // 用户ID
    string user_ID_;
};

#endif