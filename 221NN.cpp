#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

double sigmoid(double z){
    return 1/(1+exp(-z));
}

int main(){

    vector<vector<double>> input = {
        {0.1,0.2},
        {0.2,0.3},
        {0.3,0.4},
        {0.4,0.5}
    };

    vector<double> target = {0.3,0.5,0.7,0.9};

    double n = 0.6;

    double w11 = 0.1;
    double w12 = 0.2;
    double w21 = 0.3;
    double w22 = 0.4;

    double w01 = -0.5;
    double w02 = -0.5;

    double v0 = -0.5;
    double v13 = 0.5;
    double v23 = 0.6;

    cout << fixed << setprecision(4);

    for(int epoch = 0; epoch < 11; epoch++){

        double SSE = 0;

        double dw11 = 0;
        double dw12 = 0;
        double dw21 = 0;
        double dw22 = 0;
        double dw01 = 0;
        double dw02 = 0;

        double dv13 = 0;
        double dv23 = 0;
        double dv0 = 0;

        for(int i = 0; i < 4; i++){

            double a1 = (w11 * input[i][0]) + (w21 * input[i][1]) + w01;
            double a2 = (w12 * input[i][0]) + (w22 * input[i][1]) + w02;

            double z1 = sigmoid(a1);
            double z2 = sigmoid(a2);

            double a3 = (v13 * z1) + (v23 * z2) + v0;

            double y = a3;

            double error = target[i] - y;

            SSE += error * error;

             cout<<"epoch:"<<epoch
                <<" y:"<<y
                <<" target:"<<target[i]
                <<" error:"<<error<<endl;

            
            double delta1 = error * v13 * z1 * (1 - z1);
            double delta2 = error * v23 * z2 * (1 - z2);

            dw11 += delta1 * input[i][0];
            dw21 += delta1 * input[i][1];
            dw01 += delta1;

            dw12 += delta2 * input[i][0];
            dw22 += delta2 * input[i][1];
            dw02 += delta2;

            dv13 += error * z1;
            dv23 += error * z2;
            dv0 += error;
        }

        dw11 /= 4;
        dw12 /= 4;
        dw21 /= 4;
        dw22 /= 4;
        dw01 /= 4;
        dw02 /= 4;

        dv13 /= 4;
        dv23 /= 4;
        dv0 /= 4;

        w11 += n * dw11;
        w12 += n * dw12;
        w21 += n * dw21;
        w22 += n * dw22;

        w01 += n * dw01;
        w02 += n * dw02;

        v13 += n * dv13;
        v23 += n * dv23;
        v0 += n * dv0;

        cout << "Epoch: " << epoch
             << " SSE: " << SSE << endl;
        cout<<"\n";
    }

    

    for(int i = 0; i < 4; i++){

        double a1 = (w11 * input[i][0]) + (w21 * input[i][1]) + w01;
        double a2 = (w12 * input[i][0]) + (w22 * input[i][1]) + w02;

        double z1 = sigmoid(a1);
        double z2 = sigmoid(a2);

        double a3 = (v13 * z1) + (v23 * z2) + v0;

        cout << "Input: (" << input[i][0] << ", " << input[i][1] << ")"
             << " Output: " << a3
             << " Target: " << target[i] << endl;
    }

    return 0;
}
