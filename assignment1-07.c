#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define Min 2
int main()
{
    int sel, A_n = 10, B_n = 10, C_n = 10;
    char name, A, B, C;
    float price, A_p = 12, B_p = 6, C_p = 3.25, c_pay = 0, coin = 0;
    bool prog = true;
    printf("Vending Machine Simulator");
    printf("Available items: A B C\n");
    printf("A(AED 12), To select, enter 1\n");
    printf("B(AED 6), To select, enter 2\n");
    printf("C(AED 3.25), To select, enter 3\n");
    printf("To exit the program, enter 4\n");
    scanf("%d", &sel);

    if (sel > 0 && sel < 4)
    {
        printf("To confirm please enter the item name and its price: ");
        scanf("%s%f", &name, &price);
        switch (name)
        {
        case 'A':
        {
            if (price == A_p)
                printf("Confirmed\n");
            break;
        }
        case 'B':
        {
            if (price == B_p)
                printf("Confirmed\n");
            break;
        }
        case 'C':
        {
            if (price == C_p)
                printf("Confirmed\n");
            break;
        }
        default:
            printf("Not confirmed\n");
        }
        printf("Please pay for the item using 1, 0.5, 0.25 Dhirham coins\n");
        while (c_pay < price)
        {
            scanf("%f", &coin);
            if (coin != 1 || coin != 0.5 || coin != 0.25)
            {
                printf("Please pay for the item using 1, 0.5, 0.25 Dhirham coins only\n");
            }
            c_pay += coin;
        }
        printf("Paid\n");
    }
    return 0;
}