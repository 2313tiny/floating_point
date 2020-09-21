
#ifndef GARRAY_HPP
#define GARRAY_HPP

int const LAYOUT = 32;

class GbitVector{
protected:
	unsigned long int * m_array;

public:
	GbitVector();
	~GbitVector();
	bool operator[](int index) const; //access operator
	void set(int index, bool value); //set/clear bit
	void shift_right(int index); //shift right
	void shift_left(int index); //shift left
};
 
#endif //GARRAY_HPP
