#include <bits/stdc++.h>

using namespace std;

const string endline = "\n";

vector<vector<int> > a;

int avg(int h, int w,int n, int m) {
  int ans=0, h1, w1;
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      if(n+i > h-1)
        h1 = n+i-h;
      else
        h1 = n+i;

      if(m+j > w-1)
        w1 = m+j-w;
      else
        w1 = m+j;

      ans += a[h1][w1];
    }
  }
  return ans;
}

int main(){
  int w,h,b,p;
  cin >> w >> h >> b;
  a = vector<vector<int> >(h, vector<int>(w));
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> p;
      a[i][j] = p;
    }
  }
  set<int> s;
  vector<vector<int> > aux = vector<vector<int> >(h, vector<int>(w));
  for(int k = 0; k < b; k++) {
    s.clear();
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
          aux[i][j]= avg(h, w, i, j);
          s.insert(avg(h, w, i, j));
        }
    }
    a = aux;
  }

  cout << s.size() << endline;

  return 0;
}
