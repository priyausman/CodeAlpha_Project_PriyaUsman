#include<iostream>
#include<cstdlib>
using namespace std;
int main(){
 int num,attempts=0,wins=0,losses=0,guess;
 string playername;
 char input;
 srand(0);
 num=(rand()%5)+1;
 cout<<"----------WELCOME TO THE NUMBER GUESSING GAME---------\n";
 cout<<"enter your name:";
 getline(cin,playername);
 cout<<"Hello, "<<playername<<" let's play a fun number guessing game\n";
 cout<<"I have picked a number between 1 to 5 try to guess it\n";
 do{
 cout<<"enter your guess:";
 cin>>guess;
 attempts++;
 if(guess>num){
 	cout<<"To High!guess again\n";
 }
 else if(guess<num){
 	cout<<"To low!guess again\n";
 }
 else{
 	cout<<"Congratulations! "<<playername<<" You guessed the correct number in "<<attempts<<" attempts!\n";
 	wins++;
 }
 cout<<"Do you want to try again(y/n):";
 cin>>input;
 if(input=='n' || input=='N'){
 	losses++;
 }
}
while(input=='y' || input=='Y');
cout<<"--------GAME OVER-------\n";
cout<<"Thankyou for playing "<<playername<<endl;
cout<<"Your final status:\nWins:"<<wins<<endl<<"losses:"<<losses<<endl;
cout<<"Good bye,"<<playername<<endl<<"See you next time!";
}
