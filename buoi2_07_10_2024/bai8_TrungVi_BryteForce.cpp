#include <bits/stdc++.h>
using namespace std;
main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);

    int k,q;cin>>k>>q;
    vector<int> a[k];
    for(int i=0;i<k;i++){
        int n;cin>>n;
        for(int j=0;j<n;j++){
            int x;cin>>x;
            a[i].push_back(x);
        }
    }
    for(int i=0;i<q;i++){
        int x,y;cin>>x>>y;
        x--;y--;
        vector<int> newVector;
        for(int j=0;j<a[x].size();j++){
            newVector.push_back(a[x][j]);
        }
        for(int j=0;j<a[y].size();j++){
            newVector.push_back(a[y][j]);
        }
        sort(newVector.begin(),newVector.end());
        int res;
        if(newVector.size()%2==1){
            res=newVector[newVector.size()/2]*2;
        }else{
            res=newVector[newVector.size()/2]+newVector[newVector.size()/2-1];
        }
        cout<<res<<endl;
    }
    
}