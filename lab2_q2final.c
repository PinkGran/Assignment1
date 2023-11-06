#include <stdio.h>
#include <string.h> //to use strlen() function
#include <ctype.h>  //for the tolower() function
#define MAX_SUBJECTS 3
#define MAX_STUDENTS 4

typedef struct
{
    char firstName[50]; // initialising all the variables needed for this struct
    char lastName[50];
    int studentID;
    float subjectMarks[MAX_SUBJECTS];
    int aggregateMarks;
    char grade[15];
} record; // name of the struct

void enrol(record students[], int studentIndex);
void searchUpdate(record students[], int ns);
void topStudents(record students[], int ns);
void printRecord(record student);

int main()
{
    record students[MAX_STUDENTS]; // creating a variable using the struct defined earlier
    int numStudents = 0;           // to hold how many students the user has enrolled in so far
    int choice;

    do // Display menu options
    {
        printf("\nMenu:\n");
        printf("Enrol a student, Enter 1:\n");
        printf("For search update, Enter 2: \n");
        printf("For topStudents, Enter 3: \n");
        printf("To Exit, enter 4\n");
        scanf("%d", &choice); // Read user's choice

        switch (choice)
        {
        case 1:
            if (numStudents < MAX_STUDENTS) // checking to make sure user does not input more students than MAX_STUDENTS
            {
                enrol(students, numStudents);
                numStudents++; // increementing this variable after a student is enrolled
                printf("Student enrolled successfully.\n");
            }
            else
            {
                printf("Maximum number of students reached.\n"); // if number of students is greater than MAX_STUDENTS
            }
            break;
        case 2:
            searchUpdate(students, numStudents); // if user wants to search up a student
            break;
        case 3:
            topStudents(students, numStudents); // to find out top student
            break;
        case 4:
            printf("Exiting program.\n"); // exit program
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void enrol(record students[], int studentIndex) // Function to enroll a student
{
    printf("\nEnrolling student %d:\n", studentIndex + 1);

    printf("Enter first name: ");
    scanf(" %s", students[studentIndex].firstName); // storing user input to firstname

    printf("Enter last name: ");
    scanf(" %s", students[studentIndex].lastName); // storing user input to lastname

    printf("Enter student ID: ");
    while (scanf("%d", &students[studentIndex].studentID) != 1) // to make sure the user inputs a number
    {
        printf("\nPlease enter a valid student ID: ");
        fflush(stdin); // Clear input buffer
    }

    for (int i = 0; i < MAX_SUBJECTS; i++)
    {
        printf("Enter mark for Subject %d (type -1 if you do not want to enter the mark): ", i);
        while (scanf(" %f", &students[studentIndex].subjectMarks[i]) != 1) // to make sure the user inputs a number
        {
            printf("\nPlease enter a number(type -1 if you do not want to enter the mark): ");
            fflush(stdin); // Clear input buffer
        }
    }
    for (int i = 0; i < MAX_SUBJECTS; i++)
    {
        if (students[studentIndex].subjectMarks[i] == -1)
        {
            strcpy(students[studentIndex].grade, "undefined"); // display "undefined" if user input -1
            printf("Their grade is %s\n", students[studentIndex].grade);
            students[studentIndex].aggregateMarks = -1;
            printf("Their aggregate is :%d\n", students[studentIndex].aggregateMarks); // display aggergate as -1 if user input -1
            return;
        }
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
    aggregate = (totalMarks / 300) * 100; // finding aggregate and converting to percentage
    students[studentIndex].aggregateMarks = aggregate;
    printf("Their aggregate is :%d\n", aggregate);
    if (totalMarks >= 0) // assigning the grade for the aggregate marks
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

void searchUpdate(record students[], int ns) // Function to search for a student
{
    int userinput;
    printf("\n SearchUpdate\n");
    printf("\nDo you want to search by StudentID(1) or LastName(2)?: ");
    scanf(" %d", &userinput);
    switch (userinput)
    {
    case 1: // when user inputs student id
    {
        int studentid;
        printf("\nEnter Student ID: ");
        scanf(" %d", &studentid);
        for (int i = 0; i < ns; i++) // to go through each studentID to find if there is a match
        {
            if (students[i].studentID == studentid)
            {
                printRecord(students[i]); // if match was found, print all the details of the student
                char update;
                printf("Do you want to update any of the attributes? (Y/N): "); // asking if the user wants to change any attribute
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
                printf("Do you want to update subject grades? (Y/N): "); // asking if the user wants to update the grade of any of the subjects
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
            else
            {
                printf("Unfound\n");
            }
        }
        break;
    }       // end of case 1
    case 2: // when user inputs last name
    {
        char userlastname[20];
        printf("\nEnter the user's last name: ");
        scanf(" %s", &userlastname);
        for (int l = 0; l < strlen(userlastname); l++) // changing all the last names in records to lower case to compare with the user's input
        {
            userlastname[l] = tolower(userlastname[l]);
        }
        printf("%s", userlastname);

        for (int i = 0; i < ns; i++) // to go through each last name to find if there is a match
        {
            char lowercaselastname[35];
            strcpy(lowercaselastname, students[i].lastName);
            for (int l = 0; l < strlen(lowercaselastname); l++) // changing all the characters of the last name to lower case
            {
                lowercaselastname[l] = tolower(lowercaselastname[l]);
            }
            if (strcmp(lowercaselastname, userlastname) == 0)
            {
                printRecord(students[i]);
                char update;
                printf("Do you want to update any of the attributes? (Y/N): "); // asking if the user wants to change any attribute
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
                printf("Do you want to update subject grades? (Y/N): "); // asking if the user wants to update the grade of any of the subjects
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
            else
            {
                printf("Unfound\n");
            }
        }
        break;
    } // end of case 2
    default:
    {
        printf("Invalid Input\n");
    }
    } // end of switch
}

void printRecord(record student) // function to print out all the details of the student
{
    printf("\nStudent ID: %d\n", student.studentID);
    printf("First Name: %s\n", student.firstName);
    printf("Last Name: %s\n", student.lastName);
    printf("Aggregate Marks: %d\n", student.aggregateMarks);
    printf("Grade: %s\n", student.grade);
}
void topStudents(record students[], int ns) // Function to print the top student
{
    printf("The top student is: \n");
    int highestaggregate = 0;
    for (int i = 0; i < ns; i++)
    {
        if (students[i].aggregateMarks > highestaggregate) // to find out the highest aggregate
        {
            highestaggregate = students[i].aggregateMarks;
        }
    }
    for (int j = 0; j < ns; j++)
    {
        if (students[j].aggregateMarks == highestaggregate) // to find out which student got the highest aggregate
        {
            printRecord(students[j]);
        }
    }
}