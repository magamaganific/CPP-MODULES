template <typename T>
class Array
{
public:
	Array();
	Array(unsigned int n);
	Array(const Array *old);
	Array&operator=(const Array *old);
private:
	T *_arr;
	unsigned int _size;
}