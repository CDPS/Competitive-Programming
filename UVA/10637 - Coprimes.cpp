#include <bits/stdc++.h>

using namespace std;

int n,t,a[40];

int gcd( int a,  int b){
    return (b==0) ? a : gcd(b, a%b);
}

bool isCoprime(int k, int n){
    for(int i=0;i<k;i++)
        if(gcd(n,a[i])!=1)
            return 0;
    return 1;
}

void print(int k){
    printf("%d",a[0]);
    for(int i=1;i<k;i++)
        printf(" %d",a[i]);
    printf("\n");
}

void backTrack(int ni ,int acc, int idx){

    if( idx == t && acc==n){
        print(idx);
        return;
    }
    if(idx==t)
        return;
    for(int i=ni;i<= n && acc+i <=n;i++){
        if(isCoprime( idx,i)){
            a[idx]=i;
            backTrack(i,acc+i,idx+1);
        }
    }
}

int main(){

    int test,caseno=1;
    scanf("%d",&test);

    while(test--){
        scanf("%d %d", &n,&t);
        printf("Case %d:\n",caseno++);
        backTrack(1,0,0);
    }
    return 0;
}
