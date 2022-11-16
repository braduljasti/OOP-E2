#ifndef MOTOR_HPP_INCLUDED
#define MOTOR_HPP_INCLUDED

class Motor{
private:
    int brzina;
public:
    Motor(){
        brzina=0;
    }
    int getBrzina()const{
        return brzina;
    }
    void setBrzina(int b){
        brzina=b;
    }
  /*  bool setBrzina(int b){
        if (b>=0 && b<=5){
            brzina=b;
            return true;
        }
        return false;
    }*/
    friend void ispisiMotor(const Motor& m);

};



#endif // MOTOR_HPP_INCLUDED
