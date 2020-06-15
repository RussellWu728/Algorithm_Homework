#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

double Min = 100010; 
void compute(double* orig, double* index_x, int num, double* best);
double center(int t, double* orig, double* index_x);
void Dfs(int t, int num, double* orig, double* index_x, double* best);

int main() {
    int num;
    cout << "请输入圆的个数：";
    cin >> num;
    num = num + 1;
    double* orig = (double*)malloc(sizeof(double) * num);   //存储输入的圆
    double* index_x = (double*)malloc(sizeof(double) * num);   //存储圆心的横坐标
    double* best = (double*)malloc(sizeof(double) * num);   //存储最优圆的序列
    cout << "请输入圆的半径（以空格间隔）：" ; 
    for (int i = 1; i < num; i++) {
        cin >> orig[i];
    }
    Dfs(1,num, orig, index_x,best);
    cout << "最优圆排列长度：" << Min << endl;
    cout << "最优圆排列顺序：" << endl;
    for (int i = 1; i < num; i++) {
        cout << best[i] << " ";
    }
}

void compute(double* orig, double* index_x, int num, double* best) {
    double l = 0;
    double r = 0;
    for (int i = 1; i < num; i++) {
        l = min(l,index_x[i] - orig[i]);
        r = max(r,index_x[i] + orig[i]);
    }
    if ((r - l) < Min) {
        Min = r - l;
        for (int i = 1; i < num; i++)
            best[i] = orig[i];
    }

}

double center_x(int t, double* orig, double* index_x) {
    double l = 0;
    for (int i = 1; i < t; i++) {
        double temp = index_x[i] + 2.0 * sqrt((orig[t] * orig[i]));
        l = max(l, temp);
    }
    return l;
}


void Dfs(int t, int num, double* orig, double* index_x, double* best) {
    if (t == num) {
        compute(orig, index_x, num, best);
    }
    else {
        for (int i = t; i < num; i++) {
            swap(orig[t], orig[i]);
            double c = center_x(t, orig, index_x);
            if (orig[1] + c + orig[t] < Min) {
                index_x[t] = c;
                Dfs(t + 1, num, orig, index_x, best);
            }
            swap(orig[t], orig[i]);
        }
    }
}