#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<std::pair<int,int>, null_type,std::less<std::pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>
using namespace std;
#define keqing main
const int mod = 1000000007;
const int limit = 100001;
keqing(){
    int n,k;std::cin>>n>>k;
    int a[n]; for(int &x:a)std::cin>>x;
    ordered_set st;
    for(int i=0;i<k-1;i++){
        st.insert({a[i],i});
    }
    for(int i=k-1;i<n;i++){
        st.insert({a[i],i});
        cout<<st.find_by_order((k-1)/2)->first<<" ";
        st.erase({a[i-k+1],i-k+1});
    }
}