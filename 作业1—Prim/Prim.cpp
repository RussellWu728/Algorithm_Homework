// Prim.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
    temp->weight =weight_1;
    temp->link = p->link;
    p->link = temp;
}


Graph* Create(int s, int e) {
    Graph* tu = (Graph*)malloc(sizeof(struct Node) * s);
    int i,x,v,w;
    for (i = 0; i < s; i++) {
        (&tu[i])->link = NULL;
    }
    for (i = 0; i < e; i++) {
        scanf_s("%d %d %d", &x, &v ,&w);
        Insert(&tu[x], v, w);
        Insert(&tu[v], x, w);
    }
    return tu;
}




int** Prim(Graph* ptr,int v, int k) {        //v为顶点个数，k为起点
    int* visited = (int*)malloc(sizeof(int) * v);
    for (int i = 0; i < v; i++) {
        visited[i] = 0;
    }
    visited[k] = 1;
    int** shortest = (int**)malloc(sizeof(int*) * v);
    for (int i = 0; i < v - 1; i++) {
        shortest[i] = (int*)malloc(sizeof(int) * 3);
    }
    for (int i = 0; i < v-1; i++) {
        Graph* temp;
        int minlenth;
        int min_index;
        int start;
        for (int j = 0; j < v; j++) {
            if (visited[j] == 1) {
                for (Graph* w = (&ptr[j])->link; w; w = w->link) {
                    if (visited[w->vertex] == 0) {
                        minlenth =w->weight;
                        min_index =w->vertex;
                        start = j;
                        break;
                    }
                }
            }
        }
        for (int x = 0; x < v; x++) {
            if (visited[x] == 1) {
                temp = (&ptr[x])->link;
                while (temp != NULL) {
                    if (temp->weight < minlenth && visited[temp->vertex] == 0) {
                        minlenth = temp->weight;
                        min_index = temp->vertex;
                        start = x;
                    }
                    temp = temp->link;
                }
            }
        }
        visited[min_index] = 1;
        shortest[i ][0] = start;
        shortest[i][1] = min_index;
        shortest[i][2] = minlenth;
    }
    return shortest;
}





int main()
{
    int v, e, k;
    printf("依次输入顶点个数、边个数、构建最小生成树起点：");
    scanf_s("%d %d %d",&v,&e,&k);
    Graph* t1 = Create(v, e);
    /*for (int i = 0; i < 6; i++) {                     //测试图是否构建完成
        printf("%d:", i);
        for (Graph* w = (&t1[i])->link; w; w = w->link) {
            printf("%d ", w->vertex);
        }
        printf("\n");
    }*/
    int** num_1 = Prim(t1, v, k);
    printf("Prim结果：\n");
    printf("起点\t终点\t权重\n");
    for (int i = 0; i < v-1; i++) {
        printf("%d\t%d\t%d\n", num_1[i][0], num_1[i][1], num_1[i][2]);
    }
    
}

