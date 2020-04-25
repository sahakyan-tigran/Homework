#include <iostream>

#include <cmath>

const double pi = 22 / 7;

class Shape3D {
public:
	virtual ~Shape3D() {}

	virtual double area() const = 0;
	virtual double volume() const = 0;
};

class Parallelepiped : public Shape3D {
public:
	Parallelepiped(double a1, double b1, double deg1, double height1) 
		: a(a1), b(b1), deg(deg1), height(height1) {}

	virtual double area() const;
	virtual double volume() const;

private:
	double a;
	double b;
	double deg;
	double height;
};

class Cylinder : public Shape3D {
public:
	Cylinder(double r1, double height1)
		: r(r1), height(height1) {}

	virtual double area() const;
	virtual double volume() const;

private:
	double r;
	double height;
};

class Cone : public Shape3D {
public:
	Cone(double r1, double l1, double h1)
		: r(r1), l(l1), h(h1) {}

	virtual double area() const;
	virtual double volume() const;

private:
	double r;
	double l;
	double h;
};

class Sphere : public Shape3D {
public:
	Sphere(double r1) : r(r1) {}

	virtual double area() const;
	virtual double volume() const;

private:
	double r;
};

double  Parallelepiped::area() const {
	return (a + b) * 2 * height;
}

double  Parallelepiped::volume() const {
	return (sin(deg) > 0) ? (a * b * 0.5 * sin(deg)) : (a * b * (-0.5) * sin(deg));
}

double Cylinder::area() const {
	return 2 * pi * r * height;
}

double Cylinder::volume() const {
	return pi * r * r * height;
}

double Cone::area() const {
	return pi * r * l;
}

double Cone::volume() const {
	return pi * r * r * h / 3;
}

double Sphere::area() const {
	return 4 * pi * r * r;
}

double Sphere::volume() const {
	return 4 * pi * r * r * r / 3;
}

int main() {
	
	Shape3D* a = new Parallelepiped(5, 4, 1.57, 8);
	Shape3D* b = new Cylinder(3, 8);
	Shape3D* c = new Cone(3, 5, 6);
	Shape3D* d = new Sphere(4);
	Shape3D* e[4] = { a,b,c,d };

	std::cout << "This are areas " << std::endl;
	for (int i = 0; i < 4; ++i) {
		std::cout << e[i]->area() << std::endl;
	}

	std::cout << std::endl << "This are volumes " << std::endl;
	for (int i = 0; i < 4; ++i) {
		std::cout << e[i]->volume() << std::endl;
	}
	return 0;
}