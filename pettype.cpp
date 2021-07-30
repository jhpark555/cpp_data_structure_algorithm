#include <iostream>
using namespace std;

class petType
{
public:
      virtual void print() const;
      petType(string n = "");
private:
      string name;
};

class dogType: public petType
{
public:
      void print() const;
      void setBreed(string b = "");
      dogType(string n = "", string b = "");
private:
      string breed;
};

void petType::print() const
{
      cout << "Name: " << name;
}
petType::petType(string n)
{
      name = n;
}
void dogType::print() const
{
      petType::print();
      cout << ", Breed: " << breed << endl;
}
void dogType::setBreed(string b)
{
     breed= b;
}
dogType:: dogType(string n, string b) : petType(n)
{
      breed = b;
}

void callPrint(petType* p)
{
    //p.print();
    p->print();
}

int main() //Line 1
{ //Line 2
    //  petType pet("Lucky"); //Line 3
      //dogType dog("Tommy", "German Shepherd"); //Line 4
      petType *q = new petType("Lucky");
      dogType *r = new dogType("Tommy", "German Shepherd");

      r->setBreed("Siberian Husky ");
    
    //  pet.print(); //Line 5
      q->print();

      cout << endl; //Line 6
    //  dog.print(); //Line 7
      r->print();
      cout << "*** Calling the function callPrint ***"
      << endl; //Line 8

    //  callPrint(pet); //Line 9
      callPrint(q);
      cout << endl; //Line 10

      //callPrint(dog); //Line 11
      callPrint(r);

      cout << endl; //Line 12
      return 0; //Line 13
}
