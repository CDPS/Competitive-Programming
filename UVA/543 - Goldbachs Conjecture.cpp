#include <bits/stdc++.h>

using namespace std;


int m[1000001];

void sieve(long n){
    m[0]=m[1]=0;
    for(long long i=2;i<=n;i++)
        m[i]=1;
    for(long long i=2;i*i<=n;i++){
        if(m[i]){
            for(long long j=i+i;j<=n;j+=i){
                m[j]=0;
            }
        }
    }
    m[2]=0;
}

int main(){

    sieve(1000000);

    int n;

    while(true){
        scanf("%d",&n);
        if(n==0)
            break;

        if(m[n]){
            printf("Goldbach's conjecture is wrong.\n");
        }else{
            int a=0,b=0;
            for(int i=3,j=n;i<j;i++,j--){

                if( m[i] && m[j] && i+j==n){
                    a=i; b=j;
                    break;
                }
            }
            printf("%d = %d + %d\n",n,a,b);
        }
    }
    return 0;
}
