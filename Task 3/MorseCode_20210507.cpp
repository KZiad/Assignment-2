#include <iostream>
#include <map>
using namespace std;
/*
###############################################
##########  MORSE CODE TRANSLATOR  ############
# By: Zeyad Mohamed Maher Karsoun ID: 20210507
###############################################
###############################################

To use it, you first choose 1 (encrypt) or 2 (decrypt).
After making a choice, enter the text you want to encrypt or decrypt while making sure
to follow this format when converting from morse code: 1 space between letter and 3 
between words.

:D
*/


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
        {'0', "-----"}
    };
    // Choose encryption or decryption
    int action = 0;
    cout << "1. Encrypt\n2. Decrypt\n";
    while (action != 1 && action != 2)
    {
        cin >> action;
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
            string input;
            cout << "Plain text: ";
            getline(cin >> ws, input);

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

            // to add "Press any button to continue"
            system("pause");
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
            for (auto const &p : morse_code) morse_code_rev[p.second] = p.first;

            // Get input
            string input;
            cout << "Morse code: ";
            getline(cin >> ws, input);

            // string to store dot and dash combinations
            string morseLetter;

            // Loop to decipher morse code
            while (input != ""){

                // a space indicated the end of a word or letter
                if (input[0] == ' '){

                    // prints letter and empties string letter
                    cout << morse_code_rev[morseLetter];
                    morseLetter = "";

                    // checks if end of word
                    if (input[1] == ' ' && input[2] == ' '){
                        input.erase(0,3);
                        cout << ' ';
                    }
                    // removes space
                    else {
                        input.erase(0,1);
                    }
                }

                // Adds the dot or dash to string word
                else if (input[0] == '.' || input[0] == '-'){
                    morseLetter += input[0];
                    input.erase(0,1);
                }
            }

            cout << morse_code_rev[morseLetter];
            cout << endl;

            // to add "Press any button to continue"
            system("pause");


        }
        break;

        default:
        break;
    }
}