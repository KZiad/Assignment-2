#include <iostream>
#include <map>
#include <string>
using namespace std;
#include <sstream>

// Ciphers
void affine_cipher(string input, int opt);    // 0
void polybius_square(string input, int opt);  // 6
void morse_code(string input, int opt);       // 7
void xor_cipher(string input, int opt);       // 8
void railfence_cipher(string input, int opt); // 9

// Tools
string extractAlpha(string text); 


int main()
{
    
    int option = 0;
    while (option != 10)
    {

        // Get which cipher to use

        cout << "Welcome Habibi! Choose a cipher: " << endl;
        cout << "0. Affine" << endl;
        cout << "1. Caeser" << endl;
        cout << "2. Atbash" << endl;
        cout << "3. Vigenere" << endl;
        cout << "4. Baconian" << endl;
        cout << "5. Simple Substitution" << endl;
        cout << "6. Polybius Square" << endl;
        cout << "7. Morse Code" << endl;
        cout << "8. XOR" << endl;
        cout << "9. Railfence" << endl;
        cout << "10. Quit" << endl;
        cin >> option;


        if (option == 10)
        {
            break;
        }
        // Make sure the user entered a valid option
        while (cin.fail() || option < 0 || option > 10)
        {
            cin.clear();
            cin.ignore();
            cout << "Invalid input. Please try again: ";
            cin >> option;
        }
        // Choose decryption or encryption
        cout << "1. Encrypt" << endl;
        cout << "2. Decrypt" << endl;


        int opt;
        cin >> opt;

        // Make sure the user entered a valid option
        while (cin.fail() || opt < 1 || opt > 2)
        {
            cin.clear();
            cin.ignore();
            cout << "Invalid input. Please try again: ";
            cin >> opt;
        }

        // Get the input
        cout << "Please enter the text: " << endl;
        string input;
        getline(cin >> ws, input);


        // Call the cipher
        switch (option)
        {
        case 0:
            affine_cipher(input, opt);
            break;
        case 6:
            polybius_square(input, opt);
            break;
        case 7:
            morse_code(input, opt);
            break;
        case 8:
            xor_cipher(input, opt);
            break;
        case 9:
            railfence_cipher(input, opt);
            break;
        }
    }
}
void affine_cipher(string input, int opt)
{
    input = extractAlpha(input);
    // string of alphabets
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    // Getting keys
    int a, b, c;
    cout << "Enter a: ";
    cin >> a;
    cout << "Enter b: ";
    cin >> b;
    cout << "Enter c: ";
    cin >> c;

    // checking validity of keys
    while (((a * c) % 26) != 1)
    {
        cout << "Enter a: ";
        cin >> a;
        cout << "Enter b: ";
        cin >> b;
        cout << "Enter c: ";
        cin >> c;
    }

    switch (opt)
    {
    // Encryption
    case 1:

        cout << "Plain text: " << input << endl;

        cout << "Encrypted text: ";
        // loop to encrypt each letter of the input
        for (auto chr : input)
        {

            // finding the index of the letter in the alphabet
            int ind = alphabet.find(toupper(chr));

                // encrypting the letter
                int enclet = (a*ind + b);
            if (enclet > 25)
            {
                enclet %= 26;
            }
            // printing the encrypted letter
            cout << alphabet[enclet];
        }
        break;
    // decryption
    case 2:
        cout << "Encrypted text: " << input << endl;
        cout << "Plain text: ";
        for (auto chr : input)
        {
            // finding the index of the letter in the alphabet
            int ind = alphabet.find(toupper(chr));
            // decrypting the letter
            int enclet = (c * (ind - b));

            // if the decrypted letter's index is over the alphabet range, we take it modulus 26
            if (enclet > 25)
            {
                enclet %= 26;
            }
            // if the decrypted letter is negative, add 26 to it
            while (enclet < 0)
            {
                enclet += 26;
            }

            // printing the decrypted letter
            cout << alphabet[enclet];
        }
        break;
    }
    cout << endl;

    // to add "Press any button to continue"
    system("pause");
}

void morse_code(string input, int opt)
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

    switch (opt)
    {
    /*
    Encryption
    ############################
    */
    case 1:
    {
        // Input Handling
        cout << "Plain text: " << input << endl;
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

        cout << "Morse code: " << input << endl;

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
    }

    // to add "Press any button to continue"
    system("pause");
}
void xor_cipher(string input, int opt)
{
    // Getting the key
    char key;
    cout << "Please enter the key: ";
    cin >> key;

    // Making sure the key is a char
    while (cin.fail())
    {
        cin.clear();
        cin.ignore();
        cout << "Invalid input. Please try again: ";
        cin >> key;
    }


    string result, result_hexa;
    switch (opt)
    {
    // Encryption
    case 1:
        // cleaning input and taking just letters
        input = extractAlpha(input);


        // capitalizing input
        for (int i = 0; i < input.length(); i++)
        {
            input[i] = toupper(input[i]);
        }

        // Encrypting each letter then adding it to the result
        for (auto chr : input)
        {
            result += chr ^ key;
            char *temp;
            itoa(chr ^ key, temp, 16);
            string tempstr(temp);
            if (tempstr.length() == 1)
            {
                result_hexa += "0";
            }
            result_hexa += temp;
        }
        // Printing the result
        cout << "Plain text: " << input << endl;
        cout << "Encrypted text: " << result << " (Hexa: " << result_hexa << ")" << endl;
        
        break;
    // Decryption
    case 2:

        int i = 0;
        // Decrypting each letter then adding it to the result
        for (int i = 0; i < input.length(); i += 2)
        {
            stringstream ss;
            ss << hex << input[i] << input[i + 1];
            int temp;
            ss >> temp;
            result += temp ^ key;
        }
        cout << "Encrypted text hexa: " << input << endl;
        cout << "Plain text: " << result << endl;
        break;
    }
    // to add "Press any button to continue"
    system("pause");
}

