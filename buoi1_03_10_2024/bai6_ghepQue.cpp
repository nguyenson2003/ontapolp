#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007L;
int main(){
    int n, m;cin>>n>>m;
    long long res = 0;
    for(int i=0;i<2000000;i++){
        int n_temp = n-2*i;
        int m_temp = m-2*i;
        if(n_temp%2==1)n_temp-=3;
        if(n_temp%4!=0)n_temp-=6;
        if(m_temp%2==1)m_temp-=3;
        if(m_temp%4!=0)m_temp-=6;
        if(n_temp<0||m_temp<0)continue;
        res+= (long long) (n_temp / 12 + 1) *(m_temp/12+1);
        res%=mod;
    }
    cout<<res;
}