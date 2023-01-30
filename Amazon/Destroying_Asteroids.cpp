class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        
        for(auto i:asteroids){
            if(i>mass)return false;
            if(mass>INT_MAX-i)continue;
            mass+=i;
        }
        return true;
    }
};