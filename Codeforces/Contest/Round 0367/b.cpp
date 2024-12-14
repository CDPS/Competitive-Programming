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

    long query(int idx){
        long sum =0;
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


    for(int i=0;i<100000;i++){
        a[i]=0;
    }

    int aux;
    long resp=0;
    for(int i=0;i<n;i++){
        scanf("%d",&aux);
        a[aux-1]++;
    }

    Fenwick f(100000);
    f.init(a,100000);

    int q;
    scanf("%d",&q);

    while(q--){

        long  i;
        scanf("%ld",&i);

        if(i>100000)
            printf("%d\n",n);
        else
            printf("%ld\n",f.query(i));
    }
    return 0;
}
