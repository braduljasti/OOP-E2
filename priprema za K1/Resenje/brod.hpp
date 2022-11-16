#ifndef BROD_HPP_INCLUDED
#define BROD_HPP_INCLUDED

enum StanjeBroda {USIDREN, PLOVI, POKVAREN};

#include "motor.hpp"

class Brod{
private:
    StanjeBroda stanje;
    Motor motor;
    int predjenoKm;
    int kolicinaGoriva;
public:
    Brod():motor(){
        stanje=USIDREN;
        predjenoKm = kolicinaGoriva = 0;
    }
    //Brod():motor(), stanje(USIDREN), predjenoKm(0), kolicinaGoriva(0){}
    bool pokvari(){
        if (stanje!=POKVAREN){
            stanje=POKVAREN;
            kolicinaGoriva = 0;
            motor.setBrzina(0);
            return true;
        }
        return false;
    }
    bool popravi(){
        if (stanje==POKVAREN){
            stanje=USIDREN;
            motor.setBrzina(0);
            return true;

        }
        return false;
    }
    bool pokreni(){
        if (stanje==USIDREN){
            stanje=PLOVI;
            return true;
        }
        return false;
    }
    bool zaustavi(){
        if (stanje==PLOVI){
            stanje=USIDREN;
            motor.setBrzina(0);
            return true;
        }
        return false;
    }
    bool sipajGorivo(){
        if (stanje==USIDREN){
            if (kolicinaGoriva+2>15){
                kolicinaGoriva=15;
            }else{
                kolicinaGoriva+=2;
            }
            return true;
        }
        return false;
    }

    bool smanjiBrzinu(){
        int trenutnaBrzina = motor.getBrzina();
        if (stanje==PLOVI && trenutnaBrzina-1>=0){
            motor.setBrzina(trenutnaBrzina-1);
            return true;
        }
        return false;
    }
    bool povecajBrzinu(){
        int trenutnaBrzina = motor.getBrzina();
        if (stanje==PLOVI && trenutnaBrzina+1<=5){
            motor.setBrzina(trenutnaBrzina+1);
            return true;
        }
        return false;
    }
    bool putuj(){
        if (stanje==PLOVI && kolicinaGoriva>0){
            kolicinaGoriva-=1;
            predjenoKm+=motor.getBrzina()*5;
            return true;
        }
        return false;
    }
    StanjeBroda getStanje()const{
        return stanje;
    }
    int getPredjenoKm()const{
        return predjenoKm;
    }
    int getKolicinaG()const{
        return kolicinaGoriva;
    }
    Motor getMotor()const{
        return motor;
    }

};



#endif // BROD_HPP_INCLUDED
