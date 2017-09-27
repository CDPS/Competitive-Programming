#include <bits/stdc++.h>

using namespace std;

#define MAXN 1024000
#define MAXH 21

#define N 0
#define F 1
#define E 2
#define I 3

class SegmentTree{

public:

    vector<int> a;
    vector<int> tree;
    vector<int> s;

    int n;

    SegmentTree(int m=0) : n(m){

        a.resize(MAXN);
        tree.resize( 1 << MAXH );
        s.resize( 1 << MAXH);
    }

    void init(){ build(1,0,n-1);}

    void build(int node, int lo, int hi) {

      s[node]=N; //up to update

      if(lo == hi) {  tree[node] = a[lo];  return;  }

      int mid = (lo+hi)/2;

      build(2*node, lo, mid);  build(2*node + 1, mid + 1, hi);

      tree[node] = tree[2*node] + tree[2*node+1];
   }

   int query(int i, int j) {  return _query(1, 0, n - 1, i, j);  }

   int _query(int node, int lo, int hi, int i, int j) {

      if(hi < i || lo > j)return 0;

      propagate(node,lo,hi);

      if(lo >= i && hi <= j) return tree[node];

      int lf= node*2; int rt = lf+1;  int mid = (lo + hi) / 2;

      return _query(lf, lo, mid, i, j) +  _query( rt, mid + 1, hi, i, j);
   }

   void Fupdate(int i,int j){ fupdate( 1, 0, n-1 , i , j ); }

   void fupdate(int node, int lo, int hi, int i, int j){

        propagate(node,lo,hi);

        //no overlap
        if(hi<i || lo > j) return;

        //its leave
        if(hi==lo){ tree[node]=1; s[node]=N;return;}

        int lf = node*2; int rt= lf +1; int mid= (hi+lo)/2;

        //total overlap
        if(lo >= i && hi <= j){
            tree[node] = hi - lo +1;
            s[lf] = s[rt] = F;
            return;
        }

        fupdate( lf, lo, mid, i ,j );  fupdate( rt, mid +1, hi, i, j );

        tree[node] = tree[lf] + tree[rt];
    }

    void Eupdate(int i, int j){ eupdate(1, 0 , n-1 , i , j ); }

    void eupdate(int node, int lo, int hi, int i, int j){

        propagate(node,lo,hi);

        //no overlap
        if(hi < i || lo > j) return;

        //its a leave
        if(lo == hi){  tree[node]=0; s[node]=N;return; }

        int lf = node*2; int rt= (node*2) +1; int mid= (hi+lo)/2;
        //total overlap
        if(lo >=i && hi <= j){
            tree[node]= 0;
            s[lf] = s[rt] = E;
            return;
        }

        eupdate( lf, lo, mid, i, j);  eupdate( rt, mid+1, hi, i, j);

        tree[node] = tree[lf] + tree[ rt];
    }

    void Iupdate(int i, int j){ iupdate( 1, 0, n-1, i ,j ); }

    void iupdate( int node, int lo, int hi, int i, int j){

        propagate(node,lo,hi);

        //no overlap
        if(hi < i || lo > j) return;

        //its a leave
        if(lo==hi){ tree[node] = (tree[node])? 0 : 1; s[node]=N; return;}

        int lf = node*2; int rt= (node*2) +1; int mid= (hi+lo)/2;

        //total overlap
        if(lo>=i && hi <=j){
            tree[ node ] = (hi -lo +1) - tree[node];
            s[lf] = getInverse(s[lf]);
            s[rt] = getInverse(s[rt]);
            return;
        }

        iupdate(lf,lo , mid, i , j);  iupdate(rt,mid +1 , hi ,i,j);

        tree[node] = tree[lf] + tree[rt];
    }

    int getInverse(int state){
        if(state== N) return I;
        if(state== F) return E;
        if(state== E) return F;
        if(state== I) return N;
    }

    void propagate(int node, int lo, int hi){

        if( s[node]==N ) return;
        else if( s[node]==E ) tree[ node ]=0;
        else if( s[node]==F ) tree[ node ] = hi-lo +1;
        else tree[ node ] = (hi -lo +1) - tree[ node ];

        if(lo!=hi){
            int lf = node*2; int rt = node*2 +1;

            if(s[node]==F || s[node]==E)
                s[lf]=s[rt]=s[node];
            else
                s[lf]=getInverse(s[lf]), s[rt]=getInverse(s[rt]);
        }
        s[node] = N;
    }
};

int main(){

    int t,caseno=1;

    cin >> t;

    int n,m,q,l,h, qi;
    char o;

    while(t--){
        cin >> n;

        string s="";
        string si;

        while(n--){
            cin >> m >> si;
            while(m--){s+=si;}
        }

        SegmentTree st(s.size());
        for(int i=0;i<s.size();i++){
            st.a[i] = s[i]-'0';
        }
        st.init();

        cin >> q;

        cout << "Case " << caseno++ << ":\n";
        qi=1;

        while(q--){
            cin >> o >> l >> h;
            if(o=='F') st.Fupdate(l,h);
            else if(o=='E') st.Eupdate(l,h);
            else if(o =='I') st.Iupdate(l,h);
            else cout << "Q" << qi++ << ": "<< st.query(l,h) << "\n";
        }
        st.a.clear();
        st.s.clear();
        st.tree.clear();
    }

    return 0;
}
