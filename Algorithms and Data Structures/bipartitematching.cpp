#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> node;

int  blacks,whites;

typedef vector<int> VI;
typedef vector<VI> VVI;

bool FindMatch(int i, const VVI &w, VI &mc, VI &seen) {
      for (int j = 0; j < w[i].size(); j++) {
        if (!seen[ w[i][j] ]) {
          seen[ w[i][j] ] = true;
          if (mc[ w[i][j] ] < 0 || FindMatch(mc[ w[i][j] ], w, mc, seen)) {
            mc[w[i][j] ] = i;
            return true;
          }
        }
      }
      return false;
}

//return the maximun bipartite matching on a graph
//using whites as |A| and blacks as |B|
int BipartiteMatching(const VVI &w) {
      VI mc = VI(blacks, -1);
      int ct = 0;
      for (int i = 0; i < whites; i++) {
        VI seen(blacks);
        if (FindMatch(i, w,mc, seen)) ct++;
      }
      return ct;
}
