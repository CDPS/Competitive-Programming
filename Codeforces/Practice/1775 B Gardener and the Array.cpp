#include <bits/stdc++.h>

using namespace std;

int t,n,m,x,maxi;
int a[200000];

bool solve(vector<vector<int>> &v){
   int acc = 0;
   for(int i=0;i<v.size();i++){
       bool ones = 0;
       for(int j=0;j < v[i].size(); j++)
            ones|= a[v[i][j]] == 1 ;
       acc+= ones;
   }
   return acc != n;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);


    cin >> t;

    while(t--){

        cin >> n;

        maxi = -1;
        vector<vector<int>> v;
        for(int i=0;i<n;i++){
            cin >> m;
            vector<int> aux;
            while(m--){
                cin >> x; a[x-1]++;
                maxi = max(maxi, x);
                aux.push_back(x-1);
            }
            v.push_back(aux);
        }

        cout << (solve(v)? "Yes" : "No") << "\n";

        for(int i=0;i<maxi;i++) a[i] = 0;
    }

    return 0;
}
