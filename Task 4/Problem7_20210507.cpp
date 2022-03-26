// FCAI – Programming 1 – 2022 - Assignment 2
// Program Name: Problem7_20210507.cpp
// Program Description: Program to convert roman numerals to an integer
// Last Modification Date: 20/03/2022
// Author and ID and Group: Zeyad Mohamed Maher Karsoun - 20210507 - Group A
// Teaching Assistant: ???
// Purpose:
// This program will convert roman numerals to an integer


#include <iostream>
#include <map>
using namespace std;

map<char, int> romanNumerals
{
    {'I', 1},
    {'V', 5},
    {'X', 10},
    {'L', 50},
    {'C', 100},
    {'D', 500},
    {'M', 1000}
};

int main()
{
    // Take input
    cout << "Roman numeral: ";
    string input;
    cin >> input;
    // Sum will contain final number
    int sum = 0;
    
    // Loop over the input
    for (int i = 0; i < input.length(); i++)
    {
        input[i] = toupper(input[i]);

        // if the roman numeral is smaller than the one after it,
        // then it will be considered negative (like IV is -1 + 5)
        // otherwise it's positive
        if (i < input.length() - 1 && romanNumerals[input[i]] < romanNumerals[input[i + 1]])
        {
            sum -= romanNumerals[input[i]];
        }
        else
        {
            sum += romanNumerals[input[i]];
        }
    }
    // Output
    cout << input << " -> " << sum << endl;
    system("pause");
};