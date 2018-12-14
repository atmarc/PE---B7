#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>  
using namespace std;

int contadorQuick = 0;

int partition(vector<int> & a, int start, int end) {
    unsigned int pivot = a[start];
    unsigned int from_left = start+1;
    unsigned int from_right = end;
    unsigned int tmp;

    while (from_left != from_right) {
        if (a[from_left] <= pivot) from_left++;
        else {
            while (( from_left != from_right)  && (pivot < a[from_right])) from_right--;
            tmp =  a[from_right];
            a[from_right] = a[from_left];
            a[from_left] = tmp;
        }
    }

    if (a[from_left]>pivot) from_left--;
    a[start] = a[from_left];
    a[from_left] = pivot;

    return (from_left);
}

void quickSort(vector <int> & a, int p, int r) {
    ++contadorQuick;
    if (p < r) {
        int q = partition(a, p, r);
        quickSort(a, p, q - 1);
        quickSort(a, q + 1, r);
    }
}


int entropia (vector <int> &V) {
    int result = 0;
    int size = V.size();
    for (int p = 0; p < size; p++) {
        int i = p + 1;
        while(i < size) {
            if(V[p] > V[i]) ++result;
            ++i;
        }
    }
    return result;
}

int main () { 
    int tamanyVector, n;
    cout << "Tamany del vector: ";
    cin >> tamanyVector;
    for (int z = 0; z < 5; ++z) {
        vector<int> aVector(tamanyVector);
        srand(time(NULL));
        for (int i = 0; i < tamanyVector; i++) {
            int b = rand() % (INT_MAX);
            aVector[i] = b;
        }

        for(int x = tamanyVector - 1; x >= 0; x--) {
            vector<int> bVector = aVector;
            int valorsOrdenats = x;
            
            sort(bVector.begin(), bVector.begin() + valorsOrdenats);

            int entrop = entropia(bVector);

            quickSort(bVector, 0, tamanyVector);
            cout << entrop << ' ' << contadorQuick << endl;
            contadorQuick = 0;
        }
    }
}