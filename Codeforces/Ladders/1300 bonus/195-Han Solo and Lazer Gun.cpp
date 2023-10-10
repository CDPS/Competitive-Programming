#include <bits/stdc++.h>

using namespace std;

pair<int, int> a[10000];
bool killed[10000];

int main(){

    int n, x0,y0,x1,y1,x2,y2;
    cin >> n >> x0 >> y0;

    for(int i=0;i<n;i++){
        cin >> x1 >> y1;
        a[i] = make_pair(x1,y1);
    }

    int res = 0;
    for(int i=0;i<n;i++){
        x1 = a[i].first;
        y1 = a[i].second;

        if(!killed[i]){

            killed[i] = 1;
            res++;
            for(int j=0;j<n;j++){
                x2 = a[j].first;
                y2 = a[j].second;
                if( j!=i  && !killed[j] && (x1-x0)*(y2-y0) == (x2-x0)*(y1-y0)  )
                    killed[j] = 1;
            }
        }
    }
    cout  << res << "\n";
    return 0;
}
