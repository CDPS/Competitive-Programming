#include <bits/stdc++.h>

using namespace std;


struct node{
    int w,idx;

    node(int a, int b){
        w= a, idx= b;
    }
};

int main(){

    queue<node> q;

    int n,m;
    cin >> n >> m;

    int u;

    for(int i=0;i<n;i++){
        cin  >> u;
        q.push(node(u,i));
    }

    while(q.size()!=1){

        if(q.front().w <=m)
            q.pop();
        else{
            node n = q.front();
            n.w-= m;
            q.pop(); q.push(n);
        }
    }

    cout << q.front().idx +1 << "\n";

    return 0;
}
