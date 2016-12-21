#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define pii pair<int,int>
#define piii pair< pii, int >
#define vpiii vector<pii >
#define vvpii vector<vpii >
#define vi vector<int>
#define vvi vector<vi >
#define ppii pair< pii, pii >
#define vppii vector<ppii >
class UDFS{
    
    private:
        vi rank;
        vi p;
        int noc;
    public:
        UDFS(int n){
            rank.assign(n,0);
            p.assign(n,0);
            for(int i=0;i<n;i++){
                p[i]=i;
            }
            noc=n;
        }
        
        int find_set(int n){
            if(p[n]==n)
                return n;
            else
                return (p[n]=find_set(p[n]));
        }
        void find_union(int n1,int n2){
            int s1=find_set(n1);
            int s2=find_set(n2);
            if(s1==s2)
                return ;
            else
                {
                if(rank[s1]<rank[s2]){
                    p[s1]=s2;
                }
                else{
                    p[s2]=s1;
                    if(rank[s1]==rank[s2])
                        rank[s1]++;
                }
			}
                noc--;
            }

            
        bool is_same_set(int s1,int s2){
            if (find_set(s1)==find_set(s2))
                return true;
            else
                return false;
        }
         int numofcomp(){
             return noc;
         }
    
};

int cmp(ppii s1,ppii s2){
    if(s1.second.first<s2.second.first)
        return true;
    else if(s1.second.first>s2.second.first)
        return false;
    else {
        if(s1.second.second<s2.second.second)
            return true;
        else
            return false;
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   

    int n,m;
    cin>>n>>m;
    vppii edges;
    UDFS graph(n);
    for ( int i=0; i<m;i++)
        {
        pii bet;
        pii wt;
        cin>>bet.first>>bet.second>>wt.first;
        bet.first--;
        bet.second--;
        wt.second=bet.first+bet.second+wt.first;
        edges.push_back(make_pair(bet,wt));
        
    }
    sort(edges.begin(),edges.end(),cmp);
    int edge_no=0,wt_ans=0;
    while(graph.numofcomp()!=1 && edge_no<m){
        if(!graph.is_same_set(edges[edge_no].first.first,edges[edge_no].first.second)){
            graph.find_union(edges[edge_no].first.first,edges[edge_no].first.second);
            wt_ans+=edges[edge_no].second.first;
        }
        edge_no++;
    }
    cout<<wt_ans<<endl;
    return 0;
}
