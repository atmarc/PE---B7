#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <ctime>

using namespace std;

int partition(vector<int> & a, int start, int end) {
    unsigned int pivot = a[start];
    unsigned int from_left = start+1;
    unsigned int from_right = end;
    unsigned int tmp;

    while (from_left != from_right) {
        if (a[from_left]  <= pivot) from_left++;
        else {
            while (( from_left != from_right)  && (pivot < a[from_right])) from_right--;
            //cout << "swaping " << a[from_left] << " with "<< a[from_right] << endl;
            tmp =  a[from_right];
            a[from_right] = a[from_left];
            a[from_left] = tmp;
        }
    }

    if (a[from_left]>pivot) from_left--;
    a[start] = a[from_left];
    a[from_left] = pivot;

    //cout << "Vector after partition:   ";
    //print (a,start,end);
    //cout << endl;

    return (from_left);
}


int quickSort(vector <int> & a, int p, int r) {
    if (p < r) {
        int q = partition(a, p, r);
        return 2 + quickSort(a, p, q - 1) + quickSort(a, q + 1, r);
    }
    return 1;
}

int entropia (vector <int> vector) {
    int result = 0;
    for (int p = 0; p < vector.size(); p++) {
        int i = p + 1;
        while(i < vector.size()) {
            if(vector[p] > vector[i]) result ++;
            ++i;
        }
    }
    return result;
}

void merge(vector<int>& v, int left, int mid, int right) {
    int n = right - left + 1;
    vector<int> aux(n); //3,2,1,1 -> 10 amb el merge
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
int merge_sort(vector<int>& v, int left, int right) {
    if (left < right) {
        int m = (left + right)/2;
        int p = merge_sort(v, left, m) + merge_sort(v, m + 1, right);
        merge(v, left, m, right);
        return 2 + p;
    }
    return 1;
}


int main() {
    int n;
    cin >> n;
    for(int x = 0; x < n; x++) {
        vector<int> aVector;
        srand(time(NULL));
        for (int i = 0; i < 10000; i++) {
            int b = rand() % (7 + x);
            aVector.push_back(b);
        }

        long long int entrop = entropia(aVector);
        cout << entrop << endl;
        vector<int> bVector = aVector;

        int resultat_a = merge_sort(aVector, 0, aVector.size() - 1);
        cout << resultat_a << endl;

        int resultat_b = quickSort(bVector, 0, bVector.size());
        cout << resultat_b <<endl;
        cout << endl << endl << endl;
    }
}