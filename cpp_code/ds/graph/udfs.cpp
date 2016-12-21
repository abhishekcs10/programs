#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

#define ii pair<int,int>
#define vii vector<ii >
#define vvii vector<vii >
#define vi vector<int>
#define vvi vector<vi >

class udfs{
private:
		vi rank;
		vi parent;
		vi sizeofcomp;
		int numofc;
public:
		udfs(int n){
			rank.assign(n,0);
			parent.assign(n,0);
			sizeofcomp.assign(n,1);
		for(int i=0;i<n;i++)
			parent[i]=i;

		numofc=n;
}

int findSet(int n){
if (parent[n]==n)
return n;
else
return (parent[n]=findSet(parent[n]));
}

bool issameset(int n1,int n2){
if(findSet(n1)==findSet(n2))
return true;
else
return false;
}

int find_union(int n1,int n2){


int s1=findSet(n1);
int s2=findSet(n2);
if(s1==s2)
return s1;
else if(rank[s1]>rank[s2])
{parent[s2]=s1;
sizeofcomp[s1]+=sizeofcomp[s2];
}
else {
parent[s1]=s2;
sizeofcomp[s2]+=sizeofcomp[s1];
if(rank[s1]==rank[s2])
rank[s2]++;
}
numofc--;

}

int noc(){

return numofc;

}

int component_size(int vertex){

int rep=findSet(vertex);
return sizeofcomp[rep];

}

vi all_unique_component_size(){
vi ans;
int n=parent.size();
for(int i=0;i<n;i++)
{
if(parent[i]==i)
ans.push_back(sizeofcomp[i]);
}
return ans;
}

};


int main(){


int vertices,edges;
scanf("%d %d",&vertices,&edges);
udfs graph(vertices);
for(int i=0;i<edges;i++)
{
int src,dst;
scanf("%d %d",&src,&dst);
graph.find_union(src,dst);

}

int numComponents=graph.noc();

vi sizes=graph.all_unique_component_size();

 long long int totalWays = vertices*(vertices-1) / 2;
 long long int sameWays = 0;
    
    for(int i=0;i<numComponents;i++)
    {    
        sameWays = sameWays + (sizes[i]*(sizes[i]-1) / 2);
    }
    
printf("%lld",totalWays-sameWays);
printf("\n");

return 0;


}
