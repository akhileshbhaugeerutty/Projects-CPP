#ifndef NEURON_SRC_IMAGE_IMAGE_HPP
#define NEURON_SRC_IMAGE_IMAGE_HPP

#include <string>
#include "../input/input.hpp"
#include "../utils/utils.hpp"

const int IMAGE_TABLE_SIZE = 28;
const std::string MNIST_FOLDER = "training/MNIST_training/";

class Image : public Input
{
private:
  double table[IMAGE_TABLE_SIZE * IMAGE_TABLE_SIZE]; /* 28*28 */
public:
  Image(int);
  double operator [](int);
  std::string print();
};

#endif //NEURON_SRC_IMAGE_IMAGE_HPP