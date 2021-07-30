#include <iostream>
#include <iomanip>
using namespace std;


class rectangleType
{
     friend void rectangleFriend(rectangleType recObject);
     friend rectangleType operator+(const rectangleType& firstRect, const rectangleType& secondRect);
     friend ostream& operator<< (ostream&, const rectangleType &);
     friend istream& operator>> (istream&, rectangleType &);
    //  {
    //    rectangleType tempRect;
    //    tempRect.length = firstRect.length + secondRect.length;
    //    tempRect.width = firstRect.width + secondRect.width;
    //    return tempRect;
    //  }
public:
      void setDimension(double l, double w)
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
      double getLength() const
      {
        return length;
      }
      double getWidth() const
      {
        return width;
      }
      double area() const
      {
        return length * width;
      }

      double perimeter() const
      {
          return 2 * (length + width);
      }
      void print() const
      {
        cout << "Length = " << length
        << "; Width = " << width;
      }
      rectangleType& setLength(double l)
      {
        length = l;
        return *this;
      }
      //Function to set the length.
      //Postcondition: length = l
      // After setting the length, a reference to the object,
      // that is, the address of the object, is returned.
      rectangleType& setWidth(double w)
      {
        width = w;
        return *this;
      }

      rectangleType operator+(const rectangleType& rectangle) const
      {
        rectangleType tempRect;

        tempRect.length = length + rectangle.length;
        tempRect.width = width + rectangle.width;
        return tempRect;
      }
      rectangleType operator*(const rectangleType& rectangle) const
      {
        rectangleType tempRect;
        tempRect.length = length * rectangle.length;
        tempRect.width = width * rectangle.width;
        return tempRect;
      }
      bool operator==(const rectangleType& rectangle) const
      {
        return (length == rectangle.length &&
                width == rectangle.width);
      }
      //Overload the operator ==
      bool operator!=(const rectangleType& rectangle) const
      {
        return (length != rectangle.length ||
                width != rectangle.width);
      }


      //Function to set the width.
      //Postcondition: width = w
      // After setting the width, a reference to the object,
      // that is, the address of the object, is returned.
      rectangleType(double l=0, double w=0 )
      {
        length =l;
        width=w;
      }
private:
      double length;
      double width;
};

void rectangleFriend(rectangleType recFriendObject)
{
      cout << "\nrecFriendObject area: " << recFriendObject.area()
      << endl;
      recFriendObject.length = recFriendObject.length + 5;
      recFriendObject.width = recFriendObject.width + 5;
      cout << "After increasing length and width by 5 units "
      << "each, \n recFriendObject area: "
      << recFriendObject.area() << endl;
}
rectangleType operator+(const rectangleType& firstRect, const rectangleType& secondRect)
{
    rectangleType tempRect;
    tempRect.length = firstRect.length + secondRect.length;
    tempRect.width = firstRect.width + secondRect.width;
    return tempRect;
}

ostream& operator<< (ostream& osObject, const rectangleType& rectangle)
{
      osObject << "Length = " << rectangle.length
      << "; Width = " << rectangle.width;
      return osObject;
}
istream& operator>> (istream& isObject, rectangleType& rectangle)
{
      isObject >> rectangle.length >> rectangle.width;
      return isObject;
}

int main() //Line 5
{ //Line 6
  #if 0
      rectangleType myRectangle; //Line 7
      rectangleType yourRectangle; //Line 8
      cout << fixed << showpoint << setprecision(2); //Line 9
      myRectangle.setLength(15.25).setWidth(12.00); //Line 10
      cout << "Line 11 -- myRectangle: "; //Line 11
      myRectangle.print(); //Line 12
      cout << endl; //Line 13
      yourRectangle.setLength(18.50); //Line 14
      cout << "Line 15 -- yourRectangle: "; //Line 15
      yourRectangle.print(); //Line 16
      cout << endl; //Line 17
      yourRectangle.setWidth(7.50); //Line 18
      cout << "Line 19 -- yourRectangle: "; //Line 19
      yourRectangle.print(); //Line 20
      cout << endl; //Line 21

    //  rectangleFriend(myRectangle);

      cout<<endl;
      cout<<endl;
      rectangleType rectangle1(23, 45); //Line 6
      rectangleType rectangle2(12, 10); //Line 7
      rectangleType rectangle3; //Line 8
      rectangleType rectangle4; //Line 9
      cout << "Line 10: rectangle1: "; //Line 10
      rectangle1.print(); //Line 11
      cout << endl; //Line 12
      cout << "Line 13: rectangle2: "; //Line 13
      rectangle2.print(); //Line 14
      cout << endl; //Line 15
      rectangle3 = rectangle1 + rectangle2; //Line 16
      cout << "Line 17: rectangle3: "; //Line 17
      rectangle3.print(); //Line 18
      cout << endl; //Line 19
      rectangle4 = rectangle1 * rectangle2; //Line 20
      cout << "Line 21: rectangle4: "; //Line 21
      rectangle4.print(); //Line 22
      cout << endl; //Line 23
      if (rectangle1 == rectangle2) //Line 24
      cout << "Line 25: rectangle1 and "
      << "rectangle2 are equal." << endl; //Line 25
      else //Line 26
      cout << "Line 27: rectangle1 and "
      << "rectangle2 are not equal."
      << endl; //Line 27
      if (rectangle1 != rectangle3) //Line 28
      cout << "Line 29: rectangle1 and "
      << "rectangle3 are not equal."
      << endl; //Line 29
      else //Line 30
      cout << "Line 31: rectangle1 and "
      << "rectangle3 are equal." << endl;

      cout<<endl;
      cout<<endl;
#endif
      rectangleType myRectangle(23, 45); //Line 6
      rectangleType yourRectangle; //Line 7
      cout << "Line 8: myRectangle: " << myRectangle
      << endl; //Line 8
      cout << "Line 9: Enter the length and width "
      << "of a rectangle: "; //Line 9
      cin >> yourRectangle; //Line 10
      cout << endl; //Line 11
      cout << "Line 12: yourRectangle: "
      << yourRectangle << endl; //Line 12
      cout << "Line 13: myRectangle + yourRectangle: "
      << myRectangle + yourRectangle << endl; //Line 13
      cout << "Line 14: myRectangle * yourRectangle: "
      << myRectangle * yourRectangle << endl;

      return 0; //Line 22
}
