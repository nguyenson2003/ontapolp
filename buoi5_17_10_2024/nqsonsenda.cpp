#include <bits/stdc++.h>
#define int long
#define long long long
#define keqing main
const int mod = 1000000007;
const int limit = 100001;

keqing(){
    int n,w,t;std::cin>>n>>w>>t;
    int a[n]={};
    for(int &x:a)std::cin>>x;

    std::queue<int> water;
    int sum_water=0;
    int res=0;
    for(int i=0;i<t-1;i++){
        water.push(a[i]);
        sum_water+=a[i];
    }
    for(int i=t-1;i<n;i++){
        if(a[i]+sum_water < w){
            res+=w-sum_water-a[i];
            a[i]=w-sum_water;
        }
        water.push(a[i]);
        sum_water+=a[i];
        int out = water.front();
        water.pop();
        sum_water-=out;
    }
    std::cout<<res;
}