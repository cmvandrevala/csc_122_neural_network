#include <array>
#include <iostream>
#include <numeric>

using namespace std;

// Three neurons
// Each neuron gets the three inputs and has three different weights

int main()
{
  array<float, 4> inputs = {1.2, 5.1, 2.1, 4.7};

  array<float, 4> weights_1 = {3.1, 2.1, 8.7, 0.5};
  array<float, 4> weights_2 = {6.1, 2.3, 0.7, 1.2};
  array<float, 4> weights_3 = {4.1, 6.1, 8.8, 4.2};

  float bias_1 = 3.0;
  float bias_2 = 2.0;
  float bias_3 = 0.5;

  float output_1 = inner_product(inputs.begin(), inputs.end(), weights_1.begin(), bias_1);
  float output_2 = inner_product(inputs.begin(), inputs.end(), weights_2.begin(), bias_2);
  float output_3 = inner_product(inputs.begin(), inputs.end(), weights_3.begin(), bias_3);

  cout << output_1 << endl;
  cout << output_2 << endl;
  cout << output_3 << endl;

  return 0;
}
