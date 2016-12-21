
#include<cstdio>
#include<queue>
#include<vector>
using namespace std;

#define ii pair<int,int>
#define vii vector<ii >
#define vvii vector<vii >
#define pb(i) push_back(i)
#define vi vector<int>
#define BLACK 1 //seen and visited
#define WHITE 0 //not seen
#define GREY 2 //seen but not visited

int bfs (vvii &graph,int src, vi &visited)
{
queue<int> tobe;
tobe.push(src);
int sz=0;
while(!tobe.empty()){
int k=tobe.front();
tobe.pop();
visited[k]=BLACK;
sz++;
for(int j=0;j<graph[k].size();j++)
	{
	if (visited[graph[k][j].first]==WHITE)
		{
			tobe.push(graph[k][j].first);
			visited[graph[k][j].first]=GREY;
		}
	}
}
return sz;
}

int all_black(vi &visited){
for(int i=0;i<visited.size();i++){
if(visited[i]==BLACK)
continue;
else
return i;
}
return -1;

}

int main()
{
int vertex,edge;
scanf("%d %d ",&vertex,&edge);
vvii graph(vertex);
vi visited(vertex);
for(int i=0;i<edge;i++)
{
int src,dst;
scanf("%d %d",&src,&dst);
graph[src].pb(make_pair(dst,1));
graph[dst].pb(make_pair(src,1));
}

vi components;
int next;
long long int ans=1;
while((next=all_black(visited))!=-1){

int fd=bfs(graph,next,visited);
components.push_back(fd);
ans*=fd;
} 
printf("%lld\n",ans);

return 0;
}
