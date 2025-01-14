#include <iostream>
using namespace std;

// 1 to 19 2d array
const char one_to_nineteen[][10] = 
{
  "","One", "Two", "Three", "Four", "Five", "Six",
  "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve",
  "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen",
  "Eighteen", "Nineteen"
};

int input_num(string input);

void num_to_words(int);

int main()
{
  string user_input;
  cout << "Enter a number that you want to write in words: ";
  getline(cin, user_input);
  
  int num = input_num(user_input);
  //Check user input
  while (num <= 0)
  {
    cout << "Please enter a cheque amount that is bigger than zero: ";
    getline(cin, user_input);
    num = input_num(user_input);
  }

  cout << "Number to words = ";
  num_to_words(num); 
  
  return 0;
}

int input_num(string a)
{
  int input = 0;
  int position = 10;
  bool neg = false;
    
  for (int i = 0; a[i] != '\0'; i++)
  {
    if (neg)
    {
      if (a[i] >= '0' && a[i] <= '9')
      {
        input *= position;
        input -= a[i] - '0';
      }
    }
    else if (a[i] >= '0' && a[i] <= '9')
    {
      input *= position;
      input += a[i] - '0';
    }
    else if (a[i] == '-')
      neg = true;
      
  }
  return input;
}
void num_to_words(int num)
{
  if (num > 20)
  {

  }
  else
  {
    cout << one_to_nineteen[num] << endl;
  }
}