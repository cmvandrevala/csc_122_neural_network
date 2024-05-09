#include <array>
#include <iostream>
#include <cmath>
#include <vector>

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
    entropy -= target_outputs[i] * (outputs[i]);
  }
  return entropy;
}

int main()
{
  srand(time(NULL));

  float inputs[5][4] = {{1.2, 5.1, 2.1, 4.7}, {3.7, 4.1, 2.2, 4.6}, {2.2, 3.6, 2.3, 3.9}, {9.8, 6.1, 4.4, 0.3}, {2.2, 4.4, 6.4, 7.3}};
  float target_outputs[5][5] = {{1, 0, 0, 0, 0}, {0, 1, 0, 0, 0}, {0, 1, 0, 0, 0}, {0, 0, 0, 0, 1}, {0, 0, 0, 0, 1}};
  float entropies[5];
  float sum_of_entropies = 0;
  int number_of_trials = 0;
  vector<float> running_errors;
  running_errors.push_back(-1000);
  Layer *one;
  Layer *two;
  Layer *three;

  while (number_of_trials < 10000)
  {
    one = new Layer(4, 3);
    two = new Layer(3, 2);
    three = new Layer(2, 5);
    sum_of_entropies = 0;

    for (int i = 0; i < 5; i++)
    {
      float *outputs_1 = one->forward(inputs[i]);
      float *outputs_2 = two->forward(outputs_1);
      float *outputs_3 = three->forward(outputs_2);
      float entropy = categorical_cross_entropy(outputs_3, target_outputs[i], 5);
      entropies[i] = entropy;
      sum_of_entropies += entropy;
    }
    float mean_entropy = sum_of_entropies / 5;
    if (mean_entropy > running_errors.back())
    {
      running_errors.push_back(mean_entropy);
    }
    number_of_trials++;

    delete one;
    delete two;
    delete three;
  }

  for (float x : running_errors)
  {
    cout << x << endl;
  }

  return 0;
}
