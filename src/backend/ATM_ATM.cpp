#include <iostream>
#include <cstring>

#include "../../include/ATM.h"
#include "../../include/UI.h"

using namespace std;

//初始化数据文件地址
ATM::ATM(const string &user_data_file, const string &log_file)
    : user_data_file_(user_data_file), log_file_(log_file) {}