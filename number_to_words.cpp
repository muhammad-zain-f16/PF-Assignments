#include <iostream>
using namespace std;

// 1 to 19 2d array
const char one_to_nineteen[][12] = 
{
  "","One ", "Two ", "Three ", "Four ", "Five ", "Six ",
  "Seven ", "Eight ", "Nine ", "Ten ", "Eleven ", "Twelve ",
  "Thirteen ", "Fourteen ", "Fifteen ", "Sixteen ", "Seventeen ",
  "Eighteen ", "Nineteen "
};

const char teen_num[][10] = 
{
  "","","Twenty ", "Thirty ","Fourty ",
  "Fifty ", "Sixty ", "Seventy ","Eighty ",
  "Ninety "
};




// Functions prototype
int input_num(string input);

void num_to_words(int);

void show_one_19(int num);

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
  int index = 0;
  if (num >= 1000)
  {
    index = num / 1000;
    show_one_19(index);
    cout << "Thousand ";
    num = num % 1000;

  }
  if (num >= 100)
  {
    index = num / 100;
    show_one_19(index);
    cout << "Hundred ";
    num = num % 100;

  }
  if (num >= 20)
  {
    index = num / 10;
    cout << teen_num[index];
    num = num % 10;
  }
  if (num > 0)
  {
    show_one_19(num);
  }
  
  cout << endl;
}

void show_one_19(int num)
{
  if (num > 0)
  {
    cout << one_to_nineteen[num];
  }
}