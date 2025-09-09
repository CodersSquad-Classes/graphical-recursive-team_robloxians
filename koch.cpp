#include <iostream>
#include <cmath>
using namespace std;

const double PI = 3.14159265358979323846;

void koch(double x1, double y1, double x2, double y2, int n) {
    if (n == 0) {
        cout << "(" << x1 << ", " << y1 << ") -> (" << x2 << ", " << y2 << ")\n";
        return;
    }

    double dx = (x2 - x1) / 3.0;
    double dy = (y2 - y1) / 3.0;

    double xB = x1 + dx;
    double yB = y1 + dy;

    double xC = x1 + 2 * dx;
    double yC = y1 + 2 * dy;

    double angle = PI / 3.0; // 60 grados en radianes
    double xD = xB + dx * cos(angle) - dy * sin(angle);
    double yD = yB + dx * sin(angle) + dy * cos(angle);

    koch(x1, y1, xB, yB, n - 1);
    koch(xB, yB, xD, yD, n - 1);
    koch(xD, yD, xC, yC, n - 1);
    koch(xC, yC, x2, y2, n - 1);
}

int main() {
    int n;
    cout << "Nivel de recursion: ";
    cin >> n;
    koch(0.0, 0.0, 100.0, 0.0, n);
    return 0;
}