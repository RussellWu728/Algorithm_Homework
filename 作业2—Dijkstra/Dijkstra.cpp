// Dijkstra.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;


int** Creat(int s,int e) {
    int** num = (int**)malloc(sizeof(int*) * s);
    for (int i=0; i < s; i++) {
        num[i] = (int*)malloc(sizeof(int) * s);
    }
    for (int i = 0; i < s; i++) {
        for (int j = 0; j < s; j++) {
            if (i == j) {
                num[i][j] = 0;
            }
            else {
                num[i][j] = 9999;
            }
        }
    }
    for (int i = 0; i < e; i++) {
        int start, vertex, weight;
        cin >> start >> vertex >> weight;
        num[start][vertex] = weight;
    }
    return num;
}

int* Dijkstra(int** num,int s,int e,int b, int f) {
    int flag = 1;
    int* visited = (int*)malloc(sizeof(int) * s);
    int* lenth = (int*)malloc(sizeof(int) * s);
    for (int i = 0; i < s; i++) {
        visited[i] = 0;
        lenth[i] = num[b][i];
    }
    visited[b] = 1;
    while(flag!=s){
        for (int i = 0; i < s; i++) {
            if (visited[i] == 1) {
                int minlenth = 9999;
                int v = i;
                for (int j = 0; j < s; j++) {
                    if (minlenth > num[i][j]&& visited[j]==0 ) {
                        minlenth = num[i][j];
                        v = j;
                        visited[v] = 1;
                        flag = flag + 1;
                        if (lenth[v] > lenth[i] + minlenth) {
                            lenth[v] = lenth[i] + minlenth;
                        }
                    }
                }
            }
        }
    }
    return lenth;
}



int main()
{
    int s, e;
    cin >> s >> e;
    int** num = Creat(s, e);
    int start, finals;
    cin >> start >> finals;
    int* min = Dijkstra(num, s, e, start, finals);
    for (int i = 0; i < s; i++) {
        printf("%d\t", min[i]);
    }

    //测试图是否输入成功
    /*printf("\t0\t1\t2\t3\t4\t5\t6\t7\n");  
    for (int i = 0; i < s; i++) {
        printf("%d:\t", i);
        for (int j = 0; j < s; j++) {
            printf("%d\t", num[i][j]);
        }
        printf("\n");
    }*/
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
