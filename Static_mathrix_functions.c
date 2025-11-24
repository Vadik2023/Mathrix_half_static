#include "Static_mathrix_header.h"

void Input1(int *p_n1, int *p_m1, int *arr1[N])
{
    printf("Please, write first matrix elements\n");

    for (int i = 0; i < *p_n1; i++)
    {
        for (int j = 0; j < *p_m1; j++)
        {
            scanf("%d", arr1[i] + j);
        }
    }
}

void Input2(int *p_n2, int *p_m2, int *arr2[N])
{
    printf("Please, write second matrix elements\n");

    for (int i = 0; i < *p_n2; i++)
    {
        for (int j = 0; j < *p_m2; j++)
        {
            scanf("%d", arr2[i] + j);
        }
    }
}

void Menu(int *p_n1, int *p_m1, int *p_n2, int *p_m2, int *arr1[N], int *arr2[N])
{
    char choice = 'y';
    printf("\nWelcome to menu!!\n");
    while ((choice == 'y') || (choice == 'Y'))
    {
        printf("What exact function do you want to perform?\n");
        printf("You need just to write a number, then press [ENTER]\n");
        printf("1 - Input first matrix\n");
        printf("2 - Print first matrix\n");
        printf("3 - Input second matrix\n");
        printf("4 - Print second matrix\n");
        printf("5 - Transportation first matrix\n");
        printf("6 - Transportation second matrix\n");
        printf("7 - Add matrix (just show, no modification)\n");
        printf("8 - Multiplicate first matrix to second (just show, no modification)\n");
        printf("9 - Multiplicate second matrix to first (just show, no modification)\n");
        printf("0 - Exit\n");
        printf("Function number: ");

        int func_num;

        // проверка корректного ввода числа
        if (scanf("%d", &func_num) != 1)
        {
            printf("Invalid input. Please enter a number.\n\n");
            while (getchar() != '\n'); // очистка буфера
            continue;
        }

        // очищаем остатки строки после числа (Enter или пробелы)
        int tmp;
        while ((tmp = getchar()) != '\n' && tmp != EOF);

        // выбор функции
        switch (func_num)
        {
        case 1:
            Input1(p_n1, p_m1, arr1);
            break;
        case 2:
            Print(p_n1, p_m1, arr1);
            break;
        case 3:
            Input2(p_n2, p_m2, arr2);
            break;
        case 4:
            Print(p_n2, p_m2, arr2);
            break;
        case 5:
            Transpose(p_n1, p_m1, arr1);
            break;
        case 6:
            Transpose(p_n2, p_m2, arr2);
            break;
        case 7:
            Matrix_addition(p_n1, p_m1, p_n2, p_m2, arr1, arr2);
            break;
        case 8:
            Matrix_multiplicate(p_n1, p_m1, p_n2, p_m2, arr2, arr1);
            break;
        case 9:
            Matrix_multiplicate(p_n2, p_m2, p_n1, p_m1, arr1, arr2);
            break;
        case 0:
            Exit();
            break;
        default:
            printf("Invalid function number.\n");
        }

        // безопасный цикл для вопроса y/n
        while (1)
        {
            printf("\nWould you like to continue? (y/n): ");

            int c;

            // пропускаем все пробелы и Enter от предыдущего ввода
            do
            {
                c = getchar();
                if (c == EOF) return; // защита
            } while (c == ' ' || c == '\n');

            // очищаем остаток строки после ввода
            while ((tmp = getchar()) != '\n' && tmp != EOF);

            if (c == 'y' || c == 'Y')
                break;
            else if (c == 'n' || c == 'N')
            {
                printf("\nreturn to main()\n");
                return;
            }
            else
                printf("Input invalid answer, try again\n");
        }
    }
}

void Print(int *p_n, int *p_m, int *arr[N])
{
    printf("Your matrix:\n");

    for (int i = 0; i < *p_n; i++)
    {
        for (int j = 0; j < *p_m; j++)
        {
            printf("%d ", *(arr[i] + j));
        }
        printf("\n");
    }
}

void Transpose(int *p_n, int *p_m, int *arr[N])
{
    int old_n = *p_n;
    int old_m = *p_m;

    int tmp[old_m][old_n];

    for (int i = 0; i < old_n; i++)
        for (int j = 0; j < old_m; j++)
            tmp[j][i] = *(arr[i] + j);

    for (int i = 0; i < old_m; i++)
        for (int j = 0; j < old_n; j++)
            *(arr[i] + j) = tmp[i][j];

    *p_n = old_m;
    *p_m = old_n;

    printf("Matrix has been transported\n");
}

void Matrix_addition(int *p_n1, int *p_m1, int *p_n2, int *p_m2, int *arr1[N], int *arr2[N])
{
    if ((*p_n1 == *p_n2) && (*p_m1 == *p_m2))
    {
        printf("If we add first matrix to second, we will have:\n");

        for (int i = 0; i < *p_n1; i++)
        {
            for (int j = 0; j < *p_m1; j++)
            {
                printf("%d ", *(arr1[i] + j) + *(arr2[i] + j));
            }

            printf("\n");
        }
    }
    else
    {
        printf("It is impossible to summarize it((");
    }
}

void Matrix_multiplicate(int *p_n1, int *p_m1, int *p_n2, int *p_m2, int *arr1[N], int *arr2[N])
{
    if (*p_m1 == *p_n2)
    {
        printf("If we multiplicate first matrix with second, we will have:\n");

        for (int i = 0; i < *p_n1; i++)
        {
            for (int j = 0; j < *p_m2; j++)
            {
                int tmp1[*p_m1];
                int tmp2[*p_n2];
                int sum = 0;

                for (int k = 0; k < *p_m1; k++)
                {
                    tmp1[k] = *(arr1[i] + k);
                }

                for (int k = 0; k < *p_n2; k++)
                {
                    tmp2[k] = *(arr2[k] + j);
                }

                for (int k = 0; k < *p_m1; k++)
                {
                    int t = tmp1[k] * tmp2[k];
                    sum = sum + t;
                }

                printf("%d ", sum);
            }
            printf("\n");
        }
    }
    else
    {
        printf("It is impossible to multiplicate it((");
    }
}

void Exit()
{
    exit(0);
}