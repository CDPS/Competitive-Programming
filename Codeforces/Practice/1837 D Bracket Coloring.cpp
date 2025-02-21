#include <bits/stdc++.h>

using namespace std;

vector<int> a[2];
int v[200000];
int currentIndex [2];


int hazh(char c){ return c-')'};
char fp(char c){ return c==')'? '(' : ')'; }

int main(){

    int t, n ;
    string s;
    cin >> t;

    while(t--){

        cin >> n >> s;

        a[0].clear(); a[1].clear();

        int o = 0, c =0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')o++;
            if(s[i]==')')c++;
            a[ hazh(s[i]) ].push_back(i);
            v[i] = 0 ;
        }



        if(n%2==0 && o == c){


            cout << groups << "\n";
            for(int i=0;i<n;i++)
                cout << v[i] << " \n"[i==n-1];

            continue;
        }

        cout << -1 << "\n";
    }
    return 0;
}
