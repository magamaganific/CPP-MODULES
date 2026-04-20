#include <string>

template <typename whatever>
void iter(whatever *arr, const size_t len, void (*f)(whatever &)){
	if (arr == NULL || f == NULL)
		return ;
	for (size_t i = 0; i < len; i++)
		f(arr[i]);
}