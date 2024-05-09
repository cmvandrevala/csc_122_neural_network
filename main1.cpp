#include <array>
#include <iostream>

using namespace std;

// One neuron in one layer
// Three inputs with three weights plus one bias
// Neuron / network gives one output

int main()
{
  array<float, 4> inputs = {1.2, 5.1, 2.1, 4.7};
  array<float, 4> weights = {3.1, 2.1, 8.7, 0.5};
  float bias = 3.0;

  float output = 0;
  for (int i = 0; i < inputs.size(); i++)
  {
    output += inputs[i] * weights[i];
  }
  output += bias;

  cout << output << endl;

  return 0;
}
