#include <fstream>
#include <iostream>
#include <windows.h>
#include <sstream>

class Address
{
private:
    int n_dom = 0;
    int n_kv = 0;
    std::string city;
    std::string street;

public:
    Address(std::string city, std::string street,int n_dom,int n_kv) {
        this->n_dom = n_dom;
        this->n_kv = n_kv;
        this->city = city;
        this->street = street;
    }

    std::string print_address() {
        return this->city + ", " + this->street + ", " + std::to_string(this->n_dom) + ", " + std::to_string(this->n_kv);
    }

};

int count_address = 0;


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::ifstream file("in.txt");
    if (!file) {
        std::cout << "Файл не найден.";
        return 0;
    }

    file >> count_address;

    std::string* address_arr;
    address_arr = new std::string[count_address];

    int _n_dom = 0;
    int _n_kv = 0;
    std::string _city;
    std::string _street;

    std::ofstream fout("out.txt");

    for (int i = 0; i < count_address; ++i) {
        file >> _city;
        file >> _street;
        file >> _n_dom;
        file >> _n_kv;
        Address address(_city, _street, _n_dom, _n_kv);
        address_arr[i] = address.print_address();
    }


    fout << count_address << std::endl;
    for (int i = (count_address - 1); i >= 0; --i) {
        fout << address_arr[i] << std::endl;
    }
    fout.close();
    file.close();

    delete[] address_arr;
    address_arr = nullptr;
}
