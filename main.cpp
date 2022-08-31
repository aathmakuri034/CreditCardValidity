#include <iostream>

using namespace std;

bool validateCard(int cardnum, int choice){

    int first = cardnum;

    while(first>=10){
        first/=10;
    }

    //checks if the starting number of the card number is correct with the card provider inputed
    if((choice == 1 && first != 4) || (choice == 2 && first != 5) || (choice == 3 && first != 3) || (choice ==4 && first != 6)){
        return false;
    }

    int ccnum[16], num;

    //converts the card number from int to array
    for(int i=16; i>0; i--){
        num = cardnum%10;
        cardnum/=10;
        ccnum[i] = num;
    }

    for(int i=0; i<16; i++){
        cout << ccnum[i];
    }

    // int temp = cardnum, digit, total;
    // int counter = 1;
    // while(temp>10){
    //     if(counter %2 == 0){
    //         digit = temp%10;
    //         digit*=2;
    //         if(digit>10){
    //             total = (digit/10) + (digit%10);
    //         }   
    //     }
    // }

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