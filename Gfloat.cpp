#include "Gfloat.hpp" 


Gfloat::Gfloat(std::string value){
	//BEFORE POINT IN INPUT STRING
	char *ptrFirst = &value[0];
	char *ptrSecond = nullptr;
	int first = 0;  //decimal integer value before point
	int second = 0; //decimal integer value after point
	int highSecond = 0; // high order after point
	bool sign = true; //entered value is positive
	int countFirst = 0; //number of bit need for represantation first value 
	int exp = 0; //represent exponent 
	//was entered negative number
	if ('-' == *ptrFirst ){
		ptrFirst++;
		sign = false;
	}

	integer_part_of_number_before_point(ptrFirst, ptrSecond, first);
	counting_number_bit_before_point_represantation(first, countFirst);
	construct_the_base_2_represantation_before_point( first,countFirst);
	
	integer_part_of_number_after_point(ptrSecond, second);
	higher_order_represantation_after_point(second, highSecond);	
	construct_the_base_2_represantation_after_point(countFirst,second);

	integer_part_adjusted_exponent(countFirst, exp);
	construct_the_base_2_represantation_exponent(countFirst, exp);	
	setting_sign_bit(value);

	//visual test
	display_32_bits();
}


//default constructor
Gfloat::Gfloat()
{
	for (int i = 0; i < 32; ++i){
		m_gbitvector.set(i,0);
	}
	
	//visual test
	display_32_bits();
}


//first, convert to binary(base 2) the integer part:
//Divide the number repeatedly by 2 keeping track
//of each remainder, until we get a quotient 
//that is equal to zero

void Gfloat::integer_part_of_number_before_point(char *& ptrFirst, 
						char *& ptrSecond, int & first)
{

	while(static_cast<int>('.')  != static_cast<int>(*ptrFirst) ){
   	    first = first * 10 +(static_cast<int>(*ptrFirst)-static_cast<int>('0'));
	    ++ptrFirst;
	    std::cout <<"\nfirst = " <<  first << " ";
	    ptrSecond = ptrFirst;
	}	
	std::cout << std::endl;
}

//construct the base 2 represantation of the integer part
//of the number, by taking all the remainders starting from 
//the bottom of the list constructed
//above

void Gfloat::counting_number_bit_before_point_represantation(int first,
							 int & countFirst)
{
	while(0 != first ){
		++countFirst;
		first = first / 2;
	}
}

void Gfloat::construct_the_base_2_represantation_before_point( int & first,
							       int countFirst)
{
	for (int i = countFirst -1 ; i >= 0; --i){
		if(0 != first % 2){
			m_gbitvector.set(i, true);
			first = first / 2;
		} else {
			m_gbitvector.set(i, false);
			first = first / 2;
		}
	}
	
		// visual test
		for (int i = 0; i < 32; ++i){
			std::cout << m_gbitvector[i]<<" ";
		}
		std::cout << std::endl;

}

//Convert to binary (base 2) the fraction part: Multiply it repeatedly by 2
//keeping track of each integer part of the result, until we get a fraction 
//part that is equl to zero

void Gfloat::integer_part_of_number_after_point(char * ptrSecond, int &second)
{
	ptrSecond++;
	while('f' != *ptrSecond ){
  	   second = second * 10 +(static_cast<int>(*ptrSecond)-static_cast<int>('0'));
    	 //	if (0 == second){ ++shift; } //if after point sequenced 0 
	    ++ptrSecond;
	    std::cout <<"\n" <<  "second = " <<  second  << " ";
	}
	std::cout << std::endl;
}

//Construct the base 2 representation of the fractional part of the number, by 
//taking all the integer parts of teh multiplying operations, starting from the top 
// of the top of the constructed list abov`e

void Gfloat::higher_order_represantation_after_point(int second, int & highSecond)
{
	while(0 != second ){
		++highSecond;
		second = second / 10;
	}	
}

void Gfloat::construct_the_base_2_represantation_after_point(int countFirst, 
						int second)
{
	for (int i = countFirst; i< LAYOUT; ++i ){
	int highSecond = 0;
	   higher_order_represantation_after_point(second, highSecond);
           int decisionMaker = 1;
	   std::cout <<"---highSecond" <<  highSecond << std::endl;
	   for(int j = 0; j < highSecond; ++j){
			decisionMaker = decisionMaker * 10;	
	   }	
		std::cout <<"---decision maker -- = " <<  decisionMaker << std::endl;
		if ((decisionMaker - 2 * second) > 0){
			m_gbitvector.set(i, false);
			second *= 2;
			std::cout << " false second = " << second << std::endl; 
		}else{
			m_gbitvector.set(i, true);
			second = 2*second - decisionMaker; 
			std::cout << "true second = " << second << std::endl; 
	         }
	}
	// visual test
	for (int i = 0; i < 32; ++i){
			std::cout << m_gbitvector[i]<<" ";
		}
		std::cout << std::endl;
		
}

//Normalize the binary represantation of the number, shifting the 
//decimal mark countFirst-1 position to left so that only one non zero digit
//reamins to the left of it 
///&&&&&&&&&&&&&&&&&&&&&&&&&&  countFirst - 1



//Up to this moment, there are the following elements that
//would feed into the 32 bit single presion IEEE 754 binary
//floating point representation 
//&&&&&&&&&&&&&&&&&&&&&&&&&&  sign = 0 (positive number)

//Adjust the exponent in 8 bit excess/bias notation and then convert it
//from decimal(base 10) to 8 bit binary, by using the same technique
//of repeatedly dividing by 2
void Gfloat::integer_part_adjusted_exponent(int countFirst, int & exp )
{
	exp = 127 + countFirst -1 ; //need to consider 127 - countFirst !!!!
	
	//visual test
	std::cout << exp << ".... exp " << std::endl;
	std::cout << countFirst << ".... countFirst " << std::endl;
}

void Gfloat::construct_the_base_2_represantation_exponent(int countFirst, int & exp)
{
	m_gbitvector.shift_left(1); // need for make 0 first bit point shift left	
	m_gbitvector.shift_right(9); //clear first 8 bit for mantissa
	
	for (int i = 8; i >= 0; --i){
		if(0 != exp % 2){
			m_gbitvector.set(i, true);
			exp = exp / 2;
		} else {
			m_gbitvector.set(i, false);
			exp = exp / 2;
		}
	}
}	

void Gfloat::setting_sign_bit(std::string value)
{
	char * ptrFirst = &value[0];
	if ('-' == *ptrFirst ){
		ptrFirst++;
		//sign = false;
	//	m_gbitvector.shift_right(1);
		m_gbitvector.set(0, true);
	} else {
		ptrFirst++;
	//	m_gbitvector.shift_right(1);
		m_gbitvector.set(0, false);
	}
}

void Gfloat::display_32_bits()
{
	std::cout << "\n....binary floating point...\n";
	for (int i = 0; i < 32; ++i){
		std::cout << m_gbitvector[i] << " ";
	}
	std::cout << std::endl;
}
