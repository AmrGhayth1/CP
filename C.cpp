#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    // Initial guesses
    double x1 = 0, x2 = 0, x3 = 0, x4 = 0;
    double x1_old, x2_old, x3_old, x4_old;
    double ea1, ea2, ea3, ea4, ea_max;
    const double es = 0.01; // Stopping criterion (%)
    int iteration = 0;

    cout << fixed << setprecision(6);

    do {
        iteration++;
        x1_old = x1;
        x2_old = x2;
        x3_old = x3;
        x4_old = x4;

        // Gauss-Seidel formulas
        x1 = (1.0/50)*(190 - 2*x2 + 31*x3 - 6*x4);
        x2 = (1.0/-3)*(60 - x1 - 2*x3 + 55*x4);
        x3 = (1.0/33)*(60 - 2*x1 - 24*x2 - 3*x4);
        x4 = (1.0/3)*(80 - 3*x1 - 51*x2 - 2*x3);

        // Calculate approximate errors
        ea1 = fabs((x1 - x1_old) / x1) * 100.0;
        ea2 = fabs((x2 - x2_old) / x2) * 100.0;
        ea3 = fabs((x3 - x3_old) / x3) * 100.0;
        ea4 = fabs((x4 - x4_old) / x4) * 100.0;

        ea_max = max(ea1,max(ea2,max( ea3, ea4) ));

        // Output
        cout << "Iteration " << iteration << ": ";
        cout << "x1 = " << x1 << ", x2 = " << x2 << ", x3 = " << x3 << ", x4 = " << x4;
        cout << ", Max Error = " << ea_max << "%" << endl;

    } while (ea_max > es);

    return 0;
}
