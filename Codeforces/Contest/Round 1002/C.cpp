#include <bits/stdc++.h>

using namespace std;

int a[300][300];

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t, n;
    cin >> t;

    while(t--){

        cin >> n ;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin >> a[i][j];

        priority_queue<int, vector<int>, greater<int> > pq;
        for(int i=0;i<n;i++){
            int j = n;
            while(j >0 && a[i][j-1]==1)j--;
            pq.push(n-j);
        }

        int ans = 0;
        while(!pq.empty()){
            if(pq.top() > ans) ans++;
            pq.pop();
        }

        cout << min(ans + 1, n) << "\n";
    }
    return 0;
}
