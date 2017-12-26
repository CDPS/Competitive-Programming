#include <bits/stdc++.h>

using namespace std;

int main(){

    string a,b;

    cin >> a >> b;

    int ans=0,k =0,acc=0;

    for(int i=0;i<a.size();i++) ans = (a[i]=='+')? ans + 1: ans-1;

    for(int i=0;i<b.size();i++){
         if(b[i]=='+')acc++;
         if(b[i]=='-')acc--;
         if(b[i]=='?')  k++;
    }

    if(k==0){
        double r = 0.0;
        if(acc==ans) r=1.0;
        cout << fixed << setprecision(9) << r << "\n";
    }else{
        int n = (1<<k),p=0,m;

        for(int i=0;i<n;i++){
            m=acc;
            for(int j=0;j<k;j++)
                 m = ( (  i & ( 1 << j ) ) != 0 )? m+1 : m-1;
            if(m==ans) p++;
        }
        cout << fixed << setprecision(9) << double(p)/double(n) << "\n";
    }
    return 0;
}
