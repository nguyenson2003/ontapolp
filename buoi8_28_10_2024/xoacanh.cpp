#include <bits/stdc++.h>
#define int long
#define long long long
#define keqing main
const int mod = 1000000007;
const int limit = 101;
int parent[limit]={};
int count[limit]={};
int root(int u){
    if(parent[u]==u)return u;
    return parent[u]=root(parent[u]);
}
void join(int u,int v){
    int ru=root(u);
    int rv=root(v);
    if(ru==rv){
        return;
    }
    count[rv]+=count[ru];
    parent[ru]=rv;
}
keqing(){
    int n,m,q;std::cin>>n>>m>>q;
    for(int i=0;i<n;i++){
        parent[i]=i;
        count[i]=1;
    }
    std::pair<int,int> a[m]={};
    for(int i=0;i<m;i++){
        int u,v;std::cin>>u>>v;
        u--;v--;
        a[i]={u,v};
    }
    std::pair<int,int> query[q]={};
    bool isdel[m]={};
    for(int i=0;i<q;i++){
        int u,v;std::cin>>u>>v;
        u--;v--;
        query[i]={u,v};
        isdel[u]=true;
    }
    for(int i=0;i<m;i++){
        if(isdel[i])continue;
        join(a[i].first,a[i].second);
    }
    int res[q]={};
    for(int i=q-1;i>=0;i--){
        res[i]=count[root(query[i].second)];
        join(a[query[i].first].first, a[query[i].first].second);
    }
    for(int i=0;i<q;i++){
        std::cout<<res[i]<<std::endl;
    }
}