#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define Min 2
// int updateitemnumber(int item);
int main()
{
    int sel, A_n = 5, B_n = 5, C_n = 5, firstinput;
    char name, A, B, C, cancel;
    float price, A_p = 12, B_p = 6, C_p = 3.25, customer_pay = 0, coin = 0, total_amount = 0;
    bool prog1 = true, prog2 = true;
    while (prog1)
    {
        printf("Purchase Item for the consumer, enter 1\n");
        printf("Admin Mode, enter 2\n");
        printf("Exit, enter 3\n");
        scanf("%d", &firstinput);
        switch (firstinput)
        {
        case 3:
        {
            printf("PROGRAM EXITED\n");
            prog1 = false;
            break;
        }
        case 2:
        {
            printf("ADMIN MODE\n");
            break;
        }
        case 1:
        {
            printf("Consumer\n");
            prog1 = false;
            while (prog2)
            {
                printf("Vending Machine Simulator\n");
                printf("Available items: A B C\n");
                printf("A(AED 12), To select, enter 1\n");
                printf("B(AED 6), To select, enter 2\n");
                printf("C(AED 3.25), To select, enter 3\n");
                printf("To exit the program, enter 4\n");
                scanf("%d", &sel);

                switch (sel)
                {
                case 1:
                {
                    printf("To confirm please enter the item name and its price: ");
                    scanf("%s%f", &name, &price);
                    break;
                }
                case 2:
                {
                    printf("To confirm please enter the item name and its price: ");
                    scanf("%s%f", &name, &price);
                    break;
                }
                case 3:
                {
                    printf("To confirm please enter the item name and its price: ");
                    scanf("%s%f", &name, &price);
                    break;
                }
                case 0:
                {
                    printf("Purchase cancelled\n");
                    prog2 = false;
                    prog1 = false;
                    break;
                }
                case 4:
                {
                    printf("PROGRAM EXITED\n");
                    prog2 = false;
                    prog1 = false;
                    break;
                }
                default:
                {
                    printf("default");
                }
                } // end of switch(sel)
                /////////////////////////////////////////////////////////////////////////////////////////////////////
                switch (name)
                {
                case 'A':
                {
                    if (price == A_p)
                    {
                        if (A_n > 0)
                        {
                            total_amount += price;
                            A_n--;
                            if (A_n <= Min)
                            {
                                printf("ALERT: Item A is in low stock! \n");
                            }
                        }
                        else
                        {
                            printf("Item is out of stock\n");
                        }
                        printf("Confirmed\n");
                    }
                    else
                    {
                        printf("Invalid input\n");
                    }
                    break;
                }
                case 'B':
                {
                    if (price == B_p)
                    {
                        if (B_n > 0)
                        {
                            total_amount += price;
                            B_n--;
                            if (B_n <= Min)
                            {
                                printf("ALERT: Item B is in low stock! \n");
                            }
                        }
                        else
                        {
                            printf("Item is out of stock\n");
                        }
                        printf("Confirmed\n");
                    }
                    else
                    {
                        printf("Invalid input\n");
                    }
                    break;
                }
                case 'C':
                {
                    if (price == C_p)
                    {
                        if (C_n > 0)
                        {
                            total_amount += price;
                            C_n--;
                            if (C_n <= Min)
                            {
                                printf("ALERT: Item C is in low stock! \n");
                            }
                        }
                        else
                        {
                            printf("Item is out of stock\n");
                        }
                        printf("Confirmed\n");
                    }
                    else
                    {
                        printf("Invalid input\n");
                    }
                    break;
                }
                default:
                    prog2 = false;
                    break;
                } // end of switch(name)
                if (price == A_p || price == B_p || price == C_p)
                {
                    printf("Please pay for the item using 1, 0.5, 0.25 Dhirham coins\n");

                    while (customer_pay < price)
                    {
                        scanf("%f", &coin);
                        if (coin > 1 || coin < 0.25)
                        {
                            printf("Please pay for the item using 1, 0.5, 0.25 Dhirham coins only. Cancel Purchase? (y/n)\n");
                            scanf(" %c", &cancel);

                            if (cancel == 'y' || cancel == 'Y')
                            {
                                printf("Purchase canceled.\n");
                                prog2 = false;
                                break;
                            }
                            else
                            {
                                continue;
                            }
                        } // end of if for coin
                        customer_pay += coin;
                    } // end of cutomer pay while loop
                    printf("Paid\n");
                    printf("You bought item %c for %0.2f Dhs and you paid %0.2f Dhs\n", name, price, price);
                } // end of if consumer pay
                else
                {
                    prog2 = false;
                }
            } // end of while(prog2)
            break;
        }
        defaul:

        {
            printf("invalid input\n");
            prog1 = false;
            break;
        }

        } // end of switch(firstinput)

    } // end of while(prog1)
    return 0;
} // end of main()
