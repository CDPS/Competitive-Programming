#include <bits/stdc++.h>

using namespace std;

int scores[100];
int points[100];
int g[100][1000];

void solve(int n, int m){

    memset(points, 0, sizeof(points));
    int maxi = -1;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            points[j] += scores[ g[i][j] -1 ], maxi = max(points[j],maxi);

    bool first = true;
    for(int i=0;i<m;i++){
        if(points[i]==maxi){
             if(first){ cout << i + 1; first = false;}
             else{ cout << " " << i + 1; }
        }
    }
    cout  << "\n";
}

int main(){

    int n,m,t,s;

    while(cin >> n >> m){

        if(n == 0 && m ==0) break;

        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                cin >> g[i][j];

        cin >> t;

        while(t--){
            cin >> s;
            memset(scores, 0, sizeof(scores));
            for(int i=0;i<s;i++)
                cin >> scores[i];
            solve(n,m);
        }
    }
    return 0;
}
