#include <bits/stdc++.h>

using namespace std;

int solve(int a, int b){
    int a1=0,a2=0,a3=0,b1=0,b2=0,b3=0;

    while(a%2==0) a/=2,a1++;
    while(a%3==0) a/=3,a2++;
    while(a%5==0) a/=5,a3++;

    while(b%2==0) b/=2,b1++;
    while(b%3==0) b/=3,b2++;
    while(b%5==0) b/=5,b3++;

    return (a==b)? abs(a1-b1) + abs(a2-b2) + abs(a3-b3) : -1;
}

int main(){
    int a,b;
    scanf("%d %d",&a,&b);
    printf("%d\n", solve(a,b));
    return 0;
}
