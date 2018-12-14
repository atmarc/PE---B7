#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

long long int contadorMerge = 0;
long long int contadorQuick = 0;
long long int contadorBubble = 0;

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

void merge(vector<int>& v, int left, int mid, int right) {
    int n = right - left + 1;
    vector<int> aux(n);
    int i = left;
    int j = mid + 1;
    int k = 0;
    while (i <= mid and j <= right) {
        if (v[i] <= v[j]) {
            aux[k] = v[i];
            ++i;
        }
        else {
            aux[k] = v[j];
            ++j;
        }
        ++k;
    }
    while (i <= mid) {
        aux[k] = v[i];
        ++k;
        ++i;
    }
    while (j <= right) {
        aux[k] = v[j];
        ++k;
        ++j;
    }
    for (k = 0; k < n; ++k) v[left+k] = aux[k];
}
void merge_sort(vector<int>& v, int left, int right) {
    ++contadorMerge;
    if (left < right) {
        int m = (left + right)/2;
        merge_sort(v, left, m);
        merge_sort(v, m + 1, right);
        merge(v, left, m, right);
    }
}

void bubbleSort(vector<int>& a) {
      bool swapp = true;
      while(swapp){
        swapp = false;
        for (size_t i = 0; i < a.size()-1; i++) {
            if (a[i]>a[i+1] ){
                ++contadorBubble;
                a[i] += a[i+1];
                a[i+1] = a[i] - a[i+1];
                a[i] -=a[i+1];
                swapp = true;
            }
        }
    }
}

int main () { 
    int tamanyVector, n;
    cout << "Tamany del vector: ";
    cin >> tamanyVector;
    cout << "Nombre de vegades: ";
    cin >> n;
    
    for (int z = 0; z < n; ++z) {
        vector<int> aVector(tamanyVector);
        srand(time(NULL));
        for (int i = 0; i < tamanyVector; i++) {
            int b = rand() % (1000);
            //cout << b << ' ';
            aVector[i] = b;
        }

        for(int x = 0; x < tamanyVector; x++) {
            vector<int> bVector = aVector;
            int valorsOrdenats = x;
            
            merge_sort(bVector, 0, valorsOrdenats);

            //for (int i = 0; i < bVector.size(); ++i) cout << bVector[i] << ' ';
            //cout << endl;
            long long int entrop = entropia(bVector);
            //cout << "Entropia: " << entrop << endl << endl;

            quickSort(bVector, 0, bVector.size());
            //cout << "Crides quick: " << contadorQuick << endl;
            cout << entrop << ' ' << contadorQuick << endl;
            contadorQuick = 0;
            
            //cout << endl << "---------------" << endl;
        }
    }
}