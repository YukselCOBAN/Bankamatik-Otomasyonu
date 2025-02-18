#ifndef ANAMENU_H
#define ANAMENU_H

#include "MusteriBilgi.h"

class AnaMenu
{

MusteriBilgi m1;

public:
AnaMenu();
~AnaMenu();
void yetkiliKontrol();
void musteriKontrol();

int  anaMenu();
void anaMenuGiris();



};



#endif