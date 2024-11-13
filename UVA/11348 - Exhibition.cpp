#include <bits/stdc++.h>

using namespace std;

set<int> a[50];
int b[50];

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios_base::fixed);
    cout.precision(6);

    int t,n,m,x, caseno = 1 ;
    cin >> t;

    while(t--){
        cin >> n;
        map<int,int>mp;
        for(int i=0;i<n;i++){
            cin >> m;
            for(int j=0;j<m;j++)
                cin >> x, a[i].insert(x);
        }

        for(int i=0;i<n;i++)
            for(auto it=a[i].begin(); it!=a[i].end(); it++ )
                mp[*it]++;

        int total = 0;
        for(int i=0;i<n;i++)
            for(auto it=a[i].begin(); it!=a[i].end(); it++ )
                if(mp[*it] == 1)
                    total++, b[i]++;

        cout << "Case " << caseno++ << ":";
        for(int i=0;i<n;i++){
            cout << " " << double(100.*b[i])/(double)total<< "%";
            a[i].clear();
        }
        cout << "\n";
        memset(b, 0, sizeof b);
    }
    return 0;
}

