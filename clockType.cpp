#include <iostream>
using namespace std;

class clockType
{
public:
      void setTime(int hours, int minutes, int seconds);
      void printTime() const;
      bool operator==(const clockType& otherClock) const;
      //Overload the operator ==
      clockType operator+(const clockType& otherClock);
      clockType(int = 0, int = 0, int = 0);
private:
      int hr;
      int min;
      int sec;
};

bool clockType::operator==(const clockType& otherClock) const
{
      return (hr == otherClock.hr && min == otherClock.min
      && sec == otherClock.sec);
}

clockType  clockType::operator+(const clockType& otherClock)
{
      clockType ret;

      ret.hr = otherClock.hr + hr;
      ret.min = otherClock.min + min;
      ret.sec= otherClock.sec + sec;

      return ret;
}
clockType::clockType(int hours, int minutes, int seconds)
{
      if (0 <= hours && hours < 24)
      hr = hours;
      else
      hr = 0;
      if (0 <= minutes && minutes < 60)
      min = minutes;
      else
      min = 0;
      if (0 <= seconds && seconds < 60)
      sec = seconds;
      else
      sec = 0;
}
void clockType::setTime(int hours, int minutes, int seconds)
{
      if (0 <= hours && hours < 24)
      hr = hours;
      else
      hr = 0;
      if (0 <= minutes && minutes < 60)
      min = minutes;
      else
      min = 0;
      if (0 <= seconds && seconds < 60)
      sec = seconds;
      else
      sec = 0;
}

void clockType::printTime() const
{
      if (hr < 10)
      cout << "0";
      cout << hr << ":";
      if (min < 10)
      cout << "0";
      cout << min << ":";
      if (sec < 10)
      cout << "0";
      cout << sec;
}

int main() //Line 4
{ //Line 5
      clockType myClock(8, 23, 50); //Line 6
      clockType yourClock(8, 23, 50); //Line 7
      clockType tempClock(9, 16, 25); //Line 8
      cout << "Line 9: myClock: "; //Line 9
      myClock.printTime(); //Line 10
      cout << endl; //Line 11
      cout << "Line 12: yourClock: "; //Line 12
      yourClock.printTime(); //Line 13
      cout << endl; //Line 14
      cout << "Line 15: tempClock: "; //Line 15
      tempClock.printTime(); //Line 16
      cout << endl; //Line 17
      //Compare myClock and yourClock
      if (myClock == yourClock) //Line 18
      cout << "Line 19: The time of myClock and "
      << "yourClock are equal." << endl; //Line 19
      else //Line 20
      cout << "Line 21: The time of myClock and "
      << "yourClock are not equal." << endl; //Line 21
      //Compare myClock and tempClock
      if (myClock == tempClock) //Line 22
      cout << "Line 23: The time of myClock and "
      << "tempClock are equal." << endl; //Line 23
      else //Line 24
      cout << "Line 25: The time of myClock and "
      << "tempClock are not equal." << endl; //Line 25

      tempClock= myClock+yourClock;
      cout<<"Sum of two clock ";
      tempClock.printTime();
      return 0; //Line 26
}//end main
