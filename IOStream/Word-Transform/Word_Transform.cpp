#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
using namespace std;
// ����ת������ӳ��
// ����Ϊһ����ȡ�ļ���
map<string, string> BuildMap( ifstream &map_file ) {
	map<string, string> trans_map;
	string key, value; // ����ֵ
	// ��ȡ��һ�����ʴ���key������ʣ�����ݴ���value
	while( map_file >> key && getline( map_file, value ) ) {
		if( value.size( ) > 1 ) // ����ǰ���ո�
			trans_map[key] = value.substr( 1 );
		else // ʵ�ʸ����ṩ�����������ʲ�������쳣
			throw runtime_error( "no rule for " + key );
	}
	return trans_map;
}
// ʵ�ʵ�ת������
// ����Ϊһ����ת�����ַ��������ʺ�ת������
const string &Transform( const string &s, const map<string, string> &trans_map ) {
	auto map_it = trans_map.find( s );
	auto map_end = trans_map.cend( );
	if( map_it != map_end ) // ���������ת��������
		return map_it->second; // �����滻����
	else // ���ھ�ԭ·����
		return s;
}
// ����Ϊ������ȡ�ļ�����ǰ����ת�����򣬺����Ǵ�ת���ı�
void Word_Transform( ifstream &map_file, ifstream &input ) {
	auto trans_map = BuildMap( map_file );
	string text;
	while( getline( input, text ) ) { // ����������ÿһ��
		istringstream stream( text ); // ��ȡÿһ������
		string word;
		bool firstWord = true; // ���Ƶ���֮��Ŀո�
		while( stream >> word ) {
			if( firstWord == true )
				firstWord = false;
			else
				cout << " ";
			cout << Transform( word, trans_map );
		}
		cout << endl; // һ�н���
	}
}

int main( ) {
	ifstream map_file( "map_file.txt" );
	ifstream input( "input.txt" );
	Word_Transform( map_file, input );
	return 0;
}