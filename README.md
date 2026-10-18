# 2–2–1 Neural Network in C++

A feedforward neural network implemented from scratch in C++ to learn a continuous input-output mapping using batch backpropagation.

This project explores the fundamentals of artificial neural networks, including forward propagation, sigmoid activation, error calculation, backpropagation, and batch gradient descent, without relying on machine learning frameworks.

## Network Architecture

The network follows a **2–2–1 architecture**:

- **Input layer:** 2 neurons
- **Hidden layer:** 2 neurons with sigmoid activation
- **Output layer:** 1 neuron with linear activation

The network receives two input features, \(x_1\) and \(x_2\), and produces one predicted output, \(\hat{y}\).

## Training Configuration

| Parameter | Value |
|---|---|
| Architecture | 2–2–1 |
| Input neurons | 2 |
| Hidden neurons | 2 |
| Output neurons | 1 |
| Hidden activation | Sigmoid |
| Output activation | Linear |
| Initial weights and biases | Manually initialized |
| Learning rate (\(n\)) | 0.6 |
| Learning algorithm | Batch backpropagation |
| Loss function | Sum of Squared Errors (SSE) |
| Training samples | 4 |
| Batch size | 4 |
| Training epochs | 100 |

## Dataset

The network is trained on four input-output samples representing a continuous input-output mapping.

| \(x_1\) | \(x_2\) | Target \(t\) |
|---:|---:|---:|
| 0.1 | 0.2 | 0.3 |
| 0.2 | 0.3 | 0.5 |
| 0.3 | 0.4 | 0.7 |
| 0.4 | 0.5 | 0.9 |

Each training sample contains two input values and one target value. The network adjusts its parameters to reduce the prediction error on these samples.

## Forward Propagation

Forward propagation calculates the network's prediction from the input values, weights, and biases.

### 1. Hidden Layer

Each hidden neuron receives both input features.

For the first hidden neuron:

$$
a_1=w_{11}x_1+w_{21}x_2+b_1
$$

Its sigmoid activation is:

$$
z_1=\sigma(a_1)=\frac{1}{1+e^{-a_1}}
$$

For the second hidden neuron:

$$
a_2=w_{12}x_1+w_{22}x_2+b_2
$$

Its sigmoid activation is:

$$
z_2=\sigma(a_2)=\frac{1}{1+e^{-a_2}}
$$

Here, \(w_{ij}\) represents an input-to-hidden weight, \(b_j\) represents a hidden-layer bias, and \(z_j\) is the activation of hidden neuron \(j\).

In the implementation, the hidden-layer biases are named `w01` and `w02`, respectively.

### 2. Output Layer

The output neuron combines the two hidden activations using a linear function:

$$
\hat{y}=v_{13}z_1+v_{23}z_2+v_0
$$

where:

- \(v_{13}\) and \(v_{23}\) are the hidden-to-output weights.
- \(v_0\) is the output bias.
- \(\hat{y}\) is the predicted output.

The linear output activation allows the network to produce any real-valued prediction.

## Error Calculation

For each training sample, the prediction error is calculated as:

$$
e=t-\hat{y}
$$

where \(t\) is the target value and \(\hat{y}\) is the predicted output.

The Sum of Squared Errors (SSE) across \(N\) training samples is:

$$
\mathrm{SSE}=\sum_{i=1}^{N}e_i^2
$$

For this project, the batch contains \(N=4\) samples:

$$
\mathrm{SSE}=\sum_{i=1}^{4}(t_i-\hat{y}_i)^2
$$

SSE measures the total squared prediction error across the training dataset. A lower SSE indicates a smaller total squared error on these samples.

## Backpropagation

Backpropagation calculates how the prediction error contributes to the gradients of the network's weights and biases.

The implementation uses the error convention:

$$
e=t-\hat{y}
$$

With this convention, the parameter update contributions are added to the current weights and biases.

### 1. Output Layer Gradients

The per-sample update contributions for the output weights are:

$$
\Delta v_{13}=ez_1
$$

$$
\Delta v_{23}=ez_2
$$

The output bias contribution is:

$$
\Delta v_0=e
$$

These contributions depend on the prediction error and the hidden-layer activations.

