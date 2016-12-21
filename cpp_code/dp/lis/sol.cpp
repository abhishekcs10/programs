#include<cstdio>
#include<algorithm>
using namespace std;


int lis(int arr[],int n){
int dp[n+1];
for(int i=0;i<=n;i++)
{
dp[i]=1;
}

for(int i=1;i<n+1;i++)  // recursive equation lcs(i)=max(1,lcs(j)) where 0<=j<i 
//the intuition is that we calculate lis for array upto index i and then check how the lis can be obtained for i+1 elements.
//the dp[i] index will contain lis for element considering i th element is added in lis and lis for i-1 will already be calculated
{
for(int j=0;j<i;j++)
{
if(arr[j]<arr[i])
	{
	dp[i]=max(dp[i],dp[j]+1);
	}
	}
}

int ans=0,ind=-1;
for(int i=0;i<n;i++)
{
if(dp[i]>ans)
{
ans=dp[i];
ind=i;
}
}
int loop=ans-1;
printf("%d\t",arr[ind]);
for(int i=ind;i>=0&&loop>0;loop--)
{
for(int j=0;j<i;j++)
{
if(arr[j]<arr[i]&&dp[i]==dp[j]+1)
{printf("%d\t",arr[j]);
i=j;
break;
}

}
}
return ans;
}

int main(){
int arr[]={ 10, 22, 9, 33, 21, 50, 41, 60 };
printf("%d\n",lis(arr,sizeof(arr)/sizeof(arr[0])));

return 0;
}
