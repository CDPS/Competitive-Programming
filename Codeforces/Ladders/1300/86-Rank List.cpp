
#include <bits/stdc++.h>

using namespace std;

struct node{
    int p,t;
    node(int a,int b){
        p=a;
        t=b;
    }
    bool operator < (const node &a)const{
        if(p==a.p)
            return t < a.t;
        return p > a.p;
    }
};

bool compare(node a, node b){
    if(a.t == b.t && a.p == b.p)
        return true;
    return false;
}

int main(){

    int n,k;

    scanf("%d %d",&n,&k);
    int p,t;

    vector< node> v;

    for(int i=0;i<n;i++){
        scanf("%d %d", &p, &t);
        v.push_back(node(p,t));
    }
    sort(v.begin(), v.end());

    node a = v[k-1];

    int i=k-2,res=0;

    while( k>=0 && compare (a,v[i])){i--;res++;}
    i=k;
    while(k<n && compare (a,v[i])){i++;res++;}

    printf("%d\n",res+1);
    return 0;
}
