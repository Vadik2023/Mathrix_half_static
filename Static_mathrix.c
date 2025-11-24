#include "Static_mathrix_header.h"
#include "Static_mathrix_functions.c"

int main()
{
    int *arr1[N];
    int *arr2[N];

    int n1;
    int *p_n1 = &n1;

    int m1;
    int *p_m1 = &m1;

    int n2;
    int *p_n2 = &n2;

    int m2;
    int *p_m2 = &m2;

    printf("\nInput number of lines for a first matrix: ");
    scanf("%d", &n1);

    printf("Input number of columns for a first matrix: ");
    scanf("%d", &m1);
    printf("\n");

    if (n1 > m1)
    {
        for (int i = 0; i < n1; i++)
        {
            arr1[i] = (int*)malloc(n1 * sizeof(int));
        }
    }
    else
    {
        for (int i = 0; i < m1; i++)
        {
            arr1[i] = (int*)malloc(m1 * sizeof(int));
        }
    }

    printf("\nInput number of lines for a second matrix: ");
    scanf("%d", &n2);

    printf("Input number of columns for a second matrix: ");
    scanf("%d", &m2);
    printf("\n");

    if (n2 > m2)
    {
        for (int i = 0; i < n2; i++)
        {
            arr1[i] = (int*)malloc(n2 * sizeof(int));
        }
    }
    else
    {
        for (int i = 0; i < m2; i++)
        {
            arr1[i] = (int*)malloc(m2 * sizeof(int));
        }
    }

    Input1(p_n1, p_m1, arr1);
    Menu(p_n1, p_m1, p_n2, p_m2, arr1, arr2);


    if (*p_n1 > *p_m1)
    {
        for (int i = 0; i < *p_n1; i++)
        {
            free(arr1[i]);
        }
    }
    else
    {
        for (int i = 0; i < *p_m1; i++)
        {
            free(arr1[i]);
        }
    }

    if (*p_n2 > *p_m2)
    {
        for (int i = 0; i < *p_n2; i++)
        {
            free(arr2[i]);
        }
    }
    else
    {
        for (int i = 0; i < *p_m2; i++)
        {
            free(arr2[i]);
        }
    }

    return 0;
}