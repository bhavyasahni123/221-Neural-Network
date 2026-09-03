# 2:2:1 Neural Network

C++ implementation of a **2:2:1 feedforward neural network** trained from scratch using batch backpropagation to learn a continuous input-output mapping.

## Method

* **Architecture:** 2:2:1
* **Hidden activation:** Sigmoid function
* **Output activation:** Linear function
* **Initial weights:** Manually initialized
* **Initial biases:** Manually initialized
* **Learning rate:** \(n=0.6\)
* **Learning rule:** Batch backpropagation
* **Loss function:** Sum of Squared Errors (SSE)
* **Batch size:** 4
* **Epochs:** 100

For each training sample, the hidden layer computes:

```math
a_1=w_{11}x_1+w_{21}x_2+b_1
```

```math
z_1=\frac{1}{1+e^{-a_1}}
```

```math
a_2=w_{12}x_1+w_{22}x_2+b_2
```

```math
z_2=\frac{1}{1+e^{-a_2}}
```

The linear output is:

```math
\hat{y}=v_{13}z_1+v_{23}z_2+b_3
```

The error is:

```math
e=t-\hat{y}
```

SSE is calculated as:

```math
SSE=\sum_{i=1}^{N}e_i^2
```

The hidden-layer error terms are:

```math
\delta_1=e\,v_{13}z_1(1-z_1)
```

```math
\delta_2=e\,v_{23}z_2(1-z_2)
```

Gradients from all four training samples are accumulated and averaged before updating the weights and biases.

The parameter update is:

```math
w\leftarrow w+n\frac{\sum_{i=1}^{N}\Delta w_i}{N}
```

## Dataset

| \(x_1\) | \(x_2\) | Target |
| ------- | ------- | ------ |
| 0.1     | 0.2     | 0.3    |
| 0.2     | 0.3     | 0.5    |
| 0.3     | 0.4     | 0.7    |
| 0.4     | 0.5     | 0.9    |

## Results

The network is trained for **100 epochs** using batch backpropagation.

The program reports:

* Network output for each training sample
* Target value
* Prediction error
* Hidden-layer activations
* Current weights and biases
* SSE after each epoch

All reported values are formatted to **4 decimal places**.

## Technologies

* C++
* STL `vector`
* `<cmath>`
* `<iomanip>`
* Sigmoid activation
* Linear activation
* Backpropagation
* Batch gradient descent
* Sum of Squared Errors (SSE)
