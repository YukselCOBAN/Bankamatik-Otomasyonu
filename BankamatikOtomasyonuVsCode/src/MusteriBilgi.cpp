#include "MusteriBilgi.h"
#include <iostream>

#include <string.h>
#include <stdlib.h>
#include <stdio.h>


using namespace std;

MusteriBilgi::MusteriBilgi()
{
    strcpy(TcNo, "");
    strcpy(adSoyad, "");
    strcpy(adres, "");
    strcpy(tel, "");
    strcpy(sifre, "");
    bakiye=0.0;
}

MusteriBilgi::~MusteriBilgi()
{
}

MusteriBilgi::MusteriBilgi(char *tc, char *adsoyad, char *adres, char *telefon, char *sifre, float bakiye)
{
    strcpy(TcNo, tc);
    strcpy(adSoyad, adsoyad);
    strcpy(adres, adres);
    strcpy(tel, tel);
    strcpy(sifre, sifre);
    this->bakiye=bakiye;
}

void MusteriBilgi:: setTcNo(char *ptr)  //Atamak için
{
    strcpy(TcNo, ptr);
}
char * MusteriBilgi::getTcNo()  //Görmek için
{
    return TcNo;
}

void MusteriBilgi::setAdSoyad(char *ptr)
{
    strcpy(adSoyad, ptr);
}
char * MusteriBilgi::getAdSoyad()
{
    return adSoyad;
}

void MusteriBilgi::setAdres(char *ptr)
{
    strcpy(adres, ptr);
}
char *MusteriBilgi::getAdres()
{
    return adres;
}

void MusteriBilgi::setTel(char *ptr)
{
    strcpy(tel, ptr);
}
char *MusteriBilgi::getTel()
{
    return tel;
}

void MusteriBilgi::setSifre(char *ptr)
{
    strcpy(sifre, ptr);
}
char *MusteriBilgi::getSifre()
{
    return sifre;
}

void MusteriBilgi::setBakiye(float bakiye)
{
    this->bakiye = bakiye;
}
float MusteriBilgi::getBakiye()
{
    return bakiye;
}
