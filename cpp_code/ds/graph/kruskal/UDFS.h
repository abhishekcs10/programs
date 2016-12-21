class UDFS{

    private:
        vi rank;
        vi parent;
        int noc;
    public:
        UDFS(int n){
            rank.assign(n,0);
            parent.assign(n,0);
            for(int i=0;i<n;i++){
                parent[i]=i;
            }
            noc=n;
        }

        int find_set(int n){
            if(parent[n]==n)
                return n;
            else
                return (parent[n]=find_set(parent[n]));
        }
        void find_union(int n1,int n2){
            int s1=find_set(n1);
            int s2=find_set(n2);
            if(s1==s2)
                return ;
			  else
                {
                if(rank[s1]<rank[s2]){
                    parent[s1]=s2;
                }
                else{
                    parent[s2]=s1;
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



