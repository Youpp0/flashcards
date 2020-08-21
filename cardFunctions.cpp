#include <iostream>
#include <fstream>
#include "flashcard.h"
#include "cardFunctions.h"
/*
In here most of the fun stuff is handled. Card creation, file checking, and the menu 

*/
using namespace std;
//the menu is handled with a switch statement. Each choice calls the fucntion to load a deck with the 2 premade decks hard coded and the option for custom calling its own method
int menu(int choice, FlashCard*& bank){
    int size;
   switch(choice){
        case 1:
                size =loadDeck(bank,"hiragana.txt","h_definitions.txt");
                break;
        case 2: 
                size = loadDeck(bank,"katakana.txt","kata_definitions.txt");
                break;
        case 3:
                size = customDeck(bank);
                break;
        default:
                cout << "goodbye\n"; 
                exit(0);
                break;

    }

    return size;
}

int displayMenu(){
    int menu_Choice=1;

    cout << "\nPlease choose an option\n";

    printf("1. Hiragana \n2. Katakana \n3. Custom\n");

    cin >> menu_Choice;

    return menu_Choice;

}

//this opens the file and checks that it exists sending the error to output if it cannot find the file
ifstream openFile(string fileName){
    ifstream finput;
    ofstream error_Log;

    finput.open("bank/"+fileName);
    cout << "\nAttempting to open file \n";

    if(!finput.is_open()){
        cout << "\nERROR: " << fileName << "has failed to open. Please check that " << fileName << " is in the \"bank\" directory";
        error_Log.open("/log/error_Log.txt");
        error_Log << "\nERROR: " << fileName << "has failed to open. Please check that " << fileName << " is in the \"bank\" directory";
        error_Log.close();
        exit(0);

    }

    else{
        cout << "\n" << fileName << " has opened successfully\n" ;
        return finput;

    }
    


}

//This calls the openfile for both the question file and the answer file then creates a flashcard obj for each pair putting them in an array
int loadDeck(FlashCard*& bank, string qList, string aList){
    ifstream qDeck = openFile(qList);
    ifstream aDeck = openFile(aList);

    int size =0;
    string qTemp;
    string aTemp;
    //a loop is ran to determing the amount of cards will need to be created. One loop since i'm the questions will all have an answer so itll be equal in size.
    while(qDeck >> qTemp){
        size++;
    }
    //putting the reader pointer at the top of the file for later
    qDeck.clear();
    qDeck.seekg(0,ios::beg);

    bank = new FlashCard[size];

    for(int i =0; i <size; i++){
        //going through each file putting them into temp variables
        qDeck >> qTemp;
        aDeck >> aTemp;

        cout <<"\nGenerating card " << i+1 << " out of " << size << endl;
        FlashCard newCard(qTemp,aTemp);
        bank[i] = newCard;
    }

    return size;

}

//for custom decks user input is needed for the file names. after input is obtained it calls loadDeck with the filenames in hand
int customDeck(FlashCard*& bank){
    string qList = "";
    string aList = "";

    cout <<"Please enter in the file name, with extension, of the file containing your problem bank\n";
    cin >> qList;
    cout << "Please enter in the file name, with extension, of the file containing your answer bank\n";
    cin >> aList;
    
    return loadDeck(bank, qList, aList);

}

//outputs all the cards contents for testing whether they get made properly
void testCards (FlashCard*& bank,int size){
    cout << "made it to test cards. size is: " << size << endl;

    string definition,symbol;

    for(int i =0; i < size; i++){
        
        cout << bank[i].getChar() << endl;
        cout << bank[i].getDef() << endl;
        

        cout << "card: " << i+1 << endl;
    }

}