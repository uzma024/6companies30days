class Solution {
public:
    
    int distance(vector<int>& p1, vector<int>& p2){
        int a=p1[0]-p2[0] , b=p1[1]- p2[1];
        return a*a + b*b;
    }
    
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        int s12= distance(p1,p2);
        int s13= distance(p1,p3);
        int s14= distance(p1,p4);
        int s23= distance(p2,p3);
        int s24= distance(p2,p4);
        int s34= distance(p3,p4);
        
        unordered_set <int> s;
        s.insert({s12, s13, s14, s23, s24, s34});
        
        // double d= distance(p1,p2);
        return !s.count(0) && s.size() == 2;
    }
};