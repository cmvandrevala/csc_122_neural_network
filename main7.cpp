#include <array>
#include <iostream>

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
      outputs[i] = inner_product(inputs, weights, this->number_of_inputs, i * number_of_neurons, biases[i]);
    }

    return outputs;
  }
};

int main()
{
  srand(time(NULL));

  float inputs[4] = {1.2, 5.1, 2.1, 4.7};

  Layer one = Layer(4, 3);
  float *outputs_1 = one.forward(inputs);
  for (int i = 0; i < 3; i++)
  {
    cout << *(outputs_1 + i) << endl;
  }

  cout << endl;

  Layer two = Layer(3, 2);
  float *outputs_2 = two.forward(inputs);
  for (int i = 0; i < 2; i++)
  {
    cout << *(outputs_2 + i) << endl;
  }

  cout << endl;

  Layer three = Layer(2, 5);
  float *outputs_3 = three.forward(inputs);
  for (int i = 0; i < 5; i++)
  {
    cout << *(outputs_3 + i) << endl;
  }

  return 0;
}
