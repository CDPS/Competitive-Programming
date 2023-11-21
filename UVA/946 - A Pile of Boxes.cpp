#include <bits/stdc++.h>

using namespace std;

struct node {
    int x, sum;
    vector<node> child;
    node(int a):x(a){sum = 0;}
    bool canAdd(int y){
        return y + sum <=x;
    }
    void add(int y){
        child.push_back(y);
        sum+=y;
    }
};

bool add(int x, node & current){

    if(x > current.x)
        return false;

    int ans = false;

    for(int i=0;i<current.child.size() && !ans;i++)
        ans = add(x, current.child[i]);

    if(!ans){
        if(!current.canAdd(x))
            return false;
        current.add(x);
        return true;
    }
    return true;
}

int main(){

    vector<node> g;
    int n;
    while(cin >> n){

        g.push_back(node(0));

        int x;
        for(int i=0;i<n;i++){
            cin >> x;
            bool ans = false;
            for(int i=0;i<g.size() && !ans ;i++)
                 ans = add(x,g[i]);
            if(!ans)
                g.push_back(node(x));
        }

        int ans = 0;
        for(int i=0;i<g.size();i++)
            ans+= g[i].x;
        cout << ans << "\n";
        g.clear();
    }
    return 0;
}
