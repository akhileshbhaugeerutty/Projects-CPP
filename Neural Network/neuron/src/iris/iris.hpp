#ifndef NEURON_SRC_IRIS_IRIS_HPP
#define NEURON_SRC_IRIS_IRIS_HPP

#include "../input/input.hpp"
#include "../utils/utils.hpp"

const int IRIS_TABLE_SIZE = 4;
const std::string FLOWERS[3] = {"setosa", "virginica", "versicolor"};

class Iris : public Input
{
private:
  double table[IRIS_TABLE_SIZE];
public:
  Iris(int);
  double operator [](int);
};

#endif //NEURON_SRC_IRIS_IRIS_HPP