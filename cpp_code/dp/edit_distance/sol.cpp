#include<cstdio>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;

int edit_distance(string s1,int m,string s2,int n){

int dp[m+1][n+1];
for (int i=0;i<=m;i++)
{
for(int j=0;j<n+1;j++)
{
if(i*j==0)					//always carefully think of base case you cannot always use geeks for geeks to correct your equation
//if first string is empty add j characters to s1 else delete i characters from s1 
dp[i][j]=abs(i-j);
else if(s1[i-1]==s2[j-1])
dp[i][j]=dp[i-1][j-1];
else{
dp[i][j]=1+ min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));	//here [i-1][j]=> that edited string s1 has deleted one character so the remaining string is matched with string s2
//[i][j-1] means we have inserted an element in s1 that is equal to s2 and thus length i of s1 is to be now matched with remaining s2 string
//[i-1][j-1] means that we have replaced s1[i] with s2[j] thus making two character equal and recurse on remaining length (i-1)(j-1)  
}

}
}

return dp[m][n];
}


int main()
{

string s1="alisha",s2="abhishek";
printf("%d\n",edit_distance(s1,s1.size(),s2,s2.size()));


return 0;
}
