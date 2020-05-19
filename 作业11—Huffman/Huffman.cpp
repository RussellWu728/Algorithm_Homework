#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;

typedef struct {
	unsigned int weight;
	unsigned int parent, lchild, rchild;
}HTNode, * HuffmanTree;

typedef char** HuffmanCode;

void Select(HuffmanTree* HT, int n, int* s1, int* s2);


void CreateHuffmanTree(HuffmanTree* HT, int* w, int n) {
	int m = 0; 
	HuffmanTree adjust = NULL; 
	int i = 0; 
	int s1 = 0;
	int s2 = 0;
	if (n <= 1) {
		return;
	}
	m = 2 * n - 1;
	*HT = (HuffmanTree)malloc((m + 1) * sizeof(HTNode));
	if (!*HT) {
		exit(-1);
	}
	for (adjust = *HT + 1, i = 1; i <= n; ++adjust, ++i) {
		adjust->weight = *(w + i - 1);
		adjust->parent = 0;
		adjust->lchild = 0;
		adjust->rchild = 0;
	}
	for (; i <= m; ++i, ++adjust) {
		adjust->parent = 0;
	}
	for (i = n + 1; i <= m; ++i) {
		Select(HT, i - 1, &s1, &s2);
		(*HT + s1)->parent = (*HT + s2)->parent = i;
		(*HT + i)->lchild = s1;
		(*HT + i)->rchild = s2;
		(*HT + i)->weight = (*HT + s1)->weight + (*HT + s2)->weight;
	}
}

int Min(HuffmanTree HT, int n) {
	unsigned int f_min = 100;
	int flag = 0;
	for (int i = 1; i <= n; ++i) {
		if ((HT + i)->weight < f_min && (HT + i)->parent == 0) {
			f_min = (HT + i)->weight;
			flag = i;
		}
	}
	(HT + flag)->parent = 1;
	return flag;
}

void Select(HuffmanTree* HT, int n, int* s1, int* s2) {
	int tmp = 0; 
	*s1 = Min(*HT, n);
	*s2 = Min(*HT, n);
	if ((*HT + *s1)->weight > (*HT + *s2)->weight) {
		tmp = *s1;
		*s1 = *s2;
		*s2 = tmp;
	}
}

void HuffmanCoding(HuffmanTree HT, HuffmanCode* HC, int n) {
	*HC = (HuffmanCode)malloc((n + 1) * sizeof(char*));
	if (!*HC) {
		exit(-1);
	}
	char* cd = (char*)malloc(n * sizeof(char));
	if (!cd) {
		exit(-1);
	}
	*(cd + n - 1) = '\0';
	int start = 0; 
	for (int i = 1; i <= n; ++i) {
		start = n - 1;
		for (int c = i, f = (HT + i)->parent; f != 0; c = f, f = (HT + f)->parent) {
			if ((HT + f)->lchild == c) {
				*(cd + --start) = '0';
			}
			else {
				*(cd + --start) = '1';
			}
		}
		*(*HC + i) = (char*)malloc((n - start) * sizeof(char));
		strcpy_s(*(*HC + i),strlen(cd+start)+1, cd + start);
	}
	free(cd);
}

void TraverseCoding(HuffmanCode HC, int n,int* w) {
	for (int i = 1; i <= n; ++i) {
		printf("%d的哈夫曼编码:",*(w+i-1));
		puts(*(HC + i));
	}
}
int main() {
	HuffmanTree HT = NULL;
	HuffmanCode HC = NULL;
	int* w = 0;
	int n = 0; 
	printf("请输入叶子结点的个数:");
	cin >> n;
	w = (int*)malloc(n * sizeof(int));
	if (!w) {
		exit(-1);
	}
	printf("请输入权值:");
	for (int i = 0; i < n; ++i) {
		scanf_s("%d", w + i);
	}
	CreateHuffmanTree(&HT, w, n);
	HuffmanCoding(HT, &HC, n);
	printf("遍历哈夫曼编码\n");
	TraverseCoding(HC, n,w);
	if (!HT && !HC) {
		printf("OK\n");
	}
	system("pause");
	return 0;
}


