#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> //for random number generator
#define Min 2
int replenish_item();
float change_prices(float a);
int display_total_sale(float z);
void display_item_avail(int a, int b, int c);
int main()
{
    int sel, A_n = 5, B_n = 5, C_n = 5, firstinput, admin_password = 123;
    char name, A, B, C, cancel, pass, answer1;
    float price, A_p = 12, B_p = 6, C_p = 3.25, coin = 0, total_amount = 0, ap, bp, cp;
    bool prog1 = true;
    while (prog1)
    {
        printf("VENDING MACHINE SIMULATOR\n");
        printf("Purchase Item for the consumer, enter 1\n");
        printf("Admin Mode, enter 2\n");
        printf("Exit, enter 3\n");
        scanf("%d", &firstinput);
        switch (firstinput)
        {
        case 3:
        {
            printf("PROGRAM EXITED\n"); // ends program
            prog1 = false;
            break;
        }
        case 2:
        {
            printf("ADMIN MODE\n"); // admin mode
            printf("Enter Admin Password: ");
            scanf("%d", &pass);
            if (pass != admin_password)
            {
                printf("Incorrect admin password. Exiting Admin Mode.\n");
                // prog1 = false;
            }
            else
            {
                bool adminmode = true;
                int admin_selection;
                while (adminmode)
                {
                    printf("1: Replenish Items\n");
                    printf("2: Change Item Prices\n");
                    printf("3: Display Total Sale\n");
                    printf("4: Display Item Availability\n");
                    printf("0: Exit Admin Mode\n");
                    scanf("%d", &admin_selection);

                    switch (admin_selection)
                    {
                    case 0:
                    {
                        adminmode = false;
                        break;
                    }
                    case 1: // replenish items
                    {
                        A_n = replenish_item();
                        B_n = replenish_item();
                        C_n = replenish_item();
                        break;
                    }
                    case 2: // change prices of the items
                    {
                        printf("\n");
                        printf("Enter the new price for item A: \n");
                        scanf("%f", &ap);
                        printf("Enter the new price for item B: \n");
                        scanf("%f", &bp);
                        printf("Enter the new price for item C: \n");
                        scanf("%f", &cp);
                        A_p = change_prices(ap);
                        B_p = change_prices(bp);
                        C_p = change_prices(cp);
                        printf("Updated\n");
                        break;
                    }
                    case 3: // Print out the total sale amount
                    {
                        printf("\n");
                        int answer3;
                        answer3 = display_total_sale(total_amount);
                        if (answer3 == 0)
                        {
                            total_amount = 0;
                            printf("REMINDER: Collect the money from the machine\n");
                        }
                        printf("\n");
                        break;
                    }
                    case 4: // item availability
                    {
                        display_item_avail(A_n, B_n, C_n);
                        printf("\n");
                        break;
                    }
                    default:
                        printf("Invalid selection\n");
                        break;
                    } // end of switch(admin_selection)

                } // end of while(adminmode)
            }
            break;
        }
            ////////////////////////////////////////////////////////////////////////////////////////////////////
        case 1:
        {
            printf("\n");
            printf("CONSUMER\n"); // consumer mode
            // prog1 = false;
            bool prog2 = true;
            while (prog2)
            {
                float customer_pay = 0;
                printf("Available items: A B C\n");
                printf("A(AED %0.2f), To select, enter 1\n", A_p);
                printf("B(AED %0.2f), To select, enter 2\n", B_p);
                printf("C(AED %0.2f), To select, enter 3\n", C_p);
                printf("To exit the program, enter 0\n");
                scanf("%d", &sel);

                if (sel == 0)
                {
                    printf("PROGRAM EXITED\n");
                    printf("\n");
                    prog2 = false;
                } // program exits here

                else if (sel == 1 || sel == 2 || sel == 3) // enter loop if user input is valid
                {
                    switch (sel)
                    {
                    case 1: // confirm selection for A
                    {
                        printf("You want to buy Item A for %0.2f, please confirm(y/n): ", A_p);
                        scanf(" %c", &answer1);
                        break;
                    }       // end of case 1
                    case 2: // confirm selection for B
                    {
                        printf("You want to buy Item B for %0.2f, please confirm(y/n): ", B_p);
                        scanf(" %c", &answer1);
                        break;
                    }
                    case 3: // confirm selection for C
                    {
                        printf("You want to buy Item C for %0.2f, please confirm(y/n): ", C_p);
                        scanf(" %c", &answer1);
                        break;
                    }
                    default:
                    {
                        printf("Invalid input\n");
                        // prog2 = false;
                        break;
                    }
                    } // end of switch(sel)

                    if (answer1 == 'y' || answer1 == 'Y') // here loops back to consumer mode
                    {
                        printf("Confirmed\n");
                        if (sel == 1) // for item A
                        {
                            if (A_n > 0)
                            {
                                printf("Please pay for the item using 1, 0.5, 0.25 Dirham coins (continue paying until confirmed):\n");
                                while (customer_pay < A_p)
                                {
                                    scanf(" %f", &coin);
                                    if (coin == 1 || coin == 0.5 || coin == 0.25)
                                    {
                                        customer_pay += coin; // adds entered coin amt to variable customer_pay
                                    }
                                    else
                                    {
                                        printf("Invalid. Do you want to cancel the purchase? (y/n): ");
                                        scanf(" %c", &cancel);
                                        if (cancel == 'y' || cancel == 'Y')
                                        {
                                            printf("Purchase canceled\n");
                                            break;
                                        }
                                        else if (cancel == 'n' || cancel == 'N')
                                        {
                                            printf("Please pay for the item using 1, 0.5, 0.25 Dirham coins:\n");
                                        }
                                    }
                                }

                                if (customer_pay >= A_p)
                                {
                                    total_amount += A_p;
                                    A_n--; // removes 1 stock from available stock
                                    float change;
                                    change = customer_pay - A_p;
                                    printf("You bought item A for %.2f AED and you paid: %0.2f. Change due: %0.2f \n", A_p, customer_pay, change);
                                    if (A_n <= Min)
                                    {
                                        printf("ALERT: Item A is in low stock!\n");
                                    }
                                }
                            }
                            else
                            {
                                printf("Item A is out of stock\n");
                            }
                        } // for item A

                        else if (sel == 2) // for item B
                        {
                            if (B_n > 0)
                            {
                                printf("Please pay for the item using 1, 0.5, 0.25 Dirham coins (continue paying until confirmed):\n");
                                while (customer_pay < B_p)
                                {
                                    scanf(" %f", &coin);
                                    if (coin == 1 || coin == 0.5 || coin == 0.25)
                                    {
                                        customer_pay += coin;
                                    }
                                    else
                                    {
                                        printf("Invalid. Do you want to cancel the purchase? (y/n): ");
                                        scanf(" %c", &cancel);
                                        if (cancel == 'y' || cancel == 'Y')
                                        {
                                            printf("Purchase canceled\n");
                                            // prog2 = false;
                                            break;
                                        }
                                        else if (cancel == 'n' || cancel == 'N')
                                        {
                                            printf("Please pay for the item using 1, 0.5, 0.25 Dirham coins:\n");
                                        }
                                    }
                                }

                                if (customer_pay >= B_p)
                                {
                                    total_amount += B_p;
                                    B_n--;
                                    float change;
                                    change = customer_pay - B_p;
                                    printf("You bought item A for %.2f AED and you paid: %0.2f. Change due: %0.2f \n", B_p, customer_pay, change);
                                    if (B_n <= Min)
                                    {
                                        printf("ALERT: Item B is in low stock!\n");
                                    }
                                }
                            }
                            else
                            {
                                printf("Item B is out of stock\n");
                            }
                        }                  // for item B
                        else if (sel == 3) // for item C
                        {
                            if (C_n > 0)
                            {
                                printf("Please pay for the item using 1, 0.5, 0.25 Dirham coins (continue paying until confirmed):\n");
                                while (customer_pay < C_p)
                                {
                                    scanf(" %f", &coin);
                                    if (coin == 1 || coin == 0.5 || coin == 0.25)
                                    {
                                        customer_pay += coin;
                                    }
                                    else
                                    {
                                        printf("Invalid. Do you want to cancel the purchase? (y/n): ");
                                        scanf(" %c", &cancel);
                                        if (cancel == 'y' || cancel == 'Y')
                                        {
                                            printf("Purchase canceled\n");
                                            // prog2 = false;
                                            break;
                                        }
                                        else if (cancel == 'n' || cancel == 'N')
                                        {
                                            printf("Please pay for the item using 1, 0.5, 0.25 Dirham coins:\n");
                                        }
                                    }
                                }

                                if (customer_pay >= C_p)
                                {
                                    total_amount += C_p;
                                    C_n--;
                                    float change;
                                    change = customer_pay - C_p;
                                    printf("You bought item A for %.2f AED and you paid: %0.2f. Change due: %0.2f \n", C_p, customer_pay, change);
                                    if (C_n <= Min)
                                    {
                                        printf("ALERT: Item C is in low stock!\n");
                                    }
                                }
                                // break;
                            }
                            else
                            {
                                printf("Item C is out of stock\n");
                            }
                        } // for item C
                        // break;
                    }
                    else
                    {
                        printf("Not confirmed\n");
                    }
                }
            } // end of while(prog2)
        }     // end of case1

        } // switch (firstinput)
    }     // end of while(prog1)
    return 0;
} // end of main()

/// FUNCTIONS

int replenish_item() // function to replenish required item using random function
{
    int new_value;
    new_value = (rand() % 20) + 1;
    return new_value;
}

float change_prices(float a) // function to change prices of an item
{
    float new_price;
    new_price = a;
    return new_price;
}
int display_total_sale(float z) // displays total sales
{
    printf("Total Sale Amount: AED %.2f\n", z);
    printf("Reset the total sale amount to zero? (y/n): ");
    char answer;
    scanf(" %c", &answer);
    if (answer == 'y' || answer == 'Y')
    {
        z = 0;
        printf("\n");
        printf("Total Sale Amount reset to zero.\n");
        return z;
    }
    else
    {
        return 1;
    }
}
void display_item_avail(int a, int b, int c) // shows availability of each item
{
    printf("\n");
    printf("Item A: %d available\n", a);
    printf("Item B: %d available\n", b);
    printf("Item C: %d available\n", c);
}
