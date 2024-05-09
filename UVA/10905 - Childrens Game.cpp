#include <bits/stdc++.h>

using namespace std;

string a[50];

struct compare{
    bool operator () (string s1, string s2)const {
       return s1 + s2 >  s2 + s1;
    }
};

int main(){

    int n;
    while(cin >> n && n){

        for(int i=0;i<n;i++) cin >> a[i];

        sort(a, a+n, compare());

        for(int i=0;i<n;i++)
            cout << a[i];
        cout << "\n";
    }
    return 0;
}
