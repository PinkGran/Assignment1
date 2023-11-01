#include <stdio.h>
#include <stdbool.h>
#include <string.h> //for strcmp
#include <ctype.h>  //for tolower()function
#define numOfSubjects 3
#define numOfStudents 3
typedef struct
{
    char FirstName[20];
    char LastName[20];
    int StudentID;
    float SubjectMarks[3];
    int AggregateMarks;
    char Grade;
} records;
void enrol(records students[]);
int main()
{
    records students[numOfStudents];
    bool prog = true;
    int answer1;
    while (prog)
    {
        printf("To Enrol, Enter 1: \n");
        printf("for search update, Enter 2: \n");
        printf("For topStudents, Enter 3: \n");
        printf("To Exit, enter 3\n");

        scanf("%d", &answer1);
        if (answer1 == 3)
        {
            printf("\nPROGRAM EXITED\n");
            prog = false;
        }
        switch (answer1)
        {
        case 1:
        {
            printf("hello");
            enrol(students);
            break;
        }

        } // end of switch case
    }
    return 0;
}
void enrol(records students[])
{
    for (int i = 0; i < numOfStudents; i++)
    {
        float agg_marks = 0, percentage_mark = 0;
        int userid;
        char ansmarks[10];
        printf("Enter Student ID: ");
        scanf("%d", &userid);
        students[i].StudentID = userid;
        for (int j = 0; j < numOfSubjects; j++)
        {
            char response;
            printf("Do you want to input the mark for Subject %d (Y/N)? ", j);
            scanf(" %c", &response);

            if (response == 'Y' || response == 'y')
            {
                printf("Enter the mark for Subject %d: ", j);
                scanf("%f", &students[i].SubjectMarks[j]);
                agg_marks = agg_marks + students[i].SubjectMarks[j];
            }
            else
            {
                students[i].SubjectMarks[j] = -1;
            }

            // printf("\nInput the marks for Subject "%d"",j);
            // scanf("%f",students[i].SubjectMarks[j]);

            // scanf("%s", ansmarks);
            //  for (int i = 0; i < strlen(ansmarks); i++)
            //  {
            //      ansmarks[i] = tolower(ansmarks[i]);
            //  }

            // if (strcmp(ansmarks, "yes") == 0)
            // {
            //     // printf("You entered 'yes'.\n");

            // }
            // else if (strcmp(ansmarks, "no") == 0)
            // {
            //     // printf("You entered 'no'.\n");
            // }
            // else
            // {
            //     printf("Invalid input. Please enter 'yes' or 'no'.\n");
            // }
        } // end of numOfsubs for
        percentage_mark = (agg_marks / 300) * 100;
        printf("Aggregate marks = %0.2f\n ", agg_marks);
        if (percentage_mark <= 100 && percentage_mark > 84)
        {
            printf("Grade: HD \n");
        }
        else if (percentage_mark <= 84 && percentage_mark >= 75)
        {
            printf("Grade: D \n");
        }
        else if (percentage_mark < 75 && percentage_mark >= 65)
        {
            printf("Grade: C \n");
        }
        else if (percentage_mark < 65 && percentage_mark >= 50)
        {
            printf("Grade: P \n");
        }
        else if (percentage_mark < 50 && percentage_mark >= 0)
        {
            printf("Grade: F \n");
        }
        else
        {
            printf("Undefined \n");
        }

    } // end of first for
}