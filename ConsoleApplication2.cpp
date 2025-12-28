#include <iostream>
#include <vector>
#include <memory>
#include <cmath>
#include <iomanip>
#include <string>
#include <utility>

static constexpr double PI = 3.14159265358979323846;

class SolidOfRevolution {
protected:
    std::string name;

public:
    explicit SolidOfRevolution(std::string n) : name(std::move(n)) {}
    virtual ~SolidOfRevolution() = default;

    virtual double volume() const = 0;
    virtual double surfaceArea() const = 0;
    virtual void print(std::ostream& os) const = 0;
};

class Cone : public SolidOfRevolution {
private:
    double r, h;

public:
    Cone(double radius, double height)
        : SolidOfRevolution("Cone"), r(radius), h(height) {
    }

    double slantHeight() const { return std::sqrt(r * r + h * h); }

    double volume() const override { return (PI * r * r * h) / 3.0; }

    double surfaceArea() const override {
        double l = slantHeight();
        return PI * r * (r + l); // total
    }

    void print(std::ostream& os) const override {
        os << "Type: " << name
            << " | r=" << r
            << " | h=" << h
            << " | l=" << slantHeight()
            << " | V=" << volume()
            << " | S=" << surfaceArea();
    }
};

class Cylinder : public SolidOfRevolution {
private:
    double r, h;

public:
    Cylinder(double radius, double height)
        : SolidOfRevolution("Cylinder"), r(radius), h(height) {
    }

    double volume() const override { return PI * r * r * h; }

    double surfaceArea() const override { return 2.0 * PI * r * (r + h); }

    void print(std::ostream& os) const override {
        os << "Type: " << name
            << " | r=" << r
            << " | h=" << h
            << " | V=" << volume()
            << " | S=" << surfaceArea();
    }
};

class Sphere : public SolidOfRevolution {
private:
    double r;

public:
    explicit Sphere(double radius)
        : SolidOfRevolution("Sphere"), r(radius) {
    }

    double volume() const override { return (4.0 / 3.0) * PI * r * r * r; }

    double surfaceArea() const override { return 4.0 * PI * r * r; }

    void print(std::ostream& os) const override {
        os << "Type: " << name
            << " | r=" << r
            << " | V=" << volume()
            << " | S=" << surfaceArea();
    }
};

int main() {
    std::cout << std::fixed << std::setprecision(4);

    std::vector<std::unique_ptr<SolidOfRevolution>> arr;
    arr.push_back(std::make_unique<Cone>(3.0, 5.0));
    arr.push_back(std::make_unique<Cylinder>(2.0, 6.0));
    arr.push_back(std::make_unique<Sphere>(4.0));
    arr.push_back(std::make_unique<Cone>(1.5, 2.0));

    for (const auto& p : arr) {
        p->print(std::cout);
        std::cout << '\n';
    }

    return 0;
}

