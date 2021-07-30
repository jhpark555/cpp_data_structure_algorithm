//The user program that uses the class circleType
#include <iostream> //Line 1
#include <iomanip> //Line 2


class circleType
{
public:
void setRadius(double r);
//Function to set the radius.
//Postcondition: if (r >= 0) radius = r;
// otherwise radius = 0;
double getRadius();
//Function to return the radius.
//Postcondition: The value of radius is returned.
double area();
//Function to return the area of a circle.
//Postcondition: Area is calculated and returned.
double circumference();
//Function to return the circumference of a circle.
//Postcondition: Circumference is calculated and returned.
circleType(double r = 0);
//Constructor with a default parameter.
//Radius is set according to the parameter.
//The default value of the radius is 0.0;
//Postcondition: radius = r;
private:
double radius;
};

void circleType::setRadius(double r)
{
if (r >= 0)
radius = r;
else
radius = 0;
}

double circleType::getRadius()
{
return radius;
}
double circleType::area()
{
return 3.1416 * radius * radius;
}
double circleType::circumference()
{
return 2 * 3.1416 * radius;
}
circleType::circleType(double r)
{
setRadius(r);
}

using namespace std; //Line 4
int main() //Line 5
{ //Line 6
    circleType circle1(8); //Line 7
    circleType circle2; //Line 8
    double radius; //Line 9
        cout << fixed << showpoint << setprecision(2); //Line 10
        cout << "Line 11: circle1 - "
        << "radius: " << circle1.getRadius()
        << ", area: " << circle1.area()
        << ", circumference: "
        << circle1.circumference() << endl; //Line 11
        cout << "Line 12: circle2 - "
        << "radius: " << circle2.getRadius()
        << ", area: " << circle2.area()
        << ", circumference: "
        << circle2.circumference() << endl << endl; //Line 12
        cout << "Line 13: Enter the radius: "; //Line 13
        cin >> radius; //Line 14
        cout << endl; //Line 15
        circle2.setRadius(radius); //Line 16
        cout << "Line 17: After setting the radius."
        << endl; //Line 17
        cout << "Line 18: circle2 - "
        << "radius: " << circle2.getRadius()
        << ", area: " << circle2.area()
        << ", circumference: "
        << circle2.circumference() << endl; //Line 18
    return 0; //Line 19
}//end main //Line 20
