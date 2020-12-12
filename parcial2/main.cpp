#include <iostream>
#include "canon.h"
#include <math.h>
#include <stdlib.h>
#include <time.h>


using namespace std;

int main()
{

    int opc=-1;
    int d;

    //Declaracion de dos objetos de la clase canon
    canon canonOfensivo;
    canon canonDefensivo;

    d=1000; //Distancia entre los cañones dada en metros
    float rO, rD; //Rangos en los cuales la integridad de los cañones se ve comprometida
    float aO, aD;
    float g = 9.8;
    float pi = 3.1415926;

    //Rangos de daño establecidos en el problema
    canonOfensivo.setRango(0.05);
    canonDefensivo.setRango(0.025);

    //Angulos de lanzamiento establecidos
    canonOfensivo.setAlpha(50*pi/180);
    canonDefensivo.setAlpha(40*pi/180);

    //Altura
    canonOfensivo.setH(30);
    canonDefensivo.setH(20);

    while(opc!=0){

        cout<<"Menu:"<<endl;
        cout<<"1. Simular 3 ataques que comprometan al canion defensivo."<<endl;
        cout<<"2. Simular 3 ataques que comprometan al canion ofensivo."<<endl;
        cout<<"Pulse 0 para salir"<<endl;
        cout<<"Seleccione una opcion: ";
        cin>>opc;

        if(opc==1){

            float vOx, vOy, hO, hD, dD;
            float xO, yO;
            float euc;

            aO = canonOfensivo.getAlpha();
            hO = canonOfensivo.getH();
            hD = canonDefensivo.getH();
            dD = canonDefensivo.getRango()*d;

            for(float vOf = 10; vOf <= 450; vOf+=10){

                vOx = vOf*cos(aO);
                vOy = vOf*sin(aO);

                for(float t = 0; t <= 100; t+=0.1 ){

                    xO = vOx*t;
                    yO = hO + vOy*t - (0.5*g*t*t);

                    euc=pow(d-xO,2)+pow(hD-yO,2);


                    if(sqrt(euc) <= dD){
                        cout<<endl;
                        cout<<"t = "<<t<<endl;
                        cout<<"Velocidad = "<<vOf<<endl;
                        cout<<"Distancia = "<<xO<<endl;
                        cout<<"Altura = "<<yO<<endl;
                        cout<<endl;
                    }

                }

            }



        }

        if(opc == 2){

            float vDx, vDy, hO, hD, dO;
            float xD, yD;
            float euc;

            aD = canonDefensivo.getAlpha();
            hO = canonOfensivo.getH();
            hD = canonDefensivo.getH();
            dO = canonOfensivo.getRango()*d;

            for(float vDef = 10; vDef <= 450; vDef+=10){

                vDx = vDef*cos(aO);
                vDy = vDef*sin(aO);

                for(float t = 0; t <= 100; t+=0.1 ){

                    xD = vDx*t;
                    yD = hD + vDy*t - (0.5*g*t*t);

                    euc=pow(d-xD,2)+pow(yD-hO,2);


                    if(sqrt(euc) <= dO){
                        cout<<endl;
                        cout<<"t = "<<t<<endl;
                        cout<<"Velocidad = "<<vDef<<endl;
                        cout<<"Distancia = "<<xD<<endl;
                        cout<<"Altura = "<<yD<<endl;
                        cout<<endl;
                    }

                }

            }

        }

    }

    return 0;
}
