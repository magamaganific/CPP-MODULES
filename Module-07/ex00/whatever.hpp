template <class whatever>
void swap(whatever &a, whatever &b){
	whatever c = a;
	a = b;
	b = c;
}

template <class whatever>
whatever min(whatever a, whatever b){
	return(a < b? a : b);
}

template <class whatever>
whatever max(whatever a, whatever b){
	return(a > b? a : b);
}