#include <stdio.h>
#include <stdlib.h>
int* transpose(int* arr, int n, int m)
{
    int* arr_t = (int*) malloc(sizeof(int)*n*m);
    for (int i=0; i < n; i ++)
    {
        for (int j=0; j < m; j++)
        {
            arr_t[j*n + i] = arr[i*m + j];
        }
    }
    return arr_t;
}

int main()
{
    int n, m, k;
    scanf("%d %d", &n, &m);
    int* arr = (int*) malloc(sizeof(int)*n*m);
    for (int i=0; i < n; i++)
    {
        for (int j=0; j < m; j++)
        {
            scanf("%d", &k);
            arr[i*m + j] = k;
        }
    }
    int* arr_t = transpose(arr, n, m);
    for (int i=0; i < m; i++)
    {
        for (int j=0; j < n; j++)
        {
            printf("%d ", arr_t[i*n + j]);
        }
        printf("\n");
    }
    free(arr);
    free(arr_t);
}