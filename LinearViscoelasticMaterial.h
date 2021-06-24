#ifndef LINEARVISCOELASTICMATERIAL_H
#define LINEARVISCOELASTICMATERIAL_H

#include <vector>

class LinearViscoelasticMaterial
{
public:
    LinearViscoelasticMaterial();
    LinearViscoelasticMaterial(double E0, std::vector<double> Ei,std::vector<double> Taui,
                               double c1, double c2, double Tref);


    double getStorageModulus(double temperature, double frequency);
    double getLossModulus(double temperature, double frequency);

    std::vector<double> getStorageModulusVSTemperature(std::vector<double> temperature, double frequency);
    std::vector<double> getLossModulusVSTemperature(std::vector<double> temperature, double frequency);

    std::vector<double> getStorageModulusVSFrequency(double temperature, std::vector<double> frequency);
    std::vector<double> getLossModulusVSFrequency(double temperature, std::vector<double> frequency);


private:
    const double PI = 3.14159265;

    double E0,Einf;
    std::vector<double> Ei;
    std::vector<double> Taui;

    //WLF parameters
    double c1,c2,Tref;

    void calculateEinf();

};

#endif // LINEARVISCOELASTICMATERIAL_H
