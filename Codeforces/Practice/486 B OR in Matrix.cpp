#include <bits/stdc++.h>

using namespace std;

int t = 1, n, m;

bool  B[100][100];
bool  A[100][100];
int row[100];
int col[100];

bool check(){


    bool has_full_row = false, has_full_col = false;

    for(int i = 0; i < n; i++) if(row[i] == m) has_full_row = true;
    for(int j = 0; j < m; j++) if(col[j] == n) has_full_col = true;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(B[i][j] == 1) {
                bool valid = (row[i] == m && has_full_col) || (col[j] == n && has_full_row);
                if(!valid) return false;
            }
        }
    }

    return true;
}

void solve(){

    cin >> n >> m;
    for(int i=0; i < n; i++)
        for(int j=0; j < m; j++)
            cin >> B[i][j], col[j]+= B[i][j], row[i]+= B[i][j], A[i][j] = 1;;

    if(!check()){
        cout << "NO" << "\n";
        return;
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(B[i][j] == 0){
                for(int k = 0; k < m; k++) A[i][k] = 0;
                for(int k = 0; k < n; k++) A[k][j] = 0;
            }
        }
    }

    cout << "YES\n";
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cout << A[i][j] <<  " \n"[j == m-1];
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(t--)
       solve();

    return 0;
}
