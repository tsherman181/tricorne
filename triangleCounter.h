//
//  triangleCounter.h
//  Triangle Problem
//
//  Created by Tom Sherman on 7/8/21.
//

#ifndef triangleCounter_h
#define triangleCounter_h


//#include "unit_test_framework.h"
#include "defineGraph.h"
#include "shape.h"

#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cassert>
#include <fstream>
#include <cmath>

//create a vector containing subvectors (or some other type of data structure) of each of the possible 3 combinations of lines

std::vector<std::vector<Line>> getLinetrios(Shape &shape){
    std::vector<std::vector<Line>> lineTrios;
    std::vector<Line> lines = shape.getLines();
    for(int i=0; i<lines.size()-2; i++){
        for(int j=i+1; j<lines.size()-1; j++){
            for(int k=j+1; k<lines.size(); k++){
                std::vector<Line> temp = {lines[i], lines[j], lines[k]};
                lineTrios.push_back(temp);
            }
        }
    }
    
    //work still must be done here. Consider sorting using the sort function. This is a really complex problem and is way too confusing for 1am at night.
    //This now needs to be tested.
    
    //This seems to be working properly 
    
    return lineTrios;
}

int numNodesPerTriangle(std::vector<Line> &trios){
    int numNodes=6;
    if(trios[0]%trios[1]){--numNodes;}
    if(trios[0]%trios[2]){--numNodes;}
    if(trios[1]%trios[2]){--numNodes;}
    if(threeLinesShareSameIntersect(trios[1], trios[2], trios[0])){++numNodes;}
    return numNodes;
}

bool isTriangle(std::vector<Line> &trios){
    if(trios.size()!=3){return false;}
    //int nodeCount = numNodesPerTriangle(trios);
    //std::cout<<"Number of nodes = " <<nodeCount<<std::endl;
    
    if(trios[0]+trios[1]&&trios[1]+trios[2]&&trios[2]+trios[0]){
        if(trios[0].getSlope()!=trios[1].getSlope()&&trios[0].getSlope()!=trios[2].getSlope()&&trios[1].getSlope()!=trios[2].getSlope()){
            if(!(threeLinesShareSameIntersect(trios[1], trios[2], trios[0]))){
//                if(nodeCount==6){
//                    std::cout<<"Hoorah!";
//                }
//                int nodeCount = numNodesPerTriangle(trios);
//                std::cout<<"Number of nodes = " <<nodeCount<<std::endl;
                //std::cout<<"is triangle"<<std::endl;
                return true;
            }
            //else{std::cout<<"three lines share same intersect"<<std::endl;}
        }
        //else{std::cout<<"slopes are not different"<<std::endl;}

    }
    //else{std::cout<<"triangle sides do not intersect"<<std::endl;}
return false;
}

int countTriangles(Shape &shape){
    std::vector<std::vector<Line>> lineTrios = getLinetrios(shape);
    int count=0;
    int nodes3=0;
    int nodes4=0;
    int nodes5=0;
    int nodes6=0;
    for(int i=0; i<lineTrios.size(); i++){
//        std::cout<<i<<std::endl;
//        if(i==3882){
//            std::string silly="";
//        }
        
        if(isTriangle(lineTrios[i])){
            count++;
            if(numNodesPerTriangle(lineTrios[i])==3){nodes3++;}
            else if(numNodesPerTriangle(lineTrios[i])==4){nodes4++;}
            else if(numNodesPerTriangle(lineTrios[i])==5){nodes5++;}
            else if(numNodesPerTriangle(lineTrios[i])==6){nodes6++;}
        }
    }
    std::cout<<"Triangles with 3 nodes: " << nodes3<<std::endl;
    std::cout<<"Triangles with 4 nodes: " << nodes4<<std::endl;
    std::cout<<"Triangles with 5 nodes: " << nodes5<<std::endl;
    std::cout<<"Triangles with 6 nodes: " << nodes6<<std::endl;
    return count;
}

//std::vector<int> countNodes(std::vector<Line> &trios){
//    int threeNodes=0;
//    int fourNodes=0;
//    int fiveNodes=0;
//    int sixNodes=0;
//
//
//    return {};
//}







//
//class Triangle{
//
//    friend class Point;
//    friend class DefineEquality;
//    friend class Line;
//    friend class Shape;
//
//    public:
//
//
//
//    private:
//    Shape triangle;
//
//
//
//};
//
//
//
//
//
//
//
//
//
//
//
//
//std::vector<std::vector<Line>> findPairsOfIntersectingLines(Shape shape){
//    std::vector<Line> Lines = shape.getLines();
//    std::vector<std::vector<Line>> pairsOfIntersectingLines;
//    for(int i=0; i<Lines.size(); i++){
//        for(int j=i+1; j<Lines.size();j++){
//            if(Lines[i]+Lines[j]){
//                std::vector<Line> temp = {Lines[i], Lines[j]};
//                pairsOfIntersectingLines.push_back(temp);
//            }
//        }
//    }
//    return pairsOfIntersectingLines;
//}
//
//std::vector<std::vector<Line>> findTriosOfIntersectingLines(Shape shape){
//    std::vector<std::vector<Line>> triosOfLines;
//    std::vector<std::vector<Line>> pairsOfLines = findPairsOfIntersectingLines(shape);
//    std::vector<Line> lines = shape.getLines();
//    for(int i=0; i<pairsOfLines.size(); i++){
//        for(int j=0; j<lines.size(); j++){
//            if(lines[j]+pairsOfLines[i][0]&&lines[j]+pairsOfLines[i][1]){
//                std::vector<Line> temp = {lines[j], pairsOfLines[i][0], pairsOfLines[i][1]};
//                triosOfLines.push_back(temp);
//            }
//        }
//    }
//    return triosOfLines;
//}
//
//
#endif /* triangleCounter_h */
