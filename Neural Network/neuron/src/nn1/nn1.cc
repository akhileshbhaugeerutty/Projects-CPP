#include "nn1.hpp"

// class NN1
// {
// private:
// public:
//   NN1(int, int);
//   ~NN1();
//   char evaluation();
//   void apprentissage();
// };

NN1::NN1(InputType iType, int categories_)
{
  int  inputLength[] =  {   4 ,  784  };
  categories = categories_;
  Tanh tan;
  perceptrons = new Perceptron*[categories];

  for (int cat = 0; cat < categories; ++cat)
    perceptrons[cat] = new Perceptron(inputLength[iType], &tan, cat);
}

char NN1::evaluation(Input &input)
{
  double max = perceptrons[0]->calcul_delta(input);
  char category = 0;

  for (int cat = 1; cat < categories; ++cat)
  {
    double tmp = perceptrons[cat]->calcul_delta(input);
    if (tmp > max)
    {
      max = tmp;
      category = cat;
    }
  }
  return category;
}

void NN1::apprentissage(Input &input, double rate)
{
  for (int cat = 0; cat < categories; ++cat)
    perceptrons[cat]->backprop(input, rate);
}

NN1::~NN1()
{
  delete [] perceptrons;
  perceptrons = NULL;
}

