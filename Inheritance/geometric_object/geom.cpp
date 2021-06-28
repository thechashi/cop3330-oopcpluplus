#include <iostream>
#include "geom.h"

using namespace std;

// member function definitions for GeometricObject class

GeometricObject::GeometricObject()
// default constructor
{
   cout << "Running GeometricObject default constructor\n";

   top = 0;
   left = 0;
   bottom = 0;
   right = 0;
}

GeometricObject::GeometricObject(int t, int l, int b, int r)
// constructor with parameters
{
   cout << "Runnning GeometricObject constructor with parameters\n";

   top = t;
   left = l;
   bottom = b;
   right = r;
}

void GeometricObject::Draw()
{

}

void GeometricObject::Erase()
{

}

void GeometricObject::Move(int h, int v)
{

}

// member functions for class Two_D_Object

Two_D_Object::Two_D_Object()
{
   cout << "Running Two_D_Object default constructor\n";
   fillPattern = 0;		// default setting
}

Two_D_Object::Two_D_Object(int t, int l, int b, int r, int fill) :
				GeometricObject(t, l, b, r)
{
   cout << "Running Two_D_Object constructor with parameters\n";
   fillPattern = fill;
}

void Two_D_Object::Draw()
{

}

// member functions for class Rectangle

Rectangle::Rectangle()
// sets up default rectangle
{
   cout << "Running Rectangle default constructor\n";
   length = 1;
   width = 1;
}

Rectangle::Rectangle(int t, int l, int b, int r, int f, int len,
             int wid) : Two_D_Object(t,l,b,r,f)
// version with parameters
{
   cout << "Running Rectangle constructor with parameters\n";
   length = len;
   width = wid;
}

void Rectangle::Draw()
{

}

// member functions for class Circle

Circle::Circle()
{
   radius = 1;
   center_x = 1;
   center_y = 1;
}


Circle::Circle(int t, int l, int b, int r, int f, int cx,
          int cy, int rad) : Two_D_Object(t, l, b, r, f)
{
   center_x = cx;
   center_y = cy;
   radius = rad;
}

void Circle::Draw()
{

}

