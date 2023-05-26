#include <bits/stdc++.h>

using namespace std;

struct node {
    int acc;
    node *children[26];
    node(){
        acc = 0;
        for(int i=0; i<26; i++)
            children[i] = NULL;
    }
};

void add(node * root, string value){
    node *current = root;
    current->acc++;
    for(int i = 0; i< value.size(); i++){
        int index = value[i] - 'a';
        if(current->children[index] == NULL)
            current->children[index] = new node();
        current = current->children[index];
        current->acc++;
    }
}

int findPrefixCount(node * root, string value){

    node *current = root;
    for(int i = 0; i< value.size(); i++){
        int index = value[i] - 'a';
        if(current->children[index] == NULL)
            return 0;
        current = current->children[index];
    }
    return current->acc;;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n ;
    node *root = new node();
    string operation, value;
    for(int i=0 ; i< n ; i++){
        cin >> operation >> value;
        if(operation == "add")
            add(root, value);
        else
            cout << findPrefixCount(root, value) << "\n";
    }
    return 0;
}
