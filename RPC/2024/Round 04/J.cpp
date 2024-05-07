#include <bits/stdc++.h>

using namespace std;

double area(vector<pair<int,int>> polygon){
    double area = 0.0;
    int n = polygon.size();
    int j = n - 1;
    for (int i = 0; i < n; i++){
        area += (polygon[j].first + polygon[i].first) * (polygon[j].second - polygon[i].second);
        j = i;
    }
    return abs(area);
}

int main(){

    int n;
    cin >> n;

    vector<pair<int,int>> polygon;
    int x, y;

    for(int i=0;i<n;i++)
        cin >> x >> y, polygon.push_back(make_pair(x,y));

    double total = area(polygon);

    double ans = 100000000;
    for(int i=0;i<n;i++){
        for(int j=i+2;j<n;j++){

            if (i == 0 && j == n-1) continue;

            vector<pair<int,int>> p1;
            for(int k=i;k<=j;k++)
                p1.push_back(polygon[k]);

            double area1 = area(p1);
            double area2 = total - area1;
            ans = min(ans,abs(area1-area2));
        }
    }

    cout << fixed << setprecision(1) << ans/2.0 << "\n";
    return 0;
}
