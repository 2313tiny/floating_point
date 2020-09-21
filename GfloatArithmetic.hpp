#ifndef GFLOATARITHMETIC_HPP
#define GFLOATARITHMETIC_HPP

#include "Gfloat.hpp"

class GfloatArithmetic : public Gfloat{
public:
	GfloatArithmetic(std::string value)
	 	: Gfloat(value){}

	//default constructor
	GfloatArithmetic() : Gfloat() {}

	//copy constructor
	GfloatArithmetic(const GfloatArithmetic & );

	//copy assignment
	GfloatArithmetic & operator=(const GfloatArithmetic &);

	//move constructor
	GfloatArithmetic(const GfloatArithmetic &&);

	//move assignment
 	GfloatArithmetic & operator=(const GfloatArithmetic &&);

	//post increment unary+
	GfloatArithmetic & operator++(int); 

	//pre increment unary+
	GfloatArithmetic & operator++();

	//operator+ binary+
	GfloatArithmetic operator+(const GfloatArithmetic &); 


private:
	void convert_binary_to_dec_exp(const Gfloat & sum, int & exp1);

	bool is_equal_exp1_and_exp(int & exp, int & exp1) const;//true if exp >exp1
	
	void add_mantissa_sum_and_sum1(const GfloatArithmetic & sum, 
				       const GfloatArithmetic & sum1, 
					GfloatArithmetic & result);//AND with carry 

	void construct_the_base_2_represantation_exponent(Gfloat & sum, 
							  int & exp);
};


#endif //GFLOATARITHMETIC_HPP
