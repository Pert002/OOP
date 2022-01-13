#include <iostream>
#include <cmath>

class Position {
    private:
        double latitude;
        double longitude;
    public:
    Position(double lhs, double rhs) : latitude(lhs), longitude(rhs) {};
    Position() : latitude(0), longitude(0) {};
    Position Check(Position const ob);
    Position operator+(Position const rhs);
    Position operator=(Position const rhs);
    Position operator-(Position const rhs);
    Position operator*(int n);
    Position operator/(int n);
    bool operator==(Position const rhs);
    bool operator!=(Position const rhs);
    friend std::ostream &operator<<(std::ostream &out, Position const &ob);
    friend std::istream &operator>>(std::istream &in, Position &ob);
};

Position Position::Check(Position const ob) {
    Position c;
    double a;
    double b;
    a = fmod(ob.latitude,360);
    if (a > 180){
        a = -180 + (fmod(a,180));
    } else if(a < -180){
        a = 180 + (fmod(a,180));
    }
    c.latitude = a;
    b = fmod(ob.longitude,180);
    if (b > 90){
        b = -90 + (fmod(b,90));
    } else if (b < -90){
        b = 90 + (fmod(b,90));
    }
    c.longitude = b;
    return c;
}

Position Position::operator+(Position  const rhs) {
    Position c;
    c.latitude = latitude + rhs.latitude;
    c.longitude = longitude + rhs.longitude;

    return Check(c);
}

Position Position::operator-(Position const rhs) {
    Position c;
    c.latitude = latitude - rhs.latitude;
    c.longitude = longitude - rhs.longitude;

    return Check(c);
}

Position Position::operator*(int n) {
    Position c;
    c.latitude = latitude * n;
    c.longitude = longitude * n;

    return Check(c);
}

Position Position::operator/(int n) {
    Position c;
    c.latitude = latitude / n;
    c.longitude = longitude / n;

    return Check(c);
}
Position Position::operator=(Position  const rhs) {
    latitude = rhs.latitude;
    longitude = rhs.longitude;

    return *this;
}

bool Position::operator==(Position  const rhs) {
    return ((latitude == rhs.latitude) && (longitude == rhs.longitude));
}

bool Position::operator!=(Position const rhs) {
    return ((latitude!=rhs.latitude) || (longitude!=rhs.longitude));
}

std::ostream &operator<<(std::ostream &out, Position const &ob){
    out.precision(6);
    out.setf(std::ios::fixed);
    out << "latitude: " <<ob.latitude << " longitute: " << ob.longitude << "\n";
    out.unsetf(std::ios::fixed);

    return out;
}

std::istream &operator>>(std::istream &in, Position &ob){
    in >> ob.latitude >> ob.longitude;
    return in;
}


long double operator "" _lat(long double a){
    a = fmod(a,360);
    if (a > 180){
        a = -180 + fmod(a,180);
    } else if(a < -180){
        a = 180 + fmod(a,180);
    }
    return a;
}

long double operator "" _lon(long double a){
    a = fmod(a,360);
    if (a > 90){
        a = -90 + fmod(a,90);
    } else if(a < -90){
        a = 90 + fmod(a,90);
    }
    return a;
}



int main() {
    std::cout << "Hello, World!" << std::endl;
    std::cout << 253.21_lat << " " << 94.21_lon << std::endl; // приводим в порядок широту и долготу
    Position ob1, ob2;
    double n;
    int option = 7;
    bool check = true;

    std::cout << "Work with coordinates" << std::endl;

    while(check) {

        switch(option) {
            case 0: check = false; break;
            case 1:
                std::cout << "Enter the coordinates of the first point separated by space" << std::endl;
                std::cin >> ob1;
                std::cout << "Enter the coordinates of the second point separated by space" << std::endl;
                std::cin >> ob2;
                std::cout << "ob1 + ob2:\n" << ob1 + ob2;
                break;
            case 2:
                std::cout << "Enter the coordinates of the first point separated by space" << std::endl;
                std::cin >> ob1;
                std::cout << "Enter the coordinates of the second point separated by space" << std::endl;
                std::cin >> ob2;
                std::cout << "ob1 - ob2:\n" << ob1 - ob2;
                break;
            case 3:
                std::cout << "Enter number" << std::endl;
                std::cin >> n;
                std::cout << "Enter coordinates separated by space" << std::endl;
                std::cin >> ob1;
                std::cout << "Result: ";
                std::cout << ob1 * n;
                break;
            case 4:
                std::cout << "Enter number" << std::endl;
                std::cin >> n;
                try{
                    if (n==0) throw 0;
                } catch(int){
                    std::cout << "The number must not be zero" << std::endl;
                    std::cout << "Enter n not equal to zero" << std::endl;
                    std::cin >> n;
                }
                std::cout << "Enter coordinates separated by space" << std::endl;
                std::cin >> ob1;
                std::cout << "Result: ";
                std::cout << ob1 / n;
                break;
            case 5:
                std::cout << "Enter the coordinates of the first point separated by space" << std::endl;
                std::cin >> ob1;
                std::cout << "Enter the coordinates of the second point separated by space" << std::endl;
                std::cin >> ob2;
                if (ob1 == ob2) std::cout << "Сoordinates match\n";
                else std::cout << "Сoordinates do not match\n";
            case 6:
                std::cin >> ob1 >> ob2;
                if (ob1 != ob2) std::cout << "Сoordinates do not match\n";
                else std::cout << "Сoordinates match\n";
            case 7:
                std::cout << "Enter a number for action:" << std::endl;
                std::cout << "1) Addition of coordinates" <<
                std::endl << "2) Coordinate difference" <<
                std::endl << "3) Multiplication" <<
                std::endl << "4) Division" <<
                std::endl << "5) Equality test" <<
                std::endl << "6) NotEquality test" <<
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