#include<stdio.h>
#include<stdlib.h>

int color[10000];
bool is_true(int k, int**num)
{
    int i, j;
    for (i = 1; i < k; i++)
    {
        if (num[k][i] == 1 && color[i] == color[k])
            return false;
    }
    return true;
}

void set_color(int n, int m, int**num)
{
    int i, k;
    for (i = 1; i <= n; i++)
        color[i] = 0;
    k = 1;
    while (k >= 1)
    {
        color[k] = color[k] + 1;
        while (color[k] <= m) {
            if (is_true(k, num)) {
                break;
            }
            else {
                color[k] = color[k] + 1;
            }
        }
        if (color[k] <= m && k == n)
        {
            for (i = 1; i <= n; i++)
                printf("%d", color[i]);
            printf("\n");
        }
        else if (color[k] <= m && k < n)
            k = k + 1;
        else
        {
            color[k] = 0;
            k = k - 1;
        }
    }
    if (color[1] == 0) {
        printf("NO");
    }
}
void main()
{
    int i, j, n, m;
   
    printf("输入顶点数n和着色数m:\n");
    scanf_s("%d%d", &n, &m);

    int** num = (int**)malloc(sizeof(int*) * (n+1));
    for (int a = 0; a <= n; a++) {
        num[a] = (int*)malloc(sizeof(int) * (n + 1));
    }

    printf("输入无向图的邻接矩阵:\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf_s("%d", &num[i][j]);
    printf("着色所有可能的解:\n");
    set_color(n, m, num);
}