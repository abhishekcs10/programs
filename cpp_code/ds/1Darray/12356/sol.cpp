#include<cstdio>
#include<vector>
using namespace std;
int arrl[100005],arrr[100005];
int main(){
int s,b;

while((scanf("%d %d",&s,&b))&&(s||b)){

for(int i=1;i<s+1;i++)
{
arrl[i]=(i-1);
arrr[i]=(i+1);
}
arrr[s]=-1;
arrl[1]=-1;

for(int i=0;i<b;i++)
{
int l,r;
scanf("%d %d",&l,&r);

arrl[arrr[r]]=arrl[l];
arrr[arrl[l]]=arrr[r];
if(arrl[l]==-1)
printf("* ");
else
printf("%d ",arrl[l]);

if(arrr[r]==-1)
printf("*\n");
else
printf("%d\n",arrr[r]);
}
printf("-\n");
}
return 0;
}
