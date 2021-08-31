//
//  shape.h
//  Triangle Problem
//
//  Created by Tom Sherman on 7/28/21.
//

#ifndef shape_h
#define shape_h

//#include "unit_test_framework.h"
#include "defineGraph.h"


#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cassert>
#include <fstream>
#include <cmath>


class Shape{
    
    //friend declarations
    friend class Point;
    friend class DefineEquality;
    friend class Line;
    
    
    public:
    
    //Constructor
    Shape(std::vector<Point> &verticesVector) : Vertices(verticesVector), Lines({}){
        for(int i=0; i<Vertices.size()-1; i++){
            
            for(int j=i+1; j<Vertices.size(); j++){
                Line temp(Vertices[i], Vertices[j]);
                Lines.push_back(temp);
        }
            
    }
    }
    
    //functions which will help determine the existence of a triangle.
    
    int getNumLines(){
        return Lines.size();
    }
    
    int getNumVertices(){
        return Vertices.size();
    }
    
    bool linesHaveUniqueSlopes(){ //work on this //now I need to test this.//double check later
        std::vector<double> slopes;
        for(int i=0; i<Lines.size(); i++){
            slopes.push_back(Lines[i].getSlope());
            for(int j=0; j<i; j++){
                if(slopes[j]==slopes[i]){
                    return false;
                }
            }
        }
        return true;
    }
    
    int countIntersects(){
        int count=0;
        for(int x=0; x<Lines.size(); x++){
            int y=x+1;
            while(y<Lines.size()){
                if(Lines[x]+Lines[y]){
                    count++;
                }
                y++;
            }
        }
        return count;
    }
    
    std::vector<Line> getLines(){
        return Lines;
    }
    
    bool allLinesIntersect(){
        for(int i=0; i<Lines.size(); i++){
            for(int j=0; j<i; j++){
                if(!(Lines[j]+Lines[i])){return false;}
            }
        }
        return true;
    }
    
    private:
    std::vector<Line> Lines;
    std::vector<Point> Vertices;
    
};


/*
 shapes are triangles if:
 they have exactly:
    3 vertices
    3 edges
 No lines share the same slope
 Each line intersects each other line

 
 */



#endif /* shape_h */
