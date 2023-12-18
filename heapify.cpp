#include <iostream>
#include <vector>

using namespace std;

void swap(vector <int> &heap , int a , int b){

    heap[a] = heap[a] + heap[b];
    heap[b] = heap[a] - heap[b];
    heap[a] = heap[a] - heap[b];

}

void heapifyCore(vector<int> &heap , int i ){

    int l = 2*i +1;
    int r = 2*i +2;
    int largest = i;
    int s = heap.size();

    if(l < s){
        if(heap[l] < heap[i]){
            largest = i ;
        }
        else{
            largest = l ;
        }
    }
    
    if(r < s && heap[largest] < heap[r]){
        largest = r ;
    }

    if(largest != i){
        swap(heap , largest , i);
        heapifyCore(heap , largest);
    }

    return ;

}

void heapify(vector<int> &heap){

    for(int i = heap.size() ; i >= 0 ; i--){
        heapifyCore(heap , i);
    }

    return ;

}

int main(){

    vector<int> heap = {2,1,7,9,3,6,5,12};

    heapify(heap);

    for(int i = 0 ; i < heap.size() ; i++){
        cout << heap[i] << " " ; 
    }
}