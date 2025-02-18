#ifndef YETKILIISLEM_H
#define YETKILIISLEM_H

#include "MusteriBilgi.h"

class YetkiliIslem
{
    MusteriBilgi m1;  //Oluşturulan bu müşteri nesnesi üzerinde ekleme,silme,arama,güncelleme yapılır.
    public:

    YetkiliIslem();
    ~YetkiliIslem();
    void musteriEkle();
    void musteriSil();
    void musteriAra();
    void musteriGuncelle();

    int yetkiliMenu();
    void yetkiliGiris();

};




#endif