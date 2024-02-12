/*Generated using lboulang42's cppmain.sh*/

#ifndef SCALARCONVERTER_H
# define SCALARCONVERTER_H

# ifndef __CLASS__
#  define __CLASS__ "ScalarConverter"
# endif

# include <iostream>

class ScalarConverter
{
  	public:
		/*==========CANONICAL==========*/
		ScalarConverter();
		ScalarConverter::ScalarConverter(std::string const &str);
		ScalarConverter(ScalarConverter &src);
		ScalarConverter &operator=(ScalarConverter const &src);
		virtual ~ScalarConverter() =0;
		static void convert(std::string const &str);
		/*==========OPERATORS==========*/
		//ScalarConverter operator++(void);
		//ScalarConverter operator--(void);
		
		/*==========GETTERS==========*/
		//std::string get() const;
		
		/*==========SETTER==========*/
		//void set(std::string &s);
		
		/*==========EXCEPTIONS==========*/
		//class ExceptionName : public std::exception
		//{
		//	public:
		//		virtual const char *what() const throw();
		//};
	
	private:
		std::string _originalStr;
		std::string _type;
		//int _var_int;
};

// /*==========OTHER OPERATORS==========*/
// std::ostream &operator<<(std::ostream &out, ScalarConverter const &b);

#endif
