#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

struct kuca{
  int X, Y;
  string Adresa;
  kuca();
  kuca(string A, int x, int y);

  int udaljenost(kuca k);
  string adresa();
};

struct postar{
  int maxKoraka, nizKucaLen, preostaliKoraci;
  double Potrosnja;
  kuca* nizKuca = new kuca[100];
  postar(int maxkoraka, int potrosnja);

  int brojkuca();
  void odmori();
  int preostalokoraka();
  bool dodajkucu(kuca s, int k);
  bool maknikucu(string adresa);
  kuca hodaj();

};
