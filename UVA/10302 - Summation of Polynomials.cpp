#include <bits/stdc++.h>

using namespace std;

unsigned long long acc[50001];

void calc(){
    acc[0]=0;
     for(unsigned long long i=1;i<=50000ull;i++)
        acc[i]= acc[i-1] + (i*i*i);
}

int main(){
    calc();
    int n;
    while(scanf("%d",&n)==1)
        printf("%llu\n",acc[n]);
    return 0;
}
