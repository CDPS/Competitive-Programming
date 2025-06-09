#include <bits/stdc++.h>

using namespace std;

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;

    queue<int> q;
    for(int i=0;i<n;i++) q.push(i+1);

    bool print = false;
    while(!q.empty()){
        int u = q.front(); q.pop();
        if(print) cout << u << " ";
        if(!print) q.push(u);
        print = !print;
    }

    cout << "\n";

    return 0;
}
