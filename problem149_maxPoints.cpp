#include<iostream>
#include<vector>
#include<unordered_map>
#include<climits>
using namespace std;

struct Point{
    int x;
    int y;
    Point(): x(0), y(0) {}
    Point(int a, int b): x(a),y(b) {}
};

class Solution{
public:
    int maxPoints(vector<Point>& points){
       
    if(points.size() == 0) return 0;
        int bestCount = 0;
        for(int i = 0; i< points.size() -1; i++){
            unordered_map<long double, int> slope;
            int dup = 0;
            int innerBest = 0;
            for(int j = i+1; j < points.size(); j++ ){
                
                //find the slope between points[i], points[j]
                long double  slopePoint;
                
                //find if this is a duplicate
                if(points[j].x == points[i].x && points[j].y == points[i].y){
                    dup++;
                    continue;
                }
                if ( (points[j].x - points[i].x) == 0) {
                    slopePoint = INT_MAX;
                }else 
                    slopePoint = (long double)(points[j].y - points[i].y)/(points[j].x - points[i].x);                
                
                slope[slopePoint]++;
                if(innerBest<slope[slopePoint])
                    innerBest = slope[slopePoint];
            }
            innerBest+=dup; //whatever innerBest was generated for points[i], it needs to be incremented by the number of duplicates
            if(innerBest > bestCount)
                bestCount = innerBest;
            
            
            
        }
        return bestCount+1;
    }
};

int main(){
    Solution S;
   // [[84,250],[0,0],[1,0],[0,-70],[0,-70],[1,-1],[21,10],[42,90],[-42,-230]]
    vector<Point> points;
    
    // points.push_back(Point(84,250));
    points.push_back(Point());
    points.push_back(Point(94911151,94911150));
        points.push_back(Point(94911152,94911151));
        //     points.push_back(Point(0,-70));
        //         points.push_back(Point(1,-1));
        //             points.push_back(Point(21,10));
        //                 points.push_back(Point(42,90));
        //                     points.push_back(Point(-42,-230));






    // points.push_back(p3);
    cout<<S.maxPoints(points)<<endl;
}