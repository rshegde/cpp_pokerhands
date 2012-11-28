#include "deck.h"
#include "hand.h"
#include "card.h"
#include <math.h>
#include <vector>
#include <iomanip>




using namespace std;

const long int MAXITER = 1000000;
vector<double> hist(9);

void one_run();

int main()
{
//   srand ( unsigned ( time (NULL) ) );
//
//    Vec3    v(1.0, 2.0, 3.0);
//    Mat3    m(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0);
//
//    v =  2 * v + m * v;
//    v *= (m / 3.0) * norm(v);
//
//    cout << v << endl;

//


for(int i =0; i< MAXITER; i++){
  //cout << i<<"  ";
  one_run();
  if(i%10000 == 0)
    cout << "#";
}

cout<<endl;
cout<<endl; cout<<endl;
cout<<"Histogram" <<endl;
cout<<endl;
cout<<endl; cout<<endl;


//
//for(int i =0; i <9; i++)
// cout<<setprecision(4)<<100*hist[i]/MAXITER<<endl;


  return 0;
}

void one_run(){
   Deck d;
   //d.print_deck();


   Hand h1(d);
   Hand h2(d);

//   Card c1(8,0);
//   h1.Addcard(c1);
//    Card c2(3,1);
//   h1.Addcard(c2);
//      Card c3(13,2);
//   h1.Addcard(c3);
//      Card c4(12,3);
//   h1.Addcard(c4);
//      Card c5(11,1);
//   h1.Addcard(c5);
//      Card c6(10,0);
//   h1.Addcard(c6);
//         Card c7(13,0);
//   h1.Addcard(c7);
////

 for (int i = 0; i < 5; i++){
     Card c = d.Deal();
     h1.Addcard(c);
     h2.Addcard(c);
 }

   h1.Pokerrank();
  // h1.Printhand();
   h2.Pokerrank();
 //  h2.Printhand();
  // cout << endl;
 //  cout << endl;

  // hist[h1.Get_prank()]++;


}
