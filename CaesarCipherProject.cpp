#include <iostream>
#include <list>
#include <cmath>
using namespace std;
// notes : make sure caesar shift input is valid
char rotate(unsigned char ch, int n){
    char rotated;
    if(ch != '1' && ch != '2' && ch != '3' && ch != '4' && ch != '5' && ch != '6' && ch != '7' && ch != '8' && ch != '9' && ch != '0' && ch != '?' && ch != '.' && ch != ' ' && ch != '!'){
    	if(ch >= 'a' && ch <= 'z'){
    		rotated = (ch - 'a' + n) % 26 + 'a'; // rotate the character but make sure it loops around in the alphabet and doesn't go around to other characters.
    	}else{
    		rotated = (ch - 'A' + n) % 26 + 'A';
		}
	}else{
		rotated = ch;
	}
	return rotated;
}

string encipher(string str, int n) {
    string encrypted;
    for (int i = 0; i < str.length(); ++i) {
        char temp = str[i]; // get letter
        int shiftedLetter = rotate(temp, n); // rotate letter
        encrypted += shiftedLetter; // add letter to new string
    }
    return encrypted;
}

double letterScore(char ch){
    if (ch == 'A' || ch == 'a') return .0684;
    if (ch == 'B' || ch == 'b') return .0139;
    if (ch == 'C' || ch == 'c') return .0146;
    if (ch == 'D' || ch == 'd') return .0456;
    if (ch == 'E' || ch == 'e') return .1267;
    if (ch == 'F' || ch == 'f') return .0234;
    if (ch == 'G' || ch == 'g') return .0180;
    if (ch == 'H' || ch == 'h') return .0701;
    if (ch == 'I' || ch == 'i') return .0640;
    if (ch == 'J' || ch == 'j') return .0033;
    if (ch == 'K' || ch == 'k') return .0093;
    if (ch == 'L' || ch == 'l') return .0450;
    if (ch == 'M' || ch == 'm') return .0305;
    if (ch == 'N' || ch == 'n') return .0631;
    if (ch == 'O' || ch == 'o') return .0852;
    if (ch == 'P' || ch == 'p') return .0136;
    if (ch == 'Q' || ch == 'q') return .0004;
    if (ch == 'R' || ch == 'r') return .0534;
    if (ch == 'S' || ch == 's') return .0659;
    if (ch == 'T' || ch == 't') return .0850;
    if (ch == 'U' || ch == 'u') return .0325;
    if (ch == 'V' || ch == 'v') return .0084;
    if (ch == 'W' || ch == 'w') return .0271;
    if (ch == 'X' || ch == 'x') return .0007;
    if (ch == 'Y' || ch == 'y') return .0315;
    if (ch == 'Z' || ch == 'z') return .0004;
    
    return 0.0;
}

string decipher(string str) {
    double values[26]; // an array for each possible st
    double valSum;
    string destr;
    char temp;
    int count;
    int shift;
    int posShift = 0;

    while (posShift < 26) {
        posShift += 1;
        valSum = 0;
        count = 0;

        while (count <= str.length()) { // find the values for each specific shifted string
        	count += 1;
            temp = rotate(str[count], posShift);
            valSum += letterScore(temp);
        }

        values[posShift - 1] = valSum;
    }

    posShift = 1;
    int currentHighest = 0;

    while (posShift <= 26) { // find the shifted string with the highest value
    	posShift += 1;
        if (values[posShift] >= values[currentHighest]) {
            currentHighest = posShift; 
        }
    }
    shift = currentHighest + 1;
    destr = encipher(str, shift); 
    return destr;
}

int main() {
	bool inLoop = true;
	while(inLoop){
		int option; // which option would the user like to pick
		int cipherType;
    	string enstr;
    	string enstr2;
    	string destr;
    	string destr2;
    	int shift;
    	cout << "1. Encrypt a message" << endl;
    	cout << "2. Decode a message" << endl;
    	cout << "3. End the program" << endl;
    	cin >> option;
    	switch(option){
        	case 1:
            {
                int yes=0;
                cout << "Enter a message to encrypt:" << endl; 
    			cout << endl << enstr;
    			cin.ignore();
               	getline(cin, enstr, '\n');
               	cout << "Enter a caesar shift between 1 and 25" << endl;
                cin >> shift;
               	shift = shift % 25;
               	cout << "Here is the encrypted message:" << endl;
               	enstr2 = encipher(enstr,shift);
                cout << enstr2 << endl;
            }
            break;
        case 2:
            {
                cout << "Enter the message you want to decode:" << endl;
                cin.ignore();
                getline(cin, destr, '\n');
                destr2 = decipher(destr);
                cout << "Here is the decrypted message" << endl;
                cout << destr2 << endl;
                break;
            }
        	case 3:
        		cout << "Goodbye!" << endl;
        		inLoop = false;
            	break;
    	}
		}
	return 0;
	}


