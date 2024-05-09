#include <array>
#include <iostream>

using namespace std;

int main()
{
  array<float, 4> inputs = {1.2, 5.1, 2.1, 4.7};

  array<float, 4> weights_1 = {3.1, 2.1, 8.7, 0.5};
  array<float, 4> weights_2 = {6.1, 2.3, 0.7, 1.2};
  array<float, 4> weights_3 = {4.1, 6.1, 8.8, 4.2};

  float bias_1 = 3.0;
  float bias_2 = 2.0;
  float bias_3 = 0.5;

  float output_1 = 0;
  float output_2 = 0;
  float output_3 = 0;

  for (int i = 0; i < inputs.size(); i++)
  {
    output_1 += inputs[i] * weights_1[i];
    output_2 += inputs[i] * weights_2[i];
    output_3 += inputs[i] * weights_3[i];
  }
  output_1 += bias_1;
  output_2 += bias_2;
  output_3 += bias_3;

  cout << output_1 << endl;
  cout << output_2 << endl;
  cout << output_3 << endl;

  return 0;
}
