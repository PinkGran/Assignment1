# Assignment1
# my first repository

#include <stdio.h>
#include <string.h>
int main()
{
    int sel;
    char name, A, B, C;
    float price, A_p = 12, B_p = 6, C_p = 3.25;
    printf("Available items: A B C\n");
    printf("A(AED 12), To select, enter 1\n");
    printf("B(AED 6), To select, enter 2\n");
    printf("C(AED 3.25), To select, enter 3\n");
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
                printf("Confirmed");

            break;
        }
        case 'B':
        {
            if (price == B_p)
                printf("Confirmed");

            break;
        }
        case 'C':
        {
            if (price == C_p)
                printf("Confirmed");

            break;
        }
        }
    }
    return 0;
}
