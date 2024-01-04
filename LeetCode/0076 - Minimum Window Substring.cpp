class Solution {
public:

    int mp[52], current[52];

    int hash(char c){
        if(c >= 'A' && c <='Z')
            return c - 'A';
        return 26 + c - 'a';
    }
    
    bool isEquals(){
        for(int i=0;i<52;i++)
            if( current[i] < mp[i])
                return false;
        return true;
    }

    string minWindow(string s, string t) {
        
        int n = s.size(),m = t.size();

        for(int i=0;i<m;i++)
            mp[ hash(t[i]) ]++;

        int l =0 , h =0, mini = n+1; 
        for(int i=0, j=0;i<n;i++){
            
            while(j<n && !isEquals()){                 
                int index = hash(s[j++]);
                if(mp[ index] > 0)
                    current[index]++;
            } 
            if(isEquals()  && j-i < mini)
                mini = j-i, l = i, h = j;
            
            if(current[hash(s[i])] > 0) 
                current[hash(s[i])]--;
        }
        return mini !=n+1 ? s.substr(l, h-l): "";
    }
};