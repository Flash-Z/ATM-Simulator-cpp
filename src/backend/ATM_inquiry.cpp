#include <iostream>

#include "../../include/ATM.h"
#include "../../include/UI.h"

using namespace std;

void ATM::inquiry()
{
    ui.inquiry.run(balance_);
    ui.back();
}