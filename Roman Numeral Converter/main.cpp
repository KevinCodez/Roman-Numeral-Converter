#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

//Basic roman numeral converter function.
string ToRoman(int input) {
    
    string result;
    int num = input;
    
    while (num != 0) {
        
        if (num >= 1000) {
            
            result.append("M");
            num -= 1000;
            
        } else if (num >= 500) {
            
            result.append("D");
            num -= 500;
            
        } else if (num >= 100) {
            
            result.append("C");
            num -= 100;
            
        } else if (num >= 50) {
            
            result.append("L");
            num -= 50;
            
        } else if (num >= 10) {
            
            result.append("X");
            num -= 10;
            
        } else if (num >= 5) {
            
            result.append("V");
            num -= 5;
            
        } else {
            
            result.append("I");
            num -= 1;
            
        }
    
    }
    return result;
        
}

//Short form converter
string ToShortRoman(int input) {
    
    string result;
    int diff;
    
    if (input >= 1000) {
        
        diff = input / 1000;
        
        for (int i = 0; i < diff; i++) {
            result += 'M';
        }
        input %= 1000;
    }
    
    
    
    if (input >= 100) {
        diff = input / 100;
        
        if (diff == 9) {
            result += "CM";
        } else if (diff >= 5) {
            result += 'D';
            for (int i = 0; i < diff - 5; i++) {
                result += 'C';
            }
        } else if (diff == 4) {
            result += "CD";
        } else if (diff >= 1) {
            for (int i = 0; i < diff; i++) {
                result += 'C';
            }
        }
        input %= 100;
    }
    
    if (input >= 10) {
        diff = input / 10;
        if (diff == 9) {
            result += "XC";
        } else if (diff >= 5) {
            result += 'L';
            for (int i = 0; i < diff - 5; i++) {
                result += 'X';
            }
        } else if (diff == 4) {
            result += "XL";
        } else if (diff >= 1) {
            for (int i = 0; i < diff; i++) {
                result += 'X';
            }
        }
        input %= 10;
    }
    
    
    if (input >= 1) {
        diff = input;
        if (diff == 9) {
            result += "IX";
        } else if (diff >= 5) {
            result += 'V';
            for (int i = 0; i < diff - 5; i++) {
                result += 'I';
            }
        } else if (diff == 4) {
            result += "IV";
        } else if (diff >= 1) {
            for (int i = 0; i < diff; i++) {
                result += "I";
            }
        }
    }
    
    return result;
}


int main() {
    
    int input;
    int numbers[35];
    string numerals[35][4];
    
    cout << "Roman numeral converter \n\n\n";
    
    do {
        
        cout << "Enter a number: ";
        cin >> input;
        
        if (cin.fail()) {
            //checks if user entered an interger
            cout << "Invalid Input \n";
            cin.clear();
            cin.ignore(1000, '\n');
            input = 1;
        } else {
            //checks if the interger is between 1 and 5000
            if (input >= 1 && input <= 5000) {
                //At this point, the input meets all requirements and the fun begins ;D
                
                //generates number array
                for (int x = 0; x < 35; x++) {
                    numbers[x] = input + x;
                }
                    //Generates values for the roman numeral 2-Dimentional roman numeral array...
                    //This array is 35 by 4
                    //
                    for (int i = 0; i < 35; i++) {
                        int row = input + i;
                        for (int j = 0; j < 4; j++) {
                            string lower = ToRoman(row);
                            string lowerShort = ToShortRoman(row);
                            if (j == 0) {
                                //uppercase (first column)
                                numerals[i][j] = ToRoman(row);
                            } else if (j == 1) {
                                //lowercase (second column)
                                transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
                                numerals[i][j] = lower;
                            } else if (j == 2) {
                                //uppercase short form (third column)
                                numerals[i][j] = ToShortRoman(row);
                            } else if (j == 3) {
                                //lowercase short form (fourth column)
                                transform(lowerShort.begin(), lowerShort.end(), lowerShort.begin(), ::tolower);
                                numerals[i][j] = lowerShort;
                            }
                        }
                    }
                
                //Display the first 20 values of roman numerals in array
                cout << "\n\n";
                for (int i = -1; i < 20; i++) {
                    if (i == -1) {
                        cout << left << setw(15) << "Decimal";
                    } else {
                    cout << left << setw(15) << numbers[i];
                    }
                    
                    for (int j = 0; j < 4; j++) {
                        
                        if (i == -1 && j == 0) {
                            cout << setw(15) << left << "ROMAN";
                        } else if (i == -1 && j == 1) {
                            cout << setw(15) << left << "roman";
                        } else if (i == -1 && j == 2) {
                            cout << setw(15) << left << "SHORT";
                        } else if (i == -1 && j == 3) {
                            cout << setw(15) << left << "short" << endl;
                        } else {
                            cout << setw(15) << left << numerals[i][j];
                        }
                    }
                    cout << endl;
                }
                
                
                //Write to the file
                string filename = "roman.txt";
                ofstream out(filename);
                for (int i = -1; i < 35; i++) {
                    if (i == -1) {
                        out << left << setw(15) << "Decimal";
                    } else {
                    out << left << setw(15) << numbers[i];
                    }
                    
                    for (int j = 0; j < 4; j++) {
                        
                        if (i == -1 && j == 0) {
                            out << setw(15) << left << "ROMAN";
                        } else if (i == -1 && j == 1) {
                            out << setw(15) << left << "roman";
                        } else if (i == -1 && j == 2) {
                            out << setw(15) << left << "SHORT";
                        } else if (i == -1 && j == 3) {
                            out << setw(15) << left << "short" << endl;
                        } else {
                            out << setw(15) << left << numerals[i][j];
                        }
                    }
                    out << endl;
                }
                cout << "Values saved to " << filename << endl;
                
                
                
                
            } else if (input == 0) {
                cout << "Goodbye!" << endl;
                break;
            } else if (!input) {
                cout << "Invalid";
            } else {
                cout << "Please enter a valid number between 1 - 5000 \n";
            }
        }
    } while (input != 0);
}
