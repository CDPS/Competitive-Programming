#include <bits/stdc++.h>

using namespace std;

int m[165000001];
vector<int> v;

void criba( int tam){
    m[0] = 1;
    m[1] = 1;

    for(int i = 2; i <= tam; ++i)
        m[i] = i;

    for(int i = 2; i <= tam; ++i) {
        if(m[i]==i){
            for(int h = i; h <= tam; h+=i){
                    m[h]=i;
            }
        }
    }

    v.push_back(1);
    for(int i=0;i<=tam;i++){
        if(m[i]==2 || m[i]==3 || m[i]==5)
            v.push_back(i);
    }
}

int main(){
    criba(165000000);
    printf("%d\n",v.size() );
    int n;

    while(true){
        scanf("%d",&n);
        if(n==0)
            break;
        printf("%d\n",v[1000]);
    }
    return 0;
}