### 2. Hidden Layer Gradients

The derivative of the sigmoid activation function is:

$$
\sigma'(a_j)=z_j(1-z_j)
$$

For the first hidden neuron, the error contribution is:

$$
\delta_1=ev_{13}z_1(1-z_1)
$$

For the second hidden neuron:

$$
\delta_2=ev_{23}z_2(1-z_2)
$$

The input-to-hidden weight contributions are:

$$
\Delta w_{11}=\delta_1x_1
$$

$$
\Delta w_{21}=\delta_1x_2
$$

$$
\Delta w_{12}=\delta_2x_1
$$

$$
\Delta w_{22}=\delta_2x_2
$$

The hidden-layer bias contributions are:

$$
\Delta b_1=\delta_1
$$

$$
\Delta b_2=\delta_2
$$

In the C++ implementation, these bias parameters are stored as `w01` and `w02`.

## Batch Gradient Descent

The network uses batch backpropagation with all four training samples processed before each parameter update.

The training process follows these steps:

1. Perform forward propagation for each training sample.
2. Calculate the prediction error and accumulate SSE.
3. Calculate the output-layer and hidden-layer gradient contributions.
4. Accumulate the gradients from all four samples.
5. Average the accumulated gradients.
6. Update all weights and biases.
7. Repeat for 100 epochs.

For a trainable parameter \(w\), the batch update is:

$$
w\leftarrow w+\frac{n}{N}
\sum_{i=1}^{N}\Delta w_i
$$

where:

- \(w\) is the parameter being updated.
- \(n=0.6\) is the learning rate.
- \(N=4\) is the batch size.
- \(\Delta w_i\) is the per-sample update contribution.

The same update procedure applies to the network's weights and biases.

Because the error is defined as \(e=t-\hat{y}\), the code adds the accumulated update contributions rather than subtracting them.

## Training Results

The program trains the network for **100 epochs** and reports:

- Network output for each training sample.
- Corresponding target value.
- Prediction error.
- SSE after each epoch.
- Final network outputs calculated using the trained parameters.

The network's weights and biases are initialized manually, and numerical output is formatted to four decimal places.

### SSE Calculation Timing

The implementation calculates SSE during the training loop, before applying the accumulated parameter updates for that epoch.

Consequently, the SSE printed for an epoch corresponds to the parameters used during that epoch's forward passes, while the updated parameters are used in the next epoch.

After the 100 training updates, the program performs another forward pass over the four samples to print the final predictions and targets.

No specific final SSE, accuracy percentage, or convergence threshold is claimed here; these should be reported from actual program output.

## Technologies Used

- **C++** — Neural network implementation and training.
- **STL `vector`** — Storage and manipulation of training data.
- **`<cmath>`** — Mathematical operations, including the exponential function.
- **`<iomanip>`** — Formatting numerical output.
- **Sigmoid activation** — Nonlinear hidden-layer transformation.
- **Linear activation** — Output prediction.
- **Backpropagation** — Gradient computation.
- **Batch gradient descent** — Parameter updates using accumulated gradients.
- **Sum of Squared Errors** — Training error measurement.

## Key Concepts Demonstrated

- Feedforward neural network architecture.
- Forward propagation through multiple layers.
- Sigmoid activation and its derivative.
- Single-output regression.
- Backpropagation through a hidden layer.
- Batch gradient accumulation and averaging.
- Weight and bias updates.
- Training error monitoring using SSE.
- Numerical output formatting in C++.

## Future Improvements

Potential extensions to the project include:

- Plotting SSE against epochs to visualize training progress.
- Comparing different learning rates and hidden-layer sizes.
- Checking analytical gradients against numerical approximations.
- Evaluating predictions on additional input combinations.
- Comparing batch gradient descent with stochastic and mini-batch approaches.

These are possible extensions, not features claimed to be implemented in the current version.

## Conclusion

This project implements a 2–2–1 feedforward neural network from scratch in C++. It demonstrates the core mechanics of forward propagation, sigmoid activation, backpropagation, batch gradient descent, and error measurement for a continuous input-output mapping.

By implementing the training process directly, the project provides a practical foundation for understanding how neural network weights and biases are adjusted to reduce prediction error.
