#include <bits/stdc++.h>

using namespace std;

int a[5000];

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t, n;
    cin >> t;

    while(t--){

        cin >> n;
        bool zero = false, nzero = false;
        for(int i=0;i<n;i++)
            cin >> a[i], zero|= a[i] == 0, nzero|= a[i] != 0;

        if(!zero){
            cout << 1 << "\n";
            cout << 1 << " " << n << "\n";
            continue;
        }
        if(zero && !nzero){
            cout << 3 << "\n";
            cout << 1 << " " << 2 << "\n";
            cout << 2 << " " << n - 1 << "\n";
            cout << 1 << " " << 2 << "\n";
            continue;
        }
        else{

            vector<pair<int, int> > v;
            for(int i=0;i<n;i++){
                if(a[i]==0){
                    int j = i;
                    while( j<n && a[j]==0)
                        j++;

                    if(j-1 == i){
                        if(j==n)
                            v.push_back({n-2, n-1});
                        else
                            v.push_back({i,j});
                    }else
                        v.push_back({i,j-1});

                    i= j-1;
                }
            }

            cout << v.size() + 1 << "\n";
            int acc= 0;
            for(int i=0;i<v.size();i++){
                cout << v[i].first+1-acc << " " << v[i].second+1-acc << "\n";
                acc+= v[i].second - v[i].first;
            }

            cout << 1 << " " << n - acc << "\n";
        }
    }
    return 0;
}
