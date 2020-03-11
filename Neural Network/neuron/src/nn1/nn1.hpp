#ifndef NEURON_SRC_NN1_NN1_HPP
#define NEURON_SRC_NN1_NN1_HPP

#include "../perceptron/perceptron.hpp"
#include "../tanh/tanh.hpp"

enum InputType { IRIS, IMAGE };

class NN1
{
private:
  Perceptron **perceptrons = NULL;
  int categories;
public:
  NN1(InputType, int);
  ~NN1();
  char evaluation(Input&);
  void apprentissage(Input&, double);
};

#endif //NEURON_SRC_NN1_NN1_HPP