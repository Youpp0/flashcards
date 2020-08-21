/* Pedro Lopez 
   September 2019

This is a flash card program that started for japanese but now how has the ability for custom decks. Kanji not included nor planned to be included sorry.
Each card is an object held in a dynamic array based on whats in the file you give it for decks
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

