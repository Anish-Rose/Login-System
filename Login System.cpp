#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

int registration();
int login();
int passwordRecover();

int main(){
   int choose;
   cout << "------------Registration And Login Page------------\n\n";
   cout << "|| 1) Login \t\t||\n";
   cout << "|| 2) Registration \t||\n";
   cout << "|| 3) Forgot Password \t||\n";
   cout << "\n\nChoose : ";
   cin >> choose;

   switch(choose){
   case 1 :
       login();
       break;

   case 2 :
       registration();
       break;

   case 3 :
       passwordRecover();
       break;

   default :
       system("cls");
       main();
   }

}

int registration(){
    string rUser ;
    int rPass;
    int rCnfrm;

    cout << "Create your username : ";
    cin  >> rUser;

    cout  << "Create your password : " ;
    cin   >> rPass;

    cout  << "Confirm your password : ";
    cin   >> rCnfrm;


    if(rPass == rCnfrm){
        ofstream registration("registration.txt" , ios::app);
        registration << rUser << "  " << rPass << endl;
        cout << "Registration Successful";
    }
    else {
        cout << "Password Does Not Match";
    }
}

int login(){
    string lUser , luser;
    int lPass , lpass , count=0;

    cout << "Enter your Username : ";
    cin >> lUser;

    cout << "Enter your Password : ";
    cin  >> lPass;

    ifstream login("registration.txt");
    while(login >> luser >> lpass){
        if(lUser == luser && lPass == lpass){
                count = 1;
        }
    }
    if(count == 1){
        system("cls");
        cout << "\nLogin Successfull\n\n";
        cout << "\n\nWelcome " << lUser << "\n\n";
    }
    else if (count == 0){
        system("cls");
        cout << "\nLogin Unsuccessful Please Try again\n\n";
        main();
    }
}

int passwordRecover(){
    string recUser , tempUser;
    int tempPass , count=0;
    cout << "Enter your username to find your password : ";
    cin  >> recUser;

    ifstream forgotPassword("registration.txt");
    while(forgotPassword >> tempUser >> tempPass){
        if(tempUser == recUser){
                count = 1;
                break;
        }
    }
    forgotPassword.close();
    if(count == 1){
        system("cls");
        cout << "\nYour Account Has been found\n\n";
        cout << "\n\Your Username : " << recUser << "\n\n";
        cout << "\n\Your Password :  " << tempPass << "\n\n";
    }
    else if (count == 0){
        system("cls");
        cout << "\nCant Find Your Account in our Database\n\n";
        main();
    }



}

