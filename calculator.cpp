#include <iostream>
using namespace std;

int char_to_int(char x);

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

