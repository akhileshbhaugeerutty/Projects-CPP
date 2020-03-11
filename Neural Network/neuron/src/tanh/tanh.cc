# include "tanh.hpp"

// class Tanh : public Fonction_activation
// {
// private:
// public:
//   double operator ()(double);
//   double prim(double);
// };

double Tanh::operator()(double x)
{
  return (exp(x) - exp(-x)) / (exp(x) + exp(-x));
}

double Tanh::prim(double x)
{
  return 1 - pow((Tanh::operator()(x)), 2);
}