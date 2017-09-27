#include <bits/stdc++.h>

using namespace std;

int a[100000];

int main(){

    int n;
    scanf("%d",&n);

    for(int i=0;i<n;i++)
        scanf("%d",a+i);

    int ans,ch;

    ans = ch =  a[0];
    ans++;

    for(int i=1;i<n;i++){

        if(ch< a[i]){
            ans = ans  + 1 + abs(a[i]-ch) + 1;
        }else{
            ans = ans + abs(a[i]-ch) + 2;
        }
        ch = a[i];
    }

    printf("%d",ans);
    return 0;
}
