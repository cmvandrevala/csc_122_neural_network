1: clean
	g++ 1_summing_inputs.cpp -o 1_summing_inputs
	./1_summing_inputs

2: clean
	g++ 2_inputs_with_weights.cpp -o 2_inputs_with_weights
	./2_inputs_with_weights

3: clean
	g++ 3_adding_a_bias.cpp -o 3_adding_a_bias
	./3_adding_a_bias

4: clean
	g++ 4_multiple_neurons.cpp -o 4_multiple_neurons
	./4_multiple_neurons

5: clean
	g++ 5_inner_product.cpp -o 5_inner_product
	./5_inner_product

6: clean
	g++ 6_matrix_form.cpp -o 6_matrix_form
	./6_matrix_form

7: clean
	g++ 7_randomize_weights_and_biases.cpp -o 7_randomize_weights_and_biases
	./7_randomize_weights_and_biases

8: clean
	g++ 8_layer_class.cpp -o 8_layer_class
	./8_layer_class

9: clean
	g++ 9_multiple_layers.cpp -o 9_multiple_layers
	./9_multiple_layers

10: clean
	g++ 10_relu_activation_function.cpp -o 10_relu_activation_function
	./10_relu_activation_function

11: clean
	g++ 11_softmax_activation_function.cpp -o 11_softmax_activation_function
	./11_softmax_activation_function

12: clean
	g++ 12_normalization.cpp -o 12_normalization
	./12_normalization

13: clean
	g++ 13_entropy.cpp -o 13_entropy
	./13_entropy

14: clean
	g++ 14_target_outputs.cpp -o 14_target_outputs
	./14_target_outputs

15: clean
	g++ 15_mean_entropy.cpp -o 15_mean_entropy
	./15_mean_entropy

16: clean
	g++ 16_awful_training_algorithm.cpp -o 16_awful_training_algorithm
	./16_awful_training_algorithm

17: clean
	g++ 17_print_weights.cpp -o 17_print_weights
	./17_print_weights

18: clean
	g++ 18_mushroom_analysis.cpp -o 18_mushroom_analysis
	./18_mushroom_analysis

clean:
	@rm -f 1_summing_inputs
	@rm -f 2_inputs_with_weights
	@rm -f 3_adding_a_bias
	@rm -f 4_multiple_neurons
	@rm -f 5_inner_product
	@rm -f 6_matrix_form
	@rm -f 7_randomize_weights_and_biases
	@rm -f 8_layer_class
	@rm -f 9_multiple_layers
	@rm -f 10_relu_activation_function
	@rm -f 11_softmax_activation_function
	@rm -f 12_normalization
	@rm -f 13_entropy
	@rm -f 14_target_outputs
	@rm -f 15_mean_entropy
	@rm -f 16_awful_training_algorithm
	@rm -f 17_print_weights
	@rm -f 18_mushroom_analysis
