#include <bits/stdc++.h>

using namespace std;

const int MAX =   1000000;
const int LMT =      1000;

int m[(MAX>>6)+1];
int acc[1000001];

#define isComp(n)  (m[n>>6]&(1<<((n>>1)&31)))
#define setComp(n) m[n>>6]|=(1<<((n>>1)&31))


bool isPrime(int n) {
    if(n==2)return true;
    if (n < 2 || n % 2 == 0) return false;
    return ! isComp(n);
}

int isPrimeDigit(int n){
    int res=0;
    while(n){ res+= n%10; n/=10; }
    return isPrime(res);
}

void sieve() {
    for (int i = 3; i <= LMT; i += 2)
        if (!isComp(i))
            for (int j = i*i; j <= MAX; j += i+i)
                setComp(j);

    acc[0]=0; acc[1]=0; acc[2]=1;

    for(int i=3;i<=MAX;i++){
        if(isPrime(i) && isPrimeDigit(i)) acc[i]=1;
        else acc[i]=0;
        acc[i]+= acc[i-1];
    }
}

int main(){
    sieve();
    int n;
    scanf("%d",&n);
    int l,h;

    while(n--){
        scanf("%d %d",&l,&h);
        int res = (!isPrime(l))? acc[h] - acc[l] : acc[h] - acc[l] + isPrimeDigit(l) ;
        printf("%d\n",res);
    }
    return 0;
}
