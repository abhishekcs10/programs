#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

#define vc vector<char>
#define vvc vector<vc >

int find(vvc &A, vvc &B)
{
int N=A.size();
int n=B.size(),ans=0,match=1;
for(int i=0;i<N-n+1;i++)
{
for(int j=0;j<N-n+1;j++)
{
match=1;
	for(int x=0;x<n;x++)
	{
		for(int y=0;y<n;y++)
		{
			if(A[i+x][j+y]==B[x][y])
				continue;
			else{
				match=0;
				break;
			}
		}

	if(!match)
		break;
	}
if(match)
ans++;
}

}

return ans;
}

void rotate(vvc &A, vvc &B){
int n=A.size();
for(int i=0;i<n;i++)
{
for(int j=0;j<n;j++)
{
B[i][j]=A[n-j-1][i];
}
}

}
void print(vvc &A){
int n=A.size();
for(int i=0;i<n;i++)
{
for( int j=0;j<n;j++){

printf("%c",A[i][j]);
}
printf("\n");
}

}

int main()
{

int N,n;
vvc arr,search,rot;
vc row;
while(scanf("%d %d",&N,&n) &&(N||n)){
for(int i=0;i<N;i++)
{
for(int j=0;j<N;j++)
{
char k;
cin>>k;
row.push_back(k);
}
arr.push_back(row);
row.clear();
}

for(int i=0;i<n;i++)
{
for(int j=0;j<n;j++)
{
char k;
cin>>k;
row.push_back(k);

}
search.push_back(row);
rot.push_back(row);
row.clear();
}
int ans[4]={0,0,0,0};
ans[0]=find(arr,search);
rotate(search,rot);
ans[1]=find(arr,rot);
rotate(rot,search);
ans[2]=find(arr,search);
rotate(search,rot);
ans[3]=find(arr,rot);
printf("%d %d %d %d\n",ans[0],ans[1],ans[2],ans[3]);
arr.clear();
search.clear();
rot.clear();
}
return 0;
}
