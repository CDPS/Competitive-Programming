#include <bits/stdc++.h>

using namespace std;

int n,k;
int a[100000];

int main(){

    priority_queue<int, vector<int>, greater<int> > pq;

    cin >> n >> k;
    for(int i=0;i<n;i++)
        cin >> a[i];

    int i=0;
    for(;i<min(n,k);i++)
        pq.push(a[i]);

    int maxi = 0;
    while(!pq.empty()){
        int x = pq.top();
        pq.pop();
        maxi = max(x, maxi);

        priority_queue<int, vector<int>, greater<int> > aux;
        while(!pq.empty()){
            int y = pq.top();
            pq.pop();
            y-=x;
            if(y > 0)
                aux.push(y);
        }
        while(aux.size()< k && i < n)
            aux.push(a[i++]);

        pq = aux;
    }
    cout << maxi << "\n";
    return 0;
}
