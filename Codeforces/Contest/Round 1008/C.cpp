#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll a[400000],e[400001], o[400001];

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t, n;
    cin >> t;

    while(t--){

        cin >> n;

        set<ll> st;
        for(int i=0;i<2*n;i++)
            cin >> a[i], e[i]=0, o[i] = 0, st.insert(a[i]);
        sort(a, a + (2*n), greater<int>());

        ll sume = 0, sumo = 0;
        for(int i=0, j=0, k =0;i<2*n;i++){
            if(i%2) o[k++] = a[i], sumo+=a[i];
            else    e[j++] = a[i], sume+=a[i];
        }

        int idx = 0;
        while(st.count(sume-sumo))  {
            ll temp = e[idx + 1];
            sume-= temp;
            e[idx + 1] = o[idx]; sume+= o[idx];
            sumo-= o[idx]; o[idx] = temp; sumo+= temp;
            idx++;
        }

        if(idx == n){
            o[n-1] = sume-sumo;
            for(int i=0, j=0, k =0;i< (2*n)+1;i++)
                cout << ( i%2? o[j++] : e[k++] ) << " \n"[i==2*n];
        }else{
            o[n] = sume - sumo;
            for(int i=0, j=0, k =0;i< (2*n)+1;i++)
            cout << ( i%2? e[j++] : o[k++] ) << " \n"[i==2*n];
        }
    }
    return 0;
}
