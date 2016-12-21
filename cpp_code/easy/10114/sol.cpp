#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
#define id pair<int,double>
#define vid vector<id >
int main()
{
int month,dep;
double down,loan;
while ((scanf("%d %lf %lf %d",&month,&down,&loan,&dep))&&(month>0)){
vid arr;
int a;
double b;
for(int i=0;i<dep;i++)
{
scanf("%d %lf",&a,&b);
arr.push_back(make_pair(a,b));
}
//sort(arr.begin(),arr.end());
arr.push_back(make_pair(101,0));
double total_cost=(down+loan)*(1-arr[0].second),ppt=loan/month;
int a_mon=0,d_ind=1;
while(total_cost<loan){
loan-=ppt;
a_mon++;
if(arr[d_ind].first>a_mon)
total_cost*=(1-arr[d_ind-1].second);
else{
total_cost*=(1-arr[d_ind].second);
d_ind++;
}

}
if(a_mon==1)
printf("1 month\n");
else
printf("%d months\n",a_mon);

arr.clear();
}
return 0;
}
