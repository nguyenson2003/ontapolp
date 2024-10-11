#include <bits/stdc++.h>
#define keqing main
int fibo(int n){
    if(n==0)return 0;
    if(n==1)return 1;
    return fibo(n-1)+fibo(n-2);
}
keqing(){
    std::cout<<fibo(8);
}