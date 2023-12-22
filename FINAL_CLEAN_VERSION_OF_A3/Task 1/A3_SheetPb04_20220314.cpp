//File: A3_SheetPb4_20220314.cpp
//Purpose:Template – Set.
//Author: Mahmoud Gomaa Rabea
//Section:S17,18
//ID:20220314
//TA: Rana Abd-Elkader
//Date:9 Dec 2023

//#include <iostream>
//
//using namespace std;
//
//template <typename T>
//class Set {
//private:
//    T* items;    // Array to store items
//    int capacity; // Capacity of the array
//    int size;     // Current size of the set
//
//public:
//    // Constructor
//    Set(int initialCapacity = 10);
//
//    // Destructor
//    ~Set();
//
//    // Add a new item to the set
//    void add(const T& item);
//
//    // Remove an item from the set
//    void remove(const T& item);
//
//    // Return the number of items in the set
//    int getSize() const;
//
//    // Determine if an item is a member of the set
//    bool contains(const T& item) const;
//
//    // Return a dynamically created array containing each item in the set
//    T* toArray() const;
//};
//
//// Constructor
//template <typename T>
//Set<T>::Set(int initialCapacity) : capacity(initialCapacity), size(0) {
//    items = new T[capacity];
//}
//
//// Destructor
//template <typename T>
//Set<T>::~Set() {
//    delete[] items;
//}
//
//// Add a new item to the set
//template <typename T>
//void Set<T>::add(const T& item) {
//    if (!contains(item)) {
//        if (size == capacity) {
//            // If the array is full, double the capacity
//            capacity *= 2;
//            T* newArray = new T[capacity];
//            for (int i = 0; i < size; ++i) {
//                newArray[i] = items[i];
//            }
//            delete[] items;
//            items = newArray;
//        }
//
//        // Add the new item to the set
//        items[size++] = item;
//    }
//}
//
//// Remove an item from the set
//template <typename T>
//void Set<T>::remove(const T& item) {
//    for (int i = 0; i < size; ++i) {
//        if (items[i] == item) {
//            // Shift elements to fill the gap
//            for (int j = i; j < size - 1; ++j) {
//                items[j] = items[j + 1];
//            }
//            --size;
//            break;
//        }
//    }
//}
//
//// Return the number of items in the set
//template <typename T>
//int Set<T>::getSize() const {
//    return size;
//}
//
//// Determine if an item is a member of the set
//template <typename T>
//bool Set<T>::contains(const T& item) const {
//    for (int i = 0; i < size; ++i) {
//        if (items[i] == item) {
//            return true;
//        }
//    }
//    return false;
//}
//
//// Return a dynamically created array containing each item in the set
//template <typename T>
//T* Set<T>::toArray() const {
//    T* arrayCopy = new T[size];
//    for (int i = 0; i < size; ++i) {
//        arrayCopy[i] = items[i];
//    }
//    return arrayCopy;
//}
//
//// Example usage
//int main() {
//    // Create a set of integers
//    Set<int> intSet;
//    intSet.add(1);
//    intSet.add(2);
//    intSet.add(3);
//
//    // Print the size of the set
//    cout << "Size of intSet: " << intSet.getSize() << endl;
//
//    // Check if 2 is in the set
//    cout << "Is 2 in intSet? " << (intSet.contains(2) ? "Yes" : "No") << endl;
//
//    // Remove 2 from the set
//    intSet.remove(2);
//
//    // Print the updated size of the set
//    cout << "Updated size of intSet: " << intSet.getSize() << endl;
//
//    // Create a set of strings
//    Set<string> stringSet;
//    stringSet.add("anyThing");
//    stringSet.add("Alahly");
//    stringSet.add("FCAI");
//
//    // Print the size of the set
//    cout << "Size of stringSet: " << stringSet.getSize() << endl;
//
//    // Check if "egypt" is in the set
//    cout << "Is 'egypt' in stringSet? " << (stringSet.contains("egypt") ? "Yes" : "No") << endl;
//    // Check if "Alahly" is in the set
//    cout << "Is 'Alahly' in stringSet? " << (stringSet.contains("Alahly") ? "Yes" : "No") << endl;
//
//
//    return 0;
//}
