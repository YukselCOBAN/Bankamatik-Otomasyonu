#include "AnaMenu.h"
#include "MusteriIslem.h"
#include "YetkiliIslem.h"

#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>

using namespace std;

// admin  //Yetkilinin kullanıcı adı ve parolası
// 123
AnaMenu::AnaMenu()
{
}
AnaMenu::~AnaMenu()
{
}
void AnaMenu::yetkiliKontrol()
{
    system("cls");
    char kullaniciAdi[50], sifre[30];
    cout << "Yetkili Giris Ekrani..." << endl
         << endl;
    cout << "Kullanici Adi: ";
    cin >> kullaniciAdi;
    // scanf("[^\n]s", kullaniciAdi); // enter'e basana kadar girsin
    cout << "Sifre: ";
    cin >> sifre;
    // scanf("[^\n]s", sifre);

    if (strcmp(kullaniciAdi, "admin") == 0 && (strcmp(sifre, "123") == 0)) // eşitlerse 0 döndürecek
    {
        YetkiliIslem y1;
        y1.yetkiliGiris();
    }
    else
    {
        cout << "Hatali kullanici adi veya parola!!!" << endl
             << endl;
    }

    system("pause");
}
void AnaMenu::musteriKontrol()
{

    system("cls");
    char kullaniciAdi[11], sifre[30], dosyaAdi[30];
    cout << "Musteri Giris Ekrani..." << endl
         << endl;
    cout << "Kullanici Adi/TC: ";
    cin >> kullaniciAdi;
    // scanf("[^\n]s", kullaniciAdi); // enter'e basana kadar girsin
    cout << "Sifre: ";
    cin >> sifre;
    // scanf("[^\n]s", sifre);

    strcpy(dosyaAdi, kullaniciAdi);
    strcat(dosyaAdi, ".txt");

    ifstream file(dosyaAdi, ios::binary);
    file.read((char *)&m1, sizeof(MusteriBilgi));

    if (!file.is_open())
    {
        cout << "Kullanici Adi/TC hatali!" << endl
             << endl;
    }
    else
    {

        if ( sifre == m1.getSifre()) //************************** */
        {  //YANLIŞŞŞŞ----KUKKANICI ADI DOGRU SIFRE YANLIS OLDUGU ZAMAN MENUYE GIRIYOR DUZELT

            cout << "Hatali Kullanici Adi/TC!!!" << endl
                 << endl;
        }
        else
        {

            MusteriIslem mislem;
            mislem.musteriGiris(m1);
        }
    }

    file.close();
    system("pause");
}

int AnaMenu::anaMenu()
{

    system("cls");
    int secim = 0;
    cout << "\n\t BANKAMATIK OTOMASYONU" << endl
         << endl;
    cout << "\t[1]-Yetkili Girisi" << endl;
    cout << "\t[2]-Musteri Girisi" << endl;
    cout << "\t[0]-Programi Kapat" << endl;
    cout << "\tSeciminiz :  ";
    cin >> secim;
    return secim;
}

void AnaMenu::anaMenuGiris()
{

    int secim = anaMenu();
    while (secim != 0)
    {
        switch (secim)
        {
        case 1:
            yetkiliKontrol();
            break;

        case 2:
            musteriKontrol();
            break;

        case 0:
            break;

        default:
            cout << "Hatali secim yaptiniz!!!" << endl;
        }

        secim = anaMenu();
    }
}
