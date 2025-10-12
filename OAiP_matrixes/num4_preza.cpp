#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


const float eps = 1e-9; 


bool gauss(vector<vector<double>>& a, vector<double>& b, vector<double>& x) {
    int n = a.size();
    vector<int> mtr(n, -1);
    for (short col = 0, row = 0; col < n && row < n; ++col) {
        short p = row;

        for (short i = row; i < n; ++i)
            if (fabs(a[i][col]) > fabs(a[p][col])) p = i;

        if (fabs(a[p][col]) < eps) continue;
        swap(a[p], a[row]);
        swap(b[p], b[row]);
        mtr[col] = row;

        double norm = 1.0 / a[row][col];
        for (short j = col; j < n; ++j) a[row][j] *= norm;
        b[row] *= norm;

        for (short i = 0; i < n; ++i) {
            if (i == row) continue;
            double factor = a[i][col];
            if (fabs(factor) < eps) continue;
            for (short j = col; j < n; ++j)
                a[i][j] -= factor * a[row][j];
            b[i] -= factor * b[row];
        }
        ++row;
    }

    x.assign(n, 0.0);

    for (short i = 0; i < n; ++i) {
        if (mtr[i] != -1) x[i] = b[mtr[i]];
    }

    for (short i = 0; i < n; ++i) {
        if (mtr[i] == -1) {
            return false;
        }
    }
    return true;
}

int main(){
    vector<vector<double>> matrix(4, vector<double>(3));
    vector<vector<double>> syst(4, vector<double>(4));
    vector<double> radius(4);
    vector<double> coefs;

    for (short i = 0; i < 4; i++){
        cin >> matrix[i][0] >> matrix[i][1] >> matrix[i][2];
    }

    for (short i = 0; i < 4; i++){
        syst[i][0] = matrix[i][0];
        syst[i][1] = matrix[i][1];
        syst[i][2] = matrix[i][2];
        syst[i][3] = 1.0;

        radius[i] = - (matrix[i][0] * matrix[i][0] + matrix[i][1] * matrix[i][1] + matrix[i][2] * matrix[i][2]);
    }

    if (!gauss(syst, radius, coefs)){
        cout << "Can't create a sphere";
        return 0;
    }

    double r = pow((-coefs[0] / 2.0), 2) + pow((-coefs[1] / 2.0), 2) + pow((-coefs[2] / 2.0), 2) - coefs[3];

    cout << "R:" << sqrt(r);

    return 0;
}