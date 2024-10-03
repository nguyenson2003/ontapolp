#include <bits/stdc++.h>
using namespace std;
int main(){
    string str;cin>>str;
    int n = str.size();
    char c = '-';
    int res = 0;
    for(int i=0;i<n;i++){
        if(str[i]!='*' && str[i]!=c){
            res++;
            c=str[i];
        }
    }
    cout<<max(res,1);
}