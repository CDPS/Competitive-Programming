#include <bits/stdc++.h>

using namespace std;

bool check(int a,int b){
    return a%2==0&&b%2==0;
}
int main(){

    int n;

    int x,y,ax=0,ay=0,axy=0,bxy=0;
    cin >> n;

    while(n--){
        cin >> x >> y;
        axy+= (x%2); bxy+= (y%2);
        if(x%2 && y%2==0) ax++;
        if(x%2==0 && y%2) ay++;
    }

    if(check(axy,bxy) ){
        printf("0\n");
    }
    else{
      if(ax>0 && check(axy-1,bxy+1)){
            printf("1\n");
      }
      else if(ay>0 && check(axy+1,bxy-1)){
            printf("1\n");
      }
      else{
        printf("-1\n");
      }
    }
    return 0;
}
