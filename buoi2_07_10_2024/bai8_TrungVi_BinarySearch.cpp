#include <bits/stdc++.h>
#define int long
#define long long long
#define keqing main
const int mod = 1000000007;
const int limit = 1000001;

keqing(){
	std::ios_base::sync_with_stdio(0); std::cin.tie(0);
    int k,q;
    std::cin>>k>>q;
    std::vector<int> v[k];
    for(int i=0;i<k;i++){
        int n;std::cin>>n;
        for(int j=0;j<n;j++){
            int x;std::cin>>x;
            v[i].push_back(x);
        }
        std::sort(v[i].begin(),v[i].end());
    }
    while(q--){
        int a,b;std::cin>>a>>b;
        a--;b--;
        
        int minres=-limit,maxres=limit;
        while(minres<maxres){
            int midres = (minres+maxres)/2;
			if(midres>minres)midres--;
            int lowera = std::upper_bound(v[a].begin(),v[a].end(),midres)-v[a].begin();
            int lowerb = std::upper_bound(v[b].begin(),v[b].end(),midres)-v[b].begin();
            if(lowera+lowerb<(v[a].size()+v[b].size())/2+1){
                minres=midres+1;
            }else{
                maxres=midres;
            }
        }
        int res1=minres;
        if((v[a].size()+v[b].size())%2==0){
            minres=-limit,maxres=limit;
            while(minres<maxres){
                int midres = (minres+maxres)/2;
				if(midres>minres)midres--;
                int lowera = std::upper_bound(v[a].begin(),v[a].end(),midres)-v[a].begin();
                int lowerb = std::upper_bound(v[b].begin(),v[b].end(),midres)-v[b].begin();
                if(lowera+lowerb<(v[a].size()+v[b].size())/2){
                    minres=midres+1;
                }else{
                    maxres=midres;
                }
            }
        }
        int res2 = minres;
        std::cout<<res1+res2<<'\n';
    }
}