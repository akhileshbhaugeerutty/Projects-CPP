#ifndef NEURON_SRC_FONCTION_ACTIVATION_FONCTION_ACTIVATION_HPP
#define NEURON_SRC_FONCTION_ACTIVATION_FONCTION_ACTIVATION_HPP

class Fonction_activation
{
protected:
public:
  Fonction_activation();
  ~Fonction_activation();
  virtual double operator ()(double) = 0;
  virtual double prim(double) = 0;
};


#endif //NEURON_SRC_FONCTION_ACTIVATION_FONCTION_ACTIVATION_HPP