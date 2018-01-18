#include <bits/stdc++.h>

using namespace std;

int a[200000],b[200000];

class Fenwick{

    public:
    vector <int> tree;
    int maxVal;

    Fenwick(int n) {
        maxVal=n;
        tree= vector<int>(maxVal+1,0);
    }

    int query(int idx){
        int sum =0;
        while(idx > 0){

            sum+= tree[idx];
            idx -= (idx & -idx);
        }

        return sum;
    }

    void update(int idx, int val){
        while(idx<=maxVal){
            tree[idx]+=val;
            idx+= (idx & -idx);
        }
    }

    void init(int a[],int n){
        for(int i=0;i<n;i++)
            update(i+1,a[i]);
    }
};

int main(){

    int n,q,l,h;

    scanf("%d %d",&n,&q);

    for(int i=0;i<n;i++) scanf("%d",a+i);

    Fenwick f(n);
    while(q--){
        scanf("%d %d",&l,&h);
        f.update(l,1); f.update(h+1,-1);
    }


    for(int i=0;i<n;i++)
        b[i]= f.query(i+1);

    sort(a,a+n); sort(b,b+n);

    long long ans = 0;
    for(int i=0;i<n;i++)
        ans  = ans + (1ll*b[i]*a[i]);

    printf("%I64d\n",ans);
    return 0;
}
