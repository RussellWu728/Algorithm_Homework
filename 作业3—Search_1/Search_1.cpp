

#include <iostream>
using namespace std;

int Search_1(int* num,  int c,int n) {

    int i ;
    for(i=0;i<c;i++ ){
        if (num[i] == n) {
            return i+1;
        }

    }
    return 0;

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
    cout<< Search_1(num,c, k);
}

