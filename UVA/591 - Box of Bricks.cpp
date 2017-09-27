#include <bits/stdc++.h>

using namespace std;

int a[50];

int main(){

    int n,caseno=1;
    while(cin >> n && n){
        int sum =0;
        for(int i=0;i<n;i++)
            cin >> a[i],  sum+= a[i];

        int r = sum/n,res=0;
        for(int i=0;i<n;i++)
            if(a[i]> r)
                res+= a[i]-r;
        cout << "Set #" << caseno++ << "\n";
        cout << "The minimum number of moves is "<<  res << ".\n\n";
    }
    return 0;
}
