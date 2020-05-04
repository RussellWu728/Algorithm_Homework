num=[]
count=0
print("输入开始时间与截止时间（整数），输入0 0停止:")
n,m=map(int,input().split())
while(n!=0 and m!=0):
    a=(n,m)
    num.append(a)
    n, m = map(int, input().split())
nn=sorted(num,key=lambda x:x[1])
great=[]
great.append(nn[0])
count=count+1
for i in range(1,len(nn)):
    if(nn[i][0]>=great[len(great)-1][1]):
        great.append(nn[i])
        count=count+1
print(great)
print("最多共{:d}个活动".format(count))