#include <bits/stdc++.h>

using namespace std;

int n;
int a[2001];

int main(){

    cin >> n;

    for(int i=0;i<n;i++)cin >> a[i];

    long long sum = 0;
    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i=0;i<n;i++){
        sum+= a[i];
        pq.push(a[i]);
        if(sum < 0)
            sum-= pq.top(), pq.pop();
    }

    cout << pq.size() << "\n";

    return 0;
