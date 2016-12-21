#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
long long int SZ,P;
while((scanf("%lld %lld",&SZ,&P))&&(SZ||P)){
long long int root=sqrt(P);
if(root*root==P && root%2==1){}
else if(root%2==1)
	root+=2;
else root+=1;

long long int i=root/2,j=root/2;
if (root*root!=1)
{

long long int group=(root*root-P)/(root-1);
if(group==0){
i+=P-root*root;

}
else if(group==1){

j-=(root*root-(root-1)-P);
i-=root-1;

}
else if(group==2){
i-=(root-1)+(P-(root*root-(root-1)*2));
j-=root-1;
}
else{
j-=(root-1)+(P-(root*root-(root-1)*3));

}


//
}

printf("Line = %lld, column = %lld.\n",SZ/2+i+1,SZ/2+j+1);


}
return 0;
}
