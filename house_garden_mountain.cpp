#include <iostream>
#include <string>

using namespace std;

class SolarSolution
{
private:
    double wattage;
    double efficiency;
    double cost;
    
public:
    SolarSolution();
    SolarSolution(double, double, double);
    double getWattage();
    void setWattage(double);
    double getEfficiency();
    void setEfficiency(double);
    double getCost();
    void setCost(double);
    void calculateOutputPower();
};

SolarSolution::SolarSolution()
{
   wattage = 0.0;
   efficiency = 0.0;
   cost = 0.0;
}

SolarSolution::SolarSolution(double wattage_, double efficiency_, double cost_)
{
   wattage = wattage_;
   efficiency = efficiency_;
   cost = cost_;
}

double SolarSolution::getWattage()
{
   return wattage;
}

void SolarSolution::setWattage(double wattage_)
{
   wattage = wattage_;
}

double SolarSolution::getEfficiency()
{
   return efficiency;
}

void SolarSolution::setEfficiency(double efficiency_)
{
   efficiency = efficiency_;
}

double SolarSolution::getCost()
{
   return cost;
}

void SolarSolution::setCost(double cost_)
{
   cost = cost_;
}

void SolarSolution::calculateOutputPower() 
{
    double outputPower = wattage * efficiency * cost;
    cout << "The output power of the solar solution is " << outputPower << endl;
}

int main()
{
    SolarSolution solarSolution(1000, 0.8, 0.5);
    solarSolution.calculateOutputPower();
    return 0;
}