#include <bits/stdc++.h>
#define int long
#define long long long
#define keqing main
const int mod = 1000000007;
const int limit = 100001;

keqing(){
    int n;std::cin>>n;
    int dp[n+3]={};
    dp[0]=1;dp[1]=1;dp[2]=2;
    for(int i=3;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
    }
    std::cout<<dp[n];
}