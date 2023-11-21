#include <bits/stdc++.h>

using namespace std;

int main(){

    cin.tie(NULL); cin.sync_with_stdio(false);

    int n, q;
    while(cin >> n >> q){

        if(n == 0 && q == 0)
            break;

        set<int> s;
        for(int i=1;i<=n;i++) s.insert(i);

        int l, r;
        while(q--){

            cin >> l >> r;
            auto itl = s.find(l);
            auto itr = s.find(r);
            s.erase(itl, ++itr);

            auto ar= s.upper_bound(r);
            auto al= s.lower_bound(l);

            if (al != s.begin()) cout << *(-- al) << " ";
            else cout << "* ";
            if (ar != s.end()) cout << *ar << "\n";
            else cout << "*" << "\n";
        }

        cout << "-" << "\n";
    }
    return 0;
}
