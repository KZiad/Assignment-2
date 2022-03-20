// FCAI – Programming 1 – 2022 - Assignment 2
// Program Name: MorseCode_20210507.cpp
// Program Description: Program to encrypt and decrypt Morse code
// Last Modification Date: 20/03/2022
// Author and ID and Group: Zeyad Mohamed Maher Karsoun - 20210507 - Group A
// Teaching Assistant: ???
// Purpose:
// This program will encrypt and decrypt Morse code



#include <iostream>
#include <map>
using namespace std;

string getInput();

int main()
{
    map<char, string> morse_code{
        {'A', ".-"},
        {'B', "-..."},
        {'C', "-.-."},
        {'D', "-.."},
        {'E', "."},
        {'F', "..-."},
        {'G', "--."},
        {'H', "...."},
        {'I', ".."},
        {'J', ".---"},
        {'K', "-.-"},
        {'L', ".-.."},
        {'M', "--"},
        {'N', "-."},
        {'O', "---"},
        {'P', ".--."},
        {'Q', "--.-"},
        {'R', ".-."},
        {'S', "..."},
        {'T', "-"},
        {'U', "..-"},
        {'V', "...-"},
        {'W', ".--"},
        {'X', "-..-"},
        {'Y', "-.--"},
        {'Z', "--.."},
        {'1', ".----"},
        {'2', "..---"},
        {'3', "...--"},
        {'4', "....-"},
        {'5', "....."},
        {'6', "-...."},
        {'7', "--..."},
        {'8', "---.."},
        {'9', "----."},
        {'0', "-----"},
        {'.', ".-.-.-"},
        {',', "--..--"},
        {'?', "..--.."},
        {'!', "-.-.--"}};
    int action;
    while (action != 3)
    {
        // Choose encryption or decryption or quit
        action = 0;

        while (action != 1 && action != 2 && action != 3)
        {
            cout << "1. Encrypt\n2. Decrypt\n3. Quit\n";
            cin >> action;
            while (cin.fail())
            {
                cin.clear();
                cin.ignore();
            }
        }

        switch (action)
        {
        /*
        Encryption
        ############################
        */
        case 1:
        {
            // Input Handling
            cout << "Plain text: ";
            string input = getInput();

            // Conversion from text -> morse code
            cout << "Morse text: ";

            for (int i = 0; i < input.length(); i++)
            {
                // prints the space to seperate letters
                cout << ' ';

                // Print space between words
                if (input[i] == ' ')
                {
                    cout << "  ";
                }

                else
                {
                    // Print morse letter
                    cout << morse_code[toupper(input[i])];
                }
            }
            cout << endl;
        }
        break;

        /*
        Decryption
        ############################
        */

        case 2:
        {
            // Reverse morse code map for decryption
            map<string, char> morse_code_rev;
            for (auto const &p : morse_code)
                morse_code_rev[p.second] = p.first;

            // Get input
            cout << "Morse code: ";
            string input = getInput();

            // string to store dot and dash combinations
            string morseLetter;

            cout << "Plain text: ";
            // Loop to decipher morse code
            while (input != "")
            {

                // a space indicated the end of a word or letter
                if (input[0] == ' ')
                {

                    // prints letter and empties string letter
                    cout << morse_code_rev[morseLetter];
                    morseLetter = "";

                    // checks if end of word
                    if (input[1] == ' ' && input[2] == ' ')
                    {
                        input.erase(0, 3);
                        cout << ' ';
                    }
                    // removes space
                    else
                    {
                        input.erase(0, 1);
                    }
                }

                // Adds the dot or dash to string word
                else if (input[0] == '.' || input[0] == '-')
                {
                    morseLetter += input[0];
                    input.erase(0, 1);
                }
            }

            cout << morse_code_rev[morseLetter];
            cout << endl;
        }
        break;

        default:
        break;
        }
    }
    // to add "Press any button to continue"
    system("pause");
}

string getInput()
{
    string input;
    getline(cin >> ws, input);
    return input;
}