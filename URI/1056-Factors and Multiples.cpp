#include <bits/stdc++.h>

using namespace std;

long a[100];
long b[100];

typedef vector<int> VI;
typedef vector<VI> VVI;

bool FindMatch(int i, const VVI &w, VI &mr, VI &mc, VI &seen) {
  for (int j = 0; j < w[i].size(); j++) {
    if (w[i][j] && !seen[j]) {
      seen[j] = true;
      if (mc[j] < 0 || FindMatch(mc[j], w, mr, mc, seen)) {
        mr[i] = j;
        mc[j] = i;
        return true;
      }
    }
  }
  return false;
}

int BipartiteMatching(const VVI &w) {
  VI mr = VI(w.size(), -1);
  VI mc = VI(w[0].size(), -1);

  int ct = 0;
  for (int i = 0; i < w.size(); i++) {
    VI seen(w[0].size());
    if (FindMatch(i, w, mr, mc, seen)) ct++;
  }
  return ct;
}

int main(){

    int c,caseno=1;
    scanf("%d",&c);

    while(c--){
        int n,m;
        scanf("%d",&n);

        for(int i=0;i<n;i++){
            scanf("%ld",&a[i]);
        }

        scanf("%d",&m);

        for(int i=0;i<m;i++){
            scanf("%ld",&b[i]);
        }


        VVI w(n,VI(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(b[j]==0&&a[i]==0){
                    w[i][j]=1;
                }
                if(a[i]==0){
                    continue;
                }

                if(b[j]%a[i]==0){
                    w[i][j]=1;
                }
            }
        }

        int res = BipartiteMatching(w);

        printf("Case %d: %d\n",caseno++,res);

    }

    return 0;
}

