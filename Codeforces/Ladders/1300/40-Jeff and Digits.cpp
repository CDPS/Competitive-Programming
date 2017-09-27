#include <bits/stdc++.h>

using namespace std;

int a[1000];

int main(){
    int n;
    cin >> n;

    for(int i=0;i<n;i++)
        cin >> a[i];
    sort(a,a+n);

    int i=0;
    while(i<n && a[i]==0)i++;

    if(i==0){
        printf("-1");
    }else{
        i=0;
        int j=i;
        string res="";
        int acc =0;

        for(;i<n;i++){
            acc= ( (a[i]*10)%90   + (acc%90) )%90;
            if(acc==0) j=i;
        }

        for(int k=0;k<=j;k++){
            char c =  (a[k]+'0');
            res=c + res;
        }

        if(res[0]=='0')cout << "0\n";
        else cout << res << "\n";
    }
    return 0;
}
