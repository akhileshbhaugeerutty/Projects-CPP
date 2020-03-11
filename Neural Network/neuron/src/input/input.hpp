#ifndef NEURON_SRC_INPUT_INPUT_HPP
#define NEURON_SRC_INPUT_INPUT_HPP

class Input
{
protected:
  char label;
public:
  Input();
  ~Input();
  virtual double operator [](int) = 0;
  char get_label();
};


#endif //NEURON_SRC_INPUT_INPUT_HPP