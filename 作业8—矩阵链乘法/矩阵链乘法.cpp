// 矩阵链乘法.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;



void matrixcomputer(int* p, int L, int** m, int** s)
{
	int q, n = L ;
	for (int i = 1; i <= n; i++) {
		m[i][i] = 0;
	}
	for (int l = 2; l <= n; l++) 	/* 矩阵链的长度 */
	{
		for (int i = 1; i <= n - l + 1; i++)
		{
			int j = i + l - 1;         /* 等价于 l=j-i+1 */
			m[i][j] = 1000000000;
			for (int k = i; k <= j - 1; k++)
			{
				q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
				if (q < m[i][j])
				{
					m[i][j] = q;
					s[i][j] = k;
				}
			}
		}
	}
}

int main()
{
	int l;
	cin >> l;

	int* num = (int*)malloc(sizeof(int) * (l+2));
	int** arr = (int**)malloc(sizeof(int*) * (l+1));
	int** s = (int**)malloc(sizeof(int*) * (l+1));

	for (int i = 0; i <= l; i++) {
		arr[i] = (int*)malloc(sizeof(int) * (l + 1));
		s[i] = (int*)malloc(sizeof(int) * (l + 1));
	}
	for (int i = 0; i <= l; i++) {
		for (int j = 0; j <= l; j++) {
			arr[i][j] = 0;
			s[i][j] = 0;
		}
	}
	for (int i = 0; i <= l; i++) {
		cin >> num[i];
	}
	matrixcomputer(num, l, arr, s);
	/*for (int i = 0; i <= l; i++) {
		for (int j = 0; j <= l; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}*/
	cout << arr[1][l]<<endl;
	cout << s[1][l];
}

/*

6
30 35 15 5 10 20 25

*/