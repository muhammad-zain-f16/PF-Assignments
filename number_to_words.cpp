#include <iostream>
using namespace std;

// Integer to English words 123 -> One Hundred Twenty Three
// 1 -> One
// 10 -> Ten
// 11 -> Eleven
// 0 -> Zero
// less than 20
// 21 -> Twenty One 21 % 10 = 1 20 % 10 = 0 Twenty
const char one_to_nineteen[][12] =
    {
        "", "One", "Two", "Three", "Four", "Five", "Six",
        "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve",
        "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen",
        "Eighteen", "Nineteen"};

// less than 100
// 21 / 10 -> 2
const char teen_num[][10] =
    {
        "", "", "Twenty", "Thirty", "Fourty",
        "Fifty", "Sixty", "Seventy", "Eighty",
        "Ninety"};

// Functions prototype
int input_num(char[]);

void num_to_words(long long int);

void show_one_19(int num);

int main()
{
  char user_input[20];
  cout << "Enter a number that you want to write in words: ";
  cin.getline(user_input, 20);

  // convert string to integer
  long long int num = input_num(user_input);

  // edge case
  if (num == 0)
  {
    cout << "Number to words = Zero" << endl;
    return 0;
  }

  // Check user input
  while (num < 0)
  {
    cout << "Please enter a cheque amount that is bigger than zero: ";
    cin.getline(user_input, 20);
    num = input_num(user_input);
  }
cout << num << endl;
  // print the result
  cout << "Number to words = ";
  num_to_words(num);

  return 0;
}

int input_num(char arr[]) // arr[] = "12,486" - > 12486
{
  long long int input = 0;     // input -> 12
  int position = 10; // 1 12 - >
  bool neg = false;  // if the number is negative or not

  for (int i = 0; arr[i] != '\0'; i++)
  {
    if (neg)
    {
      if (arr[i] >= '0' && arr[i] <= '9')
      {
        input *= position;
        input -= arr[i] - '0'; // 0-1 = -1* 10 = -10 -2 = -12 * 10 = -123
      }
    }
    else if (arr[i] >= '0' && arr[i] <= '9') // Ascii value of arr[i] >= 48 && arr[i] <= 57
    {
      input *= position;     // input -> 12 * 10 = 120
      input += arr[i] - '0'; // 51 - 48 = 120 + 3 = 123
    }
    else if (arr[i] == '-')
      neg = true;
  }
  return input;
}

void num_to_words(long long int num)
{
  string a;
  if (num >= 1000000000)
  {
    a += one_to_nineteen[num / 1000000000];
    a += " Billion";
    num = num % 1000000000;
    if (num > 0)
    {
      a += " ";
    }
  }
  if (num >= 1000000)
  {
    if ((num / 1000000) % 1000 >=100)
    {
      a += one_to_nineteen[num / 100000000];
      a += " Hundred";
      if ((num / 1000000) % 100 >= 20)
      {
      if ((num / 1000000) % 100 != 0)
      {
        a+= " ";
        a += teen_num[(num / 10000000) % 10];
      }
      }
      
      if ((num/ 1000000)% 10 != 0)
      {
        a += " ";
        a += ((num/ 1000000)% 100 < 20 ? one_to_nineteen[(num / 1000000) % 100]: one_to_nineteen[(num / 1000000) % 10]);
        
      }
      
    }
    else if ((num / 1000000) >= 20)
    {
      a += teen_num[num / 10000000];
      if ((num/ 1000000)% 10 != 0)
      {
        a += " ";
        a += one_to_nineteen[(num / 1000000) % 10];
      }
    }
    else
    {
      a += one_to_nineteen[num / 1000000];
    }
    a += " Million";
    num = num % 1000000;
    if (num > 0)
    {
      a += " ";
    }
  }

  if (num >= 100000)
  {
    a += one_to_nineteen[num / 100000];
    a += " Hundred";
    num = num % 100000;
    if (num < 1000)
    {
      a += " Thousand";
      if (num > 0)
      {
        a += " ";
      }
    }
    else
    {
      a += " ";
    }
    
  }
  if (num >= 1000)
  {
    if (num / 1000 >= 20)
    {
      a += teen_num[num / 10000];
      if ((num / 1000) % 10 != 0)
      {
        a += " ";
        a += (one_to_nineteen[(num / 1000) % 10]);
      }
    }
    else
    {
      a += one_to_nineteen[num / 1000];
    }
    a += " Thousand";
    num = num % 1000;
    if (num > 0)
    {
      a += " ";
    }
  }

  if (num >= 100)
  {
    a += one_to_nineteen[num / 100];
    a += " Hundred";
    num = num % 100;
    if (num > 0)
    {
      a += " ";
    }
  }

  if (num >= 20) // twenty three "twenty" and then three 23/ 10 = 2 23 % 10 = 3; num % 10 != 0;
  {
    a += teen_num[num / 10];
    num = num % 10;
    if (num > 0)
    {
      a +=  " ";
    }
  }
  if (num < 20)
  {
    a += one_to_nineteen[num];
  }
  cout << a <<  endl;
}
