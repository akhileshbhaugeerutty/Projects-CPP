#include "apprentissage.hpp"

// class Apprentissage
// {
// private:
//   NN1 *neuron;
//   InputType iType;
//   int inputSize;
// public:
//   Apprentissage(NN1*, InputType, int);
//   void apprendre_base(int, double);
//   int evaluer();
//   ~Apprentissage();
// // };

Apprentissage::Apprentissage(NN1 *neuron_, InputType iType_, int inputSize_)
{
  iType = iType_;
  neuron = neuron_;
  inputSize = inputSize_;
}

void Apprentissage::apprendre_base(int iterations, double rate)
{
  Input *in;

  for (int iteration = 0; iteration < iterations; ++iteration)
  {
    if (iType == IMAGE)
      in = new Image(getRand(0, 60000));
    else
      in = new Iris(getRand(0, 60000));
    neuron->apprentissage(*in, rate);
  }
}

int Apprentissage::evaluer()
{
  int count = 0;
  Input *in;
  for (int input = 0; input < inputSize; ++input)
  {
    if (iType == IMAGE)
      in = new Image(input);
    else
      in = new Iris(input);
    int test = neuron->evaluation(*in);
    char label = in->get_label();
    if (test == label)
      ++count;
  }
  return count;
}

Apprentissage::~Apprentissage()
{

}