#include <iostream>
using namespace std;

int char_to_int(char x);
int number(char [], int &sindex); // this function will make numbers from the evaluate string
int mult_divide(char [], int &index);

int main()
{

    // user input expression 
    char eval_string[500] ;
    cout << "Enter expression to evaluate: ";
    cin >> eval_string;
    
    int ans = 0; // Final answer will be stored here
    for (int i =0;  eval_string[i] != '\0';)
    {
      if (eval_string[i] == '-')
      {
        ans -= mult_divide(eval_string, ++i);
      }
      else if (eval_string[i] == '+')
      {
        ans += mult_divide(eval_string, ++i);
      }
      else 
      {
        ans += mult_divide(eval_string, i);
      }
    
    }
    cout << "Answer = " << ans <<endl;

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

// This function will perform the calculation for multiplication and divsion and return the answer
int mult_divide(char num[], int &index)
{
    int temp = number(num, index); // this will hold the first the number
    while (num[index] != '\0' && num[index] != '+' && num[index] != '-')
    {
      if ( num[index] == '*')
      {
        temp *= number (num, ++index);
      }
      else if (num[index] == '/')
      {
        temp /= number (num, ++index);
      }
    }
  return temp;
}
