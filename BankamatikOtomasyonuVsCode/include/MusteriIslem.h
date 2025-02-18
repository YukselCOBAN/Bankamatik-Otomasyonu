#ifndef MUSTERIISLEM_H
#define MUSTERIISLEM_H

#include "MusteriBilgi.h"

class MusteriIslem
{
    MusteriBilgi m1;
    public:
    MusteriIslem();
    ~MusteriIslem();
    MusteriIslem(MusteriBilgi m1);
    void paraCek();
    void paraYatir();
    void bakiye();
    void havale();
    void hareketKaydet(char * dosyaAdi,char* mesaj);
    void hesapHareketi();
    void sifreDegistir();
    int musteriMenu();
    void musteriGiris(MusteriBilgi m1); // prototip olduğu için m1'i yazmasak da olur



};


#endif