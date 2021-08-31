//
//  defineGraph.h
//  Triangle Problem
//
//  Created by Tom Sherman on 7/8/21.
//

#ifndef defineGraph_h
#define defineGraph_h


/*
Define nessesary means for graphing:
Points with x and y coordinates
Lines with endpoints and a vector of midpoints
 
*/

#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cassert>
#include <fstream>
#include <cmath>

const double EPSILON = .001;
const double CLOSE_CONSTANT = 1;
double MAX_DIST = .001; //1 for even, .001 for odd //double not constant as it changes with number of veritces

bool equalTo(double num1, double num2){
    if(abs(num1-num2)<EPSILON)
        return true;
    return false;
}

///

bool closeTo(double num1, double num2){
    if(abs(num1-num2)<CLOSE_CONSTANT)
        return true;
    return false;
}





class Point{
        
    private:
        double xcord;
        double ycord;
  
    public:
        
    ///
    
    //Constructors
    Point(){}
    
    Point(double xcord_in, double ycord_in) : xcord(xcord_in), ycord(ycord_in){}
    
    //Assignment Operator
    Point &operator=(const Point &rhs) {
      if (this == &rhs) {
        return *this;
      }
        xcord = rhs.xcord;
        ycord = rhs.ycord;
        return *this;
    }
    
    ///
    
    //Operator Overloading
    bool operator==(const Point &rhs) const {
            return (equalTo(xcord, rhs.xcord) && equalTo(ycord, rhs.ycord));
        }
    
    
    bool operator!=(const Point &rhs) const {
        return !(rhs==*this);
        }


///

//Getter Functions

    double getXCord(){
        return xcord;
    }

    double getYCord(){
        return ycord;
    }

    
//Setter Functions
    
    void setXcord(double newX){
        xcord=newX;
    }
    
    void setYcord(double newY){
        ycord=newY;
    }
    
    
};

class Line {
    

    public:
    
    //friend declarations
    friend class Point;    
    
    //constructor
        Line(Point &end1_in, Point &end2_in) : end1(end1_in), end2(end2_in) {
        //insert code to get mid vector using endpoints here
        //struggling to figure out line here. Need to continue work. Going to create github repository stuff now.
           
            //EndPoints
            double x1 = end1.getXCord();
            double x2 = end2.getXCord();
            double y1 = end1.getYCord();
            double y2 = end2.getYCord();
            xRangeMax=std::max(x1,x2);
            xRangeMin=std::min(x1,x2);
            yRangeMax=std::max(y1,y2);
            yRangeMin=std::min(y1,y2);
            //$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
            
            //Mid point vector, hasSlope, and slope
            
            //Vertical Line Case
            if(x1==x2){
                hasSlope=false;
                slope=123456789; //crap number I know in case something goes wrong
//                while(!(equalTo(y1,y2))){
//                    if(y1<y2)
//                        y1=y1+.1;
//                    else
//                        y1=y1-.1;
//                    Point point1(x1,y1);
//                    mid.push_back(point1);
//                }
            }
            
            else{
                double m = (y1-y2)/(x1-x2);
                slope=m;
                hasSlope=true;
//                while (!(equalTo(x1, x2))){
//                    if(x1<x2)
//                        x1=x1+.1;
//                    else
//                        x1=x1-.1;
//                    y1=end1.getYCord() - (end1.getXCord()-x1)*m;
//                    Point point1(x1,y1);
//                    mid.push_back(point1);
//                }
                //mid.pop_back(); //this line is to remove the duplicate point on mid that matches end2
                
        
            
            
            }

            
    }
    
    double getSlope(){
        return slope;
    }
    
    
    
    //Assignment Operator
    Line &operator=(const Line &rhs) {
      if (this == &rhs) {
        return *this;
      }
        end1 = rhs.end1;
        end2 = rhs.end2;
        //mid = rhs.mid;
        return *this;
    }
    
    //Operator Overloading
    
    bool operator==(const Line &rhs) const {
            return ((end1==rhs.end1)||(end1==rhs.end2)) && ((end2==rhs.end2)||(end2==rhs.end1));
        } //Double check this stuff later
    
    bool operator!=(const Line &rhs) const {
            return !(rhs==*this);
        }
    
    //Special line-specific operator: INTERSECT
    
