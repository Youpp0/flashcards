/* Pedro Lopez 
   September 2019

This is a flash card program to help with japanese. I'm not currently learning japanese i just wanted a side project to do
The user will be presented with the option to pick an alphabet. After choosing an alphabet a dynamic array of flashcard objects will be made each holding the character and its definition
The character will then be shown on screen with the user prompted to guess it. The user will also have the option to give up which will give them the character again and the answer

To Do:
    Kanji library 
    katakana library
    Allow for expansion
*/


#include <iostream>
#include <fstream>
#include "flashcard.h"
#include "cardFunctions.h"
#include "game_code.h"

using namespace std;

int main(){
    FlashCard *bank = NULL;
    int size; 
    bool again;
    printBanner();
    size = menu(displayMenu(),bank);

    do{
    again = game_loop(bank, gen_Ran_Num(size));
    }while(again);
    //cout << "made it outside switch\n";
   // testCards(bank, size);


}

