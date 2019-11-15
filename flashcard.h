#include <iostream>
#include <string>
#ifndef FLASHCARDS
#define FLASHCARDS
using namespace std;

class FlashCard{
    private:
        
        string symbol;
        string definition;
    public:
        FlashCard();
        FlashCard(string symbol, string def);

        void setChar(string symbol);
        void setDef(string def);
        string getChar();
        string getDef();
        bool checkDefinition(string userInput);


        

} ;
#endif