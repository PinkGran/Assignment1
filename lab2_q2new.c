#include <stdio.h>
#include <string.h>
#define MAX_SUBJECTS 3
#define MAX_STUDENTS 4

typedef struct
{
    char firstName[50];
    char lastName[50];
    int studentID;
    float subjectMarks[MAX_SUBJECTS];
    int aggregateMarks;
    char grade[10];
} record;

void enrol(record students[], int studentIndex);
void searchUpdate(record students[], int ns);
void topStudents(record students[], int ns);
void printRecord(record student);

int main()
{
    record students[MAX_STUDENTS];
    int numStudents = 0;
    int choice;

    do
    {
        printf("\nMenu:\n");
        printf("Enrol a student, Enter 1:\n");
        printf("for search update, Enter 2: \n");
        printf("For topStudents, Enter 3: \n");
        printf("To Exit, enter 4\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            if (numStudents < MAX_STUDENTS)
            {
                enrol(students, numStudents);
                numStudents++;
                printf("Student enrolled successfully.\n");
            }
            else
            {
                printf("Maximum number of students reached.\n");
            }
            break;
        case 2:
            searchUpdate(students, numStudents);
            break;
        case 3:
            topStudents(students, MAX_STUDENTS);
            break;
        case 4:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void enrol(record students[], int studentIndex)
{
    printf("\nEnrolling student %d:\n", studentIndex + 1);

    printf("Enter first name: ");
    scanf("%s", students[studentIndex].firstName);

    printf("Enter last name: ");
    scanf("%s", students[studentIndex].lastName);

    printf("Enter student ID: ");
    scanf("%d", &students[studentIndex].studentID);

    for (int i = 0; i < MAX_SUBJECTS; i++)
    {
        printf("Enter mark for Subject %d: ", i);
        scanf("%f", &students[studentIndex].subjectMarks[i]);
    }

    float totalMarks = 0;
    int aggregate = 0;
    for (int i = 0; i < MAX_SUBJECTS; i++)
    {
        if (students[studentIndex].subjectMarks[i] >= 0)
        {
            totalMarks = totalMarks + students[studentIndex].subjectMarks[i];
        }
    }
    aggregate = (totalMarks / 300) * 100;
    students[studentIndex].aggregateMarks = aggregate;
    printf("Their aggregate is :%d\n", aggregate);
    if (totalMarks >= 0)
    {
        if (aggregate >= 85)
        {
            strcpy(students[studentIndex].grade, "HD");
        }
        else if (aggregate >= 75)
        {
            strcpy(students[studentIndex].grade, "D");
        }
        else if (aggregate >= 65)
        {
            strcpy(students[studentIndex].grade, "C");
        }
        else if (aggregate >= 50)
        {
            strcpy(students[studentIndex].grade, "P");
        }
        else
        {
            strcpy(students[studentIndex].grade, "F");
        }
        printf("Their grade is %s\n", students[studentIndex].grade);
    }
    else
    {
        students[studentIndex].aggregateMarks = -1;
        strcpy(students[studentIndex].grade, "undefined");
    }
}

void searchUpdate(record students[], int ns)
{
    int userinput;
    printf("\n SearchUpdate\n");
    printf("\nDo you want to search by StudentID(1) or LastName(2)?: ");
    scanf(" %d", &userinput);
    switch (userinput)
    {
    case 1:
    {
        int studentid;
        printf("\nEnter Student ID: ");
        scanf(" %d", &studentid);
        for (int i = 0; i < ns; i++)
        {
            if (students[i].studentID == studentid)
            {
                printRecord(students[i]);
                char update;
                printf("Do you want to update any of the attributes? (Y/N): ");
                scanf(" %c", &update);

                if (update == 'Y' || update == 'y')
                {
                    printf("Enter updated first name: ");
                    scanf("%s", students[i].firstName);

                    printf("Enter updated last name: ");
                    scanf("%s", students[i].lastName);

                    printf("Enter updated student ID: ");
                    scanf("%d", &students[i].studentID);
                }
                char updategrades;
                printf("Do you want to update subject grades? (Y/N): ");
                scanf(" %c", &updategrades);
                if (updategrades == 'Y' || updategrades == 'y')
                {
                    for (int j = 0; j < MAX_SUBJECTS; j++)
                    {
                        printf("Enter mark for Subject %d: ", j);
                        scanf("%f", &students[i].subjectMarks[j]);
                    }

                    float totalMarks = 0;
                    int aggregate = 0;
                    for (int j = 0; j < MAX_SUBJECTS; j++)
                    {
                        if (students[i].subjectMarks[j] >= 0)
                        {
                            totalMarks = totalMarks + students[i].subjectMarks[j];
                        }
                    }
                    aggregate = (totalMarks / 300) * 100;
                    students[i].aggregateMarks = aggregate;
                    printf("Their aggregate is :%d\n", aggregate);

                    if (totalMarks >= 0)
                    {
                        // students[studentIndex].aggregateMarks = aggregate;
                        if (aggregate >= 85)
                        {
                            strcpy(students[i].grade, "HD");
                        }
                        else if (aggregate >= 75)
                        {
                            strcpy(students[i].grade, "D");
                        }
                        else if (aggregate >= 65)
                        {
                            strcpy(students[i].grade, "C");
                        }
                        else if (aggregate >= 50)
                        {
                            strcpy(students[i].grade, "P");
                        }
                        else
                        {
                            strcpy(students[i].grade, "F");
                        }
                        printf("Their grade is %s\n", students[i].grade);
                    }
                }
            } // end of if
        }
        break;
    } // end of case 1
    case 2:
    {
        char userlastname[20];
        printf("\nEnter the user's last name: ");
        scanf(" %s", &userlastname);
        for (int i = 0; i < ns; i++)
        {
            if (strcmp(students[i].lastName, userlastname) == 0)
            {
                printRecord(students[i]);
                char update;
                printf("Do you want to update any of the attributes? (Y/N): ");
                scanf(" %c", &update);

                if (update == 'Y' || update == 'y')
                {
                    printf("Enter updated first name: ");
                    scanf("%s", students[i].firstName);

                    printf("Enter updated last name: ");
                    scanf("%s", students[i].lastName);

                    printf("Enter updated student ID: ");
                    scanf("%d", &students[i].studentID);
                }
                char updategrades;
                printf("Do you want to update subject grades? (Y/N): ");
                scanf(" %c", &updategrades);
                if (updategrades == 'Y' || updategrades == 'y')
                {
                    for (int j = 0; j < MAX_SUBJECTS; j++)
                    {
                        printf("Enter mark for Subject %d: ", j);
                        scanf("%f", &students[i].subjectMarks[j]);
                    }

                    float totalMarks = 0;
                    int aggregate = 0;
                    for (int j = 0; j < MAX_SUBJECTS; j++)
                    {
                        if (students[i].subjectMarks[j] >= 0)
                        {
                            totalMarks = totalMarks + students[i].subjectMarks[j];
                        }
                    }
                    aggregate = (totalMarks / 300) * 100;
                    students[i].aggregateMarks = aggregate;
                    printf("Their aggregate is :%d\n", aggregate);

                    if (totalMarks >= 0)
                    {
                        // students[studentIndex].aggregateMarks = aggregate;
                        if (aggregate >= 85)
                        {
                            strcpy(students[i].grade, "HD");
                        }
                        else if (aggregate >= 75)
                        {
                            strcpy(students[i].grade, "D");
                        }
                        else if (aggregate >= 65)
                        {
                            strcpy(students[i].grade, "C");
                        }
                        else if (aggregate >= 50)
                        {
                            strcpy(students[i].grade, "P");
                        }
                        else
                        {
                            strcpy(students[i].grade, "F");
                        }
                        printf("Their grade is %s\n", students[i].grade);
                    }
                }

            } // end of if
        }
        break;
    } // end of case 2
    default:
    {
        printf("Invalid Input\n");
    }
    } // end of switch
}

void printRecord(record student)
{
    printf("\nStudent ID: %d\n", student.studentID);
    printf("First Name: %s\n", student.firstName);
    printf("Last Name: %s\n", student.lastName);
    printf("Aggregate Marks: %d\n", student.aggregateMarks);
    printf("Grade: %s\n", student.grade);
}
void topStudents(record students[], int ns)
{
    printf("The top student is: \n");
    int highestaggregate = 0;
    for (int i = 0; i < ns; i++)
    {
        if (students[i].aggregateMarks > highestaggregate)
        {
            highestaggregate = students[i].aggregateMarks;
        }
    }
    for (int j = 0; j < ns; j++)
    {
        if (students[j].aggregateMarks == highestaggregate)
        {
            printRecord(students[j]);
        }
    }
}