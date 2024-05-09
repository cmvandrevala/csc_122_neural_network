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

  void forward(float inputs[])
  {
    float outputs[this->number_of_neurons];

    for (int i = 0; i < this->number_of_neurons; i++)
    {
      outputs[i] = inner_product(inputs, weights, this->number_of_inputs, i * number_of_neurons, biases[i]);
    }

    cout << outputs[0] << endl;
    cout << outputs[1] << endl;
    cout << outputs[2] << endl;
  }
};

int main()
{
  srand(time(NULL));

  float inputs[4] = {1.2, 5.1, 2.1, 4.7};

  Layer one = Layer(4, 3);
  one.forward(inputs);

  return 0;
}
