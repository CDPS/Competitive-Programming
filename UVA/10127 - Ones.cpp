#include <bits/stdc++.h>

using namespace std;

int ones(int n){
    int ans=1,r=1;

    while(r!=0){
        r = ((r%n) * (10%n) )%n ;
        r = (r%n + 1)%n;
        ans++;
    }
    return ans;
}
int main(){
    int n;
    while(scanf("%d",&n)==1)
        printf("%d\n",ones(n));
    return 0;
}
