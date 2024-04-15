#include <bits/stdc++.h>

using namespace std;

string a[10], b[10], no[10], oh[10], th[10], v[10];
int n;

void r(string s[10], string t[10]){
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            t[j][n-1-i] = s[i][j];
}

void h(string s[10], string t[10]){
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            t[n-1-j][i] = s[j][i];
}

bool eq(string x[10], string y[10]){
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(x[i][j] != y[i][j])return false;
    return true;
}

int main(){

    int caseno = 1;
    while(cin >> n){

        for(int i=0;i<n;i++)
            cin >> a[i] >> b[i];

        cout << "Pattern " << caseno++;
        if(eq(a,b)){ cout << " was preserved." << "\n"; continue; }
        r(a,no);
        if(eq(no,b)){ cout << " was rotated 90 degrees." << "\n"; continue;}
        r(no,oh);
        if(eq(oh,b)){ cout << " was rotated 180 degrees." << "\n"; continue;}
        r(oh,th);
        if(eq(th,b)){ cout << " was rotated 270 degrees." << "\n"; continue;}
        h(a,v);
        if(eq(v,b)){ cout << " was reflected vertically." << "\n"; continue;}
        r(v,no);
        if(eq(no,b)){ cout << " was reflected vertically and rotated 90 degrees." << "\n"; continue; }
        r(no,oh);
        if(eq(oh,b)){ cout << " was reflected vertically and rotated 180 degrees." << "\n"; continue;}
        r(oh,th);
        if(eq(th,b)){ cout << " was reflected vertically and rotated 270 degrees." << "\n"; continue;}
        cout << " was improperly transformed." << "\n";
    }
    return 0;
}
