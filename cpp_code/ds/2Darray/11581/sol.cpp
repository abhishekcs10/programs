#include<cstdio>
#include<string>
#include<iostream>
using namespace std;

int count(int A[][3],int B[][3],int ct){
int done=1;
for(int i=0;i<3;i++)
{
for(int j=0;j<3;j++)
{
if(A[i][j])
{done=0;
break;
}
}
if(!done)
break;
}
if(done)
return ct;
B[0][0]=(A[0][1]+A[1][0])%2;
B[0][1]=(A[0][0]+A[1][1]+A[0][2])%2;
B[0][2]=(A[0][1]+A[1][2])%2;
B[1][0]=(A[0][0]+A[1][1]+A[2][0])%2;
B[1][1]=(A[1][0]+A[0][1]+A[2][1]+A[1][2])%2;
B[1][2]=(A[0][2]+A[1][1]+A[2][2])%2;
B[2][0]=(A[1][0]+A[2][1])%2;
B[2][1]=(A[2][0]+A[1][1]+A[2][2])%2;
B[2][2]=(A[1][2]+A[2][1])%2;
return count(B,A,ct+1);
}



int main()
{

int test;
int grid[3][3],fgrid[3][3];
scanf("%d\n",&test);
while(test--)
{
string s;
for(int i=0;i<3;i++){
s="";
cin>>s;
if(s.length()==0)
{
//cin.ignore();
getline(cin,s);
}
for(int j=0;j<3;j++)
{
fgrid[i][j]=0;
if(s[j]=='0')
grid[i][j]=0;
if(s[j]=='1')
grid[i][j]=1;
}
}
int ans=count(grid,fgrid,0);
ans--;

printf("%d\n",ans);
}
return 0;
}
