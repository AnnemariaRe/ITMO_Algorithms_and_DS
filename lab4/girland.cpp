#include <fstream>
#include <iomanip>

using namespace std;

double minimal_B(int n, double A) {
    double h = A;
    double low = 0;
    double B = 0;

    while (h - low > 0.00001) {
        double mid = (h + low) / 2;

        double prev_lamp = A;
        double curr_lamp = mid;
        double possible_B = 0;
        int ground = 0;

        for (int i = 2; i < n; ++i) {
            double next_lamp = 2 * curr_lamp + 2 - prev_lamp;
            if (next_lamp == 0) {
                ++ground;
            }
            if (next_lamp < 0) {
                ground = 2000;
                break;
            }
            prev_lamp = curr_lamp;
            curr_lamp = next_lamp;
            possible_B = next_lamp;
        }

        if (ground <= 1) {
            h = mid;
            B = possible_B;
        } else {
            low = mid;
        }
    }

    return B;
}


int main() {
    ifstream in("garland.in");
    ofstream out("garland.out");

    int n = 0;
    double A = 0;

    in >> n >> A;
    out << setprecision(2) << fixed << minimal_B(n, A);

    return 0;
}