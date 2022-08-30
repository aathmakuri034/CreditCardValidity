#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <time.h>

using namespace std;

bool validateCard(int cardnum){

    return false;

}

int main(){
    int cardnumber, choice;

    cout << "Enter card number: ";
    cin >> cardnumber; // user's credit card number is entered

    cout << "\nSelect Card Company: " << endl;
    cout << "1. Visa" << endl;
    cout << "2. Mastercard" << endl;
    cout << "3. American Express" << endl;
    cout << "4. Discover" << endl;
    cin >> choice;

    
}