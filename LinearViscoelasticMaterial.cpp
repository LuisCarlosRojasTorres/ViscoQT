#include "LinearViscoelasticMaterial.h"

#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>

LinearViscoelasticMaterial::LinearViscoelasticMaterial()
{
    E0 = 101.9;

    gi = {0.1972,0.1403,0.0971,0.0706,0.05,0.0333,0.0206,0.0176};
    Taui = {0.581,3.13,18.8,125,1040,10900,160000,5220000};

    //WLF parameters
    c1 = 7.32;
    c2 = 93.62;
    Tref = 23;

    calculateEi();
    calculateEinf();
}

LinearViscoelasticMaterial::LinearViscoelasticMaterial(
        double E0, std::vector<double> gi, std::vector<double> Taui,
        double c1, double c2, double Tref)
    :
      E0(E0), gi(gi), Taui(Taui),c1(c1),c2(c2),Tref(Tref)
{
    calculateEi();
    calculateEinf();
}

double LinearViscoelasticMaterial::getE0()
{
    return this->E0;
}

std::vector<double> LinearViscoelasticMaterial::getGi()
{
    return this->gi;
}

std::vector<double> LinearViscoelasticMaterial::getTaui()
{
    return this->Taui;
}

double LinearViscoelasticMaterial::getC1()
{
    return this->c1;
}

double LinearViscoelasticMaterial::getC2()
{
    return this->c2;
}

double LinearViscoelasticMaterial::getTref()
{
    return this->Tref;
}

double LinearViscoelasticMaterial::getStorageModulus(
        double temperature, double frequency)
{
    //Retorna E' para una temperatura e frequencia dadas
    double ans = 0;
    double w = 2*M_PI*frequency;
    setShiftFactor(temperature);

    ans = Einf;
    for( int i = 0; i<Taui.size(); i++){
        ans += Ei.at(i)*pow(w*at*Taui.at(i),2)/(1 + pow(w*at*Taui.at(i),2));
    }
    return ans;
}

double LinearViscoelasticMaterial::getLossModulus(
        double temperature, double frequency)
{
    //Retorna E' para una temperatura e frequencia dadas
    double ans = 0;
    double w = 2*M_PI*frequency;
    setShiftFactor(temperature);

    for( int i = 0; i<Taui.size(); i++){
        ans += Ei.at(i)*(w*at*Taui.at(i))/(1 + pow(w*at*Taui.at(i),2));
    }
    return ans;
}

std::vector<double> LinearViscoelasticMaterial::getStorageModulusVSTemperature(
        std::vector<double> temperature, double frequency)
{

    //Retorna um vetor de E' para um vetor de temperaturas e uma unica frequencia
    std::vector<double> ans;

    for (double t : temperature){
        ans.push_back(getStorageModulus(t,frequency));
    }
    return ans;
}

std::vector<double> LinearViscoelasticMaterial::getLossModulusVSTemperature(
        std::vector<double> temperature, double frequency)
{
    //Retorna um vetor de E'' para um vetor de temperaturas e uma unica frequencia
    std::vector<double> ans;
    for (double t : temperature){
        ans.push_back(getLossModulus(t,frequency));
    }
    return ans;
}

std::vector<double> LinearViscoelasticMaterial::getStorageModulusVSFrequency(
        double temperature, std::vector<double> frequency)
{
    //Retorna um vetor de E' para um vetor de frequencias e uma unica temperatura
    std::vector<double> ans;
    for (double f : frequency){
        ans.push_back(getStorageModulus(temperature,f));
    }
    return ans;
}

std::vector<double> LinearViscoelasticMaterial::getLossModulusVSFrequency(
        double temperature, std::vector<double> frequency)
{
    //Retorna um vetor de E'' para um vetor de frequencias e uma unica temperatura
    std::vector<double> ans;
    for (double f : frequency){
        ans.push_back(getLossModulus(temperature,f));
    }
    return ans;
}

void LinearViscoelasticMaterial::setShiftFactor(double temperature)
{
    //Calcula o shift factor at para uma temperatura dada
    this->at = pow(10,-(c1*(temperature-Tref))/(c2+temperature-Tref));
}

void LinearViscoelasticMaterial::printData()
{
    std::cout << "Linear Viscoelastic Material: " << std::endl;
    std::cout << " - E(0): " << this->E0 << std::endl;
    for(int i = 0; i < this->Taui.size(); i++){
        std::cout << " - i: " << i
                  << " , gi: " << this->gi.at(i)
                  << ", Ei: " << this->Ei.at(i)
                  << ", Taui: " << this->Taui.at(i) << std::endl;
    }
    std::cout << "   WLF parameters: " << std::endl;
    std::cout << " - c1: " << this->c1 << ", c2: " << this->c2<< ", Tref: " << this->Tref << std::endl;

}

void LinearViscoelasticMaterial::calculateEinf()
{
    //Calcula Einf a partir do vetor Ei
    Einf = E0;
    for( double i : Ei){
        Einf-=i;
    }
}

void LinearViscoelasticMaterial::calculateEi()
{
    //Calcula o vetor Ei
    for(double i : gi){
        this->Ei.push_back(this->E0*i);
    }
}
