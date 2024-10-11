#include <bits/stdc++.h>
#define int long
#define long long long
#define keqing main
const int mod = 1000000007;
const int limit = 100001;

int pow_mod(int a,int b, int m){
    if(b==0) return 1;
    if(b==1) return a%m;
    int temp = pow_mod(a,b/2,m);
    return temp*temp%m*pow_mod(a,b%2,m)%m;
}
keqing(){
    int a,b;std::cin>>a>>b;
    printf("%03d",pow_mod(a,b,1000));
}