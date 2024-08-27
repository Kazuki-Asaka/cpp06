#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base() {
	std::cout << "Base destructors called" << std::endl;
}

Base * generate(void) {
	int	rand_value;
	Base *base;

	std::srand(std::time(NULL));
	rand_value = std::rand() % 3;
	std::cout << "Number: " << rand_value << std::endl;
	if (rand_value == 0)
		base = new A;
	else if (rand_value == 1)
		base = new B;
	else
		base = new C;
	return (base);
}

void identify(Base *p) {
	std::cout << "PTR" << std::endl;
	A * const a = dynamic_cast<A*>(p);
	if (a != NULL) {
		std::cout << "This is " << "A" << " class" << std::endl;
		return ;
	}
	B * const b = dynamic_cast<B*>(p);
	if (b != NULL) {
		std::cout << "This is " << "B" << " class" << std::endl;
		return ;
	}
	C * const c = dynamic_cast<C*>(p);
	if (c != NULL) {
		std::cout << "This is " << "C" << " class" << std::endl;
		return ;
	}
	std::cout << "This is " << "No" << " class" << std::endl;
	return ;
}

void identify(Base& p) {
	std::cout << "REF" << std::endl;
	try {
		A& a = dynamic_cast<A&>(p);
		(void)a;
		// std::cout << "a: " << &a << std::endl;
		// std::cout << "p: " << &p << std::endl;
		std::cout << "This is " << "A" << " class" << std::endl;
		return ;
	} catch (std::exception& e) {
		
	}
	try {
		B& b = dynamic_cast<B&>(p);
		(void)b;
		// std::cout << "b: " << &b << std::endl;
		// std::cout << "p: " << &p << std::endl;
		std::cout << "This is " << "B" << " class" << std::endl;
		return ;

	} catch(std::exception& e) {

	}
	try {
		C& c = dynamic_cast<C&>(p);
		// std::cout << "c: " << &c << std::endl;
		// std::cout << "p: " << &p << std::endl;
		(void)c;
		std::cout << "This is " << "C" << " class" << std::endl;
		return ;
	} catch(std::exception& e) {

	}
	std::cout << "This is " << "No" << " class" << std::endl;
	return ;
}