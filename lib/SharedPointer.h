#ifndef SharedPointer_h
#define SharedPointer_h

#include <iostream>

template <typename T>
class SharedPointer
{
   T value;
   unsigned int *count;

   public:
   
   SharedPointer (const SharedPointer & shp) {
   	this->value = shp.value;
	this->count = shp.count;
	++(*this->count);
   }

   SharedPointer (const T v) : value(v) { this->count = new unsigned int(1); }
   ~SharedPointer () {
	if (--(*this->count) == 0) delete this->count;
   }

   inline T get (void) { return this->value; }
   inline void set (T v) { this->value = v; }
   inline unsigned int getCount (void) { return *this->count; }

   inline friend std::ostream& operator<< (
         std::ostream & os,
         const SharedPointer & shp)
   {
      return os << shp.value << ":" << *shp.count;
   }

   inline SharedPointer<T>&  operator= (const SharedPointer<T> & shp)
   {
	 this->value = shp.value;
	 this->count = shp.count;
	 return *this;
   }
};

#endif
