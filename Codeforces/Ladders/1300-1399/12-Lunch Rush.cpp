#include <bits/stdc++.h>

using namespace std;

int main(){

    int n,k;
    scanf("%d %d",&n,&k);

    int maxi;

    int f,t;
    for(int i=0;i<n;i++){
        scanf("%d %d",&f,&t);
        if(i==0) maxi = (t>k)? f-(t-k) : f;
        else maxi = max(maxi ,  (t>k)? f-(t-k) : f);
    }
    printf("%d\n",maxi);
    return 0;
}
