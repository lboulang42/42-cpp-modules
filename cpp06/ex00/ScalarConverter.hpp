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
		ScalarConverter(ScalarConverter &src);
		ScalarConverter &operator=(ScalarConverter const &src);
		virtual ~ScalarConverter() =0;
		/*==========OTHER CONSTRUCTORS==========*/
		ScalarConverter::ScalarConverter(std::string const &str);
		/*==========MEMBER FUNCTIONS==========*/
		static void convert(std::string const &str);
	
	private:
		std::string _originalStr;
		std::string _type;
};

#endif
