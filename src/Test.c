#include <stdio.h>
#include "Oyun.h"
#include "Kisi.h"
#include <stdio.h>
#include <sys/ioctl.h>
int main(void)
{

    Oyun oyn = new_Oyun();
    oyn->oyun_Baslat(oyn);
    oyn->delete_Oyun(oyn);

    return 0;
}