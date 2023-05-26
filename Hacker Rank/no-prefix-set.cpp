#include <bits/stdc++.h>

using namespace std;

struct node {
    node *children[10];
    int acc;
    node(){
        acc = 0;
        for(int i=0; i<10; i++)
            children[i] = NULL;
    }
};
set<string> st;

bool add(node * root, string value){
    node *current = root;
    string partialPrefix;
    for(int i = 0; i< value.size(); i++){
        int index = value[i] - 'a';
        partialPrefix += value[i];
        if(current->children[index] == NULL)
            current->children[index] = new node();
        current = current->children[index];
        current->acc++;
        if( (i !=value.size() -1 && st.find(partialPrefix)!= st.end()) )
            return false;
    }
    return current->acc == 1;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);
    int n; string value;

    cin >> n ;
    node *root = new node();

    bool answer = true;
    for(int i=0 ; i< n ; i++){
        cin >> value;
        st.insert(value);
        answer = add(root, value);
        if(!answer) break;
    }

    if(!answer)
    {
        cout<< "BAD SET" << "\n";
        cout<< value << "\n";
    }else{
        cout<< "GOOD SET " << "\n";
    }

    return 0;
}
