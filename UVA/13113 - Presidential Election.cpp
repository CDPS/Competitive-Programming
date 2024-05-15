#include <bits/stdc++.h>

using namespace std;

double a[500], b[500];

int main(){

    int t,n,m;

    double votes, total;
    bool first = true;
    cin >> t;

    while(t--){

        cin >> m >> n;

        for(int i=0;i<m;i++)a[i]=0.0;
        total =0.0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++) cin >> b[j];
            cin >> votes;
            total+=votes;
            for(int j=0;j<m;j++)
                a[j]+= votes*b[j];
        }

        priority_queue<pair<double, int>> pq;
        for(int i=0;i<m;i++)
            pq.push(make_pair(a[i], i+1));

        if(!first) cout << "\n";
        first = false;

        cout << pq.top().second << " " << (int)(pq.top().first/100) << "\n";
        if( pq.top().first < total * 50.1)
            pq.pop(), cout << pq.top().second << " " << (int)(pq.top().first/100) << "\n";
    }

    return 0;
}
