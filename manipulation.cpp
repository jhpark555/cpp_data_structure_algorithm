#include <iostream>
using namespace std;

class integerManipulation
{
public:
      void setNum(long long n);
      //Function to set num.
      //Postcondition: num = n;
      long long getNum();
      //Function to return num.
      //Postcondition: The value of num is returned.
      void reverseNum();
      //Function to reverse the digits of num.
      //Postcondition: revNum is set to num with digits in
      // in the reverse order.
      void classifyDigits();
      //Function to count the even, odd, and zero digits of num.
      //Postcondition: evenCount = the number of even digits
      // in num.
      // oddCount = the number of odd digits in num.
      int getEvensCount();
      //Function to return the number of even digits in num.
      //Postcondition: The value of evensCount is returned.
      int getOddsCount();
      //Function to return the number of odd digits in num.
      //Postcondition: The value of oddscount is returned.
      int getZerosCount();
      //Function to return the number of zeros in num.
      //Postcondition: The value of zerosCount is returned.
      int sumDigits();
      //Function to return the sum of the digits of num.
      //Postcondition: The sum of the digits is returned.
      integerManipulation(long long n = 0);
      //Constructor with a default parameter.
      //The instance variable num is set accordingto the
      //parameter, and other instance variables are
      //set to zero.
      //The default value of num is 0;
      //Postcondition: num = n; revNum = 0; evenscount = 0;
      // oddsCount = 0; zerosCount = 0;
private:
      long long num;
      long long revNum;
      int evensCount;
      int oddsCount;
      int zerosCount;
};

class primeFactorization: public integerManipulation
{
public:
      void factorization();
      //Function to output the prime factorization of num.
      //Postcondition: Prime factorization of num is printed.
      primeFactorization(long long n = 0);
      //Constructor with a default parameter.
      //The instance variables of the base class are set according
      //to the parameters and the array first125000Primes is
      //created.
      //Postcondition: num = n; revNum = 0; evenscount = 0;
      // oddsCount = 0; zerosCount = 0;
      // first125000Primes = first 125000 prime numbers.
private:
      long long first125000Primes[125000];
      void first125000PrimeNum(long long list[], int length);
      //Function to determine and store the first 125000 prime
      //integers.
      //Postcondition: The first 125000 prime numbers are
      // determined and stored in the array first125000Primes.
      //Add additional functions as needed.
};


void integerManipulation::setNum(long long n)
{
      num = n;
}
long long integerManipulation::getNum()
{
      return num;
}
void integerManipulation::reverseNum()
{
      cout << "See Programming Exercise 9 in Chapter 6." << endl;
}
void integerManipulation::classifyDigits()
{
      long long temp;
      temp = abs(num);
      int digit;
      while (temp != 0)
      {
         digit = temp - (temp / 10 ) * 10;
         temp = temp / 10;
      if (digit % 2 == 0)
      {
         evensCount++;
        if (digit == 0)
         zerosCount++;
      }
      else
        oddsCount++;
      }
}

int integerManipulation::getEvensCount()
{
      return evensCount;
}
int integerManipulation::getOddsCount()
{
      return oddsCount;
}
int integerManipulation::getZerosCount()
{
      return zerosCount;
}
int integerManipulation::sumDigits()
{
      cout << "See Programming Exercise 1 in Chapter 5." << endl;
      return 0;
}
integerManipulation::integerManipulation(long long n)
{
      num = n;
      revNum = 0;
      evensCount = 0;
      oddsCount = 0;
      zerosCount = 0;
}

primeFactorization::primeFactorization(long long n)
: integerManipulation(n)
{
      first125000PrimeNum(first125000Primes, 125000);
}
void primeFactorization::factorization()
{
//See Programming Exercise 14 at the end of this chapter.
}

void primeFactorization::first125000PrimeNum(long long list[],int length)
{
  
}
int main()
{
   primeFactorization number;
   long long num;
    cout << "Enter an integer between 2 and "
    << "270,000,000,000,000: ";
    cin >> num;
    cout << endl;
    number.setNum(num);
    number.factorization();
  return 0;
}
