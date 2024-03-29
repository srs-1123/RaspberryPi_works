#include <iostream>
#include <string>
#include "bird.h"
#include "chicken.h"
#include "crow.h"
 
using namespace std;
 
int main(){
    CBird* b1, *b2;
    b1 = new CCrow();
    b2 = new CChicken();
    b1->sing();
    b1->fly();
    b2->sing();
    b2->fly();
    return 0;
}