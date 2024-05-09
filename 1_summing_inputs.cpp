#include <array>
#include <iostream>

using namespace std;

int main()
{
  array<float, 4> inputs = {1.2, 5.1, 2.1, 4.7};

  float output = 0;
  for (int i = 0; i < inputs.size(); i++)
  {
    output += inputs[i];
  }

  cout << output << endl;

  return 0;
}
