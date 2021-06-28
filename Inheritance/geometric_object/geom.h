class GeometricObject
{
public:
   GeometricObject();
   GeometricObject(int t, int l, int b, int r);

   void Draw();
   void Erase();
   void Move(int h, int v);

protected:
   int top,
       left,
       bottom,
       right;

private:
   // any private members are declared here
   //  and are inaccessible outside this class
};

class Two_D_Object : public GeometricObject
// derived from GeometricObject
{
public:
   Two_D_Object();
   Two_D_Object(int t, int l, int b, int r, int fill);

   void Draw();

protected:

   int fillPattern;
};

class Rectangle : public Two_D_Object
{
public:
   Rectangle();
   Rectangle(int t, int l, int b, int r, int f, int len,
             int wid);

   void Draw();

private:
   int length, width;
};

class Circle : public Two_D_Object
{
public:
   Circle();
   Circle(int t, int l, int b, int r, int f, int cx,
          int cy, int rad);

   void Draw();

private:
   int center_x;
   int center_y;
   int radius;
};
