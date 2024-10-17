#include <bits/stdc++.h>
#define int long
#define long long long
#define keqing main
const int mod = 1000000007;
const int limit = 100001;
int dp2chieu(int n){
    int dp[n+1][n+1]={};
    dp[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=n;j++){
            dp[i][j]=dp[i-1][j];
        }
        for(int j=0;j<=n;j++){
            if(i+j>n)break;
            dp[i][j+i]+=dp[i-1][j];
            dp[i][j+i]%=mod;
        }
    }
    return dp[n][n];
}
keqing(){
    int n;std::cin>>n;
    int dp[n+1]={};
    dp[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=n;j>=0;j--){
            if(j-i<0)break;
            dp[j]+=dp[j-i];
            dp[j]%=mod;
        }
    }
    std::cout<<dp[n];
}