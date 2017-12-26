#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> node;

int xs[4]={1,-1,0,0};
int ys[4]={0,0,1,-1};

int   pigs[10][10];
int wolves[10][10];
int n,m;


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

int BipartiteMatching(const VVI &w) {
      VI mc = VI(blacks, -1);
      int ct = 0;
      for (int i = 0; i < whites; i++) {
        VI seen(blacks);
        if (FindMatch(i, w,mc, seen)) ct++;
      }
      return ct;
}

int main(){

    for(int i=0;i<10;i++)for(int j=0;j<10;j++)pigs[i][j]=wolves[i][j]=-1;

    scanf("%d %d",&n,&m);

    char c;
    int p=0; int w= 0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            scanf(" %c",&c);
            if(c=='P') pigs[i][j]=p,p++;
            else if(c=='W') wolves[i][j]=w,w++;
        }


    whites = w;
    blacks = p;

    VVI g(whites,VI());

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
             if(wolves[i][j]!=-1){

                for(int k=0;k<4;k++){
                    int vx = i + xs[k];
                    int vy=  j + ys[k];

                    if(vx>=0 && vx < n && vy>=0 && vy <m){
                        if(pigs[vx][vy]!=-1){
                               g[  wolves[i][j]   ].push_back(pigs[vx][vy]);
                        }
                    }
                }
             }
        }
    }

    int ans = BipartiteMatching(g);
    printf("%d\n",ans);
    return 0;
}
