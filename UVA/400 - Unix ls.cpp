#include <bits/stdc++.h>

using namespace std;

string a[100];

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);
    int n;
    while(cin >> n){

        int maxi = 0;
        for(int i=0;i<n;i++)
            cin >> a[i], maxi = max(maxi,(int)a[i].size());
        sort(a, a+ n);

		int columns = 62 / ( maxi + 2);
		int rows = ceil((double)n / (double)columns);

        cout << "------------------------------------------------------------" << "\n";
        for(int i=0;i<rows;i++){
            for(int j=0;j<columns;j++){
                if((j*rows)+i<n)
                    cout << left << setw(maxi+2) << a[(j*rows)+i];
            }
            cout << "\n";
        }
    }
    return 0;
}
