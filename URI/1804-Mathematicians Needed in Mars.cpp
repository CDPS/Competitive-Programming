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

    int n;
    scanf("%d",&n);

    for(int i=0;i<n;i++)
        scanf("%d",a+i);

    Fenwick f(n);
    f.init(a,n);

    char c;
    int idx;

    while(cin >> c >> idx){

        if(c=='a')
            f.update(idx,a[idx-1]*-1);

        if(c=='?')
            printf("%d\n",f.query(idx-1));
    }
    return 0;
}
