#include <bits/stdc++.h>

using namespace std;

double dist(int x1,int y1, int x2, int y2){
    int dx = x2 - x1;
    int dy = y2 - y1;
    return sqrt((double) dx*dx + (double) dy*dy);
}

int main(){

    int n,k;

    cin >> n >> k;
    int x1,x2,y1,y2;
    double d = 0;

    cin >> x1 >> y1;
    for(int i=1;i<n;i++){

        cin >> x2 >> y2;
        d+= dist(x1,y1,x2,y2);
        x1 = x2;
        y1 = y2;
    }
    cout << fixed << setprecision(6) << (d/(double)50.0) * (double) k << "\n";
    return 0;
}
