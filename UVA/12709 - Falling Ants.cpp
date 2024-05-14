#include <bits/stdc++.h>

using namespace std;

struct node{

    int h, v;

    node(int h, int v) : h(h), v(v){}

    bool operator < (const node &a) {
        if(h == a.h) return v> a.v;
        return h > a.h;
    }
};

int main(){

    int n;
    while(cin >> n && n){

        vector<node> a;
        int l,w,h;
        for(int i=0;i<n;i++){
            cin  >> l >> w >> h;
            a.push_back(node(h, l*w*h));
        }
        sort(a.begin(), a.end());
        cout << a[0].v << "\n";
    }
    return 0;
}

