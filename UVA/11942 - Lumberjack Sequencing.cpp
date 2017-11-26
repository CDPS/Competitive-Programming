#include <bits/stdc++.h>

using namespace std;

int a[10];

bool ordered(){

    bool flag=true;
    for(int i=1;i<10;i++){
        if(a[i]<a[i-1]){
            flag = false;
            break;
        }
    }

    if(flag) return true;

    flag = true;
    for(int i=1;i<10;i++){
        if(a[i]>a[i-1]){
            flag = false;
            break;
        }
    }
    return flag;
}

int main(){

    int t;
    scanf("%d",&t);

    printf("Lumberjacks:\n");
    while(t--){
        for(int i=0;i<10;i++)
            scanf("%d",a+i);
        if(ordered())printf("Ordered\n");
        else printf("Unordered\n");
    }
    return 0;
}
