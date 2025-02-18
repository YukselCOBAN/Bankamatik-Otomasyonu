#include "YetkiliIslem.h"

#include <iostream>

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>

using namespace std;

YetkiliIslem::YetkiliIslem()
{
}
YetkiliIslem::~YetkiliIslem()
{
}
void YetkiliIslem::musteriEkle()
{
    char kelime[100];
    float sayi;

    system("cls");

    cout << "Musteri Ekleme Islemi" << endl
         << endl;

    cout << "Musteri TcNo:";
    scanf(" %[^\n]s", kelime);
    m1.setTcNo(kelime);

    cout << "Ad Soyad: ";
    scanf(" %[^\n]s", kelime);
    m1.setAdSoyad(kelime);

    cout << "Adres: ";
    scanf(" %[^\n]s", kelime);
    m1.setAdres(kelime);

    cout << "Telefon: ";
    scanf(" %[^\n]s", kelime);
    m1.setTel(kelime);

    

    cout << "Bakiye: ";
    scanf(" %f", &sayi);
    m1.setBakiye(sayi);

    m1.setSifre(m1.getTcNo());

    char dosyaAdi[11];
    strcpy(dosyaAdi, +m1.getTcNo()); // Her müşteriye ait dosyanın adı onun tcsi olsun
    strcat(dosyaAdi, ".txt");        // dosyanın sonuna .txt eklendi

    ofstream file(dosyaAdi,ios::binary);
    file.write((char *)&m1, sizeof(MusteriBilgi)); // binary formatta bilgileri kaydettik çünkü silme
    // güncelleme daha kolay binary formatta verileri.

    file.close();
    cout << "Yeni musteri kaydi tamamlandi" << endl
         << endl;
    system("pause"); // bir tuşa basana kadar bekle

}
void YetkiliIslem::musteriSil()
{

    char kelime[100];
    float sayi;

    system("cls");

    cout << "Musteri Silme Islemi" << endl
         << endl;

    cout << "Musteri TcNo:";scanf(" %[^\n]s", kelime);
    char dosyaAdi[11];
    strcpy(dosyaAdi, +kelime);
    strcat(dosyaAdi, ".txt");

    ifstream file(dosyaAdi,ios::binary);
    if (!file.is_open())
        cout << kelime << " numarali musteri kaydi yok!!!" << endl;

    else
    {
        file.read((char *)&m1, sizeof(MusteriBilgi));

        cout << "Musteri No/TC:" << m1.getTcNo() << endl;

        cout << "Ad Soyad: " << m1.getAdSoyad() << endl;

        cout << "Adres: " << m1.getAdres() << endl;

        cout << "Telefon: " << m1.getTel() << endl;

        cout << "Bakiye: " << m1.getBakiye() << endl
             << endl;
        
        file.close(); //Silmeden önce dosya kapalı olmalı
        char tercih;
        cout<<"Musteri kaydini silmek istediginize emin misiniz [E/H] ?"<<endl<<endl;
        cin>>tercih;
        if(tercih=='e'||tercih=='E')
        {
        remove(dosyaAdi);
        cout<<"Musteri kaydi silindi"<<endl<<endl;
        }
        else if(tercih=='h'||tercih=='H')
        {
            cout<<"Silme silemi iptal edildi"<<endl<<endl;
        }
        else
        {
            cout<<"Yanlis secim yaptiniz,degisiklik olmadi"<<endl<<endl;
        }

    }

        file.close();
        system("pause");

}
void YetkiliIslem::musteriAra()
{

    char kelime[100];
    float sayi;

    system("cls");

    cout << "Musteri Arama Islemi" << endl
         << endl;

    cout <<"Musteri TcNo:";
    scanf(" %[^\n]s", kelime);
    char dosyaAdi[11];
    strcpy(dosyaAdi, +kelime);
    strcat(dosyaAdi, ".txt");

    ifstream file(dosyaAdi,ios::binary);
    if (!file.is_open())
        cout << kelime << " numarali musteri kaydi yok!!!" << endl;

    else
    {
        file.read((char *)&m1, sizeof(MusteriBilgi));

        cout << "Musteri No/TC:" << m1.getTcNo() << endl;

        cout << "Ad Soyad: " << m1.getAdSoyad() << endl;

        cout << "Adres: " << m1.getAdres() << endl;

        cout << "Telefon: " << m1.getTel() << endl;

        cout << "Bakiye: " << m1.getBakiye() << endl
             << endl;
    }

    file.close();
    system("pause");
}
void YetkiliIslem::musteriGuncelle()
{

    char kelime[100];
    float sayi;

    system("cls");

    cout << "Musteri Guncelleme Islemi" << endl
         << endl;

    cout << "Musteri TcNo:";scanf(" %[^\n]s", kelime);
    char dosyaAdi[11];
    strcpy(dosyaAdi, +kelime);
    strcat(dosyaAdi, ".txt");

    ifstream file(dosyaAdi,ios::binary);
    if (!file.is_open())
        cout << kelime << " numarali musteri kaydi yok!!!" << endl;

    else
    {
        file.read((char *)&m1, sizeof(MusteriBilgi));

        cout << "Musteri No/TC:" << m1.getTcNo() << endl;

        cout << "Ad Soyad: " << m1.getAdSoyad() << endl;

        cout << "Adres: " << m1.getAdres() << endl;

        cout << "Telefon: " << m1.getTel() << endl;

        cout << "Bakiye: " << m1.getBakiye() << endl
             << endl;

        cout<<"Bilgilerini Guncelleyiniz..."<<endl<<endl;

        cout << "Adres: ";
        scanf(" %[^\n]s", kelime);
        m1.setAdres(kelime);

        cout << "Telefon: ";
        scanf(" %[^\n]s", kelime);
        m1.setTel(kelime);

        file.close();

        ofstream file(dosyaAdi,ios::binary);
        file.write((char *)&m1, sizeof(MusteriBilgi)); 
        file.close();
        cout << "Musteri bilgileri guncellendi" << endl
            << endl;

        }

        file.close();
        system("pause");
}

int YetkiliIslem::yetkiliMenu()
{
    system("cls");
    int secim = 0;
    cout << "Sayin Yetkili Hosgeldiniz..." << endl
         << endl;
    cout << "[1]-Musteri Ekle" << endl;
    cout << "[2]-Musteri Sil" << endl;
    cout << "[3]-Musteri Ara" << endl;
    cout << "[4]-Musteri Guncelle" << endl;
    cout << "[0]-CIKIS" << endl;
    cout << "Seciminiz :  ";
    cin >> secim;
    return secim;
}

void YetkiliIslem::yetkiliGiris()
{
    int secim = yetkiliMenu();
    while (secim != 0)
    {
        switch (secim)
        {
        case 1:
            musteriEkle();
            break;

        case 2:
            musteriSil();
            break;

        case 3:
            musteriAra();
            break;

        case 4:
            musteriGuncelle();
            break;

        case 0:
            break;

        default:
            cout << "Hatali secim yaptiniz!!!" << endl;
        }

        secim = yetkiliMenu();
    }
}
