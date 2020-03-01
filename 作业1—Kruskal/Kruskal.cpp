// Kruskal.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>


typedef struct Node Graph;

typedef struct Node {
    int vertex;
    int weight;
    Graph* link;
};


void Insert(Graph* p, int vertex_1, int weight_1) {
    Graph* temp = (Graph*)malloc(sizeof(struct Node));
    temp->vertex = vertex_1;
    temp->weight = weight_1;
    temp->link = p->link;
    p->link = temp;
}


Graph* Create(int s, int e) {
    Graph* tu = (Graph*)malloc(sizeof(struct Node) * s);
    int i, x, v, w;
    for (i = 0; i < s; i++) {
        (&tu[i])->link = NULL;
    }
    for (i = 0; i < e; i++) {
        scanf_s("%d %d %d", &x, &v, &w);
        Insert(&tu[x], v, w);
        Insert(&tu[v], x, w);
    }
    return tu;
}






int** Kruskal(Graph* ptr, int v, int e) {    //v为顶点个数，e为边的个数
    int start;
    int final;
    int minlenth;
    int** num = (int**)malloc(sizeof(int*) * 5);
    for (int i = 0; i < v - 1; i++) {
        num[i] = (int*)malloc(sizeof(int) * 3);
    }
    int* bin = (int*)malloc(sizeof(int) * v);
    for (int a = 0; a < v; a++) {
        bin[a] = a;
    }
    for (int j = 0; j < v - 1; j++) {
        minlenth = 9999;
        for (int x = 0; x < v; x++) {
            for (Graph* m = (&ptr[x])->link; m; m = m->link) {
                int s = x;
                int f = m->vertex;
                while (1) {
                    if (bin[s] == s) {
                        break;
                    }
                    else {
                        s = bin[s];
                    }
                }
                while (1) {
                    if (bin[f] == f) {
                        break;
                    }
                    else {
                        f = bin[f];
                    }
                }
                if ((s != f) && (m->weight < minlenth)) {
                    minlenth = m->weight;
                    start = x;
                    final = m->vertex;
                }
            }
        }
        num[j][0] = start;
        num[j][1] = final;
        num[j][2] = minlenth;
        bin[start] = final;
    }
    return num;
}


int main()
{
    int v, e;
    printf("依次输入顶点个数、边个数：");
    scanf_s("%d %d", &v, &e);
    Graph* t1 = Create(v, e);
    /*for (int i = 0; i < 6; i++) {                     //测试图是否构建完成
        printf("%d:", i);
        for (Graph* w = (&t1[i])->link; w; w = w->link) {
            printf("%d ", w->vertex);
        }
        printf("\n");
    }*/
    int** num = Kruskal(t1, v, e);
    printf("Kruskal结果：\n");
    printf("起点\t终点\t权重\n");
    for (int i = 0; i < v - 1; i++) {
        printf("%d\t%d\t%d\n", num[i][0], num[i][1], num[i][2]);
    }
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
