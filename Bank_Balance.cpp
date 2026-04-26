//Bank Balance
#include <iostream>
using namespace std;
const int MAX_USERS = 1000;
class Bank{
    bool exists[MAX_USERS];
    int balance[MAX_USERS];
public:
    Bank(){
        for (int i = 0; i < MAX_USERS; i++){
            exists[i] = false; balance[i] = 0;
        }
    }
    bool CREATE(int X, int Y){
        if(!exists[X]) {
            exists[X] = true;
            balance[X] = Y;
            return true;
        } else {
            balance[X] += Y;
            return false;
        }
    }
    bool DEBIT(int X, int Y){
        if (!exists[X] || balance[X] < Y)  return false;
        balance[X] -= Y;
        return true;
    }
    bool CREDIT(int X, int Y){
        if (!exists[X]) return false;
        balance[X] += Y;
        return true;
    }
    int BALANCE(int X){
        if (!exists[X])   return -1;
        return balance[X];
    }
};
int main(){
    int Q;
    cout<<"Q: ";
    cin >> Q;
    Bank bank;
    while (Q--){
        string query;
        cout<<"Query: ";
        cin >> query;
        if(query == "CREATE"){
            int X, Y;
            cout<<"X, Y:";
            cin >> X >> Y;
            if(bank.CREATE(X, Y)){
                cout << "true" << endl;}
            else{
                cout << "false" << endl;} 
        }
        else if(query == "DEBIT"){
            int X, Y;
            cout<<"X, Y:";
            cin >> X >> Y;
            if(bank.DEBIT(X, Y)){
                cout << "true" << endl;}
            else{
                cout << "false" << endl;}
        }
        else if(query == "CREDIT"){
            int X, Y;
            cout<<"X, Y:";
            cin >> X >> Y;
            if(bank.CREDIT(X, Y)){
                cout << "true" << endl;}
            else{
                cout << "false" << endl;}
        }
        else if(query == "BALANCE"){
            int X;
            cout<<"X: ";
            cin >> X;
            cout << bank.BALANCE(X) << endl;
        }
    }
    return 0;
}