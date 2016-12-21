#include<cstdio>
#include<string>
#include<vector>
//changing s1 to s2
using namespace std;
int edit_distance(string s1,int m,string s2,int n,int replace_cost,int insertion_cost,int deletion_cost){
		int dp[m+1][n+1]; 
		for(int i=0;i<m+1;i++)
		{
				for(int j=0;j<n+1;j++)
				{
						if(i==0)
								dp[i][j]=j*insertion_cost;
						else if(j==0)
								dp[i][j]=i*deletion_cost;
						else if(s1[i-1]==s2[j-1])
								dp[i][j]=dp[i-1][j-1];
						else
						{
								dp[i][j]=min(insertion_cost+dp[i][j-1],min(deletion_cost+dp[i-1][j],replace_cost+dp[i-1][j-1]));

							}


					}

			}

	return dp[m][n];
	}
int main(){

					string s1="di",s2="ri";
						printf("%d\n",edit_distance(s1,s1.size(),s2,s2.size(),0,1,1));


												return 0;
												}
