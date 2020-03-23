// Sort_1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>


#define SWAP(x,y,t) ((t)=(x),(x)=(y),(y)=(t))
#define MAX 100000

typedef struct Node {
	int key;
}element;


element* Create(int n) {
	element* a = (element*)malloc(sizeof(struct Node) * (n + 1));
	int i;
	for (i = 1; i < n + 1; i++) {
		int m;
		scanf_s("%d", &m);
		a[i].key = m;
	}
	return a;
}



void merge(element init[], element merg[], int i, int m, int n) {
	int j, k, t;
	j = m + 1;
	k = i;
	while (i <= m && j <= n) {
		if (init[i].key <= init[j].key) {
			merg[k++] = init[i++];
		}
		else {
			merg[k++] = init[j++];
		}
	}
	if (i > m) {
		for (t = j; t <= n; t++) {
			merg[t] = init[t];
		}
	}
	else {
		for (t = i; t <= m; t++) {
			merg[k + t - i] = init[t];
		}
	}
}

void mergePass(element init[], element merg[], int n, int s) {
	int i, j;
	for (i = 1; i <= n - 2 * s + 1; i += 2 * s) {
		merge(init, merg, i, i + s - 1, i + 2 * s - 1);
	}
	if (i + s - 1 < n) {
		merge(init, merg, i, i + s - 1, n);
	}
	else {
		for (j = i; j <= n; j++) {
			merg[j] = init[j];
		}
	}
}

void mergeSort(element a[], int n) {
	element extra[MAX];
	int s = 1;
	while (s < n) {
		mergePass(a, extra, n, s);
		s *= 2;
		mergePass(extra, a, n, s);
		s *= 2;
	}
}



int main() {
	FILE* fp;
	fopen_s(&fp,"input.txt", "r");
	if (fp == NULL)
	{
		printf("Open input.txt file failure.\n");
		return 0;
	}
	int n;
	element* list;
	fscanf_s(fp, "%d", &n);
	while (n != -1) {
		list = (element*)malloc(sizeof(struct Node) * (n + 1));
		for (int i = 1; i <= n; i++) {
			fscanf_s(fp, "%d", &list[i].key);
		}
		mergeSort(list, n);
		printf("%d：\n", n);
		for (int j = 1; j <= n; j++) {
			printf("%d\t", list[j].key);
		}
		printf("\n");
		
	}
}