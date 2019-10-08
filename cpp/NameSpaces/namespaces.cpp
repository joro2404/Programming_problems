#include <iostream>
using namespace std;

namespace firstSpace{

    void say_hello(){

        cout << "Hello from frist namespace" << endl;
    }
};

namespace secondSpace {

    void say_hello() {

        cout << "Hello from namespace" << endl;
    }
};

using namespace firstSpace;

int main() {

    say_hello();
}