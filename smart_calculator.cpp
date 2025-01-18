#include <iostream>
#include <string>
using namespace std;

const char one_to_nineteen[][12] = {
    "", "One", "Two", "Three", "Four", "Five", "Six",
    "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve",
    "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen",
    "Eighteen", "Nineteen"
};

const char teen_num[][10] = {
    "", "", "Twenty", "Thirty", "Forty",
    "Fifty", "Sixty", "Seventy", "Eighty",
    "Ninety"
};

// Calculator function prototypes
float number(char[], int&);
float mult_divide(char[], int&);
float process_parenthesis(char[], int&);

// Number to words function prototypes
void num_to_words(long long int);
int input_num(char[]);

// UI helper functions
void print_banner();
void print_separator(string = "═");
void print_result(float);

int main() {
  //  system("cls");  // Use "cls" for Windows
    print_banner();

    while (true) {
        print_separator();
        cout << "\n📌 Choose operation:\n";
        cout << "1. Calculator\n";
        cout << "2. Number to Words\n";
        cout << "3. Exit\n";
        cout << "Enter choice (1-3): ";

        char choice;
        cin >> choice;
        cin.ignore();

        if (choice == '1') {
            print_separator();
            cout << "\n🔢 CALCULATOR MODE\n";
            char str[60];
            cout << "Enter expression: ";
            cin.getline(str, 60);

            // Clean input
            char eval_string[60];
            int j = 0;
            for (int i = 0; str[i] != '\0'; i++) {
                if (str[i] != ' ' && str[i] != '"') {
                    eval_string[j] = str[i];
                    j++;
                }
            }
            eval_string[j] = '\0';

            float ans = 0;
            cout << "\n🔄 Processing...\n";
            for (int i = 0; eval_string[i] != '\0';) {
                if (eval_string[i] == '-') {
                    ans -= mult_divide(eval_string, ++i);
                }
                else if (eval_string[i] == '+') {
                    ans += mult_divide(eval_string, ++i);
                }
                else {
                    ans += mult_divide(eval_string, i);
                }
            }
            print_result(ans);
        }
        else if (choice == '2') {
            print_separator();
            cout << "\n📝 NUMBER TO WORDS MODE\n";
            char user_input[20];
            cout << "Enter a number: ";
            cin.getline(user_input, 20);

            long long int num = input_num(user_input);
            if (num == 0) {
                cout << "\n✨ In words: Zero\n";
            }
            else if (num < 0) {
                cout << "\n⚠️ Please enter a positive number\n";
            }
            else {
                cout << "\n✨ In words: ";
                num_to_words(num);
                cout << "\n"; // Add newline for proper formatting
            }
        }
        else if (choice == '3') {
            cout << "\n👋 Thank you for using Smart Calculator!\n";
            break;
        }
        else {
            cout << "\n⚠️ Invalid choice! Please try again.\n";
        }
    }
    return 0;
}

void print_banner() {
    cout << "\n╔══════════════════════════════════════╗\n";
    cout << "║         💫 SMART CALCULATOR 💫        ║\n";
    cout << "║    Calculate & Convert to Words!      ║\n";
    cout << "╚══════════════════════════════════════╝\n";
}

void print_separator(string ch) {
    cout << "\n";
    for(int i = 0; i < 40; i++) cout << ch;
    cout << "\n";
}

void print_result(float result) {
    print_separator("─");
    cout << "🎯 Result: " << result << "\n";

    // Convert integer part to words if it's a whole number
    if (result == (long long int)result && result >= 0 && result <= 999999999999) {
        cout << "✨ In words: ";
        num_to_words((long long int)result);
        cout << "\n"; // Add newline for proper formatting
    }
}

float number(char str[], int &index) {
    float result = 0;
    while (isdigit(str[index])) {
        result = result * 10 + (str[index] - '0');
        index++;
    }
    if (str[index] == '.') {
        index++;
        float decimal_place = 0.1;
        while (isdigit(str[index])) {
            result += (str[index] - '0') * decimal_place;
            decimal_place *= 0.1;
            index++;
        }
    }
    return result;
}

float mult_divide(char str[], int &index) {
    float result = process_parenthesis(str, index);
    while (str[index] == '*' || str[index] == '/') {
        char op = str[index];
        index++;
        if (op == '*') {
            result *= process_parenthesis(str, index);
        } else {
            result /= process_parenthesis(str, index);
        }
    }
    return result;
}

float process_parenthesis(char str[], int &index) {
    if (str[index] == '(') {
        index++;
        float result = mult_divide(str, index);
        if (str[index] == ')') {
            index++;
        }
        return result;
    } else {
        return number(str, index);
    }
}

int input_num(char user_input[]) {
    long long int num = 0;
    for (int i = 0; user_input[i] != '\0'; i++) {
        if (isdigit(user_input[i])) {
            num = num * 10 + (user_input[i] - '0');
        } else {
            return -1; // Invalid input
        }
    }
    return num;
}

void num_to_words(long long int num) {
    if (num >= 1000000000) {
        num_to_words(num / 1000000000);
        cout << " Billion ";
        num %= 1000000000;
    }
    if (num >= 1000000) {
        num_to_words(num / 1000000);
        cout << " Million ";
        num %= 1000000;
    }
    if (num >= 1000) {
        num_to_words(num / 1000);
        cout << " Thousand ";
        num %= 1000;
    }
    if (num >= 100) {
        num_to_words(num / 100);
        cout << " Hundred ";
        num %= 100;
    }
    if (num >= 20) {
        cout << teen_num[num / 10] << " ";
        num %= 10;
    }
    if (num > 0) {
        cout << one_to_nineteen[num] << " ";
    }
}
