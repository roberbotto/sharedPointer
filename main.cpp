#include "lib/SharedPointer.h"

int main ()
{
   SharedPointer<int> a(25);
   SharedPointer<double> b(2.5);
   {
   	SharedPointer<int> a1(a);
	SharedPointer<double> b2 = b;

   	std::cout << a << std::endl;
   	std::cout << a1 << std::endl;
   	std::cout << b << std::endl;
        std::cout << b2 << std::endl;
   }
   a.set(18);
   std::cout << a << std::endl;
   std::cout << b << std::endl;

   return 0;
}
