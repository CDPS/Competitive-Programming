#include <bits/stdc++.h>

using namespace std;

long long a[200000];
long long s[200001];

int main(){

    priority_queue< pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>> > pq;

    int n, k;
    cin >> n >> k;
    for(int i=0;i<n;i++)
        cin >> a[i], s[i+1]= s[i] + a[i];

    long long acc = 0;
    int index = 1;
    for(int i=0;i<k;i++)
        acc+= (i+1) * a[i];

    pq.push(make_pair(acc,index));

    for(int i=k;i<n;i++){
        acc = acc - (s[i] - s[i-k]) + k*a[i];
        pq.push(make_pair(acc,++index));
    }

    while(!pq.empty()){
        cout  << pq.top().second << " " << pq.top().first << "\n";
        pq.pop();
    }

    return 0;
}
