#include<cstdio>
#include<vector>
#include<string>
#include<iostream>
#include<map>
using namespace std;
#define readi(x) scanf("%d ",&x)
#define vi vector<int>
#define vd vector<double>
#define mcd map<char, double>
int main(){
int n;
scanf(" %d ",&n);
while(n--){
int k;

readi(k);
mcd arr;
for(int i=0;i<k;i++){

char c;
double amt;
cin>>c>>amt;
arr[c]=amt;

}

//for(int i=0;i<256;i++)
//printf("%c \t %d \n",i,arr[i]);
//printf("\n");
int m,ans=0;
scanf("%d \n",&m);
char read;
string line;
for(int i=0;i<m;i++){
line="";
getline(cin,line);
//cout<<line<<endl;
//while((read=getchar())!=EOF){
for(int j=0;j<line.length();j++)
{
auto it=arr.find(line[j]);
if(it!=arr.end())
ans+=it->second;
}
//cout<< ans<<endl;
}

printf("%0.2lf$\n",ans/100.0);
arr.clear();
}



return 0;
}
