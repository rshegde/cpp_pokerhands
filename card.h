#ifndef _CARD_H
#define _CARD_H

// This class represents a playing card, i.e., "ace of spades"
// a Card is constructed from a rank (int in range 1..12)
// and a suit (Card::spades, Card::hearts, Card::diamonds,
// Card::clubs)
//
// Cards should be created by a Deck (see deck.h)
//
// The function toString() converts a card to a string, e.g., to print
//
// Accessor functions include
//
// int GetRank()      -- returns 1, 2, ..., 13 for ace, two, ..., king
// bool SameSuitAs(c) -- returns true if same suit as Card c
// string suitString() -- returns "spades", "hearts", "diamonds" or "clubs"


#include <iostream>
#include <string>
#include <vector>
using namespace std;

const string Suitnames_l[] = {"spades", "hearts", "diamonds", "clubs"};
const string Ranknames_l[] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
const string Suitnames[] = {"s", "h", "d", "c"};
const string Ranknames[] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "T", "J", "Q", "K"};

class Card
{
  public:
    enum Suit {spades, hearts, diamonds, clubs};
    enum Rank {Ace=1, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King};

    Card(Rank r, Suit s): myRank(r), mySuit(s){}
    Card(int r, int s):myRank(Rank(r)), mySuit(Suit(s)) {}
    ~Card(){}
    int GetRank() const {return int(myRank);}                 // return rank, 1..13
    int GetSuite() const {return int(mySuit);}                //    string suitString(Suit s)      const;  // return "spades", "hearts",...

  private:
    Rank myRank;
    Suit mySuit;


};


ostream& operator << (ostream& out, const Card& c){
     out<<Ranknames[c.GetRank()-1]+Suitnames[c.GetSuite()];
     return out;
}

#endif
