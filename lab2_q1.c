#include <stdio.h>
#include <stdbool.h>
#define SIZE 24
#define nRows 8
#define nCols 3
// PROTOTYPES
void print_array(int array[], int length);
void print_matrix(int mat[][nCols], int rows);
void set_array(int arr[], int length);
void rem_align(int arr[], int length, int pos);
void insert_align(int arr[], int length, int pos, int value);
void reshape(int arr[], int length, int arr2d[nRows][nCols]);
int main()
{
    int arr[SIZE];
    int arr2d[nRows][nCols];
    // Call to different functions
    print_array(arr, SIZE);
    printf("\n");
    print_matrix(arr2d, nRows);
    printf("\n");

    set_array(arr, SIZE); // sets the value of each array element to its index in the array
    printf("\nnew array after removing element 3: \n");
    rem_align(arr, SIZE, 3);
    printf("\nnew array after adding the number 65 in position 5: \n");
    insert_align(arr, SIZE, 5, 64);
    printf("\nnew array after copying 1D array to a 2D array: \n");
    reshape(arr, SIZE, arr2d);
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
        arr[i] = i;
        printf("arr[%d]=%d\n", i, arr[i]);
    }
}
void rem_align(int arr[], int length, int pos)
{
    //: removes the array element at index pos by moving
    // its following array elements one index up in the array, see Fig 1.1. If the value of “pos” is not a valid
    // array index, print a relevant message and exit the function.
    int i;
    if (pos > length || pos < 0)
    {
        printf("Invalid position\n");
        return;
    }

    for (i = pos; i < length - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    arr[length - 1] = 0;

    for (i = 0; i < length - 1; i++)
    {
        printf("arr[%d]=%d\n", i, arr[i]);
    }
}
void insert_align(int arr[], int length, int pos, int value)
{
    //      inserts the prameter value at the array
    // index pos while moving down by one position the original array elements from index pos onwards,
    // see Fig 1.2. If the value of pos is not a valid array index, print a relevant message and exit the
    // function.
    length++;
    int i;
    for (i = length - 1; i >= pos; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[pos - 1] = value;
    for (i = 0; i < length; i++)
    {
        printf("arr[%d]=%d\n", i, arr[i]);
    }
}
void reshape(int arr[], int length, int arr2d[nRows][nCols])
{
    // implements the two requirements:
    //  If the length of arr does not equal “nRows*nCols”, print a relevant error message and exit the
    // function.
    //  Else, copy the elements of the 1-D array arr into arr2d, row by row.
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
        for (int j = 0; i < nRows; j++)
        {
            for (int k = 0; k < nCols; k++)
            {
                arr2d[j][k] == arr[i];
                i++;
            }
        }
        for (int i = 0; i < nRows; i++)
        {
            for (int j = 0; j < nCols; j++)
            {
                printf("arr2d[%d][%d]=%d", i, j, arr2d[i][j]);
                printf("\n");
            }
        }
    }
}
