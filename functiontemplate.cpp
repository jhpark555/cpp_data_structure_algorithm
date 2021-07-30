#include <iostream>
#include <cstring>
#include <iomanip>
#include <cassert>
using namespace std;

template<class Type>
Type larger(Type x, Type y)
{
  if(x> y)
    return x;
  else
    return y;
}


class newString
{
      //Overload the stream insertion and extraction operators.
      friend ostream& operator<< (ostream&osObject, const newString& str)
      {
        osObject << str.strPtr;
        return osObject;
      }
      friend istream& operator>> (istream&isObject, newString& str)
      {
        char temp[81];
        isObject >> setw(81) >> temp;
        str = temp;
        return isObject;
      }

      public:
      const newString& operator=(const newString& rightStr)
      {
        if( this != &rightStr)
        {
          delete [] strPtr;
          strLength= rightStr.strLength;
          strPtr =new char[strLength +1];
          strcopy(rightStr.strPtr);
        }
        return *this;
      }
      //overload the assignment operator
      newString(const char *str)
      {
        strLength = strlen(str);
        strPtr = new char[strLength+1];

        strcopy(str);
      }
      //constructor; conversion from the char string
      newString()
      {
        strLength =0;
        strPtr = new char[1];
        strPtr[0] = '\0';
      }
      //Default constructor to initialize the string to nullptr
      newString(const newString& rightStr)
      {
        strLength =rightStr.strLength;
        strPtr = new char[strLength +1];
        strcopy(rightStr.strPtr);
      }
      //Copy constructor
      ~newString()
      {
        delete [] strPtr;
      }
      //Destructor
      char &operator[] (int index)
      {
        assert(0 <= index && index < strLength);
        return strPtr[index];
      }
      const char &operator[](int index) const
      {
        assert(0 <= index && index < strLength);
        return strPtr[index];
      }
      //overload the relational operators
      bool operator==(const newString& rightStr) const
      {
        return (strcmp(strPtr, rightStr.strPtr) == 0);
      }
      bool operator!=(const newString&rightStr) const
      {
        return (strcmp(strPtr, rightStr.strPtr) != 0);
      }
      bool operator<=(const newString&rightStr) const
      {
        return (strcmp(strPtr, rightStr.strPtr) <= 0);
      }
      bool operator<(const newString&rightStr) const
      {
        return (strcmp(strPtr, rightStr.strPtr) < 0);
      }
      bool operator>=(const newString&rightStr) const
      {
        return (strcmp(strPtr, rightStr.strPtr) >= 0);
      }
      bool operator>(const newString&rightStr) const
      {
        return (strcmp(strPtr, rightStr.strPtr) > 0);
      }
      private:
      char* strcopy(const char *str)
      {
        for (int i = 0; i < strLength; i++)
        strPtr[i] = str[i];
        strPtr[strLength] = '\0';
        return strPtr;
      }
      char* strcopy(char * str1, const char *str2)
      {
        for (int i = 0; i < strlen(str1); i++)
        str1[i] = str2[i];
        str1[strlen(str1)] = '\0';
        return str1;
      }
      char *strPtr; //pointer to the char array
      //that holds the string
      int strLength; //variable to store the length
      //of the string
};


int main()
{
      cout << "Line 8: Larger of 5 and 6 = "
    << larger(5, 6) << endl; //Line 8
    cout << "Line 9: Larger of A and B = "
    << larger('A', 'B') << endl; //Line 9
    cout << "Line 10: Larger of 5.6 and 3.2 = "
    << larger(5.6, 3.2) << endl; //Line 10
    newString str1 = "Hello"; //Line 11
    newString str2 = "Happy"; //Line 12
    cout << "Line 13: Larger of " << str1 << " and "
    << str2 << " = " << larger(str1, str2)
    << endl; //Line 13
    return 0;
}
