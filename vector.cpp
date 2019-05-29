#include <iostream>
#include "vector.h"
#include "string"

int main(){
    Vector<int> test;
    printf("*****first test*****\n");
    printf("test 1 - push back 9 elements, pop back one, print the 8th element\n");
    printf("capacity before test: %d, size before test: %d\n",test.capacity(),test.size());
    test.push_back(6);
    test.push_back(5);
    test.push_back(4);
    test.push_back(3);
    test.push_back(2);
    test.push_back(2);
    test.push_back(2);
    test.push_back(2);
    test.push_back(2);
    test.pop_back();
    printf("8th element of 1st vector - %d\n",test[7]);
    printf("capacity after test: %d, size after test: %d\n",test.capacity(),test.size());
    printf("*****second test*****\n");
    Vector<int>test2;
    printf("2nd test - reserve space for 8 elements, push back 6 elements, shrink_to_fit vector and then clear it\n");
    printf("capacity before reserve: %d,size before reserve: %d\n",test2.capacity(),test2.size());
    test2.reserve(8);
    printf("capacity after reserve: %d, size after reserve: %d\n",test2.capacity(),test2.size());
    test2.push_back(1);
    test2.push_back(2);
    test2.push_back(3);
    test2.push_back(4);
    test2.push_back(5);
    test2.push_back(6);
    printf("capacity before shrink_to_fit: %d, size before shrink_to_fit: %d\n",test2.capacity(),test2.size());
    test2.shrink_to_fit();
    printf("capacity after shrink_to_fit: %d, size after shrink_to_fit: %d\n",test2.capacity(),test2.size());
    test2.clear();
    printf("capacity after clear: %d, size after clear: %d\n",test2.capacity(),test2.size());
    printf("*****third test*****\n");
    printf("3rd test - create one vector (push_back 4 elements) by using default constructor, other by initializer list (6 elements),"
           " swap the vectors, resize the second vector to size 6, check if vectors are equal, erase the second second vector \n");
    Vector<int>test3;
    test3.push_back(7);
    test3.push_back(8);
    test3.push_back(9);
    test3.push_back(10);
    Vector<int>test4{1,2,3,4,5,6};
    printf("capacity of 1st vector before swap: %d,size of 1st vector before swap: %d, capacity of 2nd vector before swap: %d,       size of 2nd vector before swap: %d\n",test3.capacity(),test3.size(),test4.capacity(),test4.size());
    test3.swap(test4);
    printf("capacity of 1st vector after swap: %d,size of 1st vector after swap: %d, capacity of 2nd vector after swap: %d,       size of 2nd vector after swap: %d\n",test3.capacity(),test3.size(),test4.capacity(),test4.size());
    test4.resize(6);
    printf("capacity of 1st vector after resize: %d,size of 1st vector after resize: %d, capacity of 2nd vector after resize: %d,       size of 2nd vector after resize: %d\n",test3.capacity(),test3.size(),test4.capacity(),test4.size());
    (test3==test4)?printf("vectors are equal\n"):
    printf("vectors are not equal\n");
    int* it=&test4[1];
    test4.erase(it);
    printf("capacity of 2nd vector after erase: %d, size of 2nd vector after erase: %d\n",test4.capacity(), test4.size());

    return 0;
}