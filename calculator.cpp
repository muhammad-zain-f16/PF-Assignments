#include <iostream>
using namespace std;

int char_to_int(char x);
int number(char [], int &sindex); // this function will make numbers from the evaluate string

int main()
{

    // user input expression 
    char eval_string[500] ;
    cout << "Enter expression to evaluate: ";
    cin >> eval_string;


    return 0;
}

// This function will convert char digits to number
int char_to_int(char x)
{
   return x - '0';
}

// this function will make the number from character like if 120 are three characters '1','2','0' then this function will return a number 120
int number( char str[], int &index)
{
  int n= 0;
  while (str[index] >= '0' && str[index] <= '9')
  {
    n = n* 10 + char_to_int(str[index]);
    index++;
  }
  return n;
}
