#include <array>
#include <iostream>
#include <numeric>

using namespace std;

float random_number()
{
  return ((double)rand() / (RAND_MAX)) + 1;
};

int main()
{
  srand(time(NULL));

  array<float, 4> inputs = {1.2, 5.1, 2.1, 4.7};

  float weights[3][4];
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      weights[i][j] = random_number();
    }
  }

  float biases[3];
  for (int i = 0; i < 3; i++)
  {
    biases[i] = random_number();
  }

  float outputs[3];

  for (int i = 0; i < 3; i++)
  {
    outputs[i] = inner_product(inputs.begin(), inputs.end(), weights[i], biases[i]);
  }

  cout << outputs[0] << endl;
  cout << outputs[1] << endl;
  cout << outputs[2] << endl;

  return 0;
}
