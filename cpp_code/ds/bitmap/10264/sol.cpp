#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
bool ispower2(int x)
{

return x && (!(x&(x-1)));

}

int main()
{

int dimen;
vector<int> arr,sum;
while(scanf("%d",&dimen)!=EOF){
int k;
for(int i=0;i<(1<<dimen);i++)
{
scanf("%d",&k);
arr.push_back(k);
sum.push_back(0);
}

for(int i=0;i<(1<<dimen);i++){

for(int j=0;j<dimen;j++)
{
int z=i^(1<<j);
sum[z]+=arr[i];
}
}

int max=0;
for(int i=0;i<(1<<dimen);i++)
{

for(int j=0;j<dimen;j++)
{
int z=i^(1<<j);
int some=sum[i]+sum[z];
if(some>max)
max=some;


}

}


//sort(sum.begin(),sum.end());
/*
int max=0;
for(int i=0;i<(1<<dimen);i++)
{
if(max<sum[i])
max=sum[i];
}*/
//printf("%d\n",(sum[sum.size()-1]+sum[sum.size()-2]));
printf("%d\n",max);
sum.clear();
arr.clear();
}
return 0;
}
