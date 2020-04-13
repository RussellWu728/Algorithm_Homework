// 动态规划——投资问题.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>



using namespace std;


int main()
{
    int pn;    //项目个数
    int money;    //总投资额
    cin >> pn >> money;
    int** arr_p;      //存储投资额与项目的关系
    int** arr_p_r;  //记录一定投资额下前k个项目可能获取的最大利润
    arr_p = (int**)malloc(sizeof(int*) * pn);
    arr_p_r = (int**)malloc(sizeof(int*) * pn);
    for (int i = 0; i <pn; i++) {
        arr_p[i] = (int*)malloc(sizeof(int) * (money+1));
        arr_p_r[i] = (int*)malloc(sizeof(int) * (money + 1));
    }
    for (int i = 0; i < pn; i++) {
        for (int j = 0; j <=money ; j++) {
            arr_p_r[i][j] = 0;
        }
    }

    for (int i = 0; i <pn; i++) {
        for (int j = 0; j <=money; j++) {
            cin >> arr_p[i][j];
        }
    }
    int j, i;
    for (i = 0; i < pn; i++) {
        for ( j = 0; j <= money; j++) {
            if (i == 0) {
                arr_p_r[i][j] = arr_p[i][j];
              
            }
            else {
                for (int k = 0; k <= j; k++) {
                    if (arr_p[i][k] + arr_p_r[i - 1][j - k] > arr_p_r[i][j]) //获取收益最大值时投资给自己的投资额
                    {
                        arr_p_r[i][j] = arr_p[i][k] + arr_p_r[i - 1][j - k];//更新此时最大收益
                    }
                }
            }
        }
    }
    cout << arr_p_r[pn - 1][money];


}

