class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n=s.length();
        if(n<k)return false;
        int count =pow(2,k);
        
        unordered_set <string>m;
       for(int i = 0;i <= n - k;i++){
            m.insert(s.substr(i,k));
            if(m.size()==count)return true;
        }
        return m.size()>=count;
    }
};