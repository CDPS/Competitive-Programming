#include <bits/stdc++.h>
 
using namespace std;
 
class SegmentTree{
 
public:
 
    vector<int> a;
    vector<long> tree;
    vector<long> state;
 
    int n;
 
    SegmentTree(int m) : n(m){
        int h = 1 + ceil(log2(n));
        a.resize(n);
        tree.resize( 1 << h );
        state.resize( 1 << h);
    }
 
    void init(){ build(1,0,n-1);}
 
    void build(int node,int l, int h){
 
        state[node] = 0;
 
        if(l==h){ tree[node]= a[l]; return; }
 
        int lf = node*2; int rt = lf+1; int mid = (l+h)/2;
 
        build(lf,l,mid);  build(rt,mid+1,h);
 
        tree[node] = tree[lf] + tree[rt];
    }
 
    long query(int i,int j){ return _query(1 , 0 , n-1 , i , j ); }
 
    long _query(int node, int l, int h, int i, int j){
 
        if( h < i ||  l > j) return 0;
 
         propagate(node,l,h);
 
         if(l >= i && h <= j) return tree[node];
 
        int lf = node*2; int rt = lf+1; int mid = (l+h)/2;
 
        return _query(lf, l, mid, i, j) +  _query(rt, mid+1,h,i,j);
    }
 
    void update(int i, int j, int v){ _update(1,0,n-1,i,j,v);    }
 
    void _update(int node, int l, int h, int i, int j, int v){
 
        propagate(node,l,h);
 
        if( h < i ||  l > j) return;
 
        if(l==h){ tree[node]+=v; state[node]=0; return; }
 
        int lf = node*2; int rt = lf+1; int mid = (l+h)/2;
 
        if(l >= i && h <= j){
            tree[node] += (h-l+1)*v;
            state[lf]  += v;
            state[rt]  += v;
            return;
        }
 
        _update(lf, l, mid, i, j,v);  _update(rt, mid+1,h,i,j,v);
        tree[node] = tree[lf]  + tree[rt];
    }
 
    void propagate(int node, int l, int h){
 
        if(state[node]==0) return;
 
        tree[node]+= (h-l+1)*state[node];
 
        if(l!=h){
            int lf = node*2; int rt = lf +1;
            state[lf]+= state[node]; state[rt]+=state[node];
        }
        state[node]=0;
    }
};
 
int main(){
    int t,caseno=1;
    scanf("%d",&t);
 
    int n,q,qi,h,l,v;
 
    while(t--){
        scanf("%d %d",&n,&q);
 
        SegmentTree st(n);
        for(int i=0;i<n;i++)
            st.a[i]=0;
        st.init();
 
        printf("Case %d:\n",caseno++);
 
        while(q--){
            scanf("%d",&qi);
            if(qi){
                scanf("%d %d",&l,&h);
                printf("%ld\n",st.query(l,h));
            }else{
                scanf("%d %d %d",&l,&h,&v);
                st.update(l,h,v);
            }
        }
    }
 
    return 0;
}
