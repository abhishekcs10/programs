#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

typedef struct interval{
int start;
int end;
int repeat;
}interval;



bool cmp(interval a,interval b){

if(a.end<b.end)
 return true;
else if(a.end==b.end && a.start<b.start)
	return true;
else 
	return false;
}

int main(){
int n,m;
vector<interval> arr;

while((scanf("%d %d",&n,&m)&&(n|m))){
 interval k;
for(int i=0;i<n;i++)
{
scanf("%d %d",&k.start,&k.end);
k.reapeat=0;
arr.push_back(k);
}

for(int i=0;i<m;i++)
{
interval k;
scanf("%d %d %d", &k.start,&k.end, &k.repeat);
arr.push_back(k);
}


sort(arr.begin(),arr.end(),cmp);



}

return 0;
}
