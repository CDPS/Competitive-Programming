#include <bits/stdc++.h>

using namespace std;

int a[40];
int b[40];

int main(){

    int t, n;
    cin >> t;

    while(t--){

        cin >> n;

        for(int i=0;i<n;i++) cin >> a[i];
        for(int i=0;i<n;i++) cin >> b[i];


        vector<pair<int,int>> ans;

        for (int i = 0; i < n - 1; i++)
            for (int j = 0; j < n - i - 1; j++)
                if (a[j] > a[j + 1])
                    swap(a[j], a[j + 1]),ans.push_back({1, j+1});

        for (int i = 0; i < n - 1; i++)
            for (int j = 0; j < n - i - 1; j++)
                if (b[j] > b[j + 1])
                    swap(b[j], b[j + 1]),ans.push_back({2, j+1});


        for(int i=0;i<n;i++)
            if(a[i]>b[i])
                ans.push_back({3,i+1});

        cout << ans.size() << "\n";
        for(int i=0;i<ans.size();i++)
            cout << ans[i].first << " " << ans[i].second <<"\n";
    }
    return 0;
}
