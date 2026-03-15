#include "NightClub.h"

int main()
{
    NightClub elisClub;

    Client currentClients[2];
    currentClients[0] = Client("Ivan", "ivan_bill.txt");
    currentClients[1] = Client("Maria", "maria_bill.txt");

    elisClub.calculateDailyProfit(currentClients, 2);

    return 0;
}