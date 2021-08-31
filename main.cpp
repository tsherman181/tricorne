//
//  main.cpp
//  Triangle Problem
//
//  Created by Tom Sherman on 8/13/21.
//

#include <stdio.h>
#include "triangleCounter.h"
#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cassert>
#include <fstream>
#include <cmath>

using namespace std;



vector<Point> getPolygonPoints(int numVertices, ifstream &fin){
    string dummy; string temp;
    int x; int y;
    vector<Point> vertices;
    fin>>dummy;
    
    assert(dummy=="XXX");
    int count=3;
    while(count!=numVertices){
        fin>>dummy;
        if(dummy=="XXX"){count++;}
    }
    fin>>dummy;
    for(int j=0; j<numVertices; j++){
        fin>>temp;
        x=stod(temp);
        fin>>temp;
        y=stod(temp);
        Point tempP(x,y);
        vertices.push_back(tempP);
    }
    return vertices;
}





int main(){
    //cout<<"Hello from main!"<<endl;
    ifstream fin;
    string numSides;
    fin.open("vertices.txt");
    //if(fin.is_open()){cout<<"File is open."<<endl;}
    cout<<"What degree polygon? ";
    cin>>numSides;
    if(stoi(numSides)%2==1){MAX_DIST=.001;}
    else{MAX_DIST=1;}
    vector<Point> vertices = getPolygonPoints(stoi(numSides), fin);
    Shape polygon(vertices);
    cout<<countTriangles(polygon)<<endl;;
    
    return 0;
}


