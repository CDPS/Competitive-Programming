#include <bits/stdc++.h>

using namespace std;

int n,k;
int a[100000];

int main(){

    priority_queue<int, vector<int>, greater<int> > pq;

    cin >> n >> k;
    for(int i=0;i<n;i++)
        cin >> a[i];

    for(int i=0;i<min(k,n);i++)
        pq.push(a[i]);

    int maxi = -1;
    int prev = 0;
    for(int i=k;i<n;i++){
        int x = pq.top();
        pq.pop();
        maxi = max(maxi, x-prev);
        prev = x;
        pq.push(a[i]);
    }

    while(!pq.empty()){
        int x = pq.top();
        pq.pop();
        maxi = max(maxi, x-prev);
        prev = x;
    }

    cout << maxi << "\n";
    return 0;
}

