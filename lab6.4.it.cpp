#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void Create(double* a, const int n, const double Low, const double High) {
    for (int i = 0; i < n; i++)
        a[i] = Low + rand() * (High - Low) / RAND_MAX;
}

void Print(double* a, const int n) {
    for (int i = 0; i < n; i++)
        cout << setw(10) << a[i];
    cout << endl;
}

int CountGreaterThanC(double* a, const int n, const double C) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > C)
            count++;
    }
    return count;
}

double ProductAfterMax(double* a, const int n) {
    int maxIndex = 0;
    for (int i = 1; i < n; i++) { 
        if (fabs(a[i]) > fabs(a[maxIndex])) {
            maxIndex = i;
        }
    }

    double product = 1;
    for (int i = maxIndex + 1; i < n; i++) { 
        product *= a[i];
    }

    return product;
}


void RearrangeArray(double* a, const int n) {
    double* temp = new double[n];
    int negIndex = 0;
    int posIndex = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] < 0) {
            temp[negIndex++] = a[i];
        }
    }

    
    for (int i = 0; i < n; i++) {
        if (a[i] >= 0) {
            temp[negIndex + posIndex++] = a[i];
        }
    }

    
    for (int i = 0; i < n; i++) {
        a[i] = temp[i];
    }

    delete[] temp;
}

int main() {
    srand((unsigned)time(NULL));

    int n;
    cout << "Enter (n): ";
    cin >> n;

    double C;
    cout << "Enter C: ";
    cin >> C;

    auto* a = new double[n];

    double Low = -10.0;
    double High = 10.0;

    Create(a, n, Low, High);
    Print(a, n);

    
    int count = CountGreaterThanC(a, n, C);
    cout << "Count elem >  C: " << count << endl;

    
    double product = ProductAfterMax(a, n);
    cout << "Dobutok pislya maxymalnogo za modulem: " << product << endl;

    
    RearrangeArray(a, n);
    cout << "Modified mas: ";
    Print(a, n);

    delete[] a;
    return 0;
}
