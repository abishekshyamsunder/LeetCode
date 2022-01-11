class MapSum {
public:
    unordered_map<string, int> m;
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        m[key] = val;
        
    }
    
    int sum(string prefix) {
        int s = 0;
        
        for(auto i = m.begin(); i!=m.end();i++)
        {
            string m_s = i->first;
            int l = min(m_s.length(),prefix.length());
            m_s = m_s.substr(0, l);
            if(m_s == prefix)
                s = s + i->second;
        }
        return s;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
