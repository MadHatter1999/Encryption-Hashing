#include <iostream>
#include "LinkedList.h"
using namespace std;
int main() {
    LinkedList x=LinkedList("hi");
    x.add("test");
    x.add("yo");
    x.printAll(x.root);
    return 0;
}