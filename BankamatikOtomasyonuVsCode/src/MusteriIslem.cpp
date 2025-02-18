#include "MusteriIslem.h"
#include <iostream>

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>

using namespace std;

MusteriIslem::MusteriIslem()
{
}
MusteriIslem::~MusteriIslem()
{
}
MusteriIslem::MusteriIslem(MusteriBilgi mPtr)
{

    m1 = mPtr;
}
void MusteriIslem::paraCek()
{

    system("cls");
    float sayi;
    char dosyaAdi[30];
    cout << "Para Cekme Ekrani..." << endl
         << endl;
    cout << "Bakiyeniz: " << m1.getBakiye() << " TL" << endl
         << endl;
    cout << "Cekeceginiz miktar(TL) : ";
    cin >> sayi;

    if (sayi > m1.getBakiye())
    {
        cout << "Yetersiz bakiye! " << endl;
    }
    else
    {

        m1.setBakiye((m1.getBakiye() - sayi)); // Bunu kaydetmemiz lazım dosyaya:
        strcpy(dosyaAdi, m1.getTcNo());
        strcat(dosyaAdi, ".txt");

        ofstream file(dosyaAdi);
        file.write((char *)&m1, sizeof(MusteriBilgi));
        file.close();
        cout << "Para cekme islemi tamamlandi" << endl;
        char mesaj[30];
        strcpy(mesaj, "Para Cekildi");
        hareketKaydet(m1.getTcNo(), mesaj);
    }

    system("pause");
}

void MusteriIslem::paraYatir()
{

    system("cls");
    float sayi;
    char dosyaAdi[30];
    cout << "Para Yatirma Ekrani..." << endl
         << endl;
    cout << "Bakiyeniz: " << m1.getBakiye() << " TL" << endl
         << endl;
    cout << "Yatiracaginiz miktar(TL) : ";
    cin >> sayi;

    m1.setBakiye((m1.getBakiye() + sayi)); // Bunu kaydetmemiz lazım dosyaya:
    strcpy(dosyaAdi, m1.getTcNo());
    strcat(dosyaAdi, ".txt");

    ofstream file(dosyaAdi, ios::binary);
    file.write((char *)&m1, sizeof(MusteriBilgi));
    file.close();
    cout << "Para yatirma islemi tamamlandi" << endl;

    char mesaj[30];
    strcpy(mesaj, "Para Yatirildi");
    hareketKaydet(m1.getTcNo(), mesaj);

    system("pause");
}

void MusteriIslem::bakiye()
{

    system("cls");
    cout << "Bakiye Sorgulama Ekrani..." << endl
         << endl;
    cout << "Bakiyeniz: " << m1.getBakiye() << " TL" << endl
         << endl;

    system("pause");

    char mesaj[30];
    strcpy(mesaj, "Bakiye Sorgulandi");
    hareketKaydet(m1.getTcNo(), mesaj);
}
void MusteriIslem::havale()
{

    system("cls");
    float sayi;
    char hesapNo[20];
    char dosyaAdi[30], dosyaAdi2[30];
    cout << "Havale/EFT Ekrani..." << endl
         << endl;
    cout << "Bakiyeniz: " << m1.getBakiye() << " TL" << endl
         << endl;
    cout << "Havale edilecek miktar(TL) : ";
    cin >> sayi;

    if (sayi > m1.getBakiye())
    {
        cout << "Yetersiz bakiye! " << endl;
    }
    else
    {

        cout << "Alici Hesap No: ";
        cin >> hesapNo;
        strcpy(dosyaAdi2, hesapNo);
        strcat(dosyaAdi2, ".txt");

        ifstream file(dosyaAdi2, ios::binary);
        if (!file.is_open())
        {
            cout << "Alici hesap numarasi hatali!!!" << endl;
        }
        else
        {
            MusteriBilgi gonderilenM2;
            file.read((char *)&gonderilenM2, sizeof(MusteriBilgi));
            file.close();

            ofstream file(dosyaAdi2, ios::binary);
            gonderilenM2.setBakiye(gonderilenM2.getBakiye() + sayi);
            file.write((char *)&gonderilenM2, sizeof(MusteriBilgi));
            file.close();

            strcpy(dosyaAdi, m1.getTcNo());
            strcat(dosyaAdi, ".txt");

            ofstream file2(dosyaAdi, ios::binary);
            m1.setBakiye(m1.getBakiye() - sayi);
            file2.write((char *)&m1, sizeof(MusteriBilgi));
            file2.close();
            cout << "Havale/EFT islemi tamamlandi" << endl;

            char mesaj[30];
            strcpy(mesaj, "Havale/EFT Gonderildi");
            hareketKaydet(m1.getTcNo(), mesaj);

            strcpy(mesaj, "Havale/EFT Alindi");
            hareketKaydet(gonderilenM2.getTcNo(), mesaj);

        }
        file.close();
    }

    system("pause");
}

