#include <array>
#include <iostream>
#include <numeric>

using namespace std;

// Three neurons
// Each neuron gets the three inputs and has three different weights

int main()
{
  array<float, 3> inputs = {1.2, 5.1, 2.1};

  float weights[3][3];

  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      weights[i][j] = ((double)rand() / (RAND_MAX)) + 1;
    }
  }

  float biases[3] = {3.0, 2.0, 0.5};
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
