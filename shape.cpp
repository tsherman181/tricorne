//
//  shape.cpp
//  Triangle Problem
//
//  Created by Tom Sherman on 7/28/21.
//

#include <stdio.h>

#include "unit_test_framework.h"
#include "shape.h"



using namespace std;


TEST(Triagle){
    Point point00(0,0);
    Point point01(0,1);
    Point point10(1,0);
    vector<Point> vertices = {point00,point01,point10};
    Shape triangle(vertices);
    cout<<"Intersects: "<<triangle.countIntersects()<<endl;
    cout<<"Lines: "<<triangle.getNumLines()<<endl;
    cout<<"Vertices: "<<triangle.getNumVertices()<<endl;
    ASSERT_TRUE(triangle.linesHaveUniqueSlopes());
    ASSERT_TRUE(triangle.allLinesIntersect());
}


TEST(Square){
    Point point00(0,0);
    Point point01(0,1);
    Point point10(1,0);
    Point point11(1,1);
    vector<Point> vertices = {point00,point01,point10,point11};
    Shape square(vertices);
    cout<<"Intersects: "<<square.countIntersects()<<endl;
    cout<<"Lines: "<<square.getNumLines()<<endl;
    cout<<"Vertices: "<<square.getNumVertices()<<endl;
    ASSERT_TRUE(!square.linesHaveUniqueSlopes());
    ASSERT_TRUE(!square.allLinesIntersect());
}

TEST(Pentagon){
    Point point00(0,0);
    Point point01(0,1);
    Point point10(1,0);
    Point point11(1,1);
    Point pointHalf2(.5,2);
    vector<Point> vertices = {point00,point01,point10,point11,pointHalf2};
    Shape pentagon(vertices);
    cout<<"Intersects: "<<pentagon.countIntersects()<<endl;
    cout<<"Lines: "<<pentagon.getNumLines()<<endl;
    cout<<"Vertices: "<<pentagon.getNumVertices()<<endl;
    ASSERT_TRUE(!pentagon.linesHaveUniqueSlopes());
    ASSERT_TRUE(!pentagon.allLinesIntersect());
}

TEST(Hexagon){
    Point point00(0,0);
    Point point01(0,1);
    Point point10(1,0);
    Point point11(1,1);
    Point pointHalf2(.5,2);
    Point PointHalfm2(.5,-2);
    vector<Point> vertices = {point00,point01,point10,point11,pointHalf2,PointHalfm2};
    Shape hex(vertices);
    cout<<"Intersects: "<<hex.countIntersects()<<endl;
    cout<<"Lines: "<<hex.getNumLines()<<endl;
    cout<<"Vertices: "<<hex.getNumVertices()<<endl;
    ASSERT_TRUE(!hex.linesHaveUniqueSlopes());
    ASSERT_TRUE(!hex.allLinesIntersect());
}



TEST_MAIN()


