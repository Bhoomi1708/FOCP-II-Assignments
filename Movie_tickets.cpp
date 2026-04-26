//Movie tickets
#include <iostream>
using namespace std;
const int max_users = 100;
const int max_movies = 100;
class MovieTicket{
    bool booked[max_users][max_movies];
    int available[max_movies];
public:
    MovieTicket(){
        for(int i = 0; i < max_users; i++){
            for(int j = 0; j < max_movies; j++){
                booked[i][j] = false;   }
        }

        for(int i = 0; i < max_movies; i++){
            available[i] = 100;   }
    }

    bool BOOK(int user, int movie){
        if(booked[user][movie] == true)  return false;   
        if(available[movie] == 0)  return false;        
        booked[user][movie] = true;
        available[movie]--;

        return true;
    }
    bool CANCEL(int user, int movie){
        if(booked[user][movie] == false) { return false;  }
        booked[user][movie] = false;
        available[movie]++;

        return true;
    }
    bool IS_BOOKED(int user, int movie){
        return booked[user][movie]; }
    int AVAILABLE_TICKETS(int movie){
        return available[movie];   }
};
int main(){
    int Q;
    cout<<"Q: ";
    cin >> Q;
    MovieTicket ticket;
    while (Q--){
        string query;
        cout<<"Query: ";
        cin >> query;
        if (query == "BOOK"){
            int X, Y;
            cout<<"X, Y: ";
            cin >> X >> Y;
            if (ticket.BOOK(X, Y)){
            cout << "true" << endl;}
            else{
            cout << "false" << endl;}
        }
        else if (query== "CANCEL"){
            int X, Y;
            cout<<"X, Y: ";
            cin >> X >> Y;
            if(ticket.CANCEL(X, Y)){
            cout << "true" << endl;}
            else{
            cout << "false" << endl;}
        }
        else if(query == "IS_BOOKED"){
            int X, Y;
            cout<<"X, Y: ";
            cin >> X >> Y;
            if(ticket.IS_BOOKED(X, Y)){
            cout << "true" << endl;}
            else{
            cout << "false" << endl;}
        }
        else if(query == "AVAILABLE_TICKETS"){
            int Y;
            cout<<"Y: ";
            cin >> Y;
            cout << ticket.AVAILABLE_TICKETS(Y) << endl;
        }
    }
    return 0;
}