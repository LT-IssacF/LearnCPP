#include <memory>
#include <string>
#include <vector>
#include <initializer_list>
#include <stdexcept>
#include "StrBlob.h"

int main( ) {
	StrBlob p1; // p1��һ�鵥�����ڴ汣����vector
	{
		StrBlob p2{ "a", "an", "the" }; // p2Ҳ��һ�鵥�����ڴ汣����vector
		p1 = p2; // p1������p2��vector���������ǵ�shared_ptr�����ü�����Ϊ2
		p2.push_back( "about" );
	}
	return 0;
}
