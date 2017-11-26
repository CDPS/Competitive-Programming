#include <bits/stdc++.h>

using namespace std;

int a[3];

int main(){

    long long owned=0;
    int n;
    cin >> n;
    int ai;

    while(n--){
        cin >> ai;

        if(ai==25)
            a[0]++;
        else if(ai==50){
            if(a[0]==0){
                printf("NO\n");
                return 0;
            }
            else{
                a[1]++;a[0]--;
            }
        }else{
            if(a[0]>=1 && a[1]>=1){
                a[2]++;a[1]--;a[0]--;
            }
            else if(a[0]>2){
                a[0]-=3;a[2]++;
            }else{
                printf("NO\n"); return 0;
            }
        }
    }
    printf("YES\n");
    return 0;
}
