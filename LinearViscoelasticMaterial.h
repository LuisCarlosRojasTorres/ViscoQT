#ifndef LINEARVISCOELASTICMATERIAL_H
#define LINEARVISCOELASTICMATERIAL_H

#include <vector>

class LinearViscoelasticMaterial
{
public:
    LinearViscoelasticMaterial();

    double getStorageModulus(double temperature, double frequency);
    double getLossModulus(double temperature, double frequency);




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
