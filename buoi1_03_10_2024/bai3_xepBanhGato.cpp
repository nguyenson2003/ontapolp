#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    for(int i=0;i<t;i++){
        int n;cin>>n;
        double res =0;
        for(int i=0;i<n;i++){
            int a,b;cin>>a>>b;
            res+=a*1.0/b;
        }
        // cout<<res<<" ";
        if(res==1)cout<<"YES";
        else cout<<"NO";
        cout<<endl;
    }
}