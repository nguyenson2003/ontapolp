#include <bits/stdc++.h>
using namespace std;
main(){
    int t;cin>>t;
    while (t-->0)
    {
        long long x,y;cin>>x>>y;
        long long bieny=2,bienx=1;
        long long res=3,ans=-1;
        while(x>=bienx || y>=bieny){
            if(x<=0||y<=0){
                ans=-1;
                break;
            }
            long long nextX = bienx+bieny;
            long long nextY = nextX + bieny;
            
            if(x==bienx && y <=bieny){
                ans=-1;
                break;
            }
            if(y==bieny && x<=nextX){
                ans=-1;
                break;
            }
            if(x==nextX && y<=nextY){
                ans=-1;
                break;
            }
            if(nextX>x && bieny>y){
                ans=res;
                break;
            }else if(nextX > x && nextY>y){
                ans = res+1;
                break;
            }
            bienx = nextX;
            bieny = nextY;
            res+=2;
        }
        cout<<ans<<endl;


    }
    
}