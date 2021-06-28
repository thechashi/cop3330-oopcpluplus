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
// any part of the drawing task that can be done by the base class 
//  should be done here (i.e. part of Draw that applies to ALL
//  geometric objects
{
   cout << "Running GeometricObject::Draw() function\n";
}

void GeometricObject::Erase()
{
   cout << "Running GeometricObject::Erase() function\n";
}

void GeometricObject::Move(int h, int v)
{
   cout << "Running GeometricObject::Move() function\n";
}

void GeometricObject::Boundaries()
// function to re-calculate boundaries after a change
{
   // recomputations that adjust top, left, right, bottom
   //  go here

   cout << "Running GeometricObject::Boundaries() function\n";
}

int GeometricObject::GetTop()
{
   return top;
}

int GeometricObject::GetLeft()
{
   return left;
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

void Two_D_Object::FindCenter(int& row, int& col)
{
   cout << "Running Two_D_Object::FindCenter()\n";
}


void Two_D_Object::Draw()
{
   cout << "Running Two_D_Object::Draw()\n";

   // we can call upon the base class version of Draw here
   GeometricObject::Draw();
   
   // and do any processing specific to this class' data

   cout << "Finishing Two_D_Object::Draw()\n";
}

double Two_D_Object::Area()
{
   cout << "Running Two_D_Object::Area()\n";
}

void Two_D_Object::Boundaries()
{
   cout << "Running Two_D_Object::Boundaries()\n";
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

void Rectangle::FindCenter(int& row, int& col)
{
   cout << "Running Rectangle::FindCenter()\n";
   
   // we can invoke the Two_D_Object version
   Two_D_Object::FindCenter(row, col);

   cout << "Leaving Rectangle::FindCenter()\n";
}

void Rectangle::Draw()
{
   cout << "Running Rectangle::Draw()\n";

   Two_D_Object::Draw();	// do any pre-processing

   // actual drawing of the rectangle goes here (w/ length, width)

   cout << "Finishing Rectangle::Draw()\n";
}

double Rectangle::Area()
{
   cout << "Running Rectangle::Area()\n";
}

int Rectangle::Perimeter()
{
   cout << "Running Rectangle::Perimeter()\n";
   return (2*length + 2*width);
}


// member functions for class Circle

Circle::Circle()
{
   radius = 1;
   center_x = 1;
   center_y = 1;
}


Circle::Circle(int t, int l, int b, int r, int f, int cx,
          int cy, int rad) : Two_D_Object(t,l,b,r,f)
{
   center_x = cx;
   center_y = cy;
   radius = rad;
}

void Circle::FindCenter(int& row, int& col)
{

}

void Circle::Draw()
{

}

double Circle::Area()
{

}

double Circle::Circumference()
{

}

