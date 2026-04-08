#include <stdio.h>

double house_sizes[] = {600, 800, 1000, 1200, 1500, 1800, 2000};
double house_prices[] = {150, 200, 250, 300, 350, 400, 450};

int data_count = 7;

int main() {
    double slope = 0.0;
    double intercept = 0.0;
    double step_size = 0.0000001;
    int training_rounds = 10000;

    printf("Teaching the computer to predict house prices...\n");

    for (int round = 0; round < training_rounds; round++) {
        double total_error = 0.0;

        for (int i = 0; i < data_count; i++) {
            double guessed_price = slope * house_sizes[i] + intercept;
            double error = guessed_price - house_prices[i];

            slope -= step_size * error * house_sizes[i];
            intercept -= step_size * error;

            total_error += error * error;
        }

        if (round % 2000 == 0) {
            printf("round %d | error = %.2f\n", round, total_error);
        }
    }

    printf("\nTrained model:\n");
    printf("price = %.4f * size + %.2f\n", slope, intercept);

    printf("\nPredictions:\n");
    printf("1000 sq ft: %.2f thousand\n", slope * 1000 + intercept);
    printf("1700 sq ft: %.2f thousand\n", slope * 1700 + intercept);
    printf("2500 sq ft: %.2f thousand\n", slope * 2500 + intercept);

    return 0;
}
