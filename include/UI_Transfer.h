#ifndef UI_TRANSFER_H
#define UI_TRANSFER_H

class UI_transfer{
public:
    void transfer_target();
    void transfer_confirm();
    void transfer_amount();
    void transfer_account_error();
    void insufficient_balance();
    void transfer_succeeded();
    void account_confirm_failure();
    void amount_error();
    void own_account();
};

#endif