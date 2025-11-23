#include "Static_mathrix_header.h"
#include "Static_mathrix_functions.c"

int main()
{
    int n;
    int *p_n = &n;
    int m;
    int *p_m = &m;

    printf("\nInput number of lines: ");
    scanf("%d", &n);

    printf("Input number of columns: ");
    scanf("%d", &m);
    printf("\n");

    if(n > m)
        int *arr1[n];
    else
        int *arr2[m]
    
    for (int i = 0; i < n; i++)
    {
        arr1[i] = (int*)malloc(m * sizeof(int));
    }
    
    Input(p_n, p_m, matrix);
    Menu(p_n, p_m, matrix);

    return 0;
}