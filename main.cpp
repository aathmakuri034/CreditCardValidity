#include <iostream>
#include <vector>

using namespace std;

int menu();
void printArr(vector<int> arr);
bool americanValidateCard(long long cardnumber);
bool validateCard(long long cardnum, int choice);
vector<int> numToDigits(long long cardnum);
void newDigitsVector(long long cardnumber, int size);

int main(){
    long long cardnumber;

    int choice = menu();

    cout << "Enter card number: ";
    cin >> cardnumber; // user's credit card number is entered

    cout << endl;

    bool isValid;
    if(choice <4 && choice >0)
        isValid = validateCard(cardnumber, choice);
    
    if(choice == 4) 
        isValid = americanValidateCard(cardnumber);

    // Example Credit card number -> 4417123456789113

    if(isValid){
        cout << "This is a valid card. " << endl;
    } else {
        cout << "This is not a valid card" << endl;
    }

    return 0;
}

//prints the array passed in.
//Takes a vector
void printArr(vector<int> digits){
    for(int i=0; i<digits.size(); i++){
        cout << i << ". " << digits.at(i) << endl;
    }
}

vector<int> numToDigits(long long cardnum){
    vector<int> digits;
    long long temp = cardnum;

    while(temp){
        digits.push_back(temp%10);
        temp/=10;
    }

    reverse(digits.begin(), digits.end());
    return digits;
}

void newDigitsVector(vector<int> &digits, int size){
    int tempvar;
    for(int i=size; i>=0; i--){
        if(i%2 == 0){
            tempvar = digits.at(i);
            tempvar*=2;
            if(tempvar>9){
                tempvar = tempvar/10 + tempvar%10;
            }
            digits.at(i) = tempvar;
        }
    }
}

//Validates card numbers only for American Express
//Arguments needed: 15 digit card number
bool americanValidateCard(long long cardnumber){

    vector<int> digits = numToDigits(cardnumber);

    if(digits.size() >16){
        return false;
    }

    if(digits.at(0) != 3 && (digits.at(1) != 7 || digits.at(1) != 4)){
        return false;
    }

    //step
    int tempvar;
    for(int i=15; i>=0; i--){
        if(i%2 == 0){
            tempvar = digits.at(i);
            tempvar*=2;
            if(tempvar>9){
                tempvar = tempvar/10 + tempvar%10;
            }
            digits.at(i) = tempvar;
        }
    }


    return true;
}

//Validates card numbers only for Visa, Mastercard, and Discover
//Arguments needed: 16 digit card number and an integer card co. choice
bool validateCard(long long cardnum, int choice){

    //step 1 - convert card number into a vector of digits
    vector<int> digits = numToDigits(cardnum);

    //Step 1a -- make sure the choices are selected correctly.

    if(digits.size() >17 && (choice>0 && choice<4)){
        return false;
    }

    if((choice == 1 && digits.at(0) != 4) || (choice == 2 && digits.at(0) !=5) || (choice == 3 && digits.at(0) != 6)){
        return false;
    }

    //Step 2 - double every other digit starting from the right and replace the digit
    
    if(choice >0 && choice <4)
        newDigitsVector(digits, 16);
    else if(choice == 4)
        newDigitsVector(digits,15);
    
    //Step 3 - total the numbers in the card and see if it is divisable by 10

    int total = 0;
    for(int i=0; i<digits.size(); i++){
        total+=digits.at(i);
    }

    if(total%10 == 0){
        return true;
    } else{
        return false;
    }
}

int menu(){

    int cardchoice;

    do{
        cout << "\nSelect Card Company: " << endl;
        cout << "1. Visa" << endl;
        cout << "2. Mastercard" << endl;
        cout << "3. Discover" << endl;
        cout << "4. American Express" << endl;
        cin >> cardchoice;

        if(!(cardchoice >0 && cardchoice <5)){
            cout << "Sorry that is not a valid choice!" << endl;
            cout << "Try Again" << endl;
        }
    }while(cardchoice < 0 || cardchoice > 5);


    return cardchoice;
}