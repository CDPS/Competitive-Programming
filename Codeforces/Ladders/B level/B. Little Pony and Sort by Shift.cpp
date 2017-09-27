#include <bits/stdc++.h>

using namespace std;

int a[100000];

int main(){

    int n;
    scanf("%d",&n);

    bool ordered = true;
    scanf("%d",a+0);

    for(int i=1;i<n;i++){
        scanf("%d",a+i);
        if(a[i]<a[i-1])
            ordered = false;
    }


    if(ordered){
        printf("0");
        return 0;
    }

    vector<int> v; v.push_back(a[n-1]);
    int i = n-2;

    while(i>=0 && a[i]<=a[i+1]){
        v.push_back(a[i]);
        i--;
    }

    if(v[0] > a[0]){
        printf("-1");
        return 0;
    }

    for(int j=0;j<=i;j++){
        if(j!=0 && a[j]< a[j-1]){
            printf("-1");
            return 0;
        }
    }

    cout << v.size();
    return 0;
}
