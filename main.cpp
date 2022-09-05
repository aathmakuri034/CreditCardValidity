#include <iostream>

using namespace std;

bool validateCard(int cardnum, int choice){

    

    return true;

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

    cout << endl;

    bool isValid;
    isValid = validateCard(cardnumber, choice);

    // if(isValid){
    //     cout << "This is a valid card. " << endl;
    // } else {
    //     cout << "This is not a valid card" << endl;
    // }

    return 0;
}