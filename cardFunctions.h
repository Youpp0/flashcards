#include <iostream>
#include <fstream>
#include "flashcard.h"

using namespace std;

int loadHiragana(FlashCard*& bank);
int loadKanji(FlashCard*& bank);
int displayMenu();
int menu(int choice,FlashCard*& bank);
void testCards(FlashCard*& bank, int size);
void printBanner();
ifstream openFile(string fileName);