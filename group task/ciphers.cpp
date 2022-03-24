#include <iostream>
#include <map>
#include <string>
using namespace std;
#include <sstream>
string polybius_square(string input, int opt);
void xor_cipher(string input, int opt);

int main(){
    int option = 0;
    while (option != 10){
        cout << "Welcome! Choose a cipher: " << endl;
        cout << "0. Affine (TODO)" << endl;
        cout << "1. Caeser (TODO)" << endl;
        cout << "2. Atbash (TODO)" << endl;
        cout << "3. Vigenere (TODO)" << endl;
        cout << "4. Baconian (TODO)" << endl;
        cout << "5. Simple Substitution (TODO)" << endl;
        cout << "6. Polybius Square" << endl;
        cout << "7. Morse Code(TODO)" << endl;
        cout << "8. XOR" << endl;
        cout << "9. Railfence (TODO)" << endl;
        cout << "10. Quit" << endl;
        cin >> option;
        if (option == 10){
            break;
        }
        while (cin.fail() || option < 0 || option > 10){
            cin.clear();
            cin.ignore();
            cout << "Invalid input. Please try again: ";
            cin >> option;
        }
        cout << "1. Encrypt" << endl;
        cout << "2. Decrypt" << endl;
        int opt;
        cin >> opt;
        while (cin.fail() || opt < 1 || opt > 2){
            cin.clear();
            cin.ignore();
            cout << "Invalid input. Please try again: ";
            cin >> opt;
        }
        cout << "Please enter the text: " << endl;
        string input;
        getline(cin >> ws, input);

        switch(option){
            case 6:
                cout << polybius_square(input, opt) << endl;
                system("pause");
            break;
            //case 7:
            //    morse_code(input, opt);
            //break;
            case 8:
               xor_cipher(input, opt);
            break;
            //case 9:
            //    railfence_cipher(input, opt);
            //break;

        }
    }
    
    
}
void xor_cipher(string input, int opt){
    char key;
    cout << "Please enter the key: ";
    cin >> key;
    while(cin.fail()){
        cin.clear();
        cin.ignore();
        cout << "Invalid input. Please try again: ";
        cin >> key;
    }
    string result,result_hexa;
    switch(opt){
        case 1:
            // cleaning input and taking just letters
            for(int i = 0; i < input.length(); i++){
                if(!isalpha(input[i])){
                    input.erase(i,1);
                    i--;
                }
            }
            // capitalizing input
            for(int i = 0; i < input.length(); i++){
                input[i] = toupper(input[i]);
            }
            for (auto chr : input){
                result += chr ^ key;
                char* temp;
                itoa(chr ^ key,temp, 16);
                string tempstr(temp);
                if (tempstr.length() == 1){
                    result_hexa += "0";
                }
                result_hexa += temp;
            }
            cout << "Encrypted text: " << result << " (Hexa: " << result_hexa << ")" << endl;
            break;
        case 2:
            int i = 0;
            for (int i = 0; i < input.length(); i += 2){
                stringstream ss;
                ss << hex << input[i] << input[i+1];
                int temp;
                ss >> temp;
                result += temp ^ key;

            }
            cout << "Decrypted text: " << result << endl;
            break;
    }
}
string polybius_square(string input, int opt){
    map<char, string> lets{
        {'A',"11"},
        {'B',"12"},
        {'C',"13"},
        {'D',"14"},
        {'E',"15"},
        {'F',"21"},
        {'G',"22"},
        {'H',"23"},
        {'J',"24"},
        {'I',"24"},
        {'K',"25"},
        {'L',"31"},
        {'M',"32"},
        {'N',"33"},
        {'O',"34"},
        {'P',"35"},
        {'Q',"41"},
        {'R',"42"},
        {'S',"43"},
        {'T',"44"},
        {'U',"45"},
        {'V',"51"},
        {'W',"52"},
        {'X',"53"},
        {'Y',"54"},
        {'Z',"55"}
    };
    
    
    string key;
    cout << "Please enter the key (ex. 41325, 12345): " << endl;
    cin >> key;

    string output;
    switch (opt){
        // Encrypt
        case 1:
            // cleaning input and taking just letters
            for(int i = 0; i < input.length(); i++){
                if(!isalpha(input[i])){
                    input.erase(i,1);
                    i--;
                }
            }
            // capitalizing input
            for(int i = 0; i < input.length(); i++){
                input[i] = toupper(input[i]);
            }
            for (auto chr : input)
            {
                string letter = lets[chr];
                for(int i = 0; i < letter.length(); i++){
                    letter[i] -= 1;
                    output += key[letter[i] - 48];
                }
                
                
            }
            return output;
        break;

        // Decrypt
        case 2:
            map<string, char> nums;

            for (auto &i : lets) {
                nums[i.second] = i.first;
            }
            nums["24"] = 'I';

            for (int i = 0; i < input.length(); i += 2)
            {
                char index = key.find(input[i]) *10 + key.find(input[i+1]);
                
                int letter;
                letter = (key.find(input[i]) + 1) * 10 + key.find(input[i+1]) + 1;
                
                output += nums[to_string(letter)];
                
            }
            return output;
        break;
    }
    
    return output;
}