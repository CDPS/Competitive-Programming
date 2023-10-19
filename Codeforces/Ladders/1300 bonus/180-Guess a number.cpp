#include <bits/stdc++.h>

using namespace std;

int upper =  2000000000;
int lower = -2000000000;

int main(){

    int n,x;

    cin >> n;

    string op, assert;

    while(n--){

        cin >> op >> x >> assert;
        if(assert == "N"){
			if (op == ">=")
                op = "<";
			else if (op == "<")
                op = ">=";
			else if (op == "<=")
                op= ">";
			else
                op= "<=";
        }

        if (op == ">=")
            lower = max(lower, x);
        else if (op == "<")
            upper = min(upper, x -1);
        else if (op == "<=")
            upper = min(upper, x);
        else
            lower = max(lower, x + 1);
    }

    if (lower <= upper)
        cout << lower << "\n";
	else
        cout << "Impossible" << "\n";

    return 0;
}
