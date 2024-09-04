#include <bits/stdc++.h>

using namespace std;

double oo  = 10000000;
double EPS = 1e-12;

struct point {
  double x, y;
  point() {}
  point(double x, double y) : x(x), y(y){}
  point(const point &p) : x(p.x), y(p.y){}
  point operator + (const point &p) const { return point(x+p.x, y+p.y); }
  point operator - (const point &p) const { return point(x-p.x, y-p.y); }
  point operator * (double c) const { return point(x*c, y*c);}
  point operator / (double c) const { return point(x/c, y/c);}
};

double dot(point p, point q) { return p.x*q.x+p.y*q.y; }
double dist(point p, point q){ return dot(p-q,p-q); }

point cross(point a, point b, point c) {
  double r = dot(b-a,b-a);
  if (fabs(r) < EPS) return a;
  r = dot(c-a, b-a)/r;
  if (r < 0) return a;
  if (r > 1) return b;
  return a + (b-a)*r;
}

double distPointLine(point a, point b, point c) {
  return sqrt(dist(c, cross(a, b, c)));
}

int main() {

    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios_base::fixed);
    cout.precision(3);

    string line;
    while(cin >> line && line != "*") {

        vector<point> a;
        stringstream ss(line);
        int n; ss >> n;

        double x, y;
        cin >> x >> y;
        point center = point(x, y);

        for(int i=0;i<n;i++)
            cin >> x >> y, a.push_back(point(x, y));
        a.push_back(a[0]);

        double ans = oo;
        for(int i = 0; i < n; i++){
            ans = min(ans, dist(a[i],center));
            ans = min(ans, distPointLine(a[i], a[i+1], center));
        }
        cout << ans << "\n";
    }
    return 0;
}
