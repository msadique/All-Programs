#include<iostream>
#include<string>
#include<map>
#include<fstream>
#include<ctype.h>
#define INPUT_FILE "data3.txt"
#define DICTIONARY "dict.txt"
#define COMP_FILE "compress.txt"
using namespace std;
typedef map< string, int > temp;
temp temporary, formal;
temp::iterator p;
typedef map< int, string > dict;
dict dictionary;
dict::iterator q;
int dict_size, inp_size;
int count = 0;
void collect( )
{
	ifstream fi;
	fi.open( INPUT_FILE );
	int n;	
	char x;
	string s;
	s.clear();
	if( ! fi ) 
		exit( 2 );
	while( !fi.eof( ))
	{
		x = fi.get(	);
		if(!isalpha(x)) 
			continue;
   
    	while ( ( x != ' ') && ( isalpha( x	) ) )
		{	
			if( fi.eof( )) 
				break;
    		s = s + x;
    		x = fi.get();
    	}
		p = temporary.find( s );
		if ( p == temporary.end( ))  		   //not find
		{
			temporary.insert( pair<string,int>( s , 1 ));	//insert new  word in dictionary
		}
		else
		{
			n=temporary[ s ];
			n++;
			temporary[ s ] = n;
		}
		s.clear();
	}
	inp_size = fi.tellg( );
	fi.close();
}

void make()
{	
	string s;
	ofstream fo;
	fo.open( DICTIONARY );
	if( !fo )
		exit( 1 );
	for(int i = 0; i < 256; i++ )
	{	
		s.clear( );
		s = s + char( i );
		formal.insert( pair<string, int>(s, count));
		count++;
	}
	for( p = temporary.begin(); p != temporary.end(); p++ )
	{	
		if( ( *p ).second >= 3 )
		{
			formal.insert(pair<string,int>((*p).first,count));
			count++;
		}
		else
			temporary.erase(p);
	}
	for( p = formal.begin(); p != formal.end(); p++ )
	{	
		fo<<(*p).first<<" "<<(*p).second<<endl;
		dictionary.insert(pair<int,string>((*p).second,(*p).first));
	}
	dict_size = fo.tellp();
	fo.close();
}

void compress()
{	
	int code;
	string s;
	char x;
	ifstream fi;
	ofstream fo;
	fi.open( INPUT_FILE );
	fo.open( COMP_FILE );
	if( fi.eof() || fo.eof() )
		exit( 4 );
	while( !fi.eof( ))
	{	
		s.clear();
		do
		{	
			x = fi.get();
			s = s + x;
			code = formal[ s ];
			p = formal.find( s );
			if( p != formal.end( ))   //found
			{
				fo<<code<<' ';
				break;
			}
		}while( 1 );
		
		fo<<code;
	}
	
}
int main()
{
	collect();
	make();
	compress();
	cout<<"\ntemporary size is "<<temporary.size();
	cout<<"\nno of word in dictionary"<<count;
	cout<<"\nSize of dictionary file is "<<dict_size;
	cout<<"\n"<<dictionary[257];
	return 0;
}


