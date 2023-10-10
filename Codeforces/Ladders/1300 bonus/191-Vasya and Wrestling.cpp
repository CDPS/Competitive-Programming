#include <bits/stdc++.h>

using namespace std;

int main(){

    long long n, x ,acc1=0,acc2=0;
    vector<int> a,b;
    bool res = true;
    cin >> n;

    for(int i=0;i<n;i++){
        cin >> x;
        if(x<0){
            acc2 += x *(-1);
            res = false;
            b.push_back(x *(-1));
        }else{
            acc1 += x;
            res = true;
            a.push_back(x);
        }
    }

    if(acc1==acc2){
        if(a != b ){
            for(int i=0;i< min( a.size(),b.size());i++){
                if(a[i]!=b[i]){
                    res = a[i] > b[i];
                    break;
                }
            }
        }
    }else{
        res = acc1> acc2;
    }
    cout << ( (res)? "first" : "second" ) << "\n";
    return 0;
}
