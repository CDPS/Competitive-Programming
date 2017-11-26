#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    while(scanf("%d",&n) && n){

        priority_queue<int,vector<int>,greater<int> > pq;
        int ai;
        for(int i=0;i<n;i++)
            scanf("%d",&ai),pq.push(ai);

        long long cost =0;

        for(int i=0;i<n-1;i++){
            int a=pq.top(); pq.pop();
            int b=pq.top(); pq.pop();
            int c=a+b;
            cost+=c;
            pq.push(c);
        }

        printf("%lld\n",cost);
    }
    return 0;
}
