#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int InterSearch(vector<int> arr, int low, int high, int x){
    int pos;
    if(low <= high && x >= arr[low] && x <= arr[high]) {
        pos = low + (((double)(high - low) / (arr[high] - arr[low])) * (x- arr[low]));
    }
    if (arr[pos] == x) {
        return pos;
    }
    if (arr[pos] < x) {
        InterSearch(arr, pos + 1, high, x);
    }
    if (arr[pos] > x) {
        InterSearch(arr, low, pos - 1, x);
    }
    return -1;
}


int main (){
    system ("cls");
    vector<int> arr = {12, 35, 49, 102, 187};
    int x;
    int jumlah = arr.size();
    cout << "Jumlah kursi yang tersedia: " << jumlah << endl;
    cout << "Nomor kursi yang tersedia: ";
    for (int i : arr){
        cout << i << " ";
    }
    cout << "\nMasukkan nomor kursi: "; cin >> x;
    sort(arr.begin(), arr.end()); 
    int index = InterSearch(arr, 0, arr.size() - 1, x);
    if (index == -1) {
        cout << "Status: TIDAK TERSEDIA";
        cout << "\nOpsi: Kursi terdekat yang tersedia adalah no-";
    }
    else {
        cout << "Status: TERSEDIA" << endl;
        cout << "Detail: Ditemukan pada index-" << index;
    }
}