#include <bits/stdc++.h>

using namespace std;

int a[200000];
int p[200000];
int q[200000];

set<int> sp, sq;

int t, n;

bool check(){
    map<int,int> mp;
    for(int i=0;i<n;i++){
        mp[a[i]]++;
        if(a[i] != 1 && mp[a[i]] > 2 ) return false;
        if(a[i] == 1 && mp[a[i]] > 1 ) return false;
    }

    for(int i=0;i<n;i++){
        if(sp.count(a[i]))
            p[i] = a[i], sp.erase(a[i]);
        else
            q[i] = a[i], sq.erase(a[i]);
    }

    for(int i=0;i <n;i++){
        if(p[i]==0){
            auto it = sp.upper_bound(a[i]);
            if (it == sp.begin()) return false;
            it--;
            p[i] = *it, sp.erase(it);
        }
        if(q[i]==0){
            auto it = sq.upper_bound(a[i]);
            if (it == sq.begin()) return false;
            it--;
            q[i] = *it, sq.erase(it);
        }
    }
    return true;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;

    while(t--){

        cin >> n;


        sp.clear(); sq.clear();

        for(int i=0;i<n;i++)
            cin >> a[i], sp.insert(i+1), sq.insert(i+1), p[i] = 0, q[i] = 0;

        bool f = check();

        cout << (f? "YES": "NO") << "\n";
        if(f){

            for(int i=0;i<n;i++)
                cout << p[i] << " \n"[i==n-1];

            for(int i=0;i<n;i++)
                cout << q[i] << " \n"[i==n-1];
        }
    }

    return 0;
}
