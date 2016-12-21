#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

#define vi vector<int>
#define readi(x) scanf("%d",&x)
int main()
{
int n,k;
while(scanf("%d",&n)!=EOF){
vi arr(n,0);
arr[0]=1;
int old,ans=1;
readi(old);
for(int i=1;i<n;i++)
{
readi(k);
if (abs(old-k)>n-1||abs(old-k)<1||arr[(abs(old-k))])
ans=0;
else
arr[abs(old-k)]=1;
old=k;
}

//printf("%d",arr);
for(int i=0;i<n;i++)
{
if(!arr[i])
ans=0;
}
if(ans)
printf("Jolly\n");
else
printf("Not jolly\n");

arr.clear();
}
return 0;
}
