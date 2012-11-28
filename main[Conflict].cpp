#include "deck.h"
#include "hand.h"
#include "card.h"
#include <math.h>
#include <vector>



using namespace std;

const long int MAXITER = 10000000;
vector<float> hist(9);

void one_run();

int main()
{

 srand ( unsigned ( time (NULL) ) );

for(int i =0; i< MAXITER; i++){
  //cout << i<<"  ";
  one_run();
  if(i%10000 == 0)
    cout << "#";
//  double trouble = 0;
//  for (int j=0; j <=5000000; j++) {
//        trouble=pow(1.00034,j);
//   }
}

cout<<endl;
cout<<endl; cout<<endl;
cout<<"Histogram" <<endl;
cout<<endl;
cout<<endl; cout<<endl;



for(int i =0; i <9; i++)
 cout<<100*hist[i]/MAXITER<<endl;


  return 0;
}

void one_run(){
   Deck d;
   //d.print_deck();


   Hand h1(d);
//
//   Card c1(1,0);
//   h1.Addcard(c1);
//    Card c2(1,1);
//   h1.Addcard(c2);
//      Card c3(1,2);
//   h1.Addcard(c3);
//      Card c4(1,3);
//   h1.Addcard(c4);
//      Card c5(11,0);
//   h1.Addcard(c5);
//      Card c6(4,0);
//   h1.Addcard(c6);
//         Card c7(3,0);
//   h1.Addcard(c7);

   h1.Addcard(d.Deal());
   h1.Addcard(d.Deal());
   h1.Addcard(d.Deal());

   h1.Addcard(d.Deal());

   h1.Addcard(d.Deal());

   h1.Pokerrank();
  // h1.Printhand();
  hist[h1.Get_prank()]++;

}
