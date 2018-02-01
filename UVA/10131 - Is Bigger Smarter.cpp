#include <bits/stdc++.h>

using namespace std;

int n=1, oo=-1;

struct node{
    int w,s,idx;
    node(int a,int b,int c):w(a),s(b),idx(c){}

    bool operator < (const node &a) const{
        if(w==a.w)
            return s > a.s;
        return w < a.w;
    }
}; vector<node> v;


void dp(){

    vector<int> p(n-1,-1);
    vector<int> l(n-1,1);

    int maxi = 1,last=0;
    for(int i=1;i<n-1;i++){
        for(int j=0; j< i ; j++)
            if(  v[j].w < v[i].w && v[j].s > v[i].s &&  l[i]  < 1 + l[j]   )
                p[i] = j,l[i] =1+ l[j];
        if(l[i]>maxi) last = i,maxi = l[i];
    }

    stack<int> s; int x = last;
    for(;p[x]>=0;x =p[x]) s.push(v[x].idx);
    s.push(v[x].idx);

    cout << maxi << "\n";
    while(!s.empty()) cout << s.top() << "\n",s.pop();
}

int  main(){

    int w,s;
    while(cin >> w >> s)
        v.push_back(node(w,s,n)), n++;
    sort(v.begin(),v.end());

    dp();
    return 0;
}