    bool operator+(Line &rhs) {
        
//        if(!commonXExist(*this, rhs)||!commonYExist(*this, rhs)){
//            return false;
//        }
//        else{
//            double commonX = findCommonX(*this, rhs);
//            if(!(this->getHasSlope())&&(!(rhs.getHasSlope()))){return false;} //for our purposes we should assume two vertical lines to never intersect
//            else if(!(this->getHasSlope())||(!(rhs.getHasSlope()))){
//                //single and double vertical line cases
//                if(this->getHasSlope()){
//                    double yVal = findYVal(commonX, *this);
//                    if(yVal>=rhs.yRangeMin&&yVal<=rhs.yRangeMax){return true;}
//                }
//                else{
//                    double yVal = findYVal(commonX, rhs);
//                    if(yVal>=this->yRangeMin&&yVal<=yRangeMax){return true;}
//                }
//            }
//            else if(this->getSlope()==rhs.getSlope()){
//                if(findYVal(commonX, *this)==findYVal(commonX, rhs)){return true;}
//            }
//            else{
//                //both non-vertical line cases
//                double xIntersect = findXIntersect(rhs, *this);
//                if(equalTo(findYVal(xIntersect, rhs), findYVal(xIntersect, *this))){
//                    return true;
//                }
//            }
//            return false;
//        }
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        if(!(commonXExist(*this, rhs))){
            return false;
        }
        else{
//            if(equalTo(this->slope, rhs.slope)){
//            //if(this->slope==rhs.slope){
//                //special case when slopes are identical!
//                //Assuming they share a common x, if they share a common y, they intersect
//                //^^THE ABOVE COMMENTS ARE WRONG AND ARE CAUSING AN ERROR
//
//                //The code below doesn't work for pairs of vertical lines, but that shouldn't matter as such cases should not occur
//                double commonX=findCommonX(*this, rhs);
//                double yValT = findYVal(commonX, *this);
//                double yValrhs=findYVal(commonX, rhs);
//                if(equalTo(yValT,yValrhs)){return true;}
//
//            }


            if(this->hasSlope&&rhs.hasSlope){
                //this works when both lines have slopes that are not indential
                double intersect = findXIntersect(*this, rhs);
                if(valWithinXRange(intersect, *this)&&valWithinXRange(intersect, rhs)){
                    return true;
                }
            }

            else if(this->hasSlope||rhs.hasSlope){
                //for one vertical line and one non-vertical line
                //as common x exists, if common y at the x the vertical line is at exists then the statement is true
                double commonX=findCommonX(*this, rhs);
                
                if(rhs.hasSlope){
                    double rhsYVal=findYVal(commonX, rhs);
                    if(rhsYVal<this->yRangeMax&&rhsYVal>this->yRangeMin){return true;}
                    else if((equalTo(rhsYVal, this->yRangeMax))||equalTo(rhsYVal, this->yRangeMin)){
                        return true;
                    }
                }
                else if(this->hasSlope){
                    double thisYVal=findYVal(commonX, *this);
                    if(thisYVal<rhs.yRangeMax&&thisYVal>rhs.yRangeMin){return true;}
                    else if((equalTo(thisYVal, rhs.yRangeMax)||(equalTo(thisYVal, rhs.yRangeMin)))){return true;}
                else{return false;} //this should NEVER happen //UPDATE: Actually, I think this should be false, but I'm not entirely sure.
            }
            else{return false;} //this should NEVER happen.
        }





        return false;
    }
    }
    //Share end node operator
    bool operator%(Line &rhs) {
        if(this->end1==rhs.end1||this->end1==rhs.end2||this->end2==rhs.end1||this->end2==rhs.end2){
            return true;
        }
        else{return false;}
    }
    
    
    double findYVal(double xCord, Line line1){
        return line1.slope*(xCord-line1.end1.getXCord())+line1.end1.getYCord();
    }
    //Only works for functions with slopes.
    //y-y1=m(x-x1) ---->y=m(x-x1)+y1
    
    
    
    
    double findXIntersect(Line line1, Line line2){
        double commonX = findCommonX(line1, line2);
        double y1=findYVal(commonX, line1);
        double y2=findYVal(commonX, line2);
        double topOfFraction = (line2.slope*commonX)-(line1.slope*commonX)+y1-y2;
        double bottomOfFraction = line2.slope-line1.slope;
        return topOfFraction/bottomOfFraction;
    }
    //Only works for functions with slopes
    
    
    bool getHasSlope(){
        return this->hasSlope;
    }
    
    double getMaxXRange(){
        return this->xRangeMax;
    }
    
    double getMinXRange(){
        return this->xRangeMin;
    }
    
    
    
    
    private:
        //std::vector<Point> mid; this vector I though would be useful to have, but I do not beleive I was correct in my initial assumption. Hence I have commented out all code to do with it but left it if needed
        Point end1;
        Point end2;
        bool hasSlope;
        double slope;
        double xRangeMin;
        double xRangeMax;
        double yRangeMin;
        double yRangeMax;
    
    
        
    bool commonXExist(Line line1, Line line2){
        if(line1.xRangeMax<line2.xRangeMin||line1.xRangeMin>line2.xRangeMax){
            return false;
        }
        else{
            return true;
        }
    }
    
    bool commonYExist(Line line1, Line line2){
        if(line1.yRangeMax<line2.yRangeMin||line1.yRangeMin>line2.yRangeMax){
            return false;
        }
        else{
            return true;
        }
    }
    
    
    double findCommonX(Line line1, Line line2){
        if(line1.xRangeMin<=line2.xRangeMax&&line1.xRangeMin>=line2.xRangeMin){
            return line1.xRangeMin;
        }
        else{
            return line2.xRangeMin;
        }
    }
    
    
    bool valWithinXRange(double val, Line &line1){
        if(val<line1.getMaxXRange()&&val>line1.getMinXRange()){return true;}
        else if(equalTo(val, line1.getMaxXRange())||equalTo(val, line1.getMinXRange())){return true;}
        else{return false;}
    }
    
    

    /////////
    
};

//bool threeLinesShareSameIntersect(Line &line1, Line &line2, Line &line3){
//    if(!(line1+line2)||!(line2+line3)||!(line3+line1)){return false;}
//    if(findXIntersect(line1, line2)==findXIntersect(line2, line3)){
//        double xVal = findXIntersect(line1,line2);
//        if(findYVal(xVal, line1)==findYVal(xVal, line3)){return true;}
//
//    }
//    return false;
//}


double distanceBetweenPoints(Point &point1, Point &point2){
    double xdistSqr = (point1.getXCord()-point2.getXCord())*(point1.getXCord()-point2.getXCord());
    double ydistSqr = (point1.getYCord()-point2.getYCord())*(point1.getYCord()-point2.getYCord());
    double distance = sqrt(xdistSqr+ydistSqr);
    return distance;
}


bool threeLinesShareSameIntersect(Line &line1, Line &line2, Line &line3){
    //vertical lines case (NOTE: THERE SHOULD NEVER BE TWO OR MORE VERTICAL LINES IN QUESTION HERE!)
    //Recall the order of steps to determine the existence of a triangle:
    // 1. All lines intersect
    // 2. All lines have different slopes
    // 3. All lines do not intersect at the same point
    // All of this means a triangle is present
    if(!line1.getHasSlope()||!line2.getHasSlope()||!line3.getHasSlope()){
        //from here find the interesect of the vertical line and another line
        double xVal;
        if(!line1.getHasSlope()){
            xVal=line1.getMaxXRange();
            if(closeTo(line1.findYVal(xVal, line2), line1.findYVal(xVal, line3))){return true;}
        }
        if(!line2.getHasSlope()){
            xVal=line2.getMaxXRange();
            if(closeTo(line1.findYVal(xVal, line1), line1.findYVal(xVal, line3))){return true;}
        }
        if(!line3.getHasSlope()){
            xVal=line3.getMaxXRange();
            if(closeTo(line1.findYVal(xVal, line1), line1.findYVal(xVal, line2))){return true;}
        }
        //then see if that point is on the other final line
        return false;
    }
    //non-vertical lines case
    else{
        //find intersects of lines 1 and 2
        double xVal1and2 = line1.findXIntersect(line1, line2);
        double yVal1and2 = line1.findYVal(xVal1and2, line1);
        Point i1and2(xVal1and2,yVal1and2);
        //find intersects of lines 2 and 3
        double xVal2and3 = line1.findXIntersect(line2, line3);
        double yVal2and3 = line1.findYVal(xVal2and3, line2);
        Point i2and3(xVal2and3,yVal2and3);
        //find intersects of lines 1 and 3
        double xVal1and3 = line1.findXIntersect(line1, line3);
        double yVal1and3 = line1.findYVal(xVal1and3, line1);
        Point i1and3(xVal1and3,yVal1and3);
        if((distanceBetweenPoints(i1and2,i2and3)<MAX_DIST)&&(distanceBetweenPoints(i1and2, i1and3)<MAX_DIST)&&(distanceBetweenPoints(i1and3, i2and3)<MAX_DIST)){return true;}
    }
    
    
    
//    if(closeTo(line1.findXIntersect(line1, line2), line1.findXIntersect(line2, line3))){
//        double xVal = line1.findXIntersect(line1, line2);
//        double yval1=line1.findYVal(xVal, line1);
//        double yval2=line1.findYVal(xVal, line2);
//        double yval3=line1.findYVal(xVal, line3);
//        if(closeTo(yval1,yval2)&&closeTo(yval2,yval3)){return true;}
//        //if(abs(yval1-yval2)<.2&&abs(yval2-yval3)<.2){return true;}
//    //intersecting three lines at same point case, findY val does not work for vertical lines :(
//        else{return false;}
//    }
    return false;
}





//functions used for finding intersect and their general steps


//does common x exist?

//find common x

//use x in range to find intersect x

//is intersect x in both ranges?



#endif /* defineGraph_h */
