#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

class Address
{
private:
    string city;
    string street;
    int house;
    int number;
    
public:
    Address(string c, string s, int h, int a)
        : city(c), street(s), house(h), number(a) {}
    
    string getOutAddress()
    {
        return city + ", " + street + ", "
               + to_string(house) + ", "
               + to_string(number);
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    ifstream in("in.txt");
    
    if (!in.is_open())
    {
        cerr << "Ошибка: не удалось открыть in.txt\n";
        return 1;
    }
    
    int count;
    in >> count;
    
    Address** addresses = new Address*[count];
    
    for (int i = 0; i < count; ++i)
    {
        string city, street;
        int house, number;
        in >> city >> street >> house >> number;
        addresses[i] = new Address(city, street, house, number);
    }
    in.close();
    
    ofstream out("out.txt");
    out << count;
    
    for (int i = 0; i < count; ++i)
    {
        out << " " << addresses[i]->getOutAddress();
    }
    out.close();
    
    for (int i = 0; i < count; i++)
        delete addresses[i];
    
    delete[] addresses;
    
    return 0;
}
