#include <bits/stdc++.h>
#define keqing main
int dp[1000]={};
int fibo(int n){
    if(n==0)return 0;
    if(n==1)return 1;
    if(dp[n]!=0)return dp[n];
    return dp[n] = fibo(n-1)+fibo(n-2);
}
keqing(){
    std::cout<<fibo(8);
}