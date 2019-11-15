#include <iostream>
#include <fstream>
#include "flashcard.h"
#include "cardFunctions.h"

using namespace std;

int menu(int choice, FlashCard*& bank){
    int size;
   switch(choice){
        case 1:
                size =loadHiragana(bank);
                break;
        case 3: 
                size = loadKanji(bank);
                break;
        default:
                cout << "goodbye\n"; 
                exit(0);
                break;

    }

    return size;
}

void printBanner(){
    string program_Name = "Pedro's Flash Cards";

    for (int i =0; i < program_Name.length()+2; i++){
        cout << "*";
    }

    cout << "\n*" << program_Name << "*\n";
     
    for (int i =0; i < program_Name.length()+2; i++){
        cout << "*";
    }
}

int displayMenu(){
    int menu_Choice=1;

    cout << "\nPlease choose an option\n";

    printf("1. Hiragana \n2. Katakana \n3. Kanji \n4. Custom Set\n");

    cin >> menu_Choice;

    return menu_Choice;

}

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

int loadKanji(FlashCard*& bank){
 ifstream Kanji;
        Kanji.open("bank/Kanji.txt");
        

        ifstream definitions;
        definitions.open("bank/k_definitions.txt");
        
        int size=0;
        string Kanji_temp;
        string definition_temp;
        
        
        while(Kanji >> Kanji_temp) {
           size++;
        
        }
        
        
        Kanji.seekg(0, ios::beg);
        bank = new FlashCard[size];
        for(int i =0; i < size; i++){
            printf("Loading Kanji %i out of %i\n", i+1, size);
            Kanji >> Kanji_temp;
            
            printf("Loading definition %i out of %i\n", i+1, size);
             definitions >>  definition_temp;
            
            FlashCard tempCard(Kanji_temp,definition_temp);
            bank[i] = tempCard;
        }
        Kanji.close();
        definitions.close();
        return size;

}

int loadHiragana(FlashCard*& bank){
        string word_Bank = "hiragana.txt";
        string def_Bank = "h_definitions.txt";
        
        ifstream hiragana = openFile(word_Bank);
        //hiragana.open("bank/hiragana.txt");

        

        ifstream definitions = openFile(def_Bank);
       // definitions.open("bank/h_definitions.txt");
        
        int size=0;
        string hiragana_temp;
        string definition_temp;
        
        
        while(hiragana >> hiragana_temp) {
           size++;
           
        
        }
        hiragana.clear();
        hiragana.seekg(0, ios::beg);
        
        
        
        bank = new FlashCard[size];
        for(int i =0; i < size; i++){
           // printf("Loading hiragana %i out of %i\n", i+1, size);
            hiragana >> hiragana_temp;
            
           // printf("Loading definition %i out of %i\n", i+1, size);
            definitions >>  definition_temp;

            cout << "\nGenerating flash card " << i+1 << " out of " << size << endl;
            FlashCard tempCard(hiragana_temp,definition_temp);
            bank[i] = tempCard;
        }
        hiragana.close();
        definitions.close();
        return size;
        
    }

void testCards (FlashCard*& bank,int size){
    cout << "made it to test cards. size is: " << size << endl;

    string definition,symbol;

    for(int i =0; i < size; i++){
        
        cout << bank[i].getChar() << endl;
        cout << bank[i].getDef() << endl;
        

        cout << "card: " << i+1 << endl;
    }

}