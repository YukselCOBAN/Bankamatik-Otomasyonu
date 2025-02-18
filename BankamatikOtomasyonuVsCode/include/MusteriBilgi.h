#ifndef MUSTERIBILGI_H
#define MUSTERIBILGI_H

class MusteriBilgi
{

    char TcNo[11], adSoyad[50], adres[100], tel[20], sifre[30];
    float bakiye;

public:
    MusteriBilgi();
    ~MusteriBilgi();
    MusteriBilgi(char *tc, char *adsoyad, char *adres, char *tel, char *sifre, float bakiye);

    void setTcNo(char *ptr); // Kapsülleme
    char *getTcNo();

    void setAdSoyad(char *ptr); // Kapsülleme
    char *getAdSoyad();

    void setAdres(char *ptr); // Kapsülleme
    char *getAdres();

    void setTel(char *ptr); // Kapsülleme
    char *getTel();

    void setSifre(char *ptr); // Kapsülleme
    char *getSifre();

    void setBakiye(float bakiye); // Kapsülleme
    float getBakiye();

};

#endif
