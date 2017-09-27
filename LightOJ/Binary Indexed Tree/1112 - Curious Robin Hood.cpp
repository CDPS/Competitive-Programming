#include <bits/stdc++.h>
 
using namespace std;
 
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
 
 
int a[100000];
 
int main(){
 
    int t,caseno=1;
    scanf("%d",&t);
 
    while(t--){
        int n,q;
        scanf("%d %d",&n,&q);
 
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
 
        Fenwick f(n);
        f.init(a,n);
 
        printf("Case %d:\n",caseno++);
 
        while(q--){
            int query;
            scanf("%d",&query);
 
            if(query==1){
                int i;
                scanf("%d",&i);
                int res = f.query(i+1)-f.query(i);
                printf("%d\n",res);
                f.update(i+1, res*-1);
            }
 
            if(query==2){
                int i,v;
                scanf("%d %d",&i,&v);
                f.update(i+1,v);
            }
 
            if(query==3){
                int i,j;
                scanf("%d %d",&i,&j);
                int res = f.query(j+1)-f.query(i);
                printf("%d\n",res);
            }
        }
 
    }
 
    return 0;
}
