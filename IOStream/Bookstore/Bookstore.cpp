#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Sales_data.h"
using namespace std;

istream &read( istream &is, Sales_data &item ) {
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
}
ostream &print( ostream &os, const Sales_data &item ) {
	os << item.isbn( ) << " " << item.units_sold << " "
		<< item.revenue << " " << item.avg_price( );
	return os;
}
Sales_data add( const Sales_data &lhs, const Sales_data &rhs ) {
	Sales_data sum = lhs;
	sum.combine( rhs );
	return sum;
}

int main( ) {
	ifstream input( "input.txt" );
	ofstream output( "output.txt" ); // ��ʽ�ض��ļ�
	Sales_data total; // ����һ����������ܶ�
	if( read( input, total ) ) { // ��ȡ��һ�����ۼ�¼
		Sales_data trans; // ������һ��������۶�
		while( read( input, trans ) ) { // ��ȡ��һ�����ۼ�¼
			if( total.isbn( ) == trans.isbn( ) ) // ��ͬһ����
				total.combine( trans );
			else { // �������ӡ��һ���Ľ��
				print( output, total ) << endl;
				total = trans; // ��ʼ������һ��
			}
		}
		print( output, total ); // �������һ��
		cout << "Record done!" << endl;
	}
	else // �ļ���û������
		cerr << "No data?!" << endl;
	return 0;
}