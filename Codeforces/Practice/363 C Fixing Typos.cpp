#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second

int n;
string s;

void solve(){

    cin >> s;
    n = s.size();

    vector< pair<int,char> > a;
    a.push_back({1, 'a'});

    for(int i=0;i<n;i++){

        int curr = 0;
        char c =  s[i];
        while(i < n && s[i] == c)
            i++, curr++;

        if(curr  >=2 && a.back().f == 2)
            curr = 1;
        if(curr  >=2 && a.back().f == 1)
            curr = 2;

        a.push_back({ curr , c });

        i = i -1;
    }


    for(int i=1;i<a.size();i++)
        while(a[i].f--)
            cout << a[i].s;
    cout << "\n";
}

int main(){


    cin.sync_with_stdio(false); cin.tie(NULL);

    solve();
}
