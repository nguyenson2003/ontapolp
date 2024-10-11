#include <bits/stdc++.h>
#define int long
#define long long long
#define keqing main
const int mod = 1000000007;
const int limit = 100001;
int a[100]={};int n;
int backtrack(int i,int giasan1,int giasan2){
    if(i==n){
        return std::abs(giasan1-giasan2);
    }
    int res1 = backtrack(i+1,giasan1+a[i],giasan2);
    int res2 = backtrack(i+1,giasan1,giasan2+a[i]);
    return std::min(res1,res2);
}

keqing(){
    std::cin>>n;
    for(int i=0;i<n;i++){
        std::cin>>a[i];
    }
    std::cout<<backtrack(0,0,0);
}