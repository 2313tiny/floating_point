#include "GfloatArithmetic.hpp"


//copy constructor
GfloatArithmetic::GfloatArithmetic(const GfloatArithmetic & )
{
	//emtpy body
}

//move constructor
GfloatArithmetic::GfloatArithmetic(const GfloatArithmetic &&)
{
	//empty body
}

//move assignment
GfloatArithmetic & GfloatArithmetic::operator=(const GfloatArithmetic &&)
{
	//empty body
}

void GfloatArithmetic::convert_binary_to_dec_exp(const Gfloat & sum, int & exp1)
{
	int rang = 0;
	exp1 = 0;
	for(int i = 1; i < 9; ++i){
		rang = 1;
		for (int j = 1; j < (9-i); ++j){
			rang = 2 * rang;
		}
		std::cout << i << " " << rang << " \n";
		exp1 = exp1 + this->m_gbitvector[i] * rang;
	}
}


bool GfloatArithmetic::is_equal_exp1_and_exp(int  & exp, int & exp1) const
{
	if (exp == exp1){
		//visual test
		std::cout << "OK "<< std::endl;
		return true;
	} else {
		//visual test
		std::cout << "KO " << std::endl;
		return false;
		}
}

	
void GfloatArithmetic::add_mantissa_sum_and_sum1(const GfloatArithmetic & sum, 
				       		const GfloatArithmetic & sum1, 
				        	GfloatArithmetic & result)
{
	bool carry = false;
	bool value = false;
	for(int i = 31; i > 9; --i ){

	      value = sum.m_gbitvector[i] ^ sum1.m_gbitvector[i] ^ carry;
	      carry = sum.m_gbitvector[i] & sum1.m_gbitvector[i];
	      result.m_gbitvector.set(i, value); 

	}		

	std::cout << "add mantissa for two number" << std::endl;	
}

void GfloatArithmetic
    ::construct_the_base_2_represantation_exponent(Gfloat & sum1, int & exp)
{
	for (int i = 8; i >= 0; --i){
		if(0 != exp % 2){
			sum1.m_gbitvector.set(i, true);
			exp = exp / 2;
		} else {
			sum1.m_gbitvector.set(i, false);
			exp = exp / 2;
		}
	}
}

//operator assignment
GfloatArithmetic & GfloatArithmetic::operator=(const GfloatArithmetic & x){
	for (int i = 0; i < 32; ++i){
		bool value = x.m_gbitvector[i];
		this->m_gbitvector.set(i, value);
	}	
	//visual test
	std::cout << "operator assignment" << std::endl;
	return *this; 
}

GfloatArithmetic GfloatArithmetic::operator+(const GfloatArithmetic & sum1)
{
	std::cout << "operator+ overload " << std::endl;
	GfloatArithmetic result;
	
	std::cout << "\n******_second_***********\n";
	for(int i = 0; i < 32; ++i){
		std::cout << sum1.m_gbitvector[i] << " ";
	}

	std::cout << "\n******_first_*******\n";
	for(int i = 0; i < 32; ++i){
		std::cout << this->m_gbitvector[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "\n******************\n";
	
	int exp = 0;
	convert_binary_to_dec_exp(sum1, exp);
	std::cout << "exponent = " << exp << std::endl;

	int exp1 = 0; 
	convert_binary_to_dec_exp(*this, exp1);
	std::cout << "exponent = " << exp1 << std::endl;

	if (true == is_equal_exp1_and_exp(exp, exp1)){
		add_mantissa_sum_and_sum1(*this, sum1, result);
	} else {
		std::cout << "you can add 2 number with same exponent\n";
		}	

	construct_the_base_2_represantation_exponent(result, exp);

	std::cout << "\n";
	return result;
}	


