#include <array>
#include <iostream>
#include <cmath>

using namespace std;

// Three neurons
// Each neuron gets the three inputs and has three different weights

class Layer
{
private:
  float *weights;
  float *biases;
  int number_of_neurons;
  int number_of_inputs;

  float random_number()
  {
    return ((double)rand() / (RAND_MAX)) + 1;
  };

  float inner_product(float inputs[], float weights[], int size, int offset, float bias)
  {
    float output = bias;
    for (int i = 0; i < size; i++)
    {
      output += inputs[i] * weights[i + offset];
    }
    return output;
  }

  float activation_function(float n)
  {
    return std::exp(n);
  }

  void normalize(float *outputs, int size)
  {
    float sum = 0;
    for (int i = 0; i < size; i++)
    {
      sum += outputs[i];
    }
    for (int i = 0; i < size; i++)
    {
      outputs[i] = outputs[i] / sum;
    }
  }

public:
  Layer(int number_of_inputs, int number_of_neurons)
  {
    this->number_of_neurons = number_of_neurons;
    this->number_of_inputs = number_of_inputs;
    this->biases = new float[number_of_neurons];
    for (int i = 0; i < number_of_neurons; i++)
    {
      *(this->biases + i) = random_number();
    }

    this->weights = new float[number_of_neurons * number_of_inputs];
    for (int i = 0; i < number_of_neurons; i++)
    {
      for (int j = 0; j < number_of_inputs; j++)
      {
        *(weights + i * number_of_neurons + j) = random_number();
      }
    }
  }

  float *forward(float inputs[])
  {
    float *outputs = new float[this->number_of_neurons];

    for (int i = 0; i < this->number_of_neurons; i++)
    {
      outputs[i] = activation_function(inner_product(inputs, weights, this->number_of_inputs, i * number_of_neurons, biases[i]));
    }

    normalize(outputs, this->number_of_neurons);

    return outputs;
  }
};

float categorical_cross_entropy(float outputs[], float target_outputs[], int size)
{
  float entropy = 0;
  for (int i = 0; i < size; i++)
  {
    if (abs(outputs[i]) > 0.001)
    {
      entropy -= target_outputs[i] * log(outputs[i]);
    }
    else
    {
      entropy -= 10;
    }
  }
  return entropy;
}

int main()
{
  srand(time(NULL));

  float inputs_1[4] = {1.2, 5.1, 2.1, 4.7};
  float inputs_2[4] = {3.7, 4.1, 2.2, 4.6};
  float inputs_3[4] = {2.2, 3.6, 2.3, 3.9};
  float inputs_4[4] = {9.8, 6.1, 4.4, 0.3};
  float inputs_5[4] = {2.2, 4.4, 6.4, 7.3};
  float target_output_1[5] = {1, 0, 0, 0, 0};
  float target_output_2[5] = {0, 1, 0, 0, 0};
  float target_output_3[5] = {0, 1, 0, 0, 0};
  float target_output_4[5] = {0, 0, 0, 0, 1};
  float target_output_5[5] = {0, 0, 0, 0, 1};

  Layer one = Layer(4, 3);
  Layer two = Layer(3, 2);
  Layer three = Layer(2, 5);

  float *outputs_1_1 = one.forward(inputs_1);
  float *outputs_1_2 = two.forward(outputs_1_1);
  float *outputs_1_3 = three.forward(outputs_1_2);
  float entropy_1 = categorical_cross_entropy(outputs_1_3, target_output_1, 5);
  cout << entropy_1 << endl;

  float *outputs_2_1 = one.forward(inputs_2);
  float *outputs_2_2 = two.forward(outputs_2_1);
  float *outputs_2_3 = three.forward(outputs_2_2);
  float entropy_2 = categorical_cross_entropy(outputs_2_3, target_output_2, 5);
  cout << entropy_2 << endl;

  float *outputs_3_1 = one.forward(inputs_3);
  float *outputs_3_2 = two.forward(outputs_3_1);
  float *outputs_3_3 = three.forward(outputs_3_2);
  float entropy_3 = categorical_cross_entropy(outputs_3_3, target_output_3, 5);
  cout << entropy_3 << endl;

  float *outputs_4_1 = one.forward(inputs_4);
  float *outputs_4_2 = two.forward(outputs_4_1);
  float *outputs_4_3 = three.forward(outputs_4_2);
  float entropy_4 = categorical_cross_entropy(outputs_4_3, target_output_4, 5);
  cout << entropy_4 << endl;

  float *outputs_5_1 = one.forward(inputs_5);
  float *outputs_5_2 = two.forward(outputs_5_1);
  float *outputs_5_3 = three.forward(outputs_5_2);
  float entropy_5 = categorical_cross_entropy(outputs_5_3, target_output_5, 5);
  cout << entropy_5 << endl;

  return 0;
}
