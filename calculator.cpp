#include <iostream>
using namespace std;

float number(char [], int &sindex); // this function will make numbers from the evaluate string
float mult_divide(char [], int &index);
float process_parenthesis(char [], int &index);


int main()
{
    // user input expression 
      char str[60];
       cout << "Enter expression to evaluate: ";
      cin.getline( str, 60);
      
      char eval_string[60];
      int j = 0;
      for (int i = 0; str[i] != '\0'; i++)
      {
        if (str[i] != ' ' && str[i] != '"')
        {
          eval_string[j] = str[i];
          j++;
          
        }
      }
      eval_string[j] = '\0';
    float ans = 0; 
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
    cout << "Answer = "<< ans <<endl;

    return 0;
}

// this function will make the number from character like if 120 are three characters '1','2','0' then this function will return a number 120
float number( char str[], int &index)
{
  float n= 0;
  while (str[index] >= '0' && str[index] <= '9')
  {
    n = n* 10 + str[index] - '0';
    index++;
  }
  if (str[index] == '(')
    { 
        n = process_parenthesis( str, ++index);
        index++;
    }
  return n;
}

// This function will perform the calculation for multiplication and division and return the answer
float mult_divide(char num[], int &index)
{
    float temp =number(num, index); 
   
    while (num[index] != '\0' && num[index] != '+' && num[index] != '-' && num[index] != ')' )
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

float process_parenthesis(char num [], int &index)
{
  int temp_ans = 0;
    
    while ( num [index] != ')')
    {
      if (num[index] == '-')
      {
        temp_ans -= mult_divide(num, ++index);
      }
      else if (num[index] == '+')
      {
        temp_ans += mult_divide(num, ++index);
      }
      else 
      {
        temp_ans += mult_divide(num, index);
      }
    }
    return temp_ans;
}
