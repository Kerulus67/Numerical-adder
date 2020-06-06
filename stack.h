#ifndef _STACK_H_ // #ifndef – it stands for “if not defined”
#define _STACK_H_
#include <fstream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

const int maxStackSize = 1000;
typedef int StackElementType;

class Stack {
public:
Stack();
void push(const StackElementType & item);
StackElementType pop();
StackElementType top();
bool isEmpty();
private:
StackElementType stackArray[maxStackSize];
int topIndex;
};

#endif // #ifndef _FILE_NAME_H_
