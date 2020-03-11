#ifndef NEURON_SRC_APPRENTISSAGE_APPRENTISSAGE_HPP
#define NEURON_SRC_APPRENTISSAGE_APPRENTISSAGE_HPP

#include "../nn1/nn1.hpp"
#include "../image/image.hpp"
#include "../iris/iris.hpp"

class Apprentissage
{
private:
  NN1 *neuron;
  InputType iType;
  int inputSize;
public:
  Apprentissage(NN1*, InputType, int);
  void apprendre_base(int, double);
  int evaluer();
  ~Apprentissage();
};


#endif //NEURON_SRC_APPRENTISSAGE_APPRENTISSAGE_HPP