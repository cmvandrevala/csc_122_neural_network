#include <array>
#include <iostream>
#include <numeric>

using namespace std;

int main()
{
  srand(time(NULL));

  array<float, 4> inputs = {1.2, 5.1, 2.1, 4.7};

  float weights[3][4];
  weights[0][0] = 3.1;
  weights[0][1] = 2.1;
  weights[0][2] = 8.7;
  weights[0][3] = 0.5;
  weights[1][0] = 6.1;
  weights[1][1] = 2.3;
  weights[1][2] = 0.7;
  weights[1][3] = 1.2;
  weights[2][0] = 4.1;
  weights[2][1] = 6.1;
  weights[2][2] = 8.8;
  weights[2][3] = 4.2;

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
