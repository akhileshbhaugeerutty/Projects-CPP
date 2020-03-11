#ifndef NEURON_SRC_TANH_TANH_HPP
#define NEURON_SRC_TANH_TANH_HPP

#include <math.h>
#include "../fonction_activation/fonction_activation.hpp"

class Tanh : public Fonction_activation
{
private:
public:
  double operator ()(double);
  double prim(double);
};

#endif //NEURON_SRC_TANH_TANH_HPP