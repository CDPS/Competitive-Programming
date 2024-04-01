#include <bits/stdc++.h>


using namespace std;


vector<vector<int>> f(vector<vector<int>> g){

    vector<vector<int>> m(3, vector<int>(3));

    m[0][0] = (g[0][1] + g[1][0]) %2;
    m[0][1] = (g[0][0] + g[0][2] + g[1][1]) %2;
    m[0][2] = (g[0][1] + g[1][2]) %2;
    m[1][0] = (g[0][0] + g[2][0] + g[1][1] ) %2;
    m[1][1] = (g[0][1] + g[1][0] + g[1][2] + g[2][1] ) %2;
    m[1][2] = (g[1][1] + g[0][2] + g[2][2]) %2;
    m[2][0] = (g[1][0] + g[2][1]) %2;
    m[2][1] = (g[1][1] + g[2][0] + g[2][2]) %2;
    m[2][2] = (g[2][1] + g[1][2]) %2;

    return m;
}

bool finite(vector<vector<int>> g){
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(g[i][j]==1) return false;
    return true;
}

int main(){


    int t;

    cin >> t;

    while(t--){

        vector<vector<int>> m(3, vector<int>(3));
        char c;
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                cin >> c, m[i][j] = c-'0';

        set<vector<vector<int>>> visit;
        visit.insert(m);

        int index = 0;
        while(true){
            m = f(m);
            if(visit.count(m)) {index = -1; break;}
            if(finite(m)){break;}
            visit.insert(m);
            index++;
        }

        cout << index << "\n";
    }

    return 0;
}