// function to extract only letters from the input
string extractAlpha(string text)
{
    for (int i = 0; i < text.length(); i++)
    {
        if (!isalpha(text[i]))
        {
            text.erase(i, 1);
            i--;
        }
    }
    return text;
}

void railfence_cipher(string input, int opt)
{
    // Set key
    int key = 4;

    // Cleaning input and taking just letters
    input = extractAlpha(input);

    // making the railfence matrix
    int rows = input.length();
    char inparr[rows][key];

    // filling the matrix with dots
    for (int col = 0; col < key; ++col)
    {
        for (int row = 0; row < rows; ++row)
        {
            inparr[row][col] = '.';
        }
    }

    // the steps of the railfence cipher
    int ladder[6] = {0, 1, 2, 3, 2, 1};

    string output;

    int letterCount = 0;
    int ladderCount = 0;

    switch (opt)
    {
        // Encryption
    case 1:
        cout << "Plain text: " << input << endl;

        // loop over all the rows and put the letters in the matrix based on the ladder
        for (int row = 0; row < rows; ++row)
        {
            inparr[row][ladder[ladderCount]] = input[letterCount];
            letterCount++;
            ladderCount = ladderCount > 4 ? 0 : ladderCount + 1;
        }

        // Printing the matrix and making the output string
        for (int col = 0; col < key; ++col)
        {

            for (int row = 0; row < rows; ++row)
            {

                cout << inparr[row][col];
                if (inparr[row][col] != '.')
                {
                    output += inparr[row][col];
                }
            }
            cout << endl;
        }
        // printing the output
        cout << "Encrypted Text: " << output << endl;
        break;

    // Decryption
    case 2:
        cout << "Encrypted Text: " << input << endl;

        // putting the letters in the matrix reverse the way it was encrypted
        for (int col = 0; col < key; ++col)
        {
            ladderCount = 0;
            for (int row = 0; row < rows; ++row)
            {
                if (ladderCount == col)
                {
                    inparr[row][col] = input[letterCount];
                    letterCount++;

                    if (ladderCount != 3 && ladderCount != 0 && row + (6 - (2 * ladderCount)) < rows)
                    {
                        inparr[row + (6 - (2 * ladderCount))][col] = input[letterCount];
                        letterCount++;
                    }
                }

                ladderCount = ladderCount > 4 ? 0 : ladderCount + 1;
            }
        }
        for (int col = 0; col < key; ++col)
        {

            for (int row = 0; row < rows; ++row)
            {

                cout << inparr[row][col];
                if (inparr[row][col] != '.')
                {
                }
            }
            cout << endl;
        }
        cout << "Plain text: ";

        for (int row = 0; row < rows; ++row)
        {
            for (int col = 0; col < key; ++col)
            {
                if (inparr[row][col] != '.')
                {
                    cout << inparr[row][col];
                }
            }
        }
        break;
    }
    cout << endl;
    system("pause");
}
void polybius_square(string input, int opt)
{
    // Map containing all the letters and their corresponding location on the
    // polybius square
    map<char, string> lets{
        {'A', "11"},
        {'B', "12"},
        {'C', "13"},
        {'D', "14"},
        {'E', "15"},
        {'F', "21"},
        {'G', "22"},
        {'H', "23"},
        {'J', "24"},
        {'I', "24"},
        {'K', "25"},
        {'L', "31"},
        {'M', "32"},
        {'N', "33"},
        {'O', "34"},
        {'P', "35"},
        {'Q', "41"},
        {'R', "42"},
        {'S', "43"},
        {'T', "44"},
        {'U', "45"},
        {'V', "51"},
        {'W', "52"},
        {'X', "53"},
        {'Y', "54"},
        {'Z', "55"}};

    // Key that will be used to encrypt/decrypt
    string key;
    cout << "Please enter the key (ex. 41325, 12345): " << endl;
    cin >> key;

    string output;
    switch (opt)
    {
    // Encrypt
    case 1:
        // Cleaning input and taking just letters
        input = extractAlpha(input);

        // Capitalizing input
        for (int i = 0; i < input.length(); i++)
        {
            input[i] = toupper(input[i]);
        }

        // Encrypting each letter
        for (auto c : input)
        {
            // Taking the number of the letter from the map
            string letter = lets[c];

            // Applying encryption on letter number
            for (int i = 0; i < letter.length(); i++)
            {
                letter[i] -= 1;
                output += key[letter[i] - 48];
            }
        }
        cout << output << endl;
        break;

    // Decrypt
    case 2:
        // making map nums that is the opposite of the map lets ( key is number and value is letter)
        map<string, char> nums;

        for (auto &i : lets)
        {
            nums[i.second] = i.first;
        }

        nums["24"] = 'I';

        for (int i = 0; i < input.length(); i += 2)
        {
            char index = key.find(input[i]) * 10 + key.find(input[i + 1]);

            int letter;
            letter = (key.find(input[i]) + 1) * 10 + key.find(input[i + 1]) + 1;

            output += nums[to_string(letter)];
        }
        cout << output << endl;
        break;
    }

}