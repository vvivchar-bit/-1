#include <iostream>
#include <string>
#include <vector>
#include <windows.h>

class University {
protected:
    std::string universityName;

public:
    explicit University(std::string name) : universityName(std::move(name)) {}
    virtual void print() const {
        std::cout << u8"[Університет] " << universityName << "\n";
    }
    virtual ~University() = default;
};

class Faculty : public University {
protected:
    std::string facultyName;

public:
    Faculty(std::string uniName, std::string facName)
        : University(std::move(uniName)), facultyName(std::move(facName)) {
    }

    void print() const override {
        std::cout << u8"[Факультет] " << facultyName
            << u8" | Університет: " << universityName << "\n";
    }
};

class Department : public Faculty {
    std::string departmentName;

public:
    Department(std::string uniName, std::string facName, std::string depName)
        : Faculty(std::move(uniName), std::move(facName)),
        departmentName(std::move(depName)) {
    }

    void print() const override {
        std::cout << u8"[Кафедра] " << departmentName
            << u8" | Факультет: " << facultyName
            << u8" | Університет: " << universityName << "\n";
    }
};

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    std::vector<University*> arr;
    arr.push_back(new University(u8"ЗВО НМТУ"));
    arr.push_back(new Faculty(u8"ЗВО НМТУ", u8"Інженерія програмного забезпечення"));
    arr.push_back(new Department(u8"ЗВО НМТУ",
        u8"Інженерія програмного забезпечення",
        u8"Кафедра інженерії програмного забезпечення"));

    for (auto* p : arr) p->print();
    for (auto* p : arr) delete p;

    return 0;
}

