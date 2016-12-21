#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

#define vi vector<int> 

int main()
{

int t;
vi arr,arr2;
scanf("%d",&t);
while(t--)
{
int n;
scanf("%d",&n);
for(int i=0;i<n;i++){
int k;
scanf("%d",&k);
arr.push_back(k);
}
int ans=0;
for(int i=0;i<n;i++){
ans=0;
for(int j=0;j<n;j++){

ans+=abs(arr[i]-arr[j]);

}
arr2.push_back(ans);
}

sort(arr2.begin(),arr2.end());
printf("%d\n",arr2[0]);

arr.clear();
arr2.clear();
}


return 0;
}