void MusteriIslem::hareketKaydet(char *ptr, char *mesaj)
{

    char dosyaAdi[30];
    strcpy(dosyaAdi, ptr);
    strcat(dosyaAdi, "rapor.txt");

    ofstream file(dosyaAdi, ios::app); // Dosyaya yazma formatı,ios::app son kısma ekle,oncekıler de kalsın
    file << mesaj << endl;

    file.close();
}

void MusteriIslem::hesapHareketi()
{

    system("cls");
    char dosyaAdi[30];

    cout << "Hesap Hareket Ekrani..." << endl
         << endl;

    strcpy(dosyaAdi, m1.getTcNo());
    strcat(dosyaAdi, "rapor.txt");

    ifstream file(dosyaAdi, ios::binary);
    char harf;
    while (file.get(harf))
    {
        cout << harf;
    }

    file.close();
    system("pause");
}

void MusteriIslem::sifreDegistir()
{

    system("cls");
    char dosyaAdi[30];
    char eskiSifre[30], yeniSifre[30];

    cout << "Sifre Degistirme Ekrani..." << endl
         << endl;
    cout << "Eski Sifreniz : ";
    cin >> eskiSifre;
    // scanf("%[^\n]s", eskiSifre);
    cout << "Yeni Sifreniz : ";
    cin >> yeniSifre;
    // scanf("%[^\n]s", yeniSifre);

    strcpy(dosyaAdi, m1.getTcNo());
    strcat(dosyaAdi, ".txt");

    ifstream file(dosyaAdi, ios::binary);
    file.read((char *)&m1, sizeof(MusteriBilgi));

    if (strcmp(eskiSifre, m1.getSifre()) != 0)
        cout << "Girdiginiz eski sifre yanlis!" << endl;
    else
    {
        file.close();
        m1.setSifre(yeniSifre); // Şifreyi değiştirip dosyaya yazdırdık açıp tekrardan.
        ofstream file(dosyaAdi, ios::binary);
        file.write((char *)&m1, sizeof(MusteriBilgi));
        file.close();
        cout << "Sifreniz basariyla degistirildi" << endl;
        char mesaj[30];
        strcpy(mesaj, "Sifre Degistirildi");
        hareketKaydet(m1.getTcNo(), mesaj);
    }

    file.close();

    system("pause");
}
int MusteriIslem::musteriMenu()
{
    system("cls");
    int secim = 0;
    cout << "Sayin " << m1.getAdSoyad() << " Hosgeldiniz..." << endl
         << endl;
    cout << "Hesap No: " << m1.getTcNo() << endl
         << endl;
    cout << "[1]-Para Cek" << endl;
    cout << "[2]-Para Yatir" << endl;
    cout << "[3]-Bakiye" << endl;
    cout << "[4]-Havale/EFT" << endl;
    cout << "[5]-Hesap Hareketleri" << endl;
    cout << "[6]-Sifre Degistir" << endl;
    cout << "[0]-CIKIS" << endl;
    cout << "Seciminiz :  ";
    cin >> secim;
    return secim;
}

void MusteriIslem::musteriGiris(MusteriBilgi mPtr)
{

    m1 = mPtr;
    int secim = musteriMenu();
    while (secim != 0)
    {
        switch (secim)
        {
        case 1:
            paraCek();
            break;

        case 2:
            paraYatir();
            break;

        case 3:
            bakiye();
            break;

        case 4:
            havale();
            break;

        case 5:
            hesapHareketi();
            break;

        case 6:
            sifreDegistir();
            break;

        case 0:
            break;

        default:
            cout << "Hatali secim yaptiniz!!!" << endl;
        }

        secim = musteriMenu();
    }
}