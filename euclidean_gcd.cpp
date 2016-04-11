//+=
#include<bits/stdc++.h>
using namespace std;

int compute_gcd(int a, int b)
{
a=abs(a);
b=abs(b);
if(a==0||b==0)
return 0;
else if(a%b==0)
return b;
else if(b%a== 0)
return a;
else if (a>b)
return compute_gcd(b,a%b);
else
return compute_gcd (a,b%a);

}




int main()
{
int mod,num;
scanf("%d %d",&num,&mod);
cout<<"gcd is "<<compute_gcd(mod,num)<<endl;


return 0;
}
