//The user program that uses the class die
#include <ctime>
#include <iostream> //Line 1
using namespace std; //Line 3

class die
{
public:
    die();
    //Default constructor
    //Sets the default number rolled by a die to 1
    void roll();
    //Function to roll a die.
    //This function uses a random number generator to randomly
    //generate a number between 1 and 6, and stores the number
    //in the instance variable num.
    int getNum() const;
    //Function to return the number on the top face of the die.
    //Returns the value of the instance variable num.
private:
    int num;
};

die::die()
{
    num = 1;
    srand(time(0));
}
void die::roll()
{
    num = rand() % 6 + 1;
}
int die::getNum() const
{
    return num;
}

int main() //Line 4
{ //Line 5
    die die1; //Line 6
    die die2; //Line 7
        cout << "Line 8: die1: " << die1.getNum()
        << endl; //Line 8
        cout << "Line 9: die2: " << die2.getNum()
        << endl; //Line 9
        die1.roll(); //Line 10
        cout << "Line 11: After rolling die1: "
        << die1.getNum() << endl; //Line 11
        die2.roll(); //Line 12
        cout << "Line 13: After rolling die2: "
        << die2.getNum() << endl; //Line 13
        cout << "Line 14: The sum of the numbers rolled"
        << " by the dice is: "
        << die1.getNum() + die2.getNum() << endl; //Line 14
        die1.roll(); //Line 15
        die2.roll(); //Line 16
        cout << "Line 17: After again rolling, the sum of "
        << "the numbers rolled is: "
        << die1.getNum() + die2.getNum() << endl; //Line 17
    return 0; //Line 18
}//end main //Line 19
