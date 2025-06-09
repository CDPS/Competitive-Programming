#include <bits/stdc++.h>

using namespace std;


int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t, n; string s;
    cin >> t;
    while(t--){

        cin >> n >> s;

        s = '0' + s;

        int changes = 0;
        for(int i=1;i<=n;i++)
            if(s[i]!=s[i-1])
                changes++;

       if(changes>=3)
         cout<< changes-2 + n<<"\n";
       else if(changes==2)
         cout<< changes-1 + n<<"\n";
       else
         cout<<changes+n<<"\n";
    }
    return 0;
}
