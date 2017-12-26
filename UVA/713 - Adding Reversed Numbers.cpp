#include <bits/stdc++.h>

using namespace std;

void Fill(string &a){
    for(int i=a.size();i<=201;i++)a+='0';
}

string  unFill(string a){
    string s = "",acc ="";

    int i=0;
    while(a[i]=='0')i++;
    for(;i<a.size();i++){
        if(a[i]!='0')
            s= s +  acc + a[i],acc="";
        else
            acc= acc + a[i];
    }
    return s;
}

string sum(string a, string b){

    int carry =0; string ans="";

    for(int i=0;i<a.size();i++){
        int x = (a[i]-'0'),y = (b[i]-'0');
        int c = (x+y+carry);
        carry = c>=10;
        c%=10;
        ans+=(c+'0');
    }
    return ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t;
    cin >> t;
    string a,b;

    while(t--){
        cin >> a >> b;
        Fill(a);Fill(b);
        cout << unFill(sum(a,b)) << "\n";
    }
    return 0;
}
