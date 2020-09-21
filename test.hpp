#ifndef TEST_HPP
#define TEST_HPP

#include"GfloatArithmetic.hpp" 
#include<iostream>
#include<cassert>
#include<limits>

#define YELLOW "\033[01;033m"
#define GREEN "\033[01;032m"
#define RESET "\033[01;0m"
#define RED "\033[01;031m"

 
void test_v1()
{

	
/*	Gfloat gfloat("263.3f");

	for (int i = 0; i < LAYOUT; ++i){
		std::cout << gfloat.m_gbitvector[i] << " " ; 
	}
	std::cout << std::endl;
*/

/*
	std::cout << "\n----------------------------------------------\n";	
	Gfloat gfloat1("85.125f");
	for(int i = 0; i < LAYOUT; ++i){
		std::cout << gfloat1.m_gbitvector[i] << " ";
	}
	std::cout << std::endl;
*/

/*
	std::cout << "\n----------------------------------------------\n";	
	Gfloat gfloat2("5.2f");
	for(int i = 0; i < LAYOUT; ++i){
		std::cout << gfloat2.m_gbitvector[i] << " ";
	}
	std::cout << std::endl;

*/

/*
	std::cout << "\n----------------------------------------------\n";	
	Gfloat gfloat3("67.875f");
	for(int i = 0; i < LAYOUT; ++i){
		std::cout << gfloat3.m_gbitvector[i] << " ";
	}
	std::cout << std::endl;
*/
/*	std::cout << "\n----------------------------------------------\n";	
	Gfloat gfloat4("1.125f");
	for(int i = 0; i < LAYOUT; ++i){
		std::cout << gfloat4.m_gbitvector[i] << " ";
	}
	std::cout << std::endl;
*/

/*	std::cout << "\n----------------------------------------------\n";	
	Gfloat gfloat5("-25.347f");
	for(int i = 0; i < LAYOUT; ++i){
		std::cout << gfloat5.m_gbitvector[i] << " ";
	}
	std::cout << std::endl;
*/

/*	std::cout << "\n----------------------------------------------\n";	
	Gfloat gfloat6("-128912.9823f");
	for(int i = 0; i < LAYOUT; ++i){
		std::cout << gfloat6.m_gbitvector[i] << " ";
	}
	std::cout << std::endl;
*/
	
/*	std::cout << "\n----------------------------------------------\n";	
	Gfloat gfloat7("-1000012.90099323f");
	for(int i = 0; i < LAYOUT; ++i){
		std::cout << gfloat7.m_gbitvector[i] << " ";
	}
	std::cout << std::endl;
*/
	
/*	std::cout << "\n----------------------------------------------\n";	
	Gfloat gfloat8("234.9f");
	for(int i = 0; i < LAYOUT; ++i){
		std::cout << gfloat8.m_gbitvector[i] << " ";
	}
	std::cout << std::endl;
*/

/*	std::cout << "\n----------------------------------------------\n";	
	Gfloat gfloat9("-0.9f");
	for(int i = 0; i < LAYOUT; ++i){
		std::cout << gfloat9.m_gbitvector[i] << " ";
	}
	std::cout << std::endl;
*/
/*	
	std::cout << "\n----------------------------------------------\n";	
	Gfloat gfloat10("-1.12345f");
	for(int i = 0; i < LAYOUT; ++i){
		std::cout << gfloat10.m_gbitvector[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "\n----------------------------------------------\n";	
	Gfloat gfloat11("-123456789.12345f");
	for(int i = 0; i < LAYOUT; ++i){
		std::cout << gfloat11.m_gbitvector[i] << " ";
	}
	std::cout << std::endl;
*/
/*	std::cout << "\n----------------------------------------------\n";	
	Gfloat gfloat12("0.123f");
	for(int i = 0; i < LAYOUT; ++i){
		std::cout << gfloat12.m_gbitvector[i] << " ";
	}
	std::cout << std::endl;
*/
/*	std::cout << "\n----------------------------------------------\n";	
	Gfloat gfloat14("-123.456f");
	for(int i = 0; i < LAYOUT; ++i){
		std::cout << gfloat14.m_gbitvector[i] << " ";
	}
	std::cout << std::endl;

	std::cout << RED;
	std::cout << "\nsize of float = " << sizeof(float) << " bytes\n\n";
	std::cout << YELLOW;
	std::cout << "\n\n\nsize of Gfloat = " << sizeof(Gfloat) << " bytes\n";
	std::cout << "size of GbitVector = " << sizeof(GbitVector) << " bytes\n";
	std::cout << RESET;
*/
/*
	std::cout << "max = " << std::numeric_limits<float>::max() << std::endl;
	std::cout << "min = " << std::numeric_limits<float>::min() << std::endl;
	std::cout << "lowest = " << std::numeric_limits<float>::lowest() << std::endl;

	std::cout << "max = " << std::numeric_limits<bool>::max() << std::endl;
	std::cout << "min = " << std::numeric_limits<bool>::min() << std::endl;
	std::cout << "lowest = " << std::numeric_limits<bool>::lowest() << std::endl;

	std::cout << "max = " << std::numeric_limits<char>::max() << std::endl;
	std::cout << "min = " << std::numeric_limits<char>::min() << std::endl;
	std::cout << "lowest = " << std::numeric_limits<char>::lowest() << std::endl;

	std::cout << "max = " << std::numeric_limits<std::string>::max() << std::endl;
	std::cout << "min = " << std::numeric_limits<std::string>::min() << std::endl;
	std::cout << "lowest = " << std::numeric_limits<std::string>::lowest() << std::endl;
*/
/*
	Gfloat gfa("263.3f");
	for(int i = 0; i < LAYOUT; ++i){
		std::cout << gfa.m_gbitvector[i] << " ";
	}
	std::cout << std::endl;
*/

}
void test_v2()
{
	GfloatArithmetic gfa1("215.125f");
	
	GfloatArithmetic gfa2("150.421f");

	GfloatArithmetic res;

//	res =gfa1 + gfa2;

	res = gfa1;
	std::cout << "gfa1 .....\n";	
	for (int i = 0; i < LAYOUT; ++i){
		std::cout << gfa1.m_gbitvector[i] << " "; 
	}
	std::cout << "\n........result of sum......" << std::endl;
	for (int i = 0; i < LAYOUT; ++i){
		std::cout << res.m_gbitvector[i] << " " ; 
	}
	std::cout << std::endl;

	res = gfa2;
	std::cout << "gfa2 .....\n";	
	for (int i = 0; i < LAYOUT; ++i){
		std::cout << gfa2.m_gbitvector[i] << " "; 
	}
	std::cout << "\n........result of sum......" << std::endl;
	for (int i = 0; i < LAYOUT; ++i){
		std::cout << res.m_gbitvector[i] << " " ; 
	}
	std::cout << std::endl;

	res = gfa1 + gfa2;
	std::cout << "\n........RESULT of sum......" << std::endl;
	for (int i = 0; i < LAYOUT; ++i){
		std::cout << res.m_gbitvector[i] << " " ; 
	}
	std::cout << std::endl;


}
void test_v3()
{
	Gfloat gf("365.546f");
//	for (int i = 0; i < LAYOUT; ++i){
//		std::cout << gf.m_gbitvector[i] << " " ; 
//	}

	std::cout << std::endl;

}
 
 
#endif // TEST_HPP
