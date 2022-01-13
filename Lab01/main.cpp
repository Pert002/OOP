#include<iostream>
#include<cmath> 
#include<stdexcept>
using namespace std;

class TransNumber {
private:
    double a;
    double b;
public:
    TransNumber(double lhs, double rhs); //
    TransNumber(); 
    TransNumber sum(TransNumber const rhs);
    TransNumber sub(TransNumber const rhs);
    TransNumber mul(TransNumber const rhs);
    TransNumber div(TransNumber const rhs);
    TransNumber conj() const;
    const char * equ(TransNumber const rhs); 
    void write(std::ostream &out);
    void read(std::istream &in);
    friend void record(TransNumber &lhs, TransNumber &rhs);
}; 

TransNumber::TransNumber(double lhs, double rhs) {
    a = lhs;
    b = rhs;
}

TransNumber::TransNumber() {
    a=b=0;
}


TransNumber TransNumber::sum(TransNumber const rhs){
    TransNumber c;
    c.a = a + rhs.a;
    c.b = b + rhs.b;
    return c;
}

TransNumber TransNumber::mul(TransNumber const rhs){
    TransNumber c;
    c.a = a*rhs.a + 2*b*rhs.b;
    c.b = a*rhs.b + b*rhs.a;
    return c;
}

TransNumber TransNumber::div(TransNumber const rhs){
    TransNumber c;
    if (rhs.b == 0 && rhs.a == 0){
        throw overflow_error("The second number must not be zero");
    }
    c.a = (a*rhs.a - 2*b*rhs.b) / (pow(rhs.a,2) - 2*pow(rhs.b,2));
    c.b = (b*rhs.a - a*rhs.b) / (pow(rhs.a,2) - 2*pow(rhs.b,2));
    return c;
}


TransNumber TransNumber::sub(TransNumber const rhs){
    TransNumber c;
    c.a = a - rhs.a;
    c.b = (b - rhs.b);
    return c;
}


TransNumber TransNumber::conj() const {
    TransNumber c;
    c.a = a;
    c.b = -b;
    return c;
}

const char * TransNumber::equ(TransNumber const rhs) {
    double eps = 0.0000001;
    if(a+sqrt(2)*b > rhs.a+sqrt(2)*rhs.b)
        return "More than";
    else if (a+sqrt(2)*b < rhs.a+sqrt(2)*rhs.b)
        return "Less than";
    else
        return "Equal";
}


void TransNumber::write(std::ostream &out) {
    out << a << " + " << "(" << b << ")*sqrt(2)" << std::endl;
}

void TransNumber::read(std::istream &in) {
    in >> a >> b;
}

void record(TransNumber &lhs, TransNumber &rhs) {
    std::cout << "Enter a couple of numbers for the first number:" << std::endl;
    lhs.read(std::cin);
    std::cout << "Enter the second number" << std::endl;
    rhs.read(std::cin);
}





int main() {
    TransNumber ob1, ob2;
    int option = 7;
    bool check = true;

    std::cout << "Transcendental Number Program" << std::endl;

    while(check) {

            switch(option) {
                case 0:
                    check = false;
                    break;
                case 1:
                    record(ob1, ob2);
                    ob1.sum(ob2).write(std::cout);
                    break;
                case 2:
                    record(ob1, ob2);
                    ob1.sub(ob2).write(std::cout);
                    break;
                case 3:
                    record(ob1, ob2);
                    ob1.mul(ob2).write(std::cout);
                    break;
                case 4:
                    record(ob1, ob2);
                    ob1.div(ob2).write(std::cout);
                    break;
                case 5:
                    std::cout << "Enter a couple of numbers:" << std::endl;
                    ob1.read(std::cin);
                    ob1.conj().write(std::cout);
                    break;
                case 6:
                    record(ob1, ob2);
                    ob1.write(std::cout);
                    std::cout << ob1.equ(ob2) << std::endl;
                    ob2.write(std::cout);
                    break;
                case 7:
                    std::cout << "Enter a number for action:" << std::endl;
                    std::cout << "1) Add two numbers" <<
                    std::endl << "2) Subtraction" <<
                    std::endl << "3) Multiplication" <<
                    std::endl << "4) Division" <<
                    std::endl << "5) Conjugate number" <<
                    std::endl << "6) Value Comparison" <<
                    std::endl << "7) Print Menu" <<
                    std::endl << "0) Exit" << std::endl;
                    break;
            }
            if(check){
                std::cout << "Enter a number for action:" << std::endl;
                std::cin >> option;
            }
    }
    return 0;
}