#include <bits/stdc++.h>

using namespace std;

class SegmentTree {

public:

   int l;
   vector<int>  a, tree;

   SegmentTree(vector<int> &_a, int l) : a(_a), l(l) {
      int n = a.size();
      tree =vector<int> (4 * n, 0);
      build(1, 0, n - 1,  l );
   }

   void build(int node, int lo, int hi, int level) {

      if(lo == hi) {
         tree[node] = a[lo];
         return;
      }
      int mid = (lo+hi)/2;

      build(2*node, lo, mid, level - 1);
      build(2*node + 1, mid + 1, hi, level - 1 );

      if(level %2 )
        tree[node] = tree[2*node] | tree[2*node+1];
      else
        tree[node] = tree[2*node] ^ tree[2*node+1];
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
      _update(1, ind, val, 0, a.size() - 1, l);
   }

   void _update(int node, int ind, int val, int lo, int hi, int level) {

      if(ind < lo || ind > hi)
         return;

      if(lo == hi) {
         tree[node] = val;
         return;
      }

      int mid = (lo + hi) / 2;

      _update(2*node, ind, val, lo, mid, level - 1);
      _update(2*node + 1, ind, val, mid + 1, hi, level - 1);


     if(level %2 )
        tree[node] = tree[2*node] | tree[2*node+1];
      else
        tree[node] = tree[2*node] ^ tree[2*node+1];
   }
};

int main() {

    cin.sync_with_stdio(false); cin.tie(NULL);

    int n, m, p, b;
    cin >> n >> m;

    vector<int> a(1 << n);
    for (int i = 0; i < (1 << n); i++)
        cin >> a[i];

    SegmentTree st(a, n);
    while(m--){
        cin >> p >> b;
        st.update(p-1, b);
        cout << st.query(0, (1<<n)-1) << "\n" ;
    }

    return 0;
}
