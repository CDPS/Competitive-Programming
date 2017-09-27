#include <bits/stdc++.h>

using namespace std;

map< long , long> start;
map< long, long> finish;

class SegmentTree {
public:
   vector<long>  a, tree;

   SegmentTree(vector<long> &_a) : a(_a) {
      int n = a.size();
      tree =vector<long> (4 * n, 1);
      build(1, 0, n - 1);
   }

   void build(long  node, long  lo, long hi) {

      if(lo == hi) { tree[node] = a[lo]; return;}

      long mid = (lo+hi)/2;

      build(2*node, lo, mid);  build(2*node + 1, mid + 1, hi);

      tree[node] = max(tree[2*node], tree[2*node+1]);
   }

   long query(long i, long j) { return _query(1, 0, a.size() - 1, i, j);  }

   long _query(long node, long lo, long hi, long i, long j) {

      if(hi < i || lo > j) return -1;

      if(lo >= i && hi <= j) return tree[node];

      long mid = (lo + hi) / 2;

      return  max(_query(2*node, lo, mid, i, j) , _query(2*node+1, mid + 1, hi, i, j) );
   }

};


int main(){

    long n,q,l,h;

    while(true){

        scanf("%ld",&n); if(n==0)break;  scanf("%ld",&q);

        vector< long> v(n),frec(n);
        frec[0]=1;
        scanf("%ld",&v[0]);

        for(int i=1;i<n;i++){
            scanf("%ld",&v[i]);
            if(v[i]==v[i-1]){
                frec[i] = frec[i-1]+1;
            }else{
                start [ v[i] ]  =i;
                finish[ v[i-1] ]=i-1;
                frec[i]=1;
            }
        }

        SegmentTree st(frec);

        while(q--){
            scanf("%ld %ld",&l,&h);
            l--; h--;

            long nl=l,nh=h;

            long r1=-1,r2=-1,r3=-1;

            if(v[l]==v[h]){
                printf("%ld\n",(h-l)+1 );
                continue;
            }

            if( start[  v[l] ] !=l){
                r1 = (finish[ v[l] ] - l) +1;
                nl = finish[ v[l] ]+1;
            }

            if(finish [ v[h] ] !=h){
                r2 =  ( h- start[ v[h] ])+1;
                nh = start[ v[h] ]-1;
            }

            r3 = st.query(nl,nh);
            printf("%ld\n",max(r1,max(r2,r3)));
        }
        start.clear();
        finish.clear();
    }
    return 0;
}
