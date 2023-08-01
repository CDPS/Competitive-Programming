#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> node ;

node a[30];

int main(){

    int n, x,y;

    cin >> n;
    for(int i=0;i<n;i++){
        cin >> x >> y;
        a[i]= make_pair(x,y);
    }

    int ans =0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j)
                continue;
            if(a[i].first == a[j].second)
                ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}
