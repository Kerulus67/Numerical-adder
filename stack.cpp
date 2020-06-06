#include "stack.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include <cstring>
#include <assert.h>
#include "stack.h"
using namespace std;


Stack::Stack()
{
topIndex = -1;
}

void Stack::push(const StackElementType & item)
{
    assert(topIndex < maxStackSize);
    topIndex++;
    stackArray[topIndex] = item;
}

StackElementType Stack::pop()
{
    assert(topIndex >= 0);
    int returnIndex = topIndex;
    topIndex--;
    return stackArray[returnIndex];
}

StackElementType Stack::top()
{
   // ensure array bounds not exceeded
   assert(topIndex >= 0);
   return stackArray[topIndex];
}
bool Stack::isEmpty()
{
    return bool(topIndex == -1);
}
