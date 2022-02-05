#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

class Ciphers   {
    public:
        string CaesarCipher(string userMessage, int displace);
        string A1Z26Cipher(string userMessage) const;
};

string Ciphers::CaesarCipher(string userMessage, int displace)   {  //A Caeser cipher is a cipher that changes a message based on how many letters it will be displaced by.
    int i = 0;
    string ciphers;
    while ((userMessage.length()) > i) {
        int asciiValue = int(userMessage[i]);
        if(asciiValue + displace <= 122 && asciiValue >= 97) {  //Checks to see if the current character is a letter as the ASCII values for lower case letters are 97-122.
            ciphers += char(asciiValue + displace);
        }
        else if(asciiValue + displace > 122) {  //Wraps the letters back around as we want our message to be displaced by letters, not ASCII values.
            asciiValue -= 26;
            ciphers += char(asciiValue + displace);
        }
        else if (asciiValue < 97) {  //Checks if any characters that are not letters are present such as punctuation or spaces.
            ciphers += char(asciiValue);
        }
        i++;
    }
    cout << ciphers << endl;
    return ciphers;
}

string Ciphers::A1Z26Cipher(string userMessage) const   {   //The A1Z26 cipher encodes a message based on what number the letter is in the alphabet.
    int i = 0;
    string ciphers;
    while ((userMessage.length()) > i) {
        int asciiValue = int(userMessage[i]);
        if(asciiValue >= 97 && asciiValue <= 122) {
            ciphers += to_string(asciiValue - 96) + "-";    //This changes the value of asciiValue to be correct as lowercase letters in ASCII values start at 97.
        } 
        else if(asciiValue == 32) {  //Checks to see if there was a space.
            ciphers.pop_back();  //Removes the last '-' added
            ciphers += " ";  //Adds the space to the cipher to separate the words.
        }
        i++;
    }
    ciphers.pop_back();
    cout << ciphers << endl;
    return ciphers;
}

int main() {
    string message;
    cout << "What is the message you want encoded?" << endl;
    getline(cin, message);  //getline will take an entire line of input, where as cin will stop when a space is encountered.
    transform(message.begin(), message.end(), message.begin(), ::tolower);  //tranform is used to turn the entire message into lowercase letters, as the program was made to work specifically with the ASCII values of lowercase letters.
    Ciphers cipher;
    string cipherType;
    cout << "Would you like to the A1Z26 cipher or the Caeser cipher? [a/c] " << endl;
    cin >> cipherType;
    cipherType = tolower(cipherType.at(0)); 
    while (cipherType != "a" && cipherType != "c") {
        cout << "Invalid Input. Would you like to the A1Z26 cipher or the Caeser cipher? [a/c] " << endl;
        cin >> cipherType;
        cipherType = tolower(cipherType.at(0));
    }
    int displace;
    if (cipherType == "a") {
        cipher.A1Z26Cipher(message);
    }
    
    else if (cipherType == "c") {
        cout << "How many letters would you like the cipher to be displaced by?" << endl;
        cin >> displace;
        displace = displace % 26;   //% 26 is used because even if you want to displace a message by 30 letters, it will wrap back around to being 4 letters displaced.
        cipher.CaesarCipher(message, displace);
    }
    
    return 0;
}