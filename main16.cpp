#include <array>
#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

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

  void get_weights()
  {
    for (int i = 0; i < number_of_neurons * number_of_inputs; i++)
    {
      cout << weights[i] << endl;
    }
    cout << endl;
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

  int number_of_training_inputs = 120;
  int number_of_data_fields = 8;
  float inputs[number_of_training_inputs][number_of_data_fields];
  float target_outputs[number_of_training_inputs][1];

  // 54,035 lines of data
  // 8 attributes per line
  // 1 output - edible or not
  ifstream file("mushroom_cleaned_no_headers.csv");
  string line;
  vector<float> split_line;
  int index = 0;

  if (file.is_open())
  {
    while (getline(file, line) && index < number_of_training_inputs)
    {
      stringstream ss(line);

      while (ss.good())
      {
        string substr;
        getline(ss, substr, ',');
        split_line.push_back(stof(substr));
      }
      for (int i = 0; i < number_of_data_fields; i++)
      {
        inputs[index][i] = split_line.at(i);
      }
      target_outputs[index][0] = split_line.at(number_of_data_fields);
      index++;
      split_line.clear();
    }
    file.close();
  }
  else
  {
    cerr << "Unable to open file!" << endl;
  }

  // PRINT THE DATA TO VERIFY IT READ IN CORRECTLY

  // for (int i = 0; i < number_of_training_inputs; i++)
  // {
  //   for (int j = 0; j < number_of_data_fields; j++)
  //   {
  //     cout << inputs[i][j] << '\t';
  //   }
  //   cout << endl;
  // }

  // for (int i = 0; i < number_of_training_inputs; i++)
  // {
  //   cout << target_outputs[i][0] << endl;
  // }

  float entropies[number_of_training_inputs];
  float sum_of_entropies = 0;
  int number_of_trials = 0;
  vector<float> running_errors;
  running_errors.push_back(-10000);
  Layer *one;
  Layer *two;
  Layer *three;

  while (number_of_trials < 10000)
  {
    one = new Layer(8, 3);
    two = new Layer(3, 2);
    three = new Layer(2, 1);
    sum_of_entropies = 0;

    for (int i = 0; i < number_of_training_inputs; i++)
    {
      float *outputs_1 = one->forward(inputs[i]);
      float *outputs_2 = two->forward(outputs_1);
      float *outputs_3 = three->forward(outputs_2);
      float entropy = categorical_cross_entropy(outputs_3, target_outputs[i], number_of_training_inputs);
      entropies[i] = entropy;
      sum_of_entropies += entropy;
    }
    float mean_entropy = sum_of_entropies / number_of_training_inputs;
    if (mean_entropy > running_errors.back())
    {
      running_errors.push_back(mean_entropy);
      cout << "Trial " << number_of_trials << ", Error = " << mean_entropy << endl;

      cout << "LAYER ONE WEIGHTS" << endl;
      one->get_weights();

      cout << "LAYER TWO WEIGHTS" << endl;
      two->get_weights();

      cout << "LAYER THREE WEIGHTS" << endl;
      three->get_weights();
    }
    delete one;
    delete two;
    delete three;
    number_of_trials++;
  }

  return 0;
}
