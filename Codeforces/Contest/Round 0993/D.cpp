#include <bits/stdc++.h>

using namespace std;

int a[200000];

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t, n,x;
    cin >> t;

    while(t--){
        cin >> n;

        set<int> unused;
        for(int i=0;i<n;i++)
            a[i] = - 1, unused.insert(i+1);

        for(int i=0;i<n;i++){
            cin >> x;
            if(unused.count(x))
                a[i]=x, unused.erase(x);
        }

        auto it = unused.begin();
        for(int i=0;i<n;i++){
            if(a[i]== -1)
                a[i] = *it, it++;
        }

        cout << a[0];
        for(int i=1;i<n;i++)
            cout << " " << a[i];
        cout << "\n";
    }
    return 0;
}


