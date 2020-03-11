#include "iris.hpp"

/*const int IRIS_TABLE_SIZE = 4;
const std::string FLOWERS[3] = {"setosa", "virginica", "versicolor"};

class Iris : public Input
{
private:
  double table[IRIS_TABLE_SIZE];
public:
  Iris(int);
  double operator [](int);
};*/

Iris::Iris(int flowerIndice)
{
  if (flowerIndice < 0 || flowerIndice > 149) {
    return;
  }

  std::string content = readFile("training/iris_training/iris" +  std::to_string(flowerIndice));

  for (int i = 0; i < IRIS_TABLE_SIZE; ++i) /*on remplit la table avec descriptions */
  {
    std::string token = content.substr(0, content.find(",")); /*siubstring, on cherche jusqu'au premier ; */
    table[i] = std::stod(token); /*Convertit en double */
    content = content.substr(content.find(",") + 1, content.length()); /*on supprimme le début et on recommence à partir ddu ";" */
  }

  content = content.substr(content.find('-') + 1, content.length()); /*on s'occupe de la chaine maintenant */

  for (unsigned long i = 0; i < sizeof(FLOWERS)/sizeof(FLOWERS[0]); ++i)
  {
    if (content.compare(FLOWERS[i]) == 0) /*on cherche si la chaine correspond à la fleur i, =0: equal*/
    {
      label = i;
      return;
    }
  }
}

double Iris::operator[](int indice)
{
  if (indice < 0 || indice >= IRIS_TABLE_SIZE)
    return 0;
  return table[indice];
}
