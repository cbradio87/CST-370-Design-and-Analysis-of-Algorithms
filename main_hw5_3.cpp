/*
 * Title: main_hw5_3.cpp
 * Abstract: This program takes in insertions displays a status and returns the required val
 * Author: Christopher Bray
 * ID: 8280
 * Date: 4/12/2022
 */

#include<iostream>
using namespace std;

int nextPrime(int n){
    int start = n + 1;
    while(true){
        bool okay = true;
        for(int i = 2; i * i <= start ; i = i + 1){
            if(start % i == 0){
                okay = false;
                break;
            }
        }
        if(okay)
            return start;
        start = start + 1;
    }
}
int main(){
    int size;
    cin >> size;
    int* keys = new int[size];
    bool* status = new bool[size]();
    bool* deleted = new bool[size]();
    int insertedElements = 0;
    int n;
    cin >> n;
    while(n--){
        string s;
        cin >> s;
        if(s == "insert"){
            int key;
            cin >> key;
            insertedElements = insertedElements + 1;
            double loadFactor = ((double)(insertedElements)) / size;
            if(loadFactor > 0.5){
                int newSize = nextPrime(2 * size);
                int* newKeys = new int[newSize];
                bool* newStatus = new bool[newSize]();
                for(int i = 0; i < size; i = i + 1){
                    if(status[i]){
                        int index = keys[i] % newSize;
                        while(newStatus[index]){
                            index = (index + 1) % newSize;
                        }
                        newStatus[index] = true;
                        newKeys[index] = keys[i];
                    }
                }
                keys = newKeys;
                status = newStatus;
                size = newSize;
                deleted = new bool[size]();
            }
            int index = key % size;
            while(status[index]){
                index = (index + 1) % size;
            }
            status[index] = true;
            keys[index] = key;
            deleted[index] = false;
            }
            else if(s == "displayStatus"){
                int index;
                cin >> index;
                if(deleted[index]){
                    continue;
                }
                else if(status[index]){
                cout << keys[index] << endl;
                }
                else{
                    cout << "Empty" << endl;
                }
            }
            else if(s == "tableSize"){
                cout << size << endl;
            }
            else if(s == "search"){
                int key;
                cin >> key;
                int start = key % size;
                int curr = key % size;
                do{
                    if(status[curr] && keys[curr] == key){
                        cout << key <<" Found" << endl;
                        break;
                    }
                    curr = (curr + 1) % size;
                }
                while(start != curr);
                if(keys[curr] != key){
                cout << key << " Not found" << endl;
            }
        }
        else if(s == "delete"){
            int key;
            cin >> key;
            int start = key % size;
            int curr = key % size;
            do{
                if(status[curr] && keys[curr] == key){
                    status[curr] = false;
                    insertedElements = insertedElements - 1;
                    deleted[curr] = true;
                    break;
                }
                curr = (curr + 1) % size;
            }
        while(start != curr);
            cout << key << " Deleted" << endl;
        }
    }
}


