#include <iostream>

#include "../../include/ATM.h"
#include "../../include/UI.h"

using namespace std;

void ATM::deposit()
{
    while(true)
    {
        ui.deposit.deposit_init();

        //读取用户输入(并未使用string因为ATM机不会有数字以外的其他字符输入)
        double amount;
        cin >> amount;

        if (amount == 0)
        {
            return;
        }

        // 如果用户输入的金额不是100的正整数倍，则不允许存款
        if ((int)amount % 100 != 0 || (100 * amount - (int)(amount)*100) != 0 || amount < 0)
        {
            ui.withdraw.amount_not_supported();
            ui.back();
            continue;
        }

        // 增加用户的余额
        balance_ += amount;

        // 将用户的操作保存并写入日志
        save(file_line_);
        log("存款 " + to_string(amount) + " 元");

        ui.deposit.deposit_succeeded();
        ui.back();
        return;
    }    
}