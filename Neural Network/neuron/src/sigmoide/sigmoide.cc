#include "sigmoide.h"

//class sigmoide : public Fonction_activation
//{
//  public:
//
//  private:
//    double operator ()(double);
//  double prim(double);
//};

double sigmoide::operator()(double x)
{
  return (1/(1+exp(-x)));
}

double sigmoide::prim(double x)
{
    return( (sigmoide::operator()(x))*(1-sigmoide::operator()(x)));
}
