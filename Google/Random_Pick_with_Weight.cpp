class Solution {
public:
    vector<int> w;
    Solution(vector<int>& w) {
        for(int i=1;i<w.size();i++){
            w[i] = w[i] + w[i-1];
        }
        this->w=w;
    }
    
    int pickIndex() {
        int h = w.back();
        int i = rand() % h;
        i++;
        int ind = lower_bound(w.begin(),w.end(),i) - w.begin();
        return ind;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */