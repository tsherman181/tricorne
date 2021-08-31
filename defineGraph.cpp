//
//  defineGraph.cpp
//  Triangle Problem
//
//  Created by Tom Sherman on 7/8/21.
//

//#include <stdio.h>
#include "unit_test_framework.h"
#include "defineGraph.h"

using namespace std;

TEST(pointTest){
    Point point1(1,1);
    Point point2(1,1);
    ASSERT_TRUE(point1==point2);
    Point point3(1,3);
    ASSERT_TRUE(point2!=point3);
    ASSERT_TRUE(point1!=point3);
    point3=point1;
    ASSERT_TRUE(point1==point3);
}


TEST(lineTest){
    Point point1(1,1);
    Point point2(2,2);
    Line line1(point1, point2);
    Point point3(3,2);
    Point point4(1,2);
    Line line2(point3, point2);
    line1=line2;
    Line line3(point1, point3);
    ASSERT_TRUE(line1==line2);
    ASSERT_TRUE(line1!=line3);
    //double checking the == operator with switched endpoints
    Line line4(point2, point1);
    Line line5(point1, point2);
    Line vertical(point1, point4);
    ASSERT_TRUE(line4==line5);
    //to simplify, to check for line equality, we are not going to take midpoints into account due to percison issues. It should be assumed two lines with the same endpoints should have the same points.
    
    
}

TEST(BasicIntersect){
    //two lines which intersect in the middle of each line
    Point point1(0,0);
    Point point2(2,2);
    Point point3(0,1);
    Point point4(1,0);
    Line line1(point1, point2);
    Line line2(point3, point4);
    ASSERT_TRUE(line1+line2);
}

TEST(EndPointIntersect){
    //two lines where one line's endpoint is the intersect
    Point point1(0,0);
    Point point2(1,1);
    Line line1(point1,point2);
    Point point3(0,2);
    Point point4(2,0);
    Line line2(point3,point4);
    ASSERT_TRUE(line1+line2);
}

TEST(HorziontalLineIntersect){
    //this tests a hoizontal line with a non-horizonal line
    Point point1(-10,1);
    Point point2(10,1);
    Line line1(point1,point2);
    Point point3(0,2);
    Point point4(1,0);
    Line line2(point3,point4);
    ASSERT_TRUE(line1+line2);
    
}

TEST(IndentialLinesIntersect){
    Point point1(-10,1);
    Point point2(10,1);
    Line line1(point1,point2);
    Line line2(point1,point2);
    ASSERT_TRUE(line1+line2);
}
//This test case shouldn't happen.
//TEST(TwoVerticalLinesIntersect){
//    Point point1(0,0);
//    Point point2(0,3);
//    Point point3(0,6);
//    Point point4(0,3.5);
//    Line line1(point2, point4);
//    Line line2(point1, point3);
//    ASSERT_TRUE(line1+line2);
//}

TEST(VerticalAndNonVerticalIntersect){
    Point point1(0,0);
    Point point2(0,2);
    Point point3(-1,1);
    Point point4(1,1);
    Line line1(point1,point2);
    Line line2(point3,point4);
    Line line3(point3, point1);
    ASSERT_TRUE(line1+line2);
    ASSERT_TRUE(line1+line3);
}


TEST(ThreeLinesIntersectingSamePointShareSameVerticesCase){
    Point point00(0,0);
    Point point11(1,1);
    Point point21(2,1);
    Point pointm12(-1,2);
    Line line1(point00, point11);
    Line line2(point00, point21);
    Line line3(point00, pointm12);
    ASSERT_TRUE(threeLinesShareSameIntersect(line1, line3, line2));
}

TEST(ThreeLinesIntersectingSamePointShareMiddlePointCase){
    Point point00(0,0);
    Point point22(2,2);
    Line line1(point00,point22);
    Point point02(0,2);
    Point point20(2,0);
    Line line2(point02, point20);
    Point point10(1,0);
    Point point15(1,5);
    Line line3(point10, point15);
    ASSERT_TRUE(threeLinesShareSameIntersect(line1, line2, line3));
    
}

TEST(ThreeLinesDifferentIntersects){
    Point point00(0,0);
    Point point10(1,0);
    Point pointm10(-1,0);
    Line line1(point10,point00);
    Line line2(point10,pointm10);
    Line line3(pointm10, point00);
    ASSERT_TRUE(!threeLinesShareSameIntersect(line1, line2, line3));
    ASSERT_TRUE(line1%line2);
    ASSERT_TRUE(line2%line3);
    ASSERT_TRUE(line3%line1);
    ASSERT_TRUE(line1%line3);
}

TEST(NoIntersect){
    Point point00(0,0);
    Point point10(1,0);
    Point pointm10(-1,0);
    Point pointm15(-1,5);
    Line line1(point00,point10);
    Line line2(pointm10,pointm15);
    ASSERT_TRUE(!(line1+line2));
    ASSERT_TRUE(!(line1%line2));
    
}

TEST(TheseLinesShouldNotIntersect){
    Point point00(0,0);
    Point point20(2,0);
    Line line1(point00,point20);
    Point point11(1,1);
    Point point12(1,2);
    Line line2(point11,point12);
    ASSERT_TRUE(!(line1+line2));
    ASSERT_TRUE(!(line1%line2));

    
    
    
}


TEST(o458){
    Point p03(0,3);
    Point p30(3,0);
    Point pm2m2(-2,-2);
    Point pm30(-3,0);
    Point p0m3(0,-3);
    Line line1(p03,p30);
    Line line2(p03, pm2m2);
    Line line3(pm30, p0m3);
    ASSERT_TRUE(line1+line2);
    ASSERT_TRUE(!(line1+line3));
    ASSERT_TRUE(line2+line3);
}

TEST(o104){
    Point p0m3(0,-3);
    Point p03(0,3);
    Line line1(p03,p0m3);
    Point p22(2,2);
    Line line2(p22,p03);
    Point pm2m2(-2,-2);
    Line line3(pm2m2,p22);
    ASSERT_TRUE(line1+line2);
    ASSERT_TRUE(line2+line3);
    ASSERT_TRUE(line1+line3);
}

TEST(s317){
    Point p30(3,0);
    Point p03(0,3);
    Point pm22(-2,2);
    Point p0m3(0,-3);
    Line line1(p30,p03);
    Line line2(pm22,p30);
    Line line3(p0m3,p30);
    ASSERT_TRUE(line1+line2);
    ASSERT_TRUE(line2+line3);
    ASSERT_TRUE(line3+line1);
}

TEST(s823){
    Point p03(0,3);
    Point pm30(-3,0);
    Point p22(2,2);
    Point p30(3,0);
    Line line1(pm30,p30);
    Line line2(pm30,p22);
    Line line3(pm30,p30);
    ASSERT_TRUE(threeLinesShareSameIntersect(line1, line2, line3));
}

TEST_MAIN()
