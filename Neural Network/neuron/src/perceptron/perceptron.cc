#include "perceptron.hpp"

// class Perceptron : public Fonction_activation
// {
// private:
//   double *weights;
//   Fonction_activation fonction_activation;
//   double prevDelta;
//   char label;
//   double delta;
// public:
//   Perceptron(int, Fonction_activation*, char);
//   double get_poids(int);
//   double forward(Input&);
//   double calcul_delta(Input&);
//   double get_delta();
//   void backprop(Input&, double);
//   ~Perceptron();
// };

Perceptron::Perceptron(int inputSize_, Tanh* fonction_activation_, char label_)
{
    fonction_activation = *fonction_activation_;
    inputSize = inputSize_;
    label = label_;

    weights = new double[inputSize];

    for (int i = 0; i < inputSize; ++i)
        weights[i] = getRand(-1,1);

    prevDelta = 0;
    delta = 0;
}

double Perceptron::get_poids(int indice)
{
    return weights[indice];
}

double Perceptron::forward(Input &input)
{
    // 𝒜(𝒙)=𝜑(𝑤0 +∑𝑤𝑖𝑥𝑖)
    // où 𝜑: R → [0,1] est la fonction d’activation qui renvoie une valeur entre 0 et 1
    // permettant de rapprocher l’input d’un des deux labels
    // (si cette valeur est inférieur à 0,5 alors il sera classé 0, sinon il sera classé 1).

    double sum = 0;
    for (int i = 1; i < inputSize; ++i)
        sum += weights[i] * input[i];

    return fonction_activation(weights[0] + sum);
}

double Perceptron::calcul_delta(Input &input)
{
  //𝛿𝑘−1 = 𝜑′(𝑤𝑘−1 + ∑𝑛 𝑤𝑘−1𝑥 ) × (𝒜(𝒙𝒋) − 𝑦𝑗)
  double sum = 0;
  prevDelta = delta;

  for (int i = 1; i < inputSize; ++i)
    sum += weights[i] * input[i];

  delta = fonction_activation.prim(weights[0] + sum) * (forward(input) - label); //suject said input.get_label(); TODO
  return delta;
}

double Perceptron::get_delta()
{
  return delta;
}

void Perceptron::backprop(Input &input, double rate)
{
  weights[0] -= (calcul_delta(input) * rate);
  for (int i = 1; i < inputSize; ++i)
    weights[i] -= rate * delta * input[i];
}

Perceptron::~Perceptron()
{
    delete [] weights;
    weights = NULL;
}