/*  https://en.wikipedia.org/wiki/Fenwick_tree

Chef has just learned a new data structure - Fenwick tree. This data structure holds information about array of N elements and can process two types of operations:

Add some value to ith element of the array
Calculate sum of all elements on any prefix of the array
Both operations take O(log N) time. This data structure is also well known for its low memory usage. To be more precise, it needs exactly the same amount of memory as that of array.
Given some array A, first we build data structure in some other array T. Ti stores the sum of the elements Astart, Astart + 1, ..., Ai. Index start is calculated with formula start = Fdown(i) = (i & (i + 1)). Here "&" denotes bitwise AND operation.

So, in order to find a sum of elements A0, A1, ..., AL you start with index L and calculate sum of TL + TFdown(L)-1 + TFdown(Fdown(L)-1)-1 + ... + TFdown(Fdown(...(Fdown(L)-1)-1)-1. Usually it is performed with cycle that goes from L down to 0 with function Fdown and sums some elements from T. Chef wants to verify that the time complexity to calculate sum of A0, A1, A2, ..., AL is O(log L). In order to do so, he wonders how many times he has to access array T to calculate this sum. Help him to find this out.

Since Chef works with really big indices. The value of L can be very large and is provided to you in binary representation as concatenation of strings L1, L2 repeated N times and string L3.

Input

The first line of the input contains an integer T denoting the number of test cases. The description of T test cases follows.

The only line of each test case contains three non-empty strings L1, L2, L3 and an integer N. Strings will contain only characters 0 and 1. To obtain binary representation of index L concatenate L1 with L2 repeated N times and with L3. You are guaranteed that the index will be positive.

Output

For each test case, output a single line containing number of times Fenwick tree data structure will access array T in order to compute sum of A0, A1, A2, ..., AL.

Constraints

1 ≤ T ≤ 300
1 ≤ Length(Li) ≤ 1000
1 ≤ N ≤ 106
Subtasks

Subtask #1 (20 points): |L1| + |L2| * N + |L3| ≤ 60
Subtask #2 (30 points): 1 ≤ T ≤ 30, 1 ≤ N ≤ 100
Subtask #3 (50 points): No additional constraints
Example

Input:
4
001 100 011 4
1000 1101 100 3
1010 001 101 4
010 101 000 4

Output:
6
12
8
10
*/
#include< iostream >
#include< string >
#include< cstring >
using namespace std;
 
inline int countfunclast( string s, int last ){
	int noOf1 = 0;
	for( int i = last; i >= 0; i-- ){
		if( s[ i ] == '1' )
			noOf1++;
	}
	return noOf1;
}
inline int countfunc(string s){
	int noOf1 = 0;
	for( int i = s.size() - 1 ; i >= 0 ; i-- ){
		if( s[ i ] == '1' )
			noOf1++;
	}
	return noOf1;
} 
int main(){
 
	std::ios::sync_with_stdio(false); cin.tie(NULL);
	int test;	
	cin>>test;
	register int i = 0;
	
	
	while( test-- ){
	bool thr1 = thr2 = thr3 = cat1 = cat2 = cat3 = catd = thrd =  thr2c = cat2c = false;
	string s, l1, l2, l3;
	int n;
	cin>>l1>>l2>>l3>>n;
	
	int count;
	if( l1.find( '1' ) != -1 ) cat1 = true;				//if(!cat)= string is empty
	if( l2.find( '1' ) != -1 ) cat2 = true;				//if(!thr)= string contains only 1
	if( l3.find( '1' ) != -1 ) cat3 = true; 		
	if( l1.find( '0' ) != -1 ) thr1 = true;
	if( l2.find( '0' ) != -1 ) thr2 = true;
	if( l3.find( '0' ) != -1 ) thr3 = true; 
	
	
	int last1 = l1.find_last_of( '0' );
	int last2 = l2.find_last_of( '0' );
	int last3 = l3.find_last_of( '0' );
	int count1, count2, count3;
	count1 = countfunc( l1 );
	count2 = countfunc( l2 );
	count3 = countfunc( l3 );

	if( !thr1 && !thr2 && !thr3 || !cat1 && !cat2 && !cat3 )
			count = 1;
	else{
		count = 1;
		if( !thr3 ){  	//l3 empty
			if( !thr2 ){			//l2 empty
				if( !thr1 ){      	//l1 empty
					count = 1;
				}
				else{			// l1 not empty
					count += countfunclast( l1, last1 );
				}
				
			}				
			else{			// l2 not empty
				count += countfunclast( l2, last2 ) + ( n - 1 ) * count2 + count1;
			}
	
		}				// l3 not empty	
		else{
			count += countfunclast( l3, last3 ) + n * count2 + count1;
		}
	 		
	}
	cout<<count<<endl;
	}
	return 0;
	
}
 