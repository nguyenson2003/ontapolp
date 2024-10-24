#include <bits/stdc++.h>
#define int long
#define long long long
#define keqing main
const int mod = 1000000007;
const int limit = 100001;

keqing(){
    int t;std::cin>>t;
    while(t--) {
        int a,b;std::cin>>a>>b;
        int res=0;
        while((a&1)==(b&1)){
            res++;
            a>>=1;b>>=1;
        }
        std::cout<<(1<<res)<<std::endl;
        
    }
}