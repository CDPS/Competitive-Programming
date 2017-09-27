#include <bits/stdc++.h>

using namespace std;

int a[1000];

int main(){

    int n,m;
    scanf("%d %d",&n,&m);

    priority_queue<int> pq1;
    priority_queue<int, vector<int>, greater<int> > pq2;


    for(int i=0;i<m;i++){
        scanf("%d",a+i);
        pq1.push(a[i]);
        pq2.push(a[i]);
    }

    int mini=0;
    for(int i=0;i<n;i++){
        int aux = pq2.top();
        mini+= aux;
        pq2.pop();
        if(aux-1>0)
            pq2.push(aux-1);
    }

    int maxi=0;

    for(int i=0;i<n;i++){
        int aux = pq1.top();
        maxi+= aux;
        pq1.pop();
        if(aux-1>0)
            pq1.push(aux-1);
    }

    printf("%d %d\n",maxi,mini);
    return 0;
}
