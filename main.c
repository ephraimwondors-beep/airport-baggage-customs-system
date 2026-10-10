#include <stdio.h>

int main()
{
    int ticket_class, check_hr, check_min, dep_hr, dep_min;
    char flyer_status;
    float baggage_weight, value_of_goods, surcharge, diff_in_check_in_time, departure_time, check_in_time, final_amount, weight_charge, net_weight_charge, customs_tax;

    printf("What is your ticket class (1):ECONOMY (2): BUSINESS CLASS (3): FIRST CLASS \n");
    scanf(" %d", &ticket_class);

    printf("What is your flyer status 'G': Gold 'S': Silver 'N':None \n");
    scanf(" %c", &flyer_status);

    printf("What is your baggage weight \n");
    scanf(" %f", &baggage_weight);

    printf("What is the value of goods \n");
    scanf(" %f", &value_of_goods);

    printf("What is the departure time (e.g. 1400)\n");
    scanf(" %f", &departure_time);

    printf("What is the check in time (e.g. 1300)\n");
    scanf(" %f", &check_in_time);

    // 1. Baggage Weight Checks
    if (baggage_weight > 100)
    {
        printf("UNLOAD SOME OF YOUR BAGGAGE OR ENTRY IS DENIED\n");
        return 0;
    }
    else if (ticket_class == 1 && baggage_weight <= 23)
    {
        weight_charge = 0;
    }
    else if (ticket_class == 1 && baggage_weight > 23 && baggage_weight <= 33)
    {
        weight_charge = (baggage_weight - 23) * 15;
    }
    else if (ticket_class == 1 && baggage_weight > 33 && baggage_weight <= 48)
    {
        weight_charge = 150 + (baggage_weight - 33) * 25;
    }
    else if (ticket_class == 1 && baggage_weight > 48)
    {
        weight_charge = 525 + (baggage_weight - 48) * 40 + 100;
    }
    else if (ticket_class == 2 && baggage_weight <= 32)
    {
        weight_charge = 0;
    }
    else if (ticket_class == 2 && baggage_weight > 32 && baggage_weight <= 47)
    {
        weight_charge = (baggage_weight - 32) * 20;
    }
    else if (ticket_class == 2 && baggage_weight > 47)
    {
        weight_charge = 300 + (baggage_weight - 47) * 35 + 75;
    }
    else if (ticket_class == 3 && baggage_weight <= 40)
    {
        weight_charge = 0;
    }
    else if (ticket_class == 3 && baggage_weight > 40)
    {
        weight_charge = (baggage_weight - 40) * 30;
    }

    // 2. Frequent Flyer Discount Logic
    if (flyer_status == 'G' || flyer_status == 'g')
    {
        net_weight_charge = weight_charge * 0.80;
    }
    else if (flyer_status == 'S' || flyer_status == 's')
    {
        net_weight_charge = weight_charge * 0.90;
    }
    else if (flyer_status == 'n' || flyer_status == 'N')
    {
        net_weight_charge = weight_charge;
    }
    else
    {
        printf("Warning: Invalid flyer status entered! Defaulting to no discount.\n");
        net_weight_charge = weight_charge;
    }

    // 3. Customs Duty Tax
    if (value_of_goods <= 800.00)
    {
        customs_tax = value_of_goods * 0.00;
    }
    else if (value_of_goods > 800.00 && value_of_goods <= 2000.00)
    {
        customs_tax = (value_of_goods - 800) * 0.040;
    }
    else if (value_of_goods > 2000.00 && value_of_goods <= 5000.00)
    {
        customs_tax = (value_of_goods - 2000) * 0.070 + 48;
    }
    else if (value_of_goods > 5000.00)
    {
        customs_tax = (value_of_goods - 5000) * 0.120 + 258 + 50;
    }

    // 4. Check-in Time Math
    dep_hr = (int)departure_time / 100;
    dep_min = (int)departure_time % 100;
    check_hr = (int)check_in_time / 100;
    check_min = (int)check_in_time % 100;

    diff_in_check_in_time = (dep_hr * 60 + dep_min) - (check_hr * 60 + check_min);

    if (diff_in_check_in_time >= 60)
    {
        surcharge = 0;
    }
    else if (diff_in_check_in_time >= 45)
    {
        surcharge = 30;
    }
    else if (diff_in_check_in_time >= 30)
    {
        surcharge = 75;
    }
    else
    {
        printf(" BOARDING DENIED!! Check in closed\n");
        return 0;
    }

    // 5. Itemized Receipt
    final_amount = net_weight_charge + customs_tax + surcharge;

    printf("*********************************************\n");
    printf("              ITEMIZED BREAKDOWN             \n");
    printf("*********************************************\n");
    printf("Base baggage charge is $%9.2f\n", weight_charge);
    printf("Frequent Flyer discount is -$%9.2f\n", weight_charge - net_weight_charge);
    printf("Net weight charge after discount is $%9.2f\n", net_weight_charge);
    printf("Custom tax is $%9.2f\n", customs_tax);
    printf("Late check in surcharge is $%9.2f\n", surcharge);
    printf("=============================================\n");
    printf("FINAL GRAND AMOUNT TO BE PAID is $%9.2f\n", final_amount);
    printf("=============================================\n");

    return 0;
}
