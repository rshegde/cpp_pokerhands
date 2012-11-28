#ifndef _HAND_H
#define _HAND_H

#include "card.h"
#include "deck.h"
#include <vector>

class Hand {

  public:
    enum poker_rank {Bust, Pair, Twopair, Set, Str8, Flush, Fullhs, Fours, StFlush};

    Hand(Deck &d)
    :my_poker_rank(Bust), my_poker_subrank(0){
       myCards.push_back(d.Deal());
       myCards.push_back(d.Deal());
     }
    void Pokerrank();
    void Addcard(Card c) {myCards.push_back(c);}
    void Printhand() const {
      for (int ii =0; ii<myCards.size(); ii++)
        cout << myCards[ii]<<"  ";
      cout<<"   "<<int(my_poker_rank)<<" "<<my_poker_subrank<<endl;
    }
    poker_rank Get_prank() { return my_poker_rank;}
    unsigned long int Get_subprank(){ return my_poker_subrank;}

    private:
    vector<Card> myCards;
    poker_rank my_poker_rank;
    unsigned long int my_poker_subrank;

};

//assign rank and subank values
void Hand::Pokerrank() {

//create arrays that will count ranks and suit occurances
//                                     0 1 2 3 4 5 6 7 8 9 10,11,12,13,14
//                                       A 2 3 4 5 6 7 8 9  t  j  q  k  a
   short unsigned int rankcnt[]     = {0,0,0,0,0,0,0,0,0,0, 0, 0, 0, 0, 0}; //first index unused
   short unsigned int str8test[]    = {0,0,0,0,0,0,0,0,0,0, 0, 0, 0, 0, 0}; //specifically for testing strraists
   short unsigned int suitcnt[]     = {0,0,0,0};

//populate these arrays
  for (int i =0; i < myCards.size(); i++){
       rankcnt[myCards[i].GetRank()]++;
       suitcnt[myCards[i].GetSuite()]++;}
   rankcnt[14] = rankcnt[1];

  for (int i =1; i <= 14; i++)
      if (rankcnt[i]!= 0) str8test[i]=1;

// FLUSH TESTING AND RANKING
 bool is_flush = false;
 bool is_str8_flush = false;
 short unsigned int flshindx = 5;
 short unsigned int fl_rankcnt[]  = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; //first index unused
 short unsigned int fl_str8test[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; //specifically for

 for (int i=0; i < 4; i++)
   if (suitcnt[i] >= 5){
     is_flush = true;
     flshindx = i;}

//test for straight flush and ranking it note: cannot combine with regular st8 easily
  if (is_flush){

    for (int i =0; i < myCards.size(); i++)
      if(myCards[i].GetSuite()==flshindx)
       fl_rankcnt[myCards[i].GetRank()]++;
     fl_rankcnt[14] = fl_rankcnt[1];

    for (int i =1; i <= 14; i++)
      if (fl_rankcnt[i]!= 0)
         fl_str8test[i]=1;


    for (int i=14; i > 4; i--){
      short unsigned int flstrcnt = 0;
      for (int j = i; j > i -5; j-- )
        flstrcnt+= fl_str8test[j];

      if(flstrcnt==5){
         is_str8_flush  = true;
         my_poker_subrank = i;
         is_flush = false;
         break;}} //ends for

  } //if (is_flush)

//STRAIGHT TESTING AND RANKING
  bool is_str8 = false;

  if(is_str8_flush==false && is_flush == false){
    for (int i=14; i > 4; i--){
      short unsigned int strcnt = 0;

      for (int j = i; j > i -5; j-- )
        strcnt+= str8test[j];
      if(strcnt==5){
         is_str8  = true;
         my_poker_subrank = i;
         break;
      }
    }
  }

//MULTIPLES TEST AND RANKING
  bool is_bust = true;
  bool is_set  = false;
  bool is_pair = false;
  bool is_four = false;

  short unsigned int pair_cnt = 0;
  short unsigned int set_cnt = 0;

  short unsigned int setpos= 0;
  short unsigned int pairpos[] = {0,0,0};
  short unsigned int fourpos = 0;

  for (int i=2; i <=14 ; i++){
   if(rankcnt[i] >= 2)
     is_bust = false;
   if(rankcnt[i]==4)
     is_four = true;
   if(rankcnt[i]==3){
     setpos=i;
     is_set = true;
     set_cnt++;}
   if(rankcnt[i]==2){
     pairpos[pair_cnt]=i;
     is_pair = true;
     pair_cnt++;}
  }


short unsigned int kickarr_cnt=0;
//this is the full decision tree here

  if(is_str8_flush)
     my_poker_rank = StFlush;
  else if (is_flush){
         my_poker_rank = Flush;
         for(int i=14; i >=1; i--)
           if(fl_rankcnt[i]!=0 && kickarr_cnt <5){
               my_poker_subrank+=i;
               kickarr_cnt++;}}

       else if(is_str8)
                my_poker_rank = Str8;
            else if(is_bust== false){
                     if (is_four){
                            my_poker_rank = Fours;
                            short unsigned int fours_rank;
                            short unsigned int fours_kick;
                            short unsigned int tempt=0;
                            for(int i=14; i >1; i--){
                                if(rankcnt[i] ==4) fours_rank = i;
                                if(rankcnt[i]==1 && tempt==0){
                                   fours_kick = i;
                                   tempt++; }}
                            my_poker_subrank = 14*fours_rank + fours_kick;
                            }
                     else if(set_cnt==2 || (set_cnt==1 && pair_cnt >= 1)){
                               my_poker_rank = Fullhs;
                               for(int i= 14 ; i >1; i--)
                                  if(rankcnt[i] >=2 && i!=setpos){
                                    my_poker_subrank = 14*setpos + i;
                                    break;}}
                          else if (set_cnt==1 && pair_cnt == 0){
                                    my_poker_rank = Set;
                                    for(int i=14; i >=1; i--)
                                         if(rankcnt[i]==1 && kickarr_cnt <2){
                                             my_poker_subrank+=i;
                                             kickarr_cnt++;}
                                     my_poker_subrank+= 196*setpos;}
                               else if (pair_cnt >=2){
                                      my_poker_rank = Twopair;
                                      for(int i=14; i >=1; i--)
                                         if(rankcnt[i]==1 && kickarr_cnt <1){
                                             my_poker_subrank=i;
                                             kickarr_cnt++;}
                                      my_poker_subrank+= 196*196*pairpos[pair_cnt-1]+ 196*pairpos[pair_cnt-2];
                                     }
                                    else {
                                        my_poker_rank = Pair;
                                        for(int i=14; i >=1; i--)
                                         if(rankcnt[i]==1 && kickarr_cnt <3){
                                             my_poker_subrank+=i;
                                             kickarr_cnt++;}
                                        my_poker_subrank+=196*pairpos[0];
                                        }
                    } //ends else
                else {
                    my_poker_rank = Bust;
                    for(int i=14; i >=1; i--)
                     if(rankcnt[i]!=0 && kickarr_cnt <5){
                         my_poker_subrank+=i;
                         kickarr_cnt++;}}
}





#endif
