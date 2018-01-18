#include <bits/stdc++.h>

using namespace std;

unsigned long long mmax =  0 -1;

unsigned long long fibos[93],a[100000];
set<unsigned long long > fiboSons;

class SegmentTree {

public:

   vector<int>     tree;
   int n;
   SegmentTree(int b) {
      n= b;
      tree = vector<int> (4 * n, 1);
      build(1, 0, n - 1);
   }

   void build(int node, int lo, int hi) {

      if(lo == hi) {
         tree[node] =  (fiboSons.find(a[lo])!=fiboSons.end())? 1 : 0;
         return;
      }
      int mid = (lo+hi)/2;

      build(2*node, lo, mid);
      build(2*node + 1, mid + 1, hi);

      tree[node] = tree[2*node] + tree[2*node+1];
   }

   int query(int i, int j) {
      return _query(1, 0, n - 1, i, j);
   }

   int _query(int node, int lo, int hi, int i, int j) {

      if(hi < i || lo > j)
         return 0;

      if(lo >= i && hi <= j)
         return tree[node];

      int mid = (lo + hi) / 2;

      return _query(2*node, lo, mid, i, j) + _query(2*node+1, mid + 1, hi, i, j);
   }

   void update(int ind, unsigned long long val) {
      _update(1, ind, val, 0, n - 1);
   }

   void _update(int node, int ind, unsigned long long val, int lo, int hi) {

      if(ind < lo || ind > hi)
         return;

      if(lo == hi) {
         tree[node] = (fiboSons.find(val)!=fiboSons.end())? 1 : 0;
         return;
      }

      int mid = (lo + hi) / 2;

      _update(2*node, ind, val, lo, mid);
      _update(2*node + 1, ind, val, mid + 1, hi);

      tree[node] = tree[2*node] + tree[2*node+1];
   }
};


void Fibo(){

    fibos[0]=1;fibos[1]=1;
    for(int i=2;i<93;i++)
        fibos[i]= fibos[i-1] + fibos[i-2];

    for(int i=0;i<93;i++)
        for(int j=i+1;j<93;j++)
        if (fibos[j] <= mmax - fibos[i] && fibos[i]+fibos[j]!=2ull)
            fiboSons.insert((fibos[i]+fibos[j]));
}

int main(){

    int n,q;
    cin.sync_with_stdio(false); cin.tie(NULL);

    Fibo();
    cin >> n >> q;
    for(int i=0;i<n;i++) cin >> a[i];

    int op;
    SegmentTree st(n);
    while(q--){
        cin >> op;
        if(op==1){
            int i,j;
            cin >> i >> j;
            cout << st.query(min(i-1,j-1),max(i-1,j-1)) << "\n";
        }else{
            int i; unsigned long long j;
            cin >> i >> j;
            st.update(i-1,j);
        }
    }
    return 0;
}
