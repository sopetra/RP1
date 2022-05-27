#include<cmath>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include "postar.h"
using namespace std;

// KUĆA
kuca::kuca(){}
kuca::kuca(string A, int x, int y){
 Adresa = A; X = x; Y = y;
}
int kuca::udaljenost(kuca k){
return abs(kuca::X-k.X)+abs(kuca::Y-k.Y);
}
string kuca::adresa(){
return Adresa;
}

// POŠTAR
postar::postar(int maxkoraka, int potrosnja){
  maxKoraka = maxkoraka;
  preostaliKoraci = maxkoraka;
  Potrosnja = potrosnja;
  nizKucaLen = 0;
}
int postar::brojkuca(){
  return nizKucaLen;
}
void postar::odmori(){
  preostaliKoraci = maxKoraka;
}
int postar::preostalokoraka(){
  return preostaliKoraci;
}
bool postar::dodajkucu(kuca s, int k){
  if( k < 0 || nizKucaLen == 100) return false;
  for (int i = 0; i < nizKucaLen; i++){
    if (nizKuca[i].Adresa == s.Adresa) return false;
  }
  if( k >= nizKucaLen ){
    nizKuca[nizKucaLen] = s; nizKucaLen ++; return true;
  }
  for (int i = nizKucaLen; i > k; i--){
    nizKuca[i] = nizKuca[i-1];
  }
  nizKuca[k] = s; nizKucaLen ++;
  return true;
}
bool postar::maknikucu(string adresa){
  for (int i = 0; i < nizKucaLen; i++){
    if (nizKuca[i].Adresa == adresa){
      for (int j = i; j < nizKucaLen; j++){
        nizKuca[j] = nizKuca[j+1];
      }
      nizKucaLen -= 1;
      return true;
    }
  }
  return false;
}
kuca postar::hodaj(){
  for (int i = 0; i < nizKucaLen - 1; i++){
    if(nizKuca[i].udaljenost(nizKuca[i+1])*Potrosnja == preostaliKoraci){
      preostaliKoraci = 0;
      return nizKuca[i+1];
    }
    if(nizKuca[i].udaljenost(nizKuca[i+1])*Potrosnja > preostaliKoraci){
      return nizKuca[i];
    }
    else{
      preostaliKoraci = preostaliKoraci - nizKuca[i].udaljenost(nizKuca[i+1])*Potrosnja;
    }
  }
  return nizKuca[nizKucaLen-1];
}
