#include <string>
#include <exception>

template <typename T>
class Array
{
public:
	Array(): _size(0){
		std::cout<<"Default constructor"<<std::endl;
		this->_arr = new T[this->_size];
	};
	Array(unsigned int n): _size(n){
		std::cout<<"Size constructor"<<std::endl;
		_arr = new T[n];
	};
	Array(const Array &old): _size(old._size){
		std::cout<<"Copy constructor"<<std::endl;
		this->_arr = NULL;
		*this = old;
	};
	~Array(){
		std::cout<<"Destructor"<<std::endl;
		delete this->_arr;
	};

	unsigned int size() const{
		return(this->_size);
	}

	Array&operator=(const Array &old){
		std::cout<<"Assignment called"<<std::endl;
		if (this->_arr != NULL)
			delete [] this->_arr;
		if (old._size != 0)
		{
			this->_size = old.size();
			this->_arr = new T[this->_size];
			for (unsigned int i = 0; i < this->size(); i++)
				this->_arr[i] = old._arr[i];
		}
		return(*this);
	};
	T &operator[](unsigned int index){
		if (index >= this->_size || this->_arr == NULL)
			throw Array<T>::InvalidIndexException();
		return (this->_arr[index]);
	}	
	const T &operator[](unsigned int index) const{
		if (index >= this->_size || this->_arr == NULL)
			throw Array<T>::InvalidIndexException();
		return (this->_arr[index]);
	}

	class InvalidIndexException : public std::exception{
	public:
		virtual const char	*what() const throw();
	};
private:
	T *_arr;
	unsigned int _size;
};

template<typename T>
const char *Array<T>::InvalidIndexException::what() const throw(){
	return ("Error: Invalid index.");
}