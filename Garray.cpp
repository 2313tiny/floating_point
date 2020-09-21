#include "Garray.hpp" 


GbitVector::GbitVector()
{
	m_array = new unsigned long int[LAYOUT];	
}


GbitVector::~GbitVector()
{
	if (nullptr != m_array){
		delete[] m_array;
		m_array = 0;
	}
}

bool GbitVector::operator[](int index) const
{
	int bit= index % LAYOUT;	
	return (m_array[0] & (1 << bit)) >> bit;
}

void GbitVector::set(int index, bool value)
{
	int bit = index % LAYOUT;
	if(true == value){
		m_array[0] = (m_array[0] | (1 << bit));
	} else {
		m_array[0] = (m_array[0] & (~(1<< bit)));
	}	
}

void GbitVector::shift_right(int index)
{
	for(int i = 0; i < index; ++i){
		m_array[0] = m_array[0] << 1;
	}
}

void GbitVector::shift_left(int index){
	for(int i = 0; i < index; ++i){
		m_array[0] = m_array[0] >> 1;
	}
}
