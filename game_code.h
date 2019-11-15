#include <iostream>
#include <strings.h>
#include "flashcard.h"
#include "cardFunctions.h"

int gen_Ran_Num (int size);

bool giveUp (FlashCard*& card, int target);

bool play_again();

bool game_loop (FlashCard*& card, int target);

void rules();

void fix_answer(string answer);

void pullCard(FlashCard*& card, int target);