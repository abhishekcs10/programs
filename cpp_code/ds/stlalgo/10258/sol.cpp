#include<vector>
#include<cstdio>
#include<algorithm>
#include<iostream>
#include<sstream>
using namespace std;
#define ii vector<pair<int,int> >
#define iii vector<int, ii >
int main()
{
int test;
scanf("%d\n",&test);
vector<vector<pair<int,int> > > contest;
vector<pair<int, pair<int,int> > > sot;

while(test--){
for(int i=0;i<101;i++)
{
vector<pair<int,int> > init;
for(int j=0;j<10;j++)
{
init.push_back(make_pair(0,0));
}
contest.push_back(init);
init.clear();

}

while(1){
string str;
getline(cin,str);
if(str.length()==0)
break;
//cout<<"lop\n";
istringstream is(str);
int cno,pno,time;
char stat;
is>>cno>>pno>>time>>stat;
contest[cno][0].first=1;
if(stat=='I'&&contest[cno][pno].first==0)
{
contest[cno][pno].second+=20;
}
if(stat=='C'&&contest[cno][pno].first==0)
{
contest[cno][pno].first=1;
contest[cno][pno].second+=time;
}
}
for(int i=0;i<101;i++){
int ps=0,pt=0;
for(int j=1;j<10;j++){
		if(contest[i][j].first)
			{
			ps++;
			pt+=contest[i][j].second;
			}
	}
if(contest[i][0].first)
sot.push_back(make_pair(-ps,make_pair(pt,i)));
}
sort(sot.begin(),sot.end());
for(int i=0;i<sot.size();i++)
{
cout<<sot[i].second.second<<" "<<-sot[i].first <<" "<<sot[i].second.first<<endl;
}
if(test)
cout<<endl;
//cout<<"h"<<endl;
sot.clear();
contest.clear();
}
return 0;
}
