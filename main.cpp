#include <iostream>
#include <vector>

using namespace std;

void printArr(vector<int> arr);

void validateCard(long long cardnum){

    vector<int> digits;
    long long temp = cardnum;

    while(temp){
        digits.push_back(temp%10);
        temp/=10;
    }

    reverse(digits.begin(), digits.end());

    printArr(digits);

    int tempvar;
    for(int i=15; i>=0; i--){
        if(i%2 == 0){
            tempvar = digits.at(i);
            tempvar*=2;
            if(tempvar>9){
                tempvar = tempvar/10 + tempvar%10;
                cout << "IN LOOP" << endl;
            }
            digits.at(i) = tempvar;
        }

        
    }

    cout << "-----------------------------" << endl;
    printArr(digits);

}

void printArr(vector<int> digits){
    for(int i=0; i<digits.size(); i++){
        cout << i << ". " << digits.at(i) << endl;
    }
}

int menu(){

    int cardchoice;

    cout << "\nSelect Card Company: " << endl;
    cout << "1. Visa" << endl;
    cout << "2. Mastercard" << endl;
    cout << "3. Discover" << endl;
    cin >> cardchoice;

    return cardchoice;
}

int main(){
    long long cardnumber;

    int choice = menu();

    cout << "Enter card number: ";
    cin >> cardnumber; // user's credit card number is entered

    cout << endl;

    validateCard(cardnumber);

    // Example Credit card number -> 4417123456789113

    // if(isValid){
    //     cout << "This is a valid card. " << endl;
    // } else {
    //     cout << "This is not a valid card" << endl;
    // }

    return 0;
}