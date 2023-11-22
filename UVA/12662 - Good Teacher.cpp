#include <bits/stdc++.h>

using namespace std;

int INF = 200;
int r[100];
int l[100];
string a[100];

int main(){

    int n,q;
    cin >> n ;

    for(int i=0;i<n;i++)
        cin >> a[i];

    int dist;
    for(int i=0;i<n;i++){
        if(a[i]!="?") continue;

        dist= 0; r[i] = INF;
        for(int j=i;j<n;j++){
            if(a[j]!="?"){
                r[i] = dist;
                break;
            }
            dist++;
        }

        dist= 0; l[i] = INF;
        for(int j=i;j >=0;j--){
            if(a[j]!="?"){
                l[i] = dist;
                break;
            }
            dist++;
        }
    }

    int x;
    cin >> q;
    while(q--){
        cin >>x; x--;

        if(a[x]!="?"){
            cout  << a[x] << "\n";
        }
        else{
            if( l[x] < r[x] ){
                for(int i=0;i<l[x];i++)
                    cout << "right of ";
                cout << a[ x - l[x]  ] << "\n";
            }
            else if( l[x] > r[x]){
                for(int i=0;i<r[x];i++)
                    cout << "left of ";
                cout << a[ x + r[x] ] << "\n";
            }else{
                cout << "middle of " << a[x - l[x]] << " and " << a[x + r[x]]  << "\n";
            }
        }
    }
    return 0;
}
