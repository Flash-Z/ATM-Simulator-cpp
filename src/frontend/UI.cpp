#include <iostream>

#include "../../include/UI.h"
#include "../../include/UI_insert_card.h"
#include "../../include/UI_inquiry.h"
#include "../../include/UI_menu.h"
#include "../../include/colorSet.h"
#include "../../include/UI_withdraw.h"
#include "../../include/UI_Transfer.h"
#include "../../include/UI_ChangePSW.h"

using namespace std;

void UI::back()
{
    cout << "\n请按回车返回：";
    cin.get();
    cin.get();
    system("cls");
}

void UI::file_open_failure(){
    system("cls");
    cout <<RED<< "\n用户数据打开失败，请联系银行工作人员！" <<RESET;
}