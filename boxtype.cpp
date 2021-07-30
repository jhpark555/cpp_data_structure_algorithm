#include <iostream>
#include <iomanip>

using namespace std;

class rectangleType
{
public:
      void setDimension(double l, double w);
      //Function to set the length and width of the rectangle.
      //Postcondition: length = l; width = w;
      double getLength() const;
      //Function to return the length of the rectangle.
      //Postcondition: The value of length is returned.
      double getWidth() const;
      //Function to return the width of the rectangle.
      //Postcondition: The value of width is returned.
      double area() const;
      //Function to return the area of the rectangle.
      //Postcondition: The area of the rectangle is
      // calculated and returned.
      double perimeter() const;
      //Function to return the perimeter of the rectangle.
      //Postcondition: The perimeter of the rectangle is
      // calculated and returned.
      void print() const;
      //Function to output the length and width of
      //the rectangle.
      rectangleType();
      //Default constructor
      //Postcondition: length = 0; width = 0;
      rectangleType(double l, double w);
      //Constructor with parameters
      //Postcondition: length = l; width = w;
private:
      double length;
      double width;
};

class boxType: public rectangleType
{
public:
      void setDimension(double l, double w, double h);
      //Function to set the length, width, and height
      //of the box.
      //Postcondition: length = l; width = w; height = h;
      double getHeight() const;
      //Function to return the height of the box.
      //Postcondition: The value of height is returned.
      double area() const;
      //Function to return the surface area of the box.
      //Postcondition: The surface area of the box is
      // calculated and returned.
      double volume() const;
      //Function to return the volume of the box.
      //Postcondition: The volume of the box is
      // calculated and returned.
      void print() const;
      //Function to output the length, width, and height of a box.
      boxType();
      //Default constructor
      //Postcondition: length = 0; width = 0; height = 0;
      boxType(double l, double w, double h);
//Constructor with parameters
//Postcondition: length = l; width = w; height = h;
private:
      double height;
};


void rectangleType::setDimension(double l, double w)
{
      if (l >= 0)
      length = l;
      else
      length = 0;
      if (w >= 0)
      width = w;
      else
      width = 0;
}
double rectangleType::getLength() const
{
      return length;
}
double rectangleType::getWidth()const
{
      return width;
}
double rectangleType::area() const
{
      return length * width;
}
double rectangleType::perimeter() const
{
      return 2 * (length + width);
}
void rectangleType::print() const
{
      cout << "Length = " << length
      << "; Width = " << width;
}
rectangleType::rectangleType(double l, double w)
{
      setDimension(l, w);
}
rectangleType::rectangleType()
{
      length = 0;
      width = 0;
}

void boxType::print() const
{
      rectangleType::print();
      cout << "; Height = " << height;
}
void boxType::setDimension(double l, double w, double h)
{
      rectangleType::setDimension(l, w);
      if (h >= 0)
      height = h;
      else
      height = 0;
}

double boxType::getHeight() const
{
      return height;
}
double boxType::area() const
{
      return 2 * (getLength() * getWidth()
          + getLength() * height
          + getWidth() * height);
}
double boxType::volume() const
{
      return rectangleType::area() * height;
}
boxType::boxType(double l, double w, double h)
: rectangleType(l, w)
{
      if (h >= 0)
      height = h;
      else
      height = 0;
}
boxType::boxType():rectangleType()
{
  height=0;
}

int main() //Line 6
{ //Line 7
    rectangleType yard; //Line 8
    double fenceCostPerFoot; //Line 9
    double fertilizerCostPerSquareFoot; //Line 10
    double length, width; //Line 11
    double billingAmount; //Line 12
        cout << fixed << showpoint << setprecision(2); //Line 13
        cout << "Line 14: Enter the length and width of the "
        << "yard (in feet): "; //Line 14
        cin >> length >> width; //Line 15
        cout << endl; //Line 16
        yard.setDimension(length, width); //Line 17
        cout << "Line 18: Enter the cost of fence "
        << "(per foot): $"; //Line 18
        cin >> fenceCostPerFoot; //Line 19
        cout << endl; //Line 20
        cout << "Line 21: Enter the cost of fertilizer "
        << "(per square foot): $"; //Line 21
        cin >> fertilizerCostPerSquareFoot; //Line 22
        cout << endl; //Line 23
        billingAmount = yard.perimeter() * fenceCostPerFoot
        + yard.area() * fertilizerCostPerSquareFoot; //Line 24
        cout << "Line 25: Amount due: $" << billingAmount
        << endl; //Line 25
    boxType package; //Line 26
    double height; //Line 27
    double wrappingCostPerSquareFeet; //Line 28
        cout << "Line 29: Enter the length, width, and height "
        << "of the package (in feet): "; //Line 29
        cin >> length >> width >> height; //Line 30
        cout << endl; //Line 31
        package.setDimension(length, width, height); //Line 32
        cout << "Line 33: Enter the cost (25 to 50 cents) of "
        << "wrapping per square foot: "; //Line 33
        cin >> wrappingCostPerSquareFeet; //Line 34
        cout << endl; //Line 35
        billingAmount = wrappingCostPerSquareFeet
        * package.area() / 100; //Line 36
        if (billingAmount < 1.00) //Line 37
        billingAmount = 1.00; //Line 38
        cout << "Line 39: Amount due: $" << billingAmount
        << endl; //Line 39
return 0; //Line 40
}
