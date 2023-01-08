#ifndef UI_H
#define UI_H

#include <iostream>
#include <cstring>
#include <fstream>

#include "UI_insert_card.h"
#include "UI_inquiry.h"
#include "UI_menu.h"
#include "colorSet.h"
#include "UI_withdraw.h"
#include "UI_Transfer.h"
#include "UI_changePSW.h"
#include "UI_deposit.h"

using namespace std;

class UI
{
public:
    // 创建子UI实例
    UI_insert_card insert_card;
    UI_inquiry inquiry;
    UI_menu menu;
    UI_withdraw withdraw;
    UI_transfer transfer;
    UI_changePSW changePSW;
    UI_deposit deposit;

public:
    // 返回功能
    void back();
    // 文件打开失败报错
    void file_open_failure();
};

#endif