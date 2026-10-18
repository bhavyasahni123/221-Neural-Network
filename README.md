# 2–2–1 Neural Network in C++

A feedforward neural network implemented from scratch in C++ to learn a continuous input-output mapping using batch backpropagation.

The project demonstrates how a neural network processes multiple input features, computes a prediction, propagates errors backward through a hidden layer, and updates its weights and biases to reduce prediction error.

## Network Architecture

The network follows a **2–2–1 architecture**:

- **Input layer:** 2 neurons
- **Hidden layer:** 2 neurons with sigmoid activation
- **Output layer:** 1 neuron with linear activation

The network maps two input features, \(x_1\) and \(x_2\), to a single predicted output, \(\hat{y}\).

## Training Configuration

| Parameter | Configuration |
|---|---|
| Architecture | 2–2–1 |
| Hidden activation | Sigmoid |
| Output activation | Linear |
| Initial weights | Manually initialized |
| Initial biases | Manually initialized |
| Learning rate | 0.6 |
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

Each sample contains two input values and one target output. The network learns from these examples by adjusting its parameters over successive training epochs.

## Forward Propagation

Forward propagation computes the network's prediction for a given input.

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

Here, \(w_{ij}\) represents an input-to-hidden weight, \(b_j\) is a hidden-layer bias, and \(z_j\) is the activation of hidden neuron \(j\).

### 2. Output Layer

The output neuron combines the hidden-layer activations using a linear function:

$$
\hat{y}=v_{13}z_1+v_{23}z_2+b_3
$$

where \(v_{13}\) and \(v_{23}\) are the hidden-to-output weights and \(b_3\) is the output bias.

The linear activation allows the predicted output to take any real value.

## Error Calculation

The prediction error is the difference between the target and the network's output:

$$
e=t-\hat{y}
$$

The Sum of Squared Errors (SSE) over \(N\) training samples is:

$$
\mathrm{SSE}=\sum_{i=1}^{N}e_i^2
$$

For this project, \(N=4\).

SSE measures the total squared prediction error across the training dataset. A lower SSE indicates a smaller total squared error on these samples.

## Backpropagation

Backpropagation computes how the prediction error contributes to the gradients of the network's weights and biases.

### 1. Output Layer Error

Using the error convention \(e=t-\hat{y}\), the output-layer gradient contributions are:

$$
\Delta v_{13}=ez_1
$$

$$
\Delta v_{23}=ez_2
$$

The output bias contribution is:

$$
\Delta b_3=e
$$

### 2. Hidden Layer Error

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

The corresponding input-to-hidden weight contributions are:

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

These expressions describe the per-sample gradient contributions under the stated error convention.

## Batch Gradient Descent

The network uses batch backpropagation with all four training samples in each batch.

Gradients are accumulated across the dataset and averaged before the parameters are updated.

For a parameter \(w\), the update can be expressed as:

$$
w\leftarrow w+\frac{\eta}{N}
\sum_{i=1}^{N}\Delta w_i
$$

where:

- \(w\) is a trainable parameter.
- \(\eta\) is the learning rate, set to \(0.6\).
- \(N\) is the number of training samples.
- \(\Delta w_i\) is the per-sample update contribution.

The same batch-update principle applies to the network's trainable weights and biases.

With the error defined as \(e=t-\hat{y}\), the update contributions are added under this convention. This is equivalent to gradient descent when the contributions are defined consistently with the negative derivative of the squared-error objective.

## Training Results

The network is trained for **100 epochs**.

The program reports the following information during training:

- Network output for each training sample.
- Corresponding target value.
- Prediction error.
- Hidden-layer activations.
- Current weights and biases.
- SSE after each epoch.

Reported numerical values are formatted to **four decimal places**.

The training dataset contains only four samples. Consequently, the reported SSE describes the network's fit to those samples and does not independently establish its performance on unseen data.

No final SSE or accuracy value is claimed here because it should be taken directly from the actual program output.

## Technologies Used

- **C++** — Neural network implementation and training.
- **STL `vector`** — Storage and manipulation of data and network parameters.
- **`<cmath>`** — Mathematical functions, including exponential calculations.
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
- Batch gradient accumulation.
- Weight and bias updates.
- Training error monitoring using SSE.
- Numerical output formatting in C++.

## Future Improvements

Potential extensions to the project include:

- Plotting SSE against epochs to visualize convergence.
- Comparing different learning rates and hidden-layer sizes.
- Checking analytical gradients against numerical approximations.
- Evaluating the model on additional input combinations.
- Comparing batch gradient descent with stochastic and mini-batch approaches.

These are possible extensions rather than features claimed to exist in the current implementation.

## Conclusion

This project provides a compact, from-scratch implementation of a 2–2–1 feedforward neural network in C++. It demonstrates the core mechanics of forward propagation, sigmoid activation, backpropagation, batch gradient descent, and error measurement for a continuous input-output mapping.
