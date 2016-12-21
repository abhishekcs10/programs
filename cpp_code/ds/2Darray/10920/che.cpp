#include<cstdio>
using namespace std;
int main()
{
int n=3;
int k=1;
int ans=0,mans=0;
for(int i=0;i<32;i++)
{
ans=0;
while((k<<i) & n)
{ans++;
i++;
}
if(ans>mans)
mans=ans;
}
printf("%d\n",mans);
return 0;
}
