#include <bits/stdc++.h>

using namespace std;

int a[100000];

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

    int t,caseno=1;

    scanf("%d",&t);

    while(t--){

        int n;
        cin >> n;

        for(int i=0;i<n;i++)
            cin >> a[i];

        Fenwick f(n);
    }
    return 0;
}
