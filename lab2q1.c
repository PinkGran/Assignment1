#include <stdio.h>
#include <stdbool.h>
#define SIZE 24
#define nRows 8
#define nCols 3
// FUNCTION PROTOTYPES
void print_array(int array[], int length);
void print_matrix(int mat[][nCols], int rows);
void set_array(int arr[], int length);
void rem_align(int arr[], int length, int pos);
void insert_align(int arr[], int length, int pos, int value);
void reshape(int arr[], int length, int arr2d[nRows][nCols]);
void print_trans_matrix(int arr[], int arr2d[nRows][nCols]);
bool found_duplicate(int arr[], int length);
void flip_array(int arr[], int length);
int main()
{
    int arr[SIZE];
    int arr2d[nRows][nCols];
    bool answer;

    print_array(arr, SIZE);
    printf("\n");
    print_matrix(arr2d, nRows);
    printf("\n");

    set_array(arr, SIZE); // sets the value of each array element to its index in the array
    printf("\nnew array after removing element 3: \n");
    rem_align(arr, SIZE, 3);

    printf("\nnew array after adding the number 64 in position 5: \n");
    insert_align(arr, SIZE, 5, 64);

    printf("\nnew array after copying 1D array to a 2D array: \n");
    reshape(arr, SIZE, arr2d);

    printf("\nPrinting the values of arr2d column by column: \n");
    print_trans_matrix(arr, arr2d);

    printf("\nChecking to see if there are repeating values in the array: \n");
    // found_duplicate(arr, SIZE);
    answer = found_duplicate(arr, SIZE);
    if (answer == 0)
        printf("False\n");
    else
        printf("True\n");

    printf("\nReverse content of arr: \n");
    flip_array(arr, SIZE);
}

// FUNCTION DEFINITIONS
void print_array(int array[], int length)
{
    for (int i = 0; i < length; i++)
        printf("array[%d]= %d\n", i, array[i]);
}

void print_matrix(int mat[][nCols], int rows)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < nCols; j++)
            printf("mat[%d][%d]= %d\n", i, j, mat[i][j]);
        puts("");
    }
}
void set_array(int arr[], int length) //: sets the value of each array element to its index in the array, e.g., arr[3]=3.
{
    int i;
    for (i = 0; i < length; i++)
    {
        arr[i] = i; // setting the value of each array is equal to its index number
        printf("arr[%d]=%d\n", i, arr[i]);
    }
}
void rem_align(int arr[], int length, int pos)
{
    //: removes the array element at index pos by moving
    // its following array elements one index up in the array, see Fig 1.1. If the value of “pos” is not a valid
    // array index, print a relevant message and exit the function.
    int i;
    if (pos > length || pos < 0) // if pos is out of bounds
    {
        printf("Invalid position\n");
        return;
    }

    for (i = pos; i < length - 1; i++) // if pos is not out of bounds
    {
        arr[i] = arr[i + 1]; // moving the values of all the arrays after pos 1 step back since we are removing one array from the list
    }
    arr[length - 1] = 0; // putting the last array as zero

    for (i = 0; i < length - 1; i++)
    {
        printf("arr[%d]=%d\n", i, arr[i]); // printing out the new array
    }
}
void insert_align(int arr[], int length, int pos, int value)
{
    if (pos > length || pos < 0) // if pos is out of bounds
    {
        printf("Invalid position\n");
        return;
    }
    length++;
    int i;
    for (i = length - 1; i >= pos; i--)
    {
        arr[i] = arr[i - 1]; // moving the values of the array after pos by 1 step
    }
    arr[pos - 1] = value; // changing the value of the array at position to the specified value
    for (i = 0; i < length; i++)
    {
        printf("arr[%d]=%d\n", i, arr[i]); // printing out the new array
    }
}
void reshape(int arr[], int length, int arr2d[nRows][nCols])
{
    int product;
    product = nRows * nCols;

    if (length != product)
    {
        printf("Function will not work\n");
        return;
    }
    else
    {
        int i = 0;
        for (int j = 0; j < nRows; j++)
        {
            for (int k = 0; k < nCols; k++)
            {
                arr2d[j][k] = arr[i++]; // copying the elements of 1D array to 2D array
            }
        }
        for (int i = 0; i < nRows; i++)
        {
            for (int j = 0; j < nCols; j++)
            {
                printf("arr2d[%d][%d]=%d", i, j, arr2d[i][j]); // printing out the new 2D array
                printf("\n");
            }
            puts("");
        }
    }
}
void print_trans_matrix(int arr[], int arr2d[nRows][nCols])
{
    for (int i = 0; i < nCols; i++) // goes through columns first
    {
        for (int j = 0; j < nRows; j++) // then goes through the rows
        {
            printf("arr2d[%d][%d]=%d \n", j, i, arr2d[j][i]);
        }
        puts("");
    }
}
bool found_duplicate(int arr[], int length)
{
    for (int i = 0; i < length - 1; i++)
    {
        for (int j = i + 1; j < length; j++)
        {
            if (arr[i] == arr[j])
            {
                return true; // Found a duplicate
            }
        }
    }
    return false; // No duplicates found
}
void flip_array(int arr[], int length)
{
    int first = 0;
    int last = length - 1;

    while (first < last)
    {
        // Swap the elements at the start and end positions
        int temp = arr[first];
        arr[first] = arr[last];
        arr[last] = temp;

        // Move the start position forward and the end position backward
        first++;
        last--;
    }
    for (int j = 0; j < length; j++)
    {
        printf("arr[%d]=%d\n", j, arr[j]); // printing out the new 1D array
    }
}