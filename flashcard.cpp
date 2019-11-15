#include <iostream>
#include <string>
#include "flashcard.h"

using namespace std;
FlashCard::FlashCard(){
    symbol = 'a';
    definition = "fuck";
}
FlashCard::FlashCard(string symbol, string def){

    setChar(symbol);
    setDef(def);

}

void FlashCard::setChar(string character){
         symbol = character; 
}

void FlashCard::setDef(string def){
    definition = def;
}

bool FlashCard::checkDefinition(string userInput){
        if( userInput.length() != definition.length()){
            return false;
            }
        
        for ( int i =0; i < userInput.length(); i++ ){
                if(userInput[i] != definition [i]){
                    return false;
                }

        }
        
        return true;

}

string FlashCard::getChar(){
    return symbol;
}

string FlashCard::getDef(){
    return definition;
}

