#include <bits/stdc++.h>

using namespace std;
int acc[1001];

int main(){
    int n,a;
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        scanf("%d",&a);
        acc[a]++;
    }

    for(int i=1;i<=1000;i++)
        if(acc[i]>(n+1)/2){
            printf("NO");
            return 0;
        }
    printf("YES");
    return 0;
}
