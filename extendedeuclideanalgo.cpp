//+=
#include<bits/stdc++.h>
using namespace std;

int compute_gcd(int a, int b)
{
if(a%b==0)
return b;
else if(b%a== 0)
return a;
else if (a>b)
return compute_gcd(b,a%b);
else
return compute_gcd (a,b%a);

}

int extended_euclidean_algo(int a, int b, int *x, int *y  )
{
//this is based on the fact that ax+by=d is linear combination of d in terms of a and b and is quivalent to say d is gcd of a and b or the smallest positive integer that can be represented as linearcombination
//now we know a,b and d..we need to find x and y
cout<<"ent\n";
if(b==0)
{
*x=1;
*y=0;
return a;
}
int x1,y1;
int d=extended_euclidean_algo(b,a%b,&x1,&y1);
*x=y1;
*y=x1-(a/b)*y1;
return d;
}


int main()
{
int mod,num;
scanf("%d %d",&num,&mod);
//if(compute_gcd(num,mod)==1)
//{
int x=0,y=0;
int inv=extended_euclidean_algo(num,mod,&x,&y); // to find inverse is to solve ax=1modn where a and n are coprime
cout<<x<<" "<<y<<" "<<inv<<endl;

//}

return 0;
}
