#include <stdio.h>
#include <math.h>

float sigmoid(float x) {
    return 1.0 / (1.0 + exp(-x));
}

int main() {
    float data[4][3] = {
        {0, 0, 0},
        {0, 1, 0},
        {1, 0, 0},
        {1, 1, 1}
    };

    float w1 = 0.5, w2 = 0.5, b = 0.0;
    float lr = 0.1;

    for (int epoch = 0; epoch < 1000; epoch++) {
        float gw1 = 0, gw2 = 0, gb = 0;

        for (int i = 0; i < 4; i++) {
            float x1 = data[i][0];
            float x2 = data[i][1];
            float y  = data[i][2];

            float y_pred = sigmoid(x1*w1 + x2*w2 + b);
            float err = y - y_pred;

            gw1 += err * x1;
            gw2 += err * x2;
            gb  += err;
        }

        w1 += lr * gw1;
        w2 += lr * gw2;
        b  += lr * gb;
    }

    printf("w1=%f w2=%f b=%f\n", w1, w2, b);

    return 0;
}
