#include <iostream>

class vectorClass {
private:
  int *arr;
  int capacity;
  int current;

public:
  vectorClass() {
    // class for capacity of 1 element
    arr = new int[1];
    capacity = 1;
    current = 0;
  }

  // add an element
  void push(int data) {
    // if the number of elements is equal to the capacity
    if (current == capacity) {
      int *temp = new int[2 * capacity];

      // copying old array elements to new array
      for (int i = 0; i < capacity; i++) {
        temp[i] = arr[i];
      }

      // deleting previous array
      delete[] arr;
      capacity *= 2;
      arr = temp;
    }

    // Inserting data
    arr[current] = data;
    current++;
  }

  // function to add element at any index
  void push(int data, int index) {

    if (index == capacity)
      push(data);
    else
      arr[index] = data;
  }

  int get(int index) {

    if (index < current)
      return arr[index];
  }

  void pop() { current--; }

  // function to get size of the vector
  int size() { return current; }

  // function to get capacity of the vector
  int getcapacity() { return capacity; }

  // function to print array elements
  void print() {
    for (int i = 0; i < current; i++) {
      std::cout << arr[i] << " ";
    }
  }
};

int main() {
  vectorClass v;

  return 0;
}
