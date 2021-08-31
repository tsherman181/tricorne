//
//  triangleCounter.cpp
//  Triangle Problem
//
//  Created by Tom Sherman on 7/8/21.
//

#include "triangleCounter.h"
#include "unit_test_framework.h"


using namespace std;


//TEST(triangle){
//    cout<<"hello"<<endl;
//    ASSERT_TRUE(true);
//    Point point00(0,0);
//    Point point01(0,1);
//    Point point10(1,0);
//    vector<Point> vertices = {point00,point01,point10};
//    Shape triangle(vertices);
////    vector<vector<Line>> linePairs = findPairsOfIntersectingLines(triangle);
////    vector<vector<Line>> lineTrios = findTriosOfIntersectingLines(triangle);
////    cout<<lineTrios.size()<< " traingles are in this shape." <<endl;
//}
//
//TEST(square){
//    Point point00(0,0);
//    Point point01(0,1);
//    Point point10(1,0);
//    Point point11(1,1);
//    vector<Point> vertices = {point00,point01,point10,point11};
//    Shape square(vertices);
////    vector<vector<Line>> linePairs = findPairsOfIntersectingLines(square);
////    vector<vector<Line>> lineTrios = findTriosOfIntersectingLines(square);
//    //cout<<lineTrios.size()<< " traingles are in this shape." <<endl;
//}
//
//TEST(countTrianglesInSquare){
//    Point point00(0,0);
//    Point point01(0,1);
//    Point point10(1,0);
//    Point point11(1,1);
//    vector<Point> vertices = {point00,point01,point10,point11};
//    Shape square(vertices);
//    cout<<countTriangles(square);
//}
//
//TEST(countTrianglesInPentagon){
//    Point point00(0,0);
//    Point point01(0,1);
//    Point point10(1,0);
//    Point point11(1,1);
//    Point pointhalf1AndHalf(.5,1.5);
//    vector<Point> vertices = {point00,point01,point10,point11,pointhalf1AndHalf};
//    Shape pentagon(vertices);
//    cout<<countTriangles(pentagon);
//
//}

//TEST(hex){
//    Point point00(0,0);
//    Point point01(0,1);
//    Point point10(1,0);
//    Point point11(1,1);
//    Point pointhalf1AndHalf(.5,1.5);
//    Point pointhalfm1AndHalf(.5,-.5);
//    vector<Point> vertices = {point00,point01,point10,point11,pointhalf1AndHalf, pointhalfm1AndHalf};
//    Shape hex(vertices);
//    cout<<countTriangles(hex);
//}
//
//
//TEST(Jason){
//    //for fun
//    Point point01(0,1);
//    Point point25(2,5);
//    Point point63(6,3);
//    Point pointm33(-3,3);
//    Point pointm6m2(-6,-2);
//    Point point3m4(3,-4);
//    vector<Point> vertices = {point01,point25, point63, point3m4, pointm33, pointm6m2};
//    Shape jason(vertices);
//    cout<<endl<<"The number of triangles in Jason's shape is: " << countTriangles(jason)<<endl;
//}
//
//TEST(triangleCenterNode){
////should be 4 triangles
//    Point point00(0,0);
//    Point point11(1,1);
//    Point point12(1,2);
//    Point point20(2,0);
//    vector<Point> vertices = {point00,point11,point12,point20};
//    Shape centerNodeTri(vertices);
//    cout<<countTriangles(centerNodeTri);
//}
//
//TEST(centerNodeSquare){
//    Point point00(0,0);
//    Point point01(0,1);
//    Point point10(1,0);
//    Point point11(1,1);
//    Point pointhalfhalf(.5,.5);
//    vector<Point> vertices = {point00,point01,point10,point11,pointhalfhalf};
//    Shape square(vertices);
//    cout<<countTriangles(square);
//}

//TEST(octagon){
//    Point p03(0,3); //
//    Point p0m3(0,-3); //
//    Point p30(3,0); //
//    Point pm30(-3,0); //
//    Point p22(2,2); //
//    Point p2m2(2,-2); //
//    Point pm22(-2,2); //
//    Point pm2m2(-2,-2); //
//    vector<Point> vertices = {p03,p22,p30,p0m3,p2m2,pm22,pm30,pm2m2};
//    Shape octagon(vertices);
//    ASSERT_TRUE(countTriangles(octagon)==632);
//    //cout<<endl<<countTriangles(octagon);
//
//}

