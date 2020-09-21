
#ifndef FLOAT_HPP
#define FLOAT_HPP

#include"Garray.hpp"

#include<string>
#include<iostream>

class Gfloat{
public:
	Gfloat(std::string value);
	Gfloat();
public:
	GbitVector m_gbitvector; //place where need to store value

private: //utilities
	
	void integer_part_of_number_before_point(char *& ptrFirst, 
						char *& ptrSecond, int & first);

	
	void counting_number_bit_before_point_represantation(int first, 
							     int & countFirst);

	void construct_the_base_2_represantation_before_point(int & first,
							      int countFirst);

	void integer_part_of_number_after_point(char * ptrSecond, int &second);

	
	void higher_order_represantation_after_point(int second,
						     int & highSecond);	

	void construct_the_base_2_represantation_after_point(int countFirst,
								int second);

	void integer_part_adjusted_exponent(int countFirst, int & exp );

	void construct_the_base_2_represantation_exponent(int countFirst,
							  int & exp);	
	void setting_sign_bit(std::string value);	

	void display_32_bits();
};

#endif //FLOAT_HPP
