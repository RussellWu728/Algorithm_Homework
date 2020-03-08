

#include <iostream>
using namespace std;


int** Creat(int s, int e) {
    int** num = (int**)malloc(sizeof(int*) * s);
    for (int i = 0; i < s; i++) {
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


int** Floyd(int** matrix, int s, int e) {

    for (int y = 0; y < s; y++) {
        for (int x = 0; x < s; x++) {
            for (int z=0; z < s;z++) {
                if (matrix[x][z] > (matrix[x][y] + matrix[y][z])) {
                    matrix[x][z] = (matrix[x][y] + matrix[y][z]);
                }
            }
        }
    }
    return matrix;
}


int main()
{
    int s, e;
    cin >> s >> e;
    int** num = Creat(s, e);
    int** matrix = Floyd(num, s, e);
    printf("\t0\t1\t2\t3\n");
    for (int i = 0; i < s; i++) {
        printf("%d:\t", i);
        for (int j = 0; j < s; j++) {
            printf("%d\t",matrix[i][j]);
        }
        printf("\n");
    }


    //测试是否输入成功
    /*for (int i = 0; i < s; i++) {
        cout << i << ":";
        for (Graph* w = (&num[i])->link; w; w = w->link) {
            cout << w->vertex << " ";
        }
        cout << endl;
    }*/
}
