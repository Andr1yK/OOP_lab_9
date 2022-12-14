#include <iostream>
#include <map>

using namespace std;

class B {
  private:
    int b;
    const string name;

  public:
    explicit B(int x = 0): b(x), name(__func__){};

    void show_B() const {
      cout << "class " << this->name << ":" << endl;
      cout << __FUNCTION__ << endl
           << this->name << "::b = " << b << endl << endl;
    }
};

class D1: public B  {
  private:
    int d1;
    const string name;

  public:
    explicit D1(int x = 0, int y = 0):  B(y), d1(x), name(__func__){};

    void show_D1() const {
      cout << "class " << this->name << ":" << endl;
      show_B();
      cout << __FUNCTION__ << endl
           << this->name << "::d1 = " << d1 << endl << endl;
    }
};

class D2: private B  {
  private:
    int d2;
    const string name;

  public:
    explicit D2(int x = 0, int y = 0):  B(y), d2(x), name(__func__){};

    void show_D2() const {
      cout << "class " << this->name << ":" << endl;
      show_B();
      cout << __FUNCTION__ << endl
           << this->name << "::d2 = " << d2 << endl << endl;
    }
};

class D3: private B  {
  private:
    int d3;
    const string name;

  public:
    explicit D3(int x = 0, int y = 0):  B(y), d3(x), name(__func__){};

    void show_D3() const {
      cout << "class " << this->name << ":" << endl;
      show_B();
      cout << __FUNCTION__ << endl
           << this->name << "::d3 = " << d3 << endl << endl;
    }
};

class D4: private D1  {
  private:
    int d4;
    const string name;

  public:
    explicit D4(int x = 0, int y = 0, int z = 0):  D1(y, z),  d4(x), name(__func__){};

    void show_D4() const {
      cout << "class " << this->name << ":" << endl;
      show_D1();
      cout << __FUNCTION__ << endl
           << this->name << "::d4 = " << d4 << endl << endl;
    }
};

class D5: public D1, D2, private D3 {
  private:
    int d5;
    const string name;

  public:
    explicit D5(int x = 0, int y = 0, int z = 0, int a = 0, int b = 0, int c = 0, int d = 0)
      : D1(y, z),
        D2(a, b),
        D3(c, d),
        d5(x),
        name(__func__) {};

    void show_D5() const {
      cout << "class " << this->name << ":" << endl;
      show_D1();
      show_D2();
      show_D3();
      cout << __FUNCTION__ << endl
           << this->name << "::d5 = " << d5 << endl << endl;
    }
};

class Hack {
  public:
    int b;
};

int main() {
  B o0(777);
  cout << "B o0(777);" << endl;
  cout << "sizeof(B) = " << sizeof(B) << endl;
  cout << endl << "Ієрархія класу B: " << endl;
  o0.show_B();

  D1 o1(111, 222);
  cout << "D1 o1(111, 222);" << endl;
  cout << "sizeof(D1) = " << sizeof(D1) << endl;
  cout << endl << "Ієрархія класу D1: " << endl;
  o1.show_D1();

  D2 o2(1000, 2000);
  cout << "D2 o2(1000, 2000);" << endl;
  cout << "sizeof(D2) = " << sizeof(D2) << endl;
  cout << endl << "Ієрархія класу D2: " << endl;
  o2.show_D2();

  D3 o3(1001, 2002);
  cout << "D3 o3(1001, 2002);" << endl;
  cout << "sizeof(D3) = " << sizeof(D2) << endl;
  cout << endl << "Ієрархія класу D3: " << endl;
  o3.show_D3();

  D4 o4(1, 2, 3);
  cout << "D4 o4(1, 2, 3, 4, 5);" << endl;
  cout << "sizeof(D4) = " << sizeof(D4) << endl;
  cout << endl << "Ієрархія класу D4: " << endl;
  o4.show_D4();

  D5 o5(1, 2, 3, 4, 5, 6, 7);
  cout << "D5 o5(1, 2, 3, 4, 5, 6, 7);" << endl;
  cout << "sizeof(D5) = " << sizeof(D4) << endl;
  cout << endl << "Ієрархія класу D5: " << endl;
  o5.show_D5();

  Hack *hack = reinterpret_cast<Hack *>(&o0);

  cout << "private value from o0 (instance of class B): " << hack->b << endl;

  return 0;
}
