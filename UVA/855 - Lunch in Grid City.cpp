#include <bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin >> t;

    while(t--){

        int s,a,n,x,y;
        cin >> s >> a >> n;
        vector<int> xs;
        vector<int> ys;
        for(int i=0;i<n;i++)
            cin >> x >> y, xs.push_back(x), ys.push_back(y);
        sort(xs.begin(), xs.end());
        sort(ys.begin(), ys.end());

        if(n%2==0)n--;
        int mid =  n/2;
        cout << "(Street: " << xs[mid] << ", Avenue: " << ys[mid] << ")" << "\n";
    }

    return 0;
}
