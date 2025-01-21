#include <bits/stdc++.h>

using namespace std;

int a[1000];

int main(){


    int n,k;

    cin >> n >> k;

    for(int i=0;i<n;i++) cin >> a[i];


    int ans = 0;
    priority_queue<int> pq;

    for(int i=0;i<n;i++){

        pq.push(a[i]);
        int h = k;
        priority_queue<int> temp = pq;

        while(temp.top() <= h && !temp.empty()){
            h-=temp.top() ; temp.pop();
            if(!temp.empty()) temp.pop();
        }

        if(!temp.empty()) break;
        ans = pq.size();
    }

    cout << ans << "\n";

    return 0;
}
