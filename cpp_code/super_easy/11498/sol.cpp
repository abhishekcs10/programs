#include<cstdio>
using namespace std;
int main()
{
int t;
while((scanf("%d",&t))&&t)
{
int divx,divy,x,y;
scanf("%d %d",&divx,&divy);
for(int i=0;i<t;i++)
{
scanf("%d %d",&x,&y);

if(x==divx||y==divy)
printf("divisa\n");
if(x>divx && y>divy)
printf("NE\n");
if(x>divx && y<divy)
printf("SE\n");
if(x<divx && y>divy)
printf("NO\n");
if(x<divx && y<divy)
printf("SO\n");
}
}


return 0;
}
