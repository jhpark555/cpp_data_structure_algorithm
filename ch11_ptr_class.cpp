#include <iostream>
using namespace std;

class ptrMemberVarType
{
public:
      void print() const;
      //Function to output the data stored in the array p.
      void insertAt(int index, int num);
      //Function to insert num into the array p at the
      //position specified by index.
      //If index is out of bounds, the program is terminated.
      //If index is within bounds, but greater than the index
      //of the last item in the list, num is added at the end
      //of the list.
      ptrMemberVarType(int size = 10);
      //Constructor
      //Creates an array of the size specified by the
      //parameter size; the default array size is 10.
      ~ptrMemberVarType();
      //Destructor
      //Deallocates the memory space occupied by the array p.
      ptrMemberVarType (const ptrMemberVarType& otherObject);
      //Copy constructor
private:
      int maxSize; //variable to store the maximum size of p
      int length; //variable to store the number elements in p
      int *p; //pointer to an int array
};

void ptrMemberVarType::print() const
{
      for (int i = 0; i < length; i++)
      cout << p[i] << " ";
}
void ptrMemberVarType::insertAt(int index, int num)
{
      //If index is out of bounds, terminate the program
    //  assert(index >= 0 && index < maxSize);
      if (index < length)
      p[index] = num;
      else
      {
      p[length] = num;
      length++;
      }
}
ptrMemberVarType::ptrMemberVarType(int size)
{
      if (size <= 0)
      {
      cout << "The array size must be positive." << endl;
      cout << "Creating an array of the size 10." << endl;
      maxSize = 10;
      }
      else
      maxSize = size;
      length = 0;
      p = new int[maxSize];
}

ptrMemberVarType::~ptrMemberVarType()
{
      delete [] p;
}

ptrMemberVarType::ptrMemberVarType(const ptrMemberVarType& otherObject)
{
      maxSize = otherObject.maxSize;
      length = otherObject.length;
      p = new int[maxSize];
      for (int i = 0; i < length; i++)
      p[i] = otherObject.p[i];
}

void testCopyConst(ptrMemberVarType temp) //Line 37
{ //Line 38
      cout << "Line 39: *** Inside the function "
      << "testCopyConst ***" << endl; //Line 39
      cout << "Line 40: Object temp data: "; //Line 40
      temp.print(); //Line 41
      cout << endl; //Line 42
      temp.insertAt(3, -100); //Line 43
      cout << "Line 44: After changing temp: "; //Line 44
      temp.print(); //Line 45
      cout << endl; //Line 46
      cout << "Line 47: *** Exiting the function "
      << "testCopyConst ***" << endl; //Line 47
} //Line

int main() //Line 5
{ //Line 6
      ptrMemberVarType listOne; //Line 7
      int num; //Line 8
      cout << "Line 9: Enter 5 integers." << endl; //Line 9
      for (int index = 0; index < 5; index++) //Line 10
      { //Line 11
            cin >> num; //Line 12
            listOne.insertAt(index, num); //Line 13
      } //Line 14
      cout << "Line 15: listOne: "; //Line 15
            listOne.print(); //Line 16
            cout << endl; //Line 17
      //Declare listTwo and initialize it using listOne
      ptrMemberVarType listTwo(listOne); //Line 18
      cout << "Line 19: listTwo: "; //Line 19
            listTwo.print(); //Line 20
            cout << endl; //Line 21
            listTwo.insertAt(5, 34); //Line 22
            listTwo.insertAt(2, -76); //Line 23
      cout << "Line 24: After modifying listTwo: "; //Line 24
            listTwo.print(); //Line 25
            cout << endl; //Line 26
      cout << "Line 27: After modifying listTwo, "
      << "listOne: "; //Line 27
            listOne.print(); //Line 28
            cout << endl; //Line 29
      cout << "Line 30: Calling the function testCopyConst"
      << endl; //Line 30
      //Call function testCopyConst
            testCopyConst(listOne); //Line 31
      cout << "Line 32: After a call to the function "
            << "testCopyConst, " << endl
            << " listOne is: "; //Line 32
            listOne.print(); //Line 33
            cout << endl; //Line 34
      return 0; //Line 35
}
