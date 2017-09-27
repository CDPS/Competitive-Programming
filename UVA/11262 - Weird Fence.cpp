#include <bits/stdc++.h>

using namespace std;

int t,n,k,rc,bc;

struct point{
   int x,y;
   point(int a,int b){ x=a; y = b; }
};

vector<point> r,b;

double dis(point a,point b){
    return sqrt( ( (a.x-b.x) * (a.x-b.x) )  + ( (a.y-b.y)*(a.y-b.y) )  ) ;
}

bool findMatch(int i, const vector< vector<int> > &g, vector<int>  &blues, vector<int>  &visit) {

  for (int j = 0; j < g[i].size(); j++) {
    if (!visit[ g[i][j] ] ) {
      visit[ g[i][j] ] = true;
      if (blues[ g[i][j] ] < 0 || findMatch(blues[ g[i][j] ], g,  blues, visit)) {
        blues[ g[i][j] ] = i;
        return true;
      }
    }
  }
  return false;
}

int bipartiteMatching(const vector< vector<int> > &g) {

  vector<int> blues = vector<int> (bc, -1);

  int ans = 0;
  for (int i = 0; i < rc ; i++) {
    vector<int> visit(bc);
    if (findMatch(i, g,blues, visit)) ans++;
  }
  return ans;
}

vector < vector<int> > buildGraph(double d){
    vector<vector<int> > g(rc);
    for(int i=0;i<rc;i++)
        for(int j=0;j<bc;j++)
            if(dis(r[i],b[j])<=d)
                g[i].push_back(j);
    return g;
}

long binarySearch(double mind,double maxd){

    long l =long(mind), h = (maxd)+1, r=1000000, m;

    while(l<h){
        m = l + (h-l)/2;

        int matching = bipartiteMatching(buildGraph(double(m)) );
        if(k<=matching)
             h = m,r=m;
        else l = m+1;
    }
    return ( (r!=1000000)? r: -1);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    int x,y; string c;

    while(t--){

    	cin.ignore();
        cin >> n >> k;

        r=b=vector<point>();
        bc=rc=0;

        for(int i=0;i<n;i++){
            cin >> x >> y >> c;
            if(c[0]=='r')
                r.push_back(point(x,y)),rc++;
            else
                b.push_back(point(x,y)),bc++;
        }

        double maxd= -1, mind=1000000;

        for(int i=0;i<rc;i++)
            for(int j=0;j<bc;j++)
                maxd= max(maxd,dis(r[i],b[j])),mind= min(mind,dis(r[i],b[j]));

        long ans = binarySearch(mind,maxd);
        if(ans==-1) cout << "Impossible\n";
        else    cout << ans << "\n";
    }
    return 0;
}
