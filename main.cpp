#include <iostream>
#include <math.h>
#include <cstdint>

using namespace std;

class Power {
    double number, power;
public:
    void set(double num, double pow) {
        number = num;
        power = pow;
    }

    void calculate(double n = 2, double p = 5) {
        cout << pow(n, p) << endl;
    }
};

class RGBA {
    uint8_t m_red = 0, m_green = 0, m_blue = 0, m_alpha = 255;
public:
    RGBA(uint8_t r, uint8_t g, uint8_t b, uint8_t a) : m_red(r), m_green(g), m_blue(b), m_alpha(a) {
    }

    void print() {
        cout << "Red = " << +m_red << " Green = " << +m_green
             << " Blue = " << +m_blue << " Alpha = " << +m_alpha << endl;
    }
};

class Stack {
    int arr[10];
    int size = 0;
public:
    void reset() {
        size = 0;
        for (int i = 0; i < 10; ++i) {
            arr[i] = 0;
        }
    }

    bool push(int number) {
        if (size == 10) {
            cout << "Stack overflow" << endl;
            return false;
        }
        arr[size++] = number;
        return true;
    }

    int pop() {
        if (!size)
            cout << "Stack is empty" << endl;
        int tmp = arr[size - 1];
        size--;
        return tmp;
    }

    void print() {
        cout << "( ";
        if (size) {
            for (int i = 0; i < size; ++i) {
                cout << arr[i] << " ";
            }
        }

        cout << ")" << endl;
    }
};

int main() {
    Power p;
    p.set(3, 3);
    p.calculate();

    RGBA rgba(78, 45, 5, 200);
    rgba.print();

    Stack stack;
    stack.reset();
    stack.print();

    stack.push(3);
    stack.push(6);
    stack.push(5);
    stack.print();

    stack.pop();
    stack.print();

    stack.pop();
    stack.pop();
    stack.print();
    return 0;
}
