#include<cstdio>
#include<algorithm>
using namespace std;

#define vector<int> vi

int main(){

vi arr;
int n;
for(int i=0;i<n;i++)
{
int k;
scanf("%d",&k);
arr.push_back(k);
}


sort(arr.begin(),arr.end());
arr.resize(unique(arr.begin(),arr.end())-arr.begin());

return 0;
}
