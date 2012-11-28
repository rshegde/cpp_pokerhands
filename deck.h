#ifndef _DECK_H
#define _DECK_H

#include "card.h"
#include <vector>
#include <algorithm>
#include <functional>
#include <ctime>
#include <cstdlib>


using namespace std;

// this class respresents a deck of cards
// When a Deck is constructed, it contains 52 cards
// in a "regular" order (aces, twos, threes, ... , kings)
//
// Shuffling a deck makes it consist of 52 cards in a random order
//
// GetCard() returns a card from the deck and decreases the
// number of cards in the deck (returned by Size())

// random generator function:
ptrdiff_t myrandom (ptrdiff_t i) { return rand()%i;}

// pointer object to it:
ptrdiff_t (*p_myrandom)(ptrdiff_t) = myrandom;


class Deck
{
  public:
    Deck(){
       for(int s = 0; s<=3; s++)
        for(int r= 1; r<=13; r++){
             Card c(r, s);
              myCards.push_back(c);
         }

     random_shuffle ( myCards.begin(), myCards.end(), p_myrandom );
    }           // pristine, sorted deck
    ~Deck() {}



  void print_deck(){
     for(int ii=0; ii<52; ii++){
        if(ii%13==0) cout << endl;
        cout<<myCards[ii]<<" ";
     }
    cout << endl;
   }

  Card Deal(){
     Card temp = myCards[0];
     myCards.erase(myCards.begin());
     return temp;}   // get a card, after 52 a joker is returned

  private:
    vector<Card> myCards;
};

#endif
