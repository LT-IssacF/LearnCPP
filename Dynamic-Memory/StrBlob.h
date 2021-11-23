#include <memory>
#include <string>
#include <vector>
#include <initializer_list>
#include <stdexcept>
class StrBlob {
public:
	typedef std::vector<std::string>::size_type size_type;
	StrBlob( );
	StrBlob( std::initializer_list<std::string> il );
	// �����ֳ�Ա��������Ҫ�ı�Ԫ�أ�����ֱ�����õײ��vector�����Ӧ��Ա����ɹ���
	size_type size( ) const { return data->size( ); };
	bool empty( ) const { return data->empty( ); };
	// ��Ҫ��ӻ�ɾ���������û�����ƣ�����Ҳ��������
	void push_back( const std::string &t ) { return data->push_back( t ); }
	void pop_back( );
	// ��Ԫ�ؽ��з��ʣ�������ֵ
	const std::string &front( ) const;
	const std::string &back( ) const;
private:
	std::shared_ptr<std::vector<std::string>> data;
	void check( size_type i, const std::string &msg ) const;
};
// �޲γ�ʼ��������һ����vector
StrBlob::StrBlob( ) : data( std::make_shared<std::vector<std::string>>( ) ) { };
// ��initializer_list��ʼ��vector
StrBlob::StrBlob( std::initializer_list<std::string> il ) :
	data( std::make_shared<std::vector<std::string>>( il ) ) { };
void StrBlob::check( size_type i, const std::string &msg ) const {
	if( i >= data->size( ) )
		throw std::out_of_range( msg );
}
void StrBlob::pop_back( ) {
	check( 0, "pop_back on empty StrBlob" );
	data->pop_back( );
}
const std::string &StrBlob::front( ) const {
	check( 0, "front on empty StrBlob" );
	return data->front( );
}
const std::string &StrBlob::back( ) const {
	check( 0, "back on empty StrBlob" );
	return data->back( );
}
