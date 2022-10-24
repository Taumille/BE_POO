#include <iostream>
#include "Part1.hpp"
#include <math.h>

using namespace std;

//Modulo pour les float
double modulo(double x, double y){
    float result;
    result = x - floor(x/y)*y;
    return result;
}



Source::Source(){
    cout<<"Entrez V0 : ";
    cin>>V0;
    cout<<endl;
    cout<<"Entrez phi : ";
    cin>>phi;
    cout<<endl;
}

float Echelon::tension(float t){
    if (t>phi){
        return V0;
    }
    return 0;
}

Rectangle::Rectangle(){
    cout<<"Saisir le temps en haut :";
    cin>>T;
    cout<<endl;
}

float Rectangle::tension(float t){
    if (t<phi+T && t>phi){
        return V0;
    }
}




Periodic::Periodic(){
    cout<<"Saisir la période P:";
    cin>>P;
    cout<<endl;
}


float Triangulaire::tension(float t){
    float tp = t -1.5 - phi;
    float Pp = P;
    if (modulo(tp,Pp) < Pp/2){
        return 2*V0/Pp*(modulo(tp,Pp));
    }
    else{
        return 2*V0/Pp*(1-modulo(tp-Pp/2,Pp));
    }
}

float Sinusoidal::tension(float t){
    return sin(2*3.1415*t/P + phi);
}

Creneau::Creneau(){
    cout<<"Saisir le temps en haut :";
    cin>>T;
    cout<<endl;
}

float Creneau::tension(float t){
    float tp = t - phi;
    if (modulo(tp,P)<T){
        return V0;
    }
    return 0;
}