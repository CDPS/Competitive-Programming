#include <bits/stdc++.h>

using namespace std;

bool isOp(char c){
   return c == '+' || c == '-' || c == '*' || c == '/';
}

bool isVar(char c){
   return c >= 'a' && c  <= 'z';
}

bool isNum(char c){
   return c >= '0' && c  <= '9';
}

string f(string s) {

    string ans = "";
    for (int i = 0; i < s.size(); i++) {
        if (isOp(s[i])) {
            ans +='o';
        } else if (isVar(s[i])) {
            ans +='x';
        } else if (isNum(s[i])) {
            ans +='x';
            while(isNum(s[i+1]) && i < s.size()-1) i++;
        } else {
            ans += s[i];
        }
    }
    return ans;
}

void buildPi(string& p, vector<int> &pi){
  pi = vector<int>(p.length());
  int k = -2;
  for(int i = 0; i < p.length(); i++) {
    while(k >= -1 && p[k+1] != p[i])
      k = (k == -1) ? -2 : pi[k];
    pi[i] = ++k;
  }
}

int KMP(string& t, string& p){
  int ans = 0;
  vector<int> pi;
  buildPi(p, pi);
  int k = -1;
  for(int i = 0; i < t.length(); i++) {
    while(k >= -1 && p[k+1] != t[i])
      k = (k == -1) ? -2 : pi[k];
    k++;
    if(k == p.length() - 1) {
      ans++;
      k = (k == -1) ? -2 : pi[k];
    }
  }
  return ans;
}

int main(){
    cin.sync_with_stdio(false); cin.tie(NULL);
    string a, b;

    while(cin >> a >> b){
        string fa = f(a), fb = f(b);
        cout << KMP(fb,fa) << "\n";
    }
    return 0;
}
