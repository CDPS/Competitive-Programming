#include <bits/stdc++.h>

using namespace std;

int main(){
    int t,a,mini,n,caseno=1;
    scanf("%d",&t);

    while(t--){
        scanf("%d",&n);
        mini= -1;
        for(int i=0;i<n;i++){
            scanf("%d",&a);
            mini = max(mini,a);
        }
        printf("Case %d: %d\n",caseno++,mini);
    }
    return 0;
}
