#include <string>

template <typename whatever, typename F>
void iter(whatever *arr, const size_t len, F f){
	if (arr == NULL || f == NULL)
		return ;
	for (size_t i = 0; i < len; i++)
		f(arr[i]);
}