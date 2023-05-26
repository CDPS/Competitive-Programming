#include <bits/stdc++.h>

using namespace std;

string input;
string result;

bool isPalindrome(string s){
    string reversed = s;
    reverse(reversed.begin(),reversed.end());
    return reversed == s;
}

void llps(string s="", int index=0){

    if(isPalindrome(s))
        result = max(result,s);

    for(int i=index; i<input.size();i++)
        llps(s+input[i], i+1);
}

int main(){

    cin >> input;
    llps();
    cout << result << "\n";
    return 0;
}


