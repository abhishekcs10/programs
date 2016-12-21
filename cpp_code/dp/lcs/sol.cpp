#include<cstdio>
#include<algorithm>
#include<string>
using namespace std;
#define LEFT 1
#define DIAG 2
#define DOWN 3

int lcs( string s1,int m,string s2,int n){

int dp[m+1][n+1],loc[m+1][n+1];
for(int i=0;i<m+1;i++)
{
for(int j=0;j<n+1;j++)
{
if(i*j==0)
{
dp[i][j]=0;
loc[i][j]=0;
}
else if(s1[i-1]==s2[j-1])
{
dp[i][j]=1+dp[i-1][j-1];
loc[i][j] = DIAG;
}
else{
dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
if(dp[i-1][j]>dp[i][j-1])
loc[i][j]=DOWN;
else
loc[i][j]=LEFT;
}
}
}

for(int i=m,j=n;i>0&&j>0;)
{
if(loc[i][j]==DIAG)
{printf("%c",s1[i-1]);
i=i-1;
j=j-1;
}
else if(loc[i][j]==DOWN)
i=i-1;
else
j=j-1; 
}
printf("\n");
return dp[m][n];
}




int main()
{

string s1="AGGTAB",s2="GXTXAYB";
printf("%d\n",lcs(s1,s1.size(),s2,s2.size()));

return 0;
}
