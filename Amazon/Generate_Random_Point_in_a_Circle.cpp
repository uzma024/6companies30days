class Solution {
public:
    double r,x,y;
    
    Solution(double radius, double x_center, double y_center) {
        this->r = radius;
        this->x = x_center;
        this->y = y_center;
    }
    
    vector<double> randPoint() {
        double x_temp = (double)rand()/RAND_MAX * 2 * r - r + x;        
        double y_temp = (double)rand()/RAND_MAX * 2 * r - r + y;
    
        while(sq(x_temp,y_temp) > r*r){
            x_temp = (double)rand()/RAND_MAX * 2 * r - r + x;
            y_temp = (double)rand()/RAND_MAX * 2 * r - r + y;
        }
        
        return {x_temp,y_temp};
    }
    
    double sq(double x_temp, double y_temp){
        return (x-x_temp)*(x-x_temp) + (y-y_temp)*(y-y_temp);
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */