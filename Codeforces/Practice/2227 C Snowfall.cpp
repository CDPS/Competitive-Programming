#include <bits/stdc++.h>

using namespace std;

int t, n, x;

void solve(){

    cin >> n;

    vector<int> mod_two;
    vector<int> mod_three;
    vector<int> mod_six;
    vector<int> not_divisible;

    for(int i=0; i <n; i++){
        cin >> x;
        if(x %6 == 0) mod_six.push_back(x);
        else if(x %2 == 0) mod_two.push_back(x);
        else if(x%3 ==0 ) mod_three.push_back(x);
        else not_divisible.push_back(x);
    }

    for(int i=0; i < mod_six.size();i++)
        cout << mod_six[i] << " ";
    for(int i=0; i < mod_two.size();i++)
        cout << mod_two[i] << " ";
    for(int i=0; i < not_divisible.size();i++)
        cout << not_divisible[i] << " ";
    for(int i=0; i < mod_three.size();i++)
        cout << mod_three[i] << " ";

    cout << "\n";
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >>  t;
    while(t--)
        solve();
}
