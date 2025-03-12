#include <bits/stdc++.h>

using namespace std;

bool solve(double sum, int n, double x){

    if(n==1) return sum == x;
    if(sum/double(n) == x) return true;

    queue< pair<int,double> > q;
    for(int i=2;i<=n;i++)
        if(n%i==0)
            q.push({n/i, sum/double(i)});

    while(!q.empty()){
        auto u = q.front(); q.pop();
        if(u.first == 1 && u.second == x)
            return true;
        if(u.first == 1 && u.second != x)
            continue;
        if(u.second/double(u.first) == x)
            return true;
        for(int i=2;i<=u.first;i++)
            if(u.first%i ==0)
                q.push({u.first/i, u.second/double(i)});
    }
    return false;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t , n, x;
    cin >> t;

    while(t--){

        cin >> n >> x;

        int sum = 0, y;
        for(int i=0;i<n;i++)
            cin >> y, sum+= y;

        cout << (solve(double(sum), double(n), double(x))? "YES" : "NO") << "\n";
    }
    return 0;
}
