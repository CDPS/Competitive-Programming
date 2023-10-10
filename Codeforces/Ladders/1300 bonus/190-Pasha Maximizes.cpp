#include <bits/stdc++.h>

using namespace std;

int main(){

    int k, n;
    string s;
    cin >> s >> k;
    n = s.size();
    for(int i=0;i< n && k>0;i++){
        int index = -1;
        int maxi = s[i];

        for(int j= i+1; j<= min(n-1,i+k) ; j++)
            if(s[j]> maxi)
                index = j, maxi = s[j];

        if(index != -1){
            while(index > i )
                k--, swap(s[index],s[index-1]),index--;
        }
    }
    cout << s << "\n";
    return 0;
}

