#include <bits/stdc++.h>

using namespace std;

int a[100];

int main(){

    int n, ni,nj,nk;
    cin >> n;

    for(int i=0;i<n;i++)
        cin >> a[i];

    bool found = false;
    for(int i=0;i<n && !found;i++){
        for(int j=0;j<n &&!found ;j++){
            for(int k=0;k<n && !found;k++){
                if(j!=i && k!=i && j!=k && a[j]+a[k]==a[i]){
                    ni = i;
                    nj = j;
                    nk = k;
                    found = true;
                }
            }
        }
    }

    if(found)
        cout << ni + 1 << " " << nj + 1 << " " << nk +1 << "\n";
    else
        cout << -1 << "\n";

    return 0;
}
