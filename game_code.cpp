#include <iostream>
#include <fstream>
#include <strings.h>
#include <time.h>
#include "game_code.h"
#include "flashcard.h"
#include "cardFunctions.h"


int gen_Ran_Num (int size){

    int ranNum;

    srand (time(NULL));

    ranNum = rand() % size;

    return ranNum;

}

void pullCard(FlashCard*& card, int target){
    cout << endl << card[target].getChar() << endl;
}

void rules(){
    
    char continue_check;
    cout << "\nYou will be shown a character. Enter your guess as to what it may be\n";
    cout << "Enter any character to continue\n";
    cin >> continue_check;


}

void fix_answer(string answer){

    for (int i=0; i < answer.length(); i ++){
        tolower(answer[i]);
    }

}

bool giveUp (FlashCard*& card, int target){
    char answer;

    cout << "Give up?(y/n)\n";
    cin >> answer;
    
    if(answer == 'n'){
         return false;
    }
   
    else{
        cout << endl;
        card[target].getChar();
        cout << "\nThe definition is: ";
        cout << card[target].getDef() << endl;
       

        return true;
    }




}

bool game_loop (FlashCard*& card, int target){



    bool ans_flag = false;
    string answer = " ";
    rules();

    do{
        
        pullCard(card, target);

        cout << "Guess: ";
        cin >> answer;

        fix_answer(answer);

        if (!card[target].checkDefinition(answer)){
            cout << "\nSorry " << answer << " was incorrect\n";
            ans_flag = giveUp(card, target);
        }

        else{

            cout << "\nCorrect!\n";
            ans_flag = true;
        }
    } while (!ans_flag);



    return play_again();


}

bool play_again(){
    char answer;
    cout << "want to play again?(y/n)\n";
    cin >> answer;

    if (answer == 'y')
        return true;
    else 
        return false;
}