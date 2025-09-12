// Max Heap Implementation
// Insert operation with heapify up

#include <bits/stdc++.h>
using namespace std;

class Heap {
    vector<int> data;
    int size;
    
public:
    Heap() {
        size = 0;
    }
    
    void insert(int val) {
        // Push the value
        data.push_back(val);
        size++;
        
        // Adjust the value (heapify up)
        int current = size - 1;
        while(current > 0) {
            int parent = (current - 1) / 2;
            if(data[parent] < data[current]) {
                swap(data[parent], data[current]);
                current = parent;
            } else {
                break;
            }
        }
    }
    
    void print() {
        for(int i = 0; i < size; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Heap h;
    h.insert(10);
    h.insert(20);
    h.print();
    return 0;
}
