#include <bits/stdc++.h>

using namespace std;


int main(){


    int n;
    scanf("%d",&n);

    bool a[2000];
    map<int,int>mp;
    memset(a,0,2000);

    int x;

    while(n--){
        scanf("%d",&x);
        a[x-1]=1;
        mp[x]++;
    }

    for(int i=0;i<2000;i++){
        if(a[i])
            printf("%d aparece %d vez(es)\n",i+1,mp[i+1]);
    }
    return 0;
}
