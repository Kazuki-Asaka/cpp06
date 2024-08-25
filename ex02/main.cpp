#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main() {
	{
		Base *base;
		base = generate();
		identify(base);
		identify(*base);
		delete base;
	}

	{
		Base* base;
		base = new A;
		identify(base);
		identify(*base);
		delete base;
	}

	{
		Base* base;
		base = new B;
		identify(base);
		identify(*base);
		delete base;
	}
	
	{
		Base* base;
		base = new C;
		identify(base);
		identify(*base);
		delete base;
	}
}

__attribute__((destructor))
static void destructor() {
	system("leaks -q ex02");
}