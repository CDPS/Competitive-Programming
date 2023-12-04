#include <bits/stdc++.h>

using namespace std;

int main(){

    int n, x;
    while(cin >> n && n){

        vector<int> a;

        for(int i=0;i<n;i++)
            cin >> x , a.push_back(x);
        sort(a.begin(), a.end());

        bool ans = true;
        for(int i=1;i<n && ans ;i++)
            ans = a[i] <= a[i-1]+200;

        ans = ans && ((1422 - a[n-1])*2 <= 200);
        cout << (  (ans)? "POSSIBLE" : "IMPOSSIBLE"  ) << "\n";
    }
    return 0;
}
