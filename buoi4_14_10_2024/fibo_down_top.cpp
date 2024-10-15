#include <bits/stdc++.h>
#define int long
#define long long long
#define keqing main
const int mod = 1000000007;
const int limit = 100001;

keqing(){
    int n;std::cin>>n;
    int fibo[n+10]={};
    fibo[0]=0;fibo[1]=1;fibo[2]=1;
    for(int i=2;i<=n;i++){
        fibo[i]=fibo[i-1]+fibo[i-2];
    }
    std::cout<<fibo[n];
}