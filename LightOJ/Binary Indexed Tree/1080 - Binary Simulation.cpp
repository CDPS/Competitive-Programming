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
 
        string s;
        cin >> s;
 
        int n = s.size();
 
        for(int i=0;i<n;i++)
            a[i]=s[i]-'0';
 
        Fenwick f(n);
        int q;
        scanf("%d",&q);
 
        printf("Case %d:\n",caseno++);
 
        while(q--){
            char query;
            scanf(" %c",&query);
            if(query=='I'){
                int i , j;
                scanf("%d %d",&i,&j);
                f.update(i,1);
                f.update(j+1,-1);
            }else{
                    int i;
                    scanf("%d", &i);
                    printf("%d\n", a[i-1] ^ (f.query(i)%2));
            }
        }
    }
 
    return 0;
}
