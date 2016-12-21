#include<algorithm>
#include<string>
#include<cstdio>
#include<iostream>
using namespace std;
int main(){
string s;
while(1){
cin>>s;
if(s.compare("#")==0)
break;
int test=next_permutation(s.begin(),s.end());
if(!test){
cout<<"No Successor\n";
}
else
cout<<s<<endl;
}
return 0;
}
