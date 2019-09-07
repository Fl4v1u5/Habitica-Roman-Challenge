
#include <iostream>
#include <string>

using namespace std;

int dec_to_rom();
int rom_to_dec();
int choose();

int main()
{
    cout << "Hello Habitica!" << endl;
    cout << "This app converts from and to roman numerals and is part of a challenge by Zyasha from Habitica." << endl << endl;
    cout << "Will you (1) convert from decimal to roman, (2) from roman to decimal numerals or (3) exit?" << endl;

    choose();
    return 0;
}

int dec_to_rom(){
    cout << "Please, introduce a decimal number: ";

    int input;
    cin >> input;
    cout << endl;
    int input_copy = input;
    string numeral = "";

    while (input >= 1000){
        input -= 1000;
        numeral.append("M");
    }
    while (input >= 100){
        if (input >= 900){
            input -= 900;
            numeral.append("CM");
        } else if (input >= 500){
            input -= 500;
            numeral.append("D");
        } else if (input >= 400){
            input -= 400;
            numeral.append("CD");
        } else if (input < 400){
            input -= 100;
            numeral.append("C");
        }
    }
    while (input >= 10){
        if (input >= 90){
            input -= 90;
            numeral.append("XC");
        } else if (input >= 50){
            input -= 50;
            numeral.append("L");
        } else if (input >= 40){
            input -= 40;
            numeral.append("XL");
        } else if (input < 40){
            input -= 10;
            numeral.append("X");
        }
    }
    while (input > 0){
        if (input == 9){
            input -= 9;
            numeral.append("IX");
        } else if (input >= 5){
            input -= 5;
            numeral.append("V");
        } else if (input == 4){
            input -= 4;
            numeral.append("IV");
        } else if (input < 4){
            input -= 1;
            numeral.append("I");
        }
    }

    cout << input_copy << " in roman numerals is " << numeral << "." << endl;

    cout << "\nWhat will you do?\n(1) Roman to Decimal.\n(2) Decimal to Roman.\n(3) Exit.\n\n";
    int choice; cin >> choice; cout << endl;
    switch (choice){
        case 1: dec_to_rom(); break;
        case 2: rom_to_dec(); break;
        case 3: exit(0); break;
        default: cout << "Wrong option. Type again:" << endl;
    }
}

int  rom_to_dec(){
    cout << "(USE UPPERCASE, any other symbol will be ignored) Please, introduce a roman numeral: ";

    string input;
    cin >> input;
    cout << endl;
    int counter = 0; //A counter to add to the value
    string used_list; //A list of used positions
    string current; //This is the current number that will be examined

    for (int i = 0; i < input.size(); i++) {
        if (i < input.size()-1){
            current = {input[i], input[i+1]};
        } else {
            current = input[i];
        }


        //Accounting for special cases
        if (current == "IV"){
            counter += 4;
            used_list.append(to_string(i));
        } else if (current == "IX"){
            counter += 9;
            used_list.append(to_string(i));
        } else if (current == "XL"){
            counter += 40;
            used_list.append(to_string(i));
        } else if (current == "XC"){
            counter += 90;
            used_list.append(to_string(i));
        } else if (current == "CD"){
            counter += 400;
            used_list.append(to_string(i));
        } else if (current == "CM"){
            counter += 900;
            used_list.append(to_string(i));
        }

        //Adding regular cases
        string i1 = to_string(i); string i2 = to_string(i-1); current = input[i];
        if (used_list.find(i1) == string::npos && used_list.find(i2) == string::npos){
            if (current == "I"){
                counter += 1;
            } else if (current == "V"){
                counter += 5;
            } else if (current == "X"){
                counter += 10;
            } else if (current == "L"){
                counter += 50;
            } else if (current == "C"){
                counter += 100;
            } else if (current == "D"){
                counter += 500;
            } else if (current == "M"){
                counter += 1000;
            }
        }
    }

    cout << input << " in decimal is " << counter << "." << endl;
    counter = 0;
    used_list.clear();

    cout << "\nWhat will you do?\n(1) Roman to Decimal.\n(2) Decimal to Roman.\n(3) Exit.\n\n";
    int choice; cin >> choice; cout << endl;
    switch (choice){
        case 1: dec_to_rom(); break;
        case 2: rom_to_dec(); break;
        case 3: exit(0); break;
        default: cout << "Wrong option. Type again:" << endl;
    }
}

int choose(){
    int choice;
    cin >> choice;
    cout << endl;

    switch (choice){
        case 1: dec_to_rom(); break;
        case 2: rom_to_dec(); break;
        case 3: exit(0); break;
        default: cout << "Wrong option. Type again:" << endl; choose();
    }
}
