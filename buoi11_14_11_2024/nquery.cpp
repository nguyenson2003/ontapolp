#include <bits/stdc++.h>
#define int long
#define long long long
#define keqing main
const int mod = 1000000007;
const int limit = 100001;

class Node
{
    public:
    Node *left, *right;
    int size;
    int depth;
    int tienTo, hauTo, tongDay, fx;
    Node(int value)
    {
        left = right = nullptr;
        size = 1;
        depth = 1;
        tienTo = hauTo = tongDay = fx = value;
    }
    Node(Node *l, Node *r)
    {
        left = l;
        right = r;
        cacl();
    }
    void cacl(){
        if(left==nullptr || right == nullptr)return;
        this->size = left->size + right->size;
        depth = std::max(left->depth, right->depth)+1;
        tienTo = (left->tienTo + right->tienTo + left->tongDay * right->size)%mod;
        hauTo = (right->hauTo + left->hauTo + right->tongDay * left->size)%mod;
        tongDay = (left->tongDay + right->tongDay)%mod;
        fx = (left->fx + right->fx + left->hauTo * right->size + right->tienTo * left->size)%mod;
    }
    void insert(int index, int value){
        if(size==1 && index==0){
            left = new Node(value);
            right = new Node(tongDay);
            cacl();
            return;
        }
        if(size==1 && index==1){
            left = new Node(tongDay);
            right = new Node(value);
            cacl();
            return;
        }
        if(index<=left->size){
            left->insert(index,value);
        }else{
            right->insert(index-left->size,value);
        }
        balance();
        cacl();
    }
    void del(int index){
        if(size==1 && index ==0){
            size=0;
            depth=0;
            tienTo=hauTo=tongDay=fx=0;
            return;
        }
        if(index<left->size){
            left->del(index);
        }else{
            right->del(index-left->size);
        }
        cacl();
    }
    Node* get(int fromIndex,int toIndex){
        if(fromIndex<=0 && size-1<=toIndex){
            return this;
        }
        if(toIndex<0 || fromIndex>=size){
            Node* temp = new Node(0);
            temp->size=0;
            return temp;
        }
        return new Node(
            left->get(fromIndex,toIndex),
            right->get(fromIndex-left->size,toIndex-left->size)
        );
    }
    void rotateRight(){
        right = new Node(left->right,right);
        left = left->left;
        cacl();
    }
    void rotateLeft(){
        left = new Node(left,right->left);
        right = right->right;
        cacl();
    }
    void balance(){
        if(depth<=5)return;
        if(left->depth>right->depth+1){
            if(left->left->depth < left->right->depth)left->rotateLeft();
            rotateRight();
        }
        if(right->depth>left->depth+1){
            if(right->right->depth < right->left->depth)right->rotateRight();
            rotateLeft();
        }
        cacl();
    }
};

keqing()
{
    int n;std::cin>>n;
    int a[n]; for(int &x:a)std::cin>>x;

    Node* root = new Node(a[0]);
    for(int i=1;i<n;i++){
        root->insert(i,a[i]);
    }
    int q = n;
    while(q--){
        char type;std::cin>>type;
        if(type=='C'){
            int index,value;std::cin>>index>>value;
            root->insert(index-1,value);
        }else if(type=='R'){
            int l,r;std::cin>>l>>r;
            std::cout<<root->get(l-1,r-1)->fx<<'\n';
        }else if(type=='U'){
            int index,value;std::cin>>index>>value;
            root->del(index-1);
            root->insert(index-1,value);
        }else{
            int index;std::cin>>index;
            root->del(index-1);
        }
    }
}