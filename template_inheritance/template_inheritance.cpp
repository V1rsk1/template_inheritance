#include <iostream>
#include <string>

using namespace std;

template <typename T1, typename T2>
class Base {
protected:
    T1 value1;
    T2 value2;

public:
    Base() : value1(0), value2(0) {}
    Base(T1 v1, T2 v2) : value1(v1), value2(v2) {}

    virtual ~Base() {}

    void setValue1(T1 v1) { value1 = v1; }
    void setValue2(T2 v2) { value2 = v2; }

    T1 getValue1() const { return value1; }
    T2 getValue2() const { return value2; }

    virtual void print() const {
        cout << "Базові значення: " << value1 << ", " << value2 << endl;
    }
};

template <typename T1, typename T2, typename T3, typename T4>
class Child : public Base<T1, T2> {
protected:
    T3 value3;
    T4 value4;

public:
    Child() : Base<T1, T2>(), value3(), value4() {}
    Child(T1 v1, T2 v2, T3 v3, T4 v4) : Base<T1, T2>(v1, v2), value3(v3), value4(v4) {}

    void setValue3(T3 v3) { value3 = v3; }
    void setValue4(T4 v4) { value4 = v4; }

    T3 getValue3() const { return value3; }
    T4 getValue4() const { return value4; }

    void print() const override {
        Base<T1, T2>::print();
        cout << "Значення нащадка: " << value3 << ", " << value4 << endl;
    }
};

template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
class Child2 : public Child<T1, T2, T3, T4> {
private:
    T5 value5;
    T6 value6;

public:
    Child2() : Child<T1, T2, T3, T4>(), value5(), value6() {}
    Child2(T1 v1, T2 v2, T3 v3, T4 v4, T5 v5, T6 v6)
        : Child<T1, T2, T3, T4>(v1, v2, v3, v4), value5(v5), value6(v6) {}

    void setValue5(T5 v5) { value5 = v5; }
    void setValue6(T6 v6) { value6 = v6; }

    T5 getValue5() const { return value5; }
    T6 getValue6() const { return value6; }

    void print() const override {
        Child<T1, T2, T3, T4>::print();
        cout << "Значення нащадка 2: " << value5 << ", " << value6 << endl;
    }
};

int main() {
    Base<int, double> base(5, 10.5);
    base.print();

    Child<int, double, string, char> child(1, 2.5, "Привіт", 'C');
    child.print();

    Child2<int, double, string, char, bool, float> child2(10, 20.5, "Світ", 'A', true, 3.14);
    child2.print();

    return 0;
}
