import numpy
def lcs(x, y):
    m = len(x) + 1
    n = len(y) + 1
    if m == 1 or n == 1:
        print("存在空字符串！")
        return -1
    lcs_len = numpy.zeros((m,n))

    for i in range(1, m):
        for j in range(1, n):
            if (x[i - 1] == y[j - 1]):
                lcs_len[i][j] = lcs_len[i - 1][j - 1] + 1
            else:
                max_len = lcs_len[i - 1][j]
                if lcs_len[i][j - 1] > lcs_len[i - 1][j]:
                    max_len = lcs_len[i][j - 1]
                lcs_len[i][j] = max_len
    i = m - 2
    j = n - 2
    ns = ''
    while 1:
        if i == -1 or j == -1:
            break
        if x[i] == y[j]:
            ns= x[i]+ns
            i = i - 1
            j = j - 1
        else:
            if lcs_len[i][j + 1] > lcs_len[i + 1][j]:
                i = i - 1
            else:
                j = j - 1
    print(ns)



s1=input()
s2=input()
#ABDCDAB
#BDACBA
#BDCA
lcs(s1,s2)