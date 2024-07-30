#include "Serializer.hpp"

uintptr_t Serializer::serialize(Data *ptr) {
	return(reinterpret_cast<uintptr_t>(ptr));
	// return (static_cast<uintptr_t>(ptr));
}

Data*  Serializer::deserialize(uintptr_t row) {
	return (reinterpret_cast<Data *>(row));
}