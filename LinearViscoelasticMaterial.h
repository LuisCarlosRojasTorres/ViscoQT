#ifndef LINEARVISCOELASTICMATERIAL_H
#define LINEARVISCOELASTICMATERIAL_H

#include <vector>


class LinearViscoelasticMaterial
{
public:
    LinearViscoelasticMaterial();
    LinearViscoelasticMaterial(double E0, std::vector<double> gi,std::vector<double> Taui,
                               double c1, double c2, double Tref);

    double getE0();
    std::vector<double> getGi();
    std::vector<double> getTaui();
    double getC1();
    double getC2();
    double getTref();

    double getStorageModulus(double temperature, double frequency);
    double getLossModulus(double temperature, double frequency);

    std::vector<double> getStorageModulusVSTemperature(std::vector<double> temperature, double frequency);
    std::vector<double> getLossModulusVSTemperature(std::vector<double> temperature, double frequency);

    std::vector<double> getStorageModulusVSFrequency(double temperature, std::vector<double> frequency);
    std::vector<double> getLossModulusVSFrequency(double temperature, std::vector<double> frequency);

    void setShiftFactor(double temperature);

    void printData();


private:

    double E0; //Instantaneous elastic modulus
    std::vector<double> gi; //normalized elastic parameters
    std::vector<double> Taui; //relaxation times

    //WLF parameters
    double c1,c2,Tref;

    //Variaveis que sao calculadas
    double Einf;
    double at = 1; //Shift factor
    std::vector<double> Ei; // elastic modulus

    void calculateEinf();
    void calculateEi();

};

#endif // LINEARVISCOELASTICMATERIAL_H
