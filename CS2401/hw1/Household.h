/**********************************************************
      This is a class describing a single household. It has private member
      variables for the name of the head of the household, the street address
      of the household, the number of people living in the household, and
      the household income. The functions allow access to and modification
      of those attributes either by the application programmer or by the
      user through the input functions.
**********************************************************/
  #include<iostream>
  #include<string>
  #include<fstream>
#ifndef HOUSEHOLD_H
#define HOUSEHOLD_H

  class Household {
	public:
		Household();
		// Mutators
		void set_head(const std::string& hd);
		void set_address(const std::string& add);
		void set_occupants(int num);
		void set_income(int inc);
		// Accessors
		std::string get_head()const;
		std::string get_address()const;
		int get_occupants()const;
		int get_income() const;
		// Input and output
		void input(std::istream& ins);
		void output(std::ostream& outs)const;
  private:
	  std::string house_head;
	  std::string address;
	  int occupants;
	  int income;
  };

  //overloaded i/o operators
  std::istream& operator >>(std::istream& ins, Household& h);
  std::ostream& operator <<(std::ostream& outs, const Household& h);

#endif
