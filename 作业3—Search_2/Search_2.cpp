

#include <iostream>
using namespace std;

int Search_1(int* num, int c, int n) {
    int l, r;
    l = 0;
    r = c-1;
    int mid = (l + r) / 2;
    while (1 != (r-1)) {
        if (num[mid] > n) {
            r = mid;
            mid = (l + r) / 2;
        }
        else if (num[mid] < n) {
            l = mid;
            mid = (l + r) / 2;
        }
        else {
            return mid + 1;
        }
        
        return 0;
    }
}

int main()
{
    int c;
    cin >> c;
    int* num = (int*)malloc(sizeof(int) * c);
    for (int i = 0; i < c; i++) {
        num[i] = i + 1;
    }
    int k;
    cin >> k;
    cout << Search_1(num, c, k);
}