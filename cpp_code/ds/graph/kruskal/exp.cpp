#include "library.h"
#include "UDFS.h"


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


int main()
{
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
