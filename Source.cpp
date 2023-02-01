#include <vector>
#include <iostream>

using namespace std;

bool cerosUnos(vector<int> v, int p, int q);
int segmentosOK(vector<int> v, int longitud);

int main()
{
    int c, n, l, aux;
    vector<int> v;

    cin >> c;

    for (int j = 0; j < c; j++) {
        cin >> n >> l;
        for (int i = 0; i < l; i++) {
            cin >> aux;
            v.push_back(aux);
        }
        cout << "Salida: " << segmentosOK(v, n) << endl;
        v.clear();
    }
    return 0;
}

int segmentosOK(vector<int> v, int longitud) {
    int ok = 0, numSegmentos = v.size() - longitud + 1;

    for (int i = 0; i < numSegmentos; i++) { cerosUnos(v, i, i + longitud) ? ok++ : ok; }
    return ok;
}

bool cerosUnos(vector<int> v, int p, int q) {
    int ceros = 0, unos = 0;

    for (int i = 0; i < v.size(); i++) {
        if (i >= p && i < q) {
            switch (v[i]) {
            case 0:
                ceros++;
                break;
            case 1:
                unos++;
                break;
            default:
                break;
            }
        }
    }
    return ceros == unos ? true : false;
}

/*
    5 Numbers of input vectors
    3 10 l=3, n=10
    -3 2 7 1 3 0 0 8 1 0
    2 5
    7 -9 6 2 7
    1 5
    8 1 1 1 1
    10 10
    2 3 4 5 6 7 8 9 10 11
    2 10
    -1 -1 1 0 1 0 1 0 1 0

    4 4 1 1 8
    */