#include <bits/stdc++.h>

using namespace std;

int n;
int a[13];
int main(){

    string line;
    while(cin >> n && n){
        cin.ignore();
        int mini = 1000000;
        for(int i=0;i<n;i++){
            getline(cin,line);
            int r =0;
            for(int j=0;j<line.size();j++)
                if(line[j]==' ')r++;
            mini = min(mini,r);
            a[i]=r;
        }

        int res =0;
        for(int i=0;i<n;i++)
            res =res + (a[i]-mini);
        cout << res << "\n";
    }
    return 0;
}
