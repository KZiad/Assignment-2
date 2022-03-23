#include <iostream>
#include <regex>
#include <complex>
#include<string>

using namespace std;

regex format(R"(^\(([+-]?\d*\.?\d*)([+-]\d*\.?\d*)i\) ?([+\-*\/]) ?\(([+-]?\d*\.?\d*)([+-]\d*\.?\d*)i\)$)");

bool isFormatCorrect(string input){
    return regex_match(input,format);
}

int main() {

    cout << "Write complex operation: ";
    string input;
    getline(cin, input);


    if (!isFormatCorrect(input)){
        cout << "Incorrect format" << endl;
        return 1;
    }
    sregex_iterator capt(input.begin(), input.end(), format);
    sregex_iterator end;

    
    string captures[4];


    cout << "size: " << capt->size() << endl;

    for(int i = 0; i < capt->size(); ++i)
    {
        captures[i] = (*capt)[i];
    }
    ++capt;
    complex <double> num1(stod(captures[1]), stod(captures[2]));
    complex <double> num2(stod(captures[4]), stod(captures[5]));
    char opr = captures[3][0];
    complex <double> result;

    switch(opr)
    {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            result = num1 / num2;
            break;
    }
    char opr2 = result.imag() < 0 ? : '+';
    cout << result.real()<< opr2 << result.imag() << "i" << endl;
    system("pause");
}
