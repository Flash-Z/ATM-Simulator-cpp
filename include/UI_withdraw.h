#ifndef UI_WITHDRAW_H
#define UI_WITHDRAW_H

class UI_withdraw
{
public:
    void withdraw_init();
    void insufficient_balance();
    void amount_dily_limited(const double amount);
    void amount_not_supported();
    void withdraw_succeeded();
    void single_time_limited(const long long singleAmount);
};

#endif