#include <bits/stdc++.h>

using namespace std;


class SegmentTree {

public:

   vector<int>  a, tree;

   SegmentTree(vector<int> &_a) : a(_a) {
      int n = a.size();
      tree =vector<int> (4 * n, 1);
      build(1, 0, n - 1);
   }

   void build(int node, int lo, int hi) {

      if(lo == hi) {
         tree[node] = a[lo];
         return;
      }
      int mid = (lo+hi)/2;

      build(2*node, lo, mid);
      build(2*node + 1, mid + 1, hi);

      tree[node] = tree[2*node] * tree[2*node+1];
   }

   int query(int i, int j) {
      return _query(1, 0, a.size() - 1, i, j);
   }

   int _query(int node, int lo, int hi, int i, int j) {

      if(hi < i || lo > j)
         return 1;

      if(lo >= i && hi <= j)
         return tree[node];

      int mid = (lo + hi) / 2;

      return _query(2*node, lo, mid, i, j) * _query(2*node+1, mid + 1, hi, i, j);
   }

   void update(int ind, int val) {
      _update(1, ind, val, 0, a.size() - 1);
   }

   void _update(int node, int ind, int val, int lo, int hi) {

      if(ind < lo || ind > hi)
         return;

      if(lo == hi) {
         tree[node] = val;
         return;
      }

      int mid = (lo + hi) / 2;

      _update(2*node, ind, val, lo, mid);
      _update(2*node + 1, ind, val, mid + 1, hi);

      tree[node] = tree[2*node] * tree[2*node+1];
   }
};


int main(){

    int n,k,d1,d2;
    char c;

    while(cin >> n >> k){
        vector<int> a;
        int ai;

        for(int i=0;i<n;i++){
            cin >> ai;
            if(ai>0)a.push_back(1);
            if(ai<0)a.push_back(-1);
            if(ai==0)a.push_back(0);
        }

        SegmentTree st(a);

        string s="";

        while(k--){
            cin >> c >> d1 >> d2;
            if(c=='C'){
               if(d2>0)d2=1;
               if(d2<0)d2=-1;
               if(d2==0)d2=0;

               st.update(d1-1,d2);
               a[d1-1]=d2;
            }
            else{
                int v = st.query(d1-1,d2-1);
                if( v > 0) s+='+';
                else if(v < 0) s+='-';
                else s+='0';
            }
        }
        cout << s << "\n";
    }
    return 0;
}
