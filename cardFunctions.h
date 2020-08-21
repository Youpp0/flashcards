#include <iostream>
#include <fstream>
#include "flashcard.h"

using namespace std;

//int loadHiragana(FlashCard*& bank);
//int loadKanji(FlashCard*& bank);
int loadDeck(FlashCard*& bank,string qDeck, string aDeck);
int displayMenu();
int menu(int choice,FlashCard*& bank);
int customDeck(FlashCard*& bank);
void testCards(FlashCard*& bank, int size);
ifstream openFile(string fileName);