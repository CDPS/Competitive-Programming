#include <bits/stdc++.h>

using namespace std;

int equals[101];

int main(){

    int t,n,q,k,x;
    char op;
    cin >> t;
    bool first = true;
    while(t--){

        cin >> n >> q;

        for(int i=0;i<=n;i++)
            equals[i] = false;

        if(!first) cout << "\n";
        first = false;

        while(q--){
            cin >> k;
            vector<int> a;
            for(int i=0;i<k*2;i++)
                cin >> x, a.push_back(x);
            cin >> op;
            if(op == '='){
                for(int i=0;i<k*2;i++)
                    equals[ a[i] ] = true;
            }
        }

        bool already = false;
        int index = 0;
        for(int i=1;i<=n;i++){
            if(!equals[i] && !already){
                index = i;
                already = true;
            }
            else if(!equals[i] && already){
                index = 0;
                break;
            }
        }
        cout << index << "\n";
    }
    return 0;
}
