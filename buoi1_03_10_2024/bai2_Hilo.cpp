#include <bits/stdc++.h>
using namespace std;
#define int long long
#define main signed main
#define elif else if
#define fix_(x) setprecision(x)<<fixed
#define endl "\n"
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
string bit(int a){
    string s="";
    while (a>0)
    {
        if (a%2) s = '1' +s;
        else s = '0'+s;
        a/=2;
    }
    return s;
}
main(){
    FAST;
    int n;
    cin>>n;
    string s =bit(n);
    string res1="",res2="";
    int cnt=0;
    for (int i = s.size()-1;i>=0;i--){
        cnt++;
        if (cnt<=8){res2 = s[i] + res2;}
        else {
            res1 = s[i] +res1;
        }
    }
    n = res1.size();
    for (int i = n;i<8;i++){
        res1 = '0' +res1;
    }
    cout<<res1<<"\n"<<res2;
}