//TEST(septagon){
//    Point p03(0,3); //
//    Point p0m3(0,-3); //
//    Point p30(3,0); //
//    Point pm30(-3,0); //
//    Point p22(2,2); //
//    Point p2m2(2,-2); //
//    Point pm22(-2,2); //
//    vector<Point> vertices = {p03,p22,p30,p0m3,p2m2,pm22,pm30};
//    Shape septagon(vertices);
//    cout<<countTriangles(septagon);
//
//}

//TEST(septagonRegular){
//    Point p0m4(0,-4);
//    Point pm3m2(-3,-2);
//    Point pm41(-4,1);
//    Point pm24(-2,4);
//    Point p24(2,4);
//    Point p41(4,1);
//    Point p3m2(3,-2);
//    vector<Point> vertices = {p0m4,pm3m2,pm41,pm24,p24,p41,p3m2};
//    Shape septagonRegular(vertices);
//    //cout<<countTriangles(septagonRegular);
//    ASSERT_TRUE(countTriangles(septagonRegular)==287);
//    }

//TEST(thirteenSidedPentagon){
//    Point p1(0,-50);
//    Point p2(-23,-44);
//    Point p3(-41,-28);
//    Point p4(-50,-6);
//    Point p5(-47,18);
//    Point p6(-33,37);
//    Point p7(-12,49);
//    Point p8(12,49);
//    Point p9(33,37);
//    Point p10(47,18);
//    Point p11(50,-6);
//    Point p12(41,-28);
//    Point p13(23,-44);
//    vector<Point> vertices = {p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11,p12,p13};
//    Shape thirteen(vertices);
//    //cout<<countTriangles(thirteen);
//    ASSERT_TRUE(countTriangles(thirteen)==11297);
//}

TEST(twentySidedPentagon){
    Point p1(8, -49);
    Point p2(-8,-49);
    Point p3(-23,-45);
    Point p4(-35,-35);
    Point p5(-45,-23);
    Point p6(-49,-8);
    Point p7(-49,8);
    Point p8(-45,23);
    Point p9(-35,35);
    Point p10(-23,45);
    Point p11(-8,49);
    Point p12(8,49);
    Point p13(23,45);
    Point p14(35,35);
    Point p15(45,23);
    Point p16(49,8);
    Point p17(49,-8);
    Point p18(45,-23);
    Point p19(35,-35);
    Point p20(23,-45);
    vector<Point> vertices = {p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11,p12,p13, p14,p15,p16,p17,p18,p19,p20};
    Shape twenty(vertices);
    //cout<<countTriangles(twenty);
    //ASSERT_TRUE(countTriangles(twenty)==136200);
}
    /*
     8 -49
     -8 -49
     -23 -45
     -35 -35
     -45 -23
     -49 -8
     -49 8
     -45 23
     -35 35
     -23 45
     -8 49
     8 49
     23 45
     35 35
     45 23
     49 8
     49 -8
     45 -23
     35 -35
     23 -45
     
     */


//TEST(isTriangle){
//    Point p00(0,0);
//    Point p66(6,6);
//    Point p50(5,0);
//    Line line1(p00,p66);
//    Line line2(p66,p50);
//    Line line3(p50,p00);
//    vector<Line> trio ={line1,line2,line3};
//    ASSERT_TRUE(isTriangle(trio));
//    Point p121(12,1);
//    Line line4(p00,p121);
//    trio={line1,line4,line3};
//    ASSERT_TRUE(!(isTriangle(trio)));
//
//}
//
//TEST(moreIsTriangle){
//    Point point00(0,0);
//    Point point22(2,2);
//    Line line1(point00,point22);
//    Point point02(0,2);
//    Point point20(2,0);
//    Line line2(point02, point20);
//    Point point10(1,0);
//    Point point15(1,5);
//    Line line3(point10, point15);
//    vector<Line> trio ={line1,line2,line3};
//    ASSERT_TRUE(!(isTriangle(trio)));
//    Point point01half(0,1.5);
//    Point point61half(6,1.5);
//    Line line4(point01half,point61half);
//    vector<Line> trio2 = {line1,line2,line4};
//    ASSERT_TRUE(isTriangle(trio2));
//}
TEST_MAIN()
