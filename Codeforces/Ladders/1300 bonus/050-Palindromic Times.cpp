#include <bits/stdc++.h>

using namespace std;

int a[21] = {110, 220, 330, 440, 550, 1001, 1111, 1221, 1331, 1441, 1551, 2002, 2222, 2332};

int main(){

    int h,m;
    scanf("%d:%d",&h,&m);
    int number = (h*100) + m;

    int res = 0;
    for(int i=0;i<21;i++){
        if(number<a[i]){
           res=a[i];
           break;
        }
    }
    printf("%02d:%02d", res/100, res%100);
    return 0;
}
