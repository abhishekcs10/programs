#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

#define vi vector<int> 

int main()
{

int t;
vi arr;
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

sort(arr.begin(),arr.end());

printf("%d\n",(arr[n-1]-arr[0])*2);
arr.clear();
}


return 0;
}
