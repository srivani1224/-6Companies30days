class Solution {
    double x,y,r;
    double PI = 3.14159265358979323846264;;
public:
    Solution(double radius, double x_center, double y_center) {
        x = x_center;
        y = y_center;
        r = radius;
    }
    
    double generateRand()
    {
        return ((double)rand()/ RAND_MAX);   
    }
    
    vector<double> randPoint() 
    {
        double radius = sqrt(generateRand()) * r;
        double theta = generateRand() * 2 * PI;
        double xaxis = x + (radius * cos(theta));
        double yaxis = y + (radius * sin(theta));
        return vector<double>{xaxis, yaxis};
    }
};
