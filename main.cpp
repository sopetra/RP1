#include <iostream>
#include <string>
#include "postar.h"
using namespace std;

int main (){
   postar p1(20, 3);
   postar p2(10, 2);
   cout << p1.brojkuca() << endl; // 0
   cout << p2.brojkuca() << endl; // 0

   kuca k1("prva", 3, 3);
   kuca k2("druga", 4, 5);
   kuca k3("treca", 2, 5);
   kuca k4("cetvrta", 3, 4);

   cout << k1.udaljenost(k2) << endl; // 3, jer |4-3|+|5-3| = 3
   cout << k2.udaljenost(k3) << endl; // 2
   cout << k3.udaljenost(k4) << endl; // 2

   cout << p1.dodajkucu(k2, 13) << endl; // 1
   cout << p1.dodajkucu(k2, 0) << endl; // 0, vec postoji
   cout << p1.dodajkucu(k1, 0) << endl; // 1
   cout << p1.brojkuca() << endl; // 2

   cout << p1.preostalokoraka() << endl; // 20
   cout << p1.hodaj().adresa() << endl; // druga
   cout << p1.preostalokoraka() << endl; //11 jer 11=(20-udaljenost*potrosnja)

   cout << p1.hodaj().adresa() << endl; // druga
   cout << p1.preostalokoraka() << endl; // 2

   cout << p1.hodaj().adresa() << endl; // prva
   cout << p1.preostalokoraka() << endl; // 2
   p1.odmori();
   cout << p1.preostalokoraka() << endl; // 20

   p2.dodajkucu(k1, p2.brojkuca()); // dodajemo na kraj
   p2.dodajkucu(k2, p2.brojkuca());
   p2.dodajkucu(k3, p2.brojkuca());
   p2.dodajkucu(k4, p2.brojkuca());
   cout << p2.brojkuca() << endl; // 4
   cout << p2.hodaj().adresa() << endl; // treca
   cout << p2.maknikucu(k2.adresa()) << endl; // 1
   cout << p2.maknikucu(k3.adresa()) << endl; // 1

   cout << p2.brojkuca() << endl; // 2
   cout << p2.maknikucu(k3.adresa()) << endl; // 0
   cout << p2.brojkuca() << endl; // 2
   cout << p1.brojkuca() << endl; // 2

   return 0;
}
