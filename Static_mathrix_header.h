#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#define N 10

void Input1(int *p_n1, int *p_m1, int *arr1[N]);
void Input2(int *p_n2, int *p_m2, int *arr2[N]);
void Menu(int *p_n1, int *p_m1, int *p_n2, int *p_m2, int *arr1[N], int *arr2[N]);
void Print(int *p_n, int *p_m, int *arr[N]);
void Transpose(int *p_n, int *p_m, int *arr[N]);
void Matrix_addition(int *p_n1, int *p_m1, int *p_n2, int *p_m2, int *arr1[N], int *arr2[N]);
void Matrix_multiplicate(int *p_n1, int *p_m1, int *p_n2, int *p_m2, int *arr1[N], int *arr2[N]);
void Exit();