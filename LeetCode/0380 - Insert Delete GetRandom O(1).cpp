class RandomizedSet {
public:

    unordered_map<int,int> mp;
    vector<int> a;
    RandomizedSet() { ios_base::sync_with_stdio(false); }
    
    bool insert(int val) {
        
        if(mp.count(val) > 0 )
            return false;

        a.push_back(val);
        mp[val] = a.size() -1;
        return true;
    }
    
    bool remove(int val) {

        if(mp.count(val) == 0 )
            return false;
        
        int indexVal  = mp[val];
        mp[ a[a.size()-1 ]] = indexVal;

        swap( a[indexVal], a[a.size()-1 ] );
        a.pop_back();
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
        return a[rand()%a.size()];  
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */