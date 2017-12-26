#include <bits/stdc++.h>

using namespace std;

int a[100000];

int n,k;
int main(){

    scanf("%d %d",&n,&k);

    int ne=0;
    for(int i=0;i<n;i++)scanf("%d",a+i),ne = (a[i]<=0) ne+1:ne;

    int ans = 0;
    if(a[0]>=0){
        int r = a[0]* (k%2?-1:1);
        ans = ans + r;
        for(int i=1;i<n;i++)ans = ans + a[i];
    }
    else if(ne>=k){
        for(int i=0;i<n;i++){
            if(a[i]<=0 && k)a[i]*=-1,k--;
            ans = ans + a[i];
        }
    }else{


    }
    return 0;
}
