#include <iostream>

#include "../../include/ATM.h"
#include "../../include/UI.h"

using namespace std;

void ATM::withdraw()
{
    while (true)
    {
        ui.withdraw.withdraw_init();

        // 读取用户的输入
        double amount;
        cin >> amount;

        if (amount == 0)
        {
            return;
        }

        // 如果用户的单笔取款限额超过了限额，则不允许取款(先检测这个防止数据越下面的int界)
        if (amount > SINGLE_LIMIT)
        {
            ui.withdraw.single_time_limited(SINGLE_LIMIT);
            ui.back();
            continue;
        }

        // 如果用户输入的金额不是100的正整数倍，则不允许取款
        if ((int)amount % 100 != 0 || (100 * amount - (int)(amount)*100) != 0 || amount < 0)
        {
            ui.withdraw.amount_not_supported();
            ui.back();
            continue;
        }

        // 如果用户的余额不足，则不允许取款
        if (balance_ < amount)
        {
            ui.withdraw.insufficient_balance();
            ui.back();
            continue;
        }

        // 如果用户的单日取款限额超过了限额，则不允许取款
        if (daily_withdraw_ + amount > DAILY_LIMIT)
        {
            ui.withdraw.amount_dily_limited(DAILY_LIMIT - daily_withdraw_);
            ui.back();
            continue;
        }
        // 扣除用户的余额
        balance_ -= amount;

        // 记录用户的取款金额
        daily_withdraw_ += amount;

        // 将用户的操作保存并写入日志
        save(file_line_);
        log("取款 " + to_string(amount) + " 元");

        ui.withdraw.withdraw_succeeded();
        ui.back();
        return;
    }
}