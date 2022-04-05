#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

class Sales_data {
	// 非成员函数的友元声明
	friend Sales_data add(const Sales_data &lhs, const Sales_data &rhs);
	friend std::istream &read(std::istream &is, Sales_data &rhs);
	friend std::ostream &print(std::ostream &ou, const Sales_data &os);
public:
	Sales_data(const std::string &s, const unsigned int &cnt, const double &price) :
		bookNO(s), units_sold(cnt), revenue(price * cnt) {}

	Sales_data() : Sales_data("", 0, 0.0) {}
	Sales_data(const std::string &s) : Sales_data(s, 0, 0.0) {}

	Sales_data(const Sales_data &rhs) : bookNO(rhs.bookNO), units_sold(rhs.units_sold), revenue(rhs.revenue) {}
	Sales_data &operator=(const Sales_data &rhs);

	Sales_data(std::istream &is);

	std::string isbn() const {
		return this->bookNO;
	}

	Sales_data &combine(const Sales_data &rhs);

	double avg_price() const {
		return this->units_sold > 0 ? this->revenue / this->units_sold : 0.0;
	}
private:
	std::string bookNO;
	unsigned int units_sold;
	double revenue;
};

Sales_data &Sales_data::operator=(const Sales_data &rhs) {
	this->bookNO = rhs.bookNO;
	this->units_sold = rhs.units_sold;
	this->revenue = rhs.revenue;
	return *this;
}

Sales_data::Sales_data(std::istream &is) {
	read(is, *this);
}

Sales_data &Sales_data::combine(const Sales_data &rhs) {
	this->units_sold += rhs.units_sold;
	this->revenue += rhs.revenue;
	return *this;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {
	Sales_data tmp(lhs);
	tmp.combine(rhs);
	return tmp;
}

std::istream &read(std::istream &is, Sales_data &rhs) {
	double price;
	is >> rhs.bookNO >> rhs.units_sold >> price;
	rhs.revenue = price * rhs.units_sold;
	return is;
}

std::ostream &print(std::ostream &os, const Sales_data &rhs) {
	os << rhs.bookNO << " " << rhs.units_sold << " " << rhs.revenue << " " << rhs.avg_price() << std::endl;
	return os;
}