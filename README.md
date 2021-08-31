# tricorne
This project is my attempt at finding a computational solution to the number of triangles formed by intersecting diagonals of a regular polygon.


**Approach to the problem

My general approach to the problem was:
  first, to define a suitable interface to display a polygon with intersecting diagonals
  second, to count the number of triangles in said polygon using Steven and Jim Sommar's method.


**Structure

My code is structured in terms of vertices, lines, and shapes. A vertex is simply made of a pair of coordinates, two doubles, one representing x the other representing y (defineGraph.h). A line is not a true line, but rather a line segment, who's only defining features is its two end vertices (defineGraph.h). A shape is made of vertices and lines, with lines connecting each vertex to each other vertex (shape.h).


**Method

From here, I wrote code to immitate the triangle finding method of Article 98.1.5 by Steven and Jim Sommars discussed on pages 2-4. This used the shape created to attempt to identify as many triangles as possible within that shape.


**Regular Polygon Creation

To create the shapes used, the vertices of regular polygons were required. For these, I used https://www.mathopenref.com/coordpolycalc.html and also occasionally used my own calculations to determine the vertices of the appropriate regular polygons. These were then read these in from a text file (verticesText.txt) into main.cpp to create the shapes desired. 


**Solution Verification

I then used Article 98.1.5 page 5 to check my solutions. 


**Sources

“Polygon Vertex Calculator.” Coordinates of the Vertices of a Regular Polygon with Calculator, Math Open Reference, 2011, www.mathopenref.com/coordpolycalc.html. 

Sommars, Steven E, and Tim Sommars. “The Number of Triangles Formed by Intersecting Diagonals of a Regular Polygon.” Journal of Integer Sequences, vol. 1, 1998, pp. 1–6., cs.uwaterloo.ca/journals/JIS/index.html. 









