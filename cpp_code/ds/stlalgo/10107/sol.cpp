#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{

unsigned long long int s;
vector<unsigned long long int> arr;
while(scanf("%llu",&s)!=EOF){
arr.push_back(s);
sort(arr.begin(),arr.end());
int sz=arr.size();
if(arr.size()%2==0)
{
printf("%llu\n",(arr[sz/2]+arr[(sz/2)-1])/2);
}
else
{
printf("%llu\n",arr[sz/2]);

}


}

return 0;
}
