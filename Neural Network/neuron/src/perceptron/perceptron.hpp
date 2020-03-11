#ifndef NEURON_SRC_PERCEPTRON_PERCEPTRON_HPP
#define NEURON_SRC_PERCEPTRON_PERCEPTRON_HPP

#include <math.h>
#include "../tanh/tanh.hpp"
#include "../input/input.hpp"
#include "../utils/utils.hpp"

class Perceptron
{
private:
  double *weights = NULL;
  Tanh fonction_activation;
  double prevDelta;
  char label;
  double delta;
  int inputSize;
public:
  Perceptron(int, Tanh*, char);
  double get_poids(int);
  double forward(Input&);
  double calcul_delta(Input&);
  double get_delta();
  void backprop(Input&, double);
  ~Perceptron();
};

#endif //NEURON_SRC_PERCEPTRON_PERCEPTRON_HPP