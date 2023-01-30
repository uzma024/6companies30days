class Solution {
public:
    vector <int> v1,v2;
    
    Solution(vector<int>& nums) {
        v1=v2=nums;
    }
    
    vector<int> reset() {
        return v1;
    }
    
    vector<int> shuffle() {
        int n = v2.size();
        int t1 = rand()%n;
        int t2 = rand()%n;
        swap(v2[t1],v2[t2]);
        return v2;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */