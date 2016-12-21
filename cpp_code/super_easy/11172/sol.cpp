#include<cstdio>
using namespace std;
int main(){
int t;
scanf("%d",&t);
while(t--)
{
long long int a,b;
scanf("%lld %lld",&a,&b);
if(a<b){

printf("<\n");
}
else if(a>b)
{
printf(">\n");

}
else
printf("=\n");


}

return 0;
}

