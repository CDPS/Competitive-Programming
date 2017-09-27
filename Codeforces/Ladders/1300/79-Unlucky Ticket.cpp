#include <bits/stdc++.h>

using namespace std;

int a[100],b[100],n;

bool isLess(){
    bool f=1;
    for(int i=0;i<n && f;i++)
        if(a[i]>=b[n-1-i]) f=0;

    if(f) return f;

    f=1;
    for(int i=0;i<n && f;i++)
        if(a[i]>=b[i]) f=0;

    return f;
}

bool isGreater(){

    bool f=1;
    for(int i=0;i<n && f;i++)
        if(a[i]<=b[n-1-i])f=0;

    if(f) return f;

    f=1;
    for(int i=0;i<n && f;i++)
        if(a[i]<=b[i])f=0;

    return f;
}

int main(){

    string s;
    cin >> n;
    cin >> s;

    for(int i=0;i<n;i++)
        a[i]=s[i]-'0', b[i]=s[i+n]-'0';
    sort(a,a+n); sort(b,b+n);

    cout << ( (isGreater() || isLess())? "YES":"NO");
    return 0;
}
