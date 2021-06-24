#include "LinearViscoelasticMaterial.h"
#include <math.h>

LinearViscoelasticMaterial::LinearViscoelasticMaterial()
{
    E0 = 101.9;
    Ei.push_back(20.09); //1
    Ei.push_back(14.29); //2
    Ei.push_back(9.89); //3
    Ei.push_back(7.19); //4
    Ei.push_back(5.095); //5
    Ei.push_back(2.1); //7
    Ei.push_back(3.39); //6
    Ei.push_back(1.79); //8

    Taui.push_back(0.58); //1
    Taui.push_back(3.13); //2
    Taui.push_back(18.8); //3
    Taui.push_back(125); //4
    Taui.push_back(1042); //5
    Taui.push_back(10900); //6
    Taui.push_back(160000); //7
    Taui.push_back(5220000); //8

    //WLF parameters
    c1 = 7.32;
    c2 = 93.62;
    Tref = 23;

    calculateEinf();
}

double LinearViscoelasticMaterial::getStorageModulus(double temperature, double frequency)
{
    double ans = 0;
    double at = pow(10,-(c1*(temperature-Tref))/(c2+temperature-Tref));
    double w = 2*PI*frequency;

    ans = Einf;
    for( int i = 0; i<Taui.size(); i++){
        ans += Ei.at(i)*pow(w*at*Taui.at(i),2)/(1 + pow(w*at*Taui.at(i),2));
    }
    return ans;
}

double LinearViscoelasticMaterial::getLossModulus(double temperature, double frequency)
{
    double ans = 0;
    double at = pow(10,-(c1*(temperature-Tref))/(c2+temperature-Tref));
    double w = 2*PI*frequency;

    for( int i = 0; i<Taui.size(); i++){
        ans += Ei.at(i)*(w*at*Taui.at(i))/(1 + pow(w*at*Taui.at(i),2));
    }
    return ans;
}

void LinearViscoelasticMaterial::calculateEinf()
{
    Einf = E0;
    for( double i : Ei){
        Einf-=i;
    }
}
