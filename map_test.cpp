#include "ft_containers.hpp"
#include <iostream>
#include <list>
#include <map>

#define RED "\033[1;31m"
#define GREEN "\033[1;33m"
#define RESET "\033[0m"

template < class key >

class Cmp {

public:
	Cmp(void) {};
	bool operator()(const int &x, const int &y) const { return (x > y);} 
};

template < class key, class value, class Cmp>
void print_2m (std::map < key, value, Cmp> &a, ft::map < key, value, Cmp > &b) {

	std::cout << "std::map size: " << a.size() << std::endl;
	std::cout << "ft::map size: " << b.size() << std::endl;
	std::cout << std::endl;
	std::cout << "std::map elems: " << std:: endl;
	for(typename std::map < key, value, Cmp>::iterator beg = a.begin();
		beg != a.end(); beg++)
		std::cout  << (*beg).first << " ==> " <<  (*beg).second << "| ";
	std::cout << std::endl;
	std::cout << "ft::map elems: " << std:: endl;
	for(typename ft::map < key, value, Cmp>::iterator beg = b.begin();
		beg != b.end(); beg++)
		std::cout << (*beg).first << " ==> " <<  (*beg).second << "| ";
	std::cout << std::endl << std::endl;

}

int map_test(void) {
{
	std::cout <<  "\033c";
	std::cout << std::endl << GREEN << "*** Constructor ***" << RESET << std::endl;
	std::cout << RED << "explicit map (const key_compare& comp = key_compare(),\
const allocator_type& alloc = allocator_type())" << RESET << std::endl;
	std::map < int, std::string > a;
	ft::map < int, std::string > b;

	std::cout << "std::map size: " << a.size() << std::endl;
	std::cout << "ft::map size: " << b.size() << std::endl;
}
{
	std::cout << std::endl << RED << "map (InputIterator first, InputIterator last, \
const key_compare& comp = key_compare(), const allocator_type& alloc =\
 allocator_type());" << RESET << std::endl;
 	std::cout << std::endl;
	
	std::list < std::pair < int, std::string > > c;
	c.push_back(std::pair< int, std::string>(1, "123"));
	c.push_back(std::pair< int, std::string>(2, "456"));
	c.push_back(std::pair< int, std::string>(3, "79"));
	c.push_back(std::pair< int, std::string>(4, "dsaf"));
	c.push_back(std::pair< int, std::string>(5, "sdf"));
	c.push_back(std::pair< int, std::string>(6, "asd"));
	c.push_back(std::pair< int, std::string>(7, "zxc"));
	c.push_back(std::pair< int, std::string>(8, "yjyu"));
	c.push_back(std::pair< int, std::string>(9, "mi.l8"));
	c.push_back(std::pair< int, std::string>(10, "xczz"));
	c.push_back(std::pair< int, std::string>(11, "ipi"));
	c.push_back(std::pair< int, std::string>(12, "qwr"));
	std::map < int, std::string > a(c.begin(), c.end());
	ft::map < int, std::string > b(c.begin(), c.end());

	std::cout << "list: " << std::endl;
	for(std::list < std::pair< int, std::string> >::iterator beg = c.begin();
		beg != c.end(); beg++)
		std::cout << "key: " << (*beg).first << " value : " <<  (*beg).second << std::endl;
	std::cout << std::endl;
	print_2m(a, b);
	getchar();
	std::cout <<  "\033c";
}
{
	std::cout << std::endl << RED << "map (const map& x);" << RESET << std::endl;
	std::cout << std::endl;
	
	std::map < int, std::string > aa;
	ft::map < int, std::string > bb;

	aa.insert(std::pair< int, std::string>(45, "123"));
	aa.insert(std::pair< int, std::string>(82, "456"));
	aa.insert(std::pair< int, std::string>(12, "79"));
	aa.insert(std::pair< int, std::string>(57, "dsaf"));
	aa.insert(std::pair< int, std::string>(69, "sdf"));
	aa.insert(std::pair< int, std::string>(123, "asd"));
	aa.insert(std::pair< int, std::string>(457, "zxc"));
	aa.insert(std::pair< int, std::string>(1, "yjyu"));
	aa.insert(std::pair< int, std::string>(457, "mi.l8"));
	aa.insert(std::pair< int, std::string>(418, "xczz"));
	aa.insert(std::pair< int, std::string>(77, "ipi"));
	aa.insert( std::pair< int, std::string>(427, "qwr"));

	bb.insert(std::pair< int, std::string>(45, "123"));
	bb.insert(std::pair< int, std::string>(82, "456"));
	bb.insert(std::pair< int, std::string>(12, "79"));
	bb.insert(std::pair< int, std::string>(57, "dsaf"));
	bb.insert(std::pair< int, std::string>(69, "sdf"));
	bb.insert(std::pair< int, std::string>(123, "asd"));
	bb.insert(std::pair< int, std::string>(457, "zxc"));
	bb.insert(std::pair< int, std::string>(1, "yjyu"));
	bb.insert(std::pair< int, std::string>(457, "mi.l8"));
	bb.insert(std::pair< int, std::string>(418, "xczz"));
	bb.insert(std::pair< int, std::string>(77, "ipi"));
	bb.insert(std::pair< int, std::string>(427, "qwr"));

	print_2m(aa, bb);

	std::map < int, std::string > a(aa);
	ft::map < int, std::string > b(bb);

	std::cout << "После применения:" << std::endl;

	print_2m(a, b);
	print_2m(aa, bb);
	getchar();
	std::cout <<  "\033c";

}
{
	std::cout << std::endl << GREEN << "*** Iterators ***" << RESET << std::endl;
	std::cout << RED << "begin, end" << RESET << std::endl;
	std::map < int, std::string > a;
	ft::map < int, std::string > b;

	a.insert(std::pair< int, std::string>(45, "123"));
	a.insert(std::pair< int, std::string>(82, "456"));
	a.insert(std::pair< int, std::string>(12, "79"));
	a.insert(std::pair< int, std::string>(57, "dsaf"));
	a.insert(std::pair< int, std::string>(69, "sdf"));
	a.insert(std::pair< int, std::string>(123, "asd"));
	a.insert(std::pair< int, std::string>(457, "zxc"));
	a.insert(std::pair< int, std::string>(1, "yjyu"));
	a.insert(std::pair< int, std::string>(457, "mi.l8"));
	a.insert(std::pair< int, std::string>(418, "xczz"));
	a.insert(std::pair< int, std::string>(77, "ipi"));
	a.insert( std::pair< int, std::string>(427, "qwr"));

	b.insert(std::pair< int, std::string>(45, "123"));
	b.insert(std::pair< int, std::string>(82, "456"));
	b.insert(std::pair< int, std::string>(12, "79"));
	b.insert(std::pair< int, std::string>(57, "dsaf"));
	b.insert(std::pair< int, std::string>(69, "sdf"));
	b.insert(std::pair< int, std::string>(123, "asd"));
	b.insert(std::pair< int, std::string>(457, "zxc"));
	b.insert(std::pair< int, std::string>(1, "yjyu"));
	b.insert(std::pair< int, std::string>(457, "mi.l8"));
	b.insert(std::pair< int, std::string>(418, "xczz"));
	b.insert(std::pair< int, std::string>(77, "ipi"));
	b.insert(std::pair< int, std::string>(427, "qwr"));

	std::cout << "std::map elems: " << std:: endl;
	for(std::map < int, std::string >::iterator beg = a.begin();
		beg != a.end(); beg++)
		std::cout << "key: " << (*beg).first << " value : " <<  (*beg).second << std::endl;
	std::cout << std::endl;
	std::cout << "ft::map elems: " << std:: endl;
	for(ft::map < int, std::string >::iterator beg = b.begin();
		beg != b.end(); beg++)
		std::cout << "key: " << (*beg).first << " value : " <<  (*beg).second << std::endl;
	std::cout << std::endl;
	getchar();
	std::cout <<  "\033c";

	std::cout << RED << "const begin, const end" << RESET << std::endl;

	std::cout << "std::map elems: " << std:: endl;
	for(std::map < int, std::string >::const_iterator beg = a.begin();
		beg != a.end(); beg++)
		std::cout << "key: " << (*beg).first << " value : " <<  (*beg).second << std::endl;
	std::cout << std::endl;
	std::cout << "ft::map elems: " << std:: endl;
	for(ft::map < int, std::string >::const_iterator beg = b.begin();
		beg != b.end(); beg++)
		std::cout << "key: " << (*beg).first << " value : " <<  (*beg).second << std::endl;
	std::cout << std::endl;
	getchar();
	std::cout <<  "\033c";

	std::cout << RED << "rbegin, rend" << RESET << std::endl;

	std::cout << "std::map elems: " << std:: endl;
	for(std::map < int, std::string >::reverse_iterator rbeg = a.rbegin();
		rbeg != a.rend(); rbeg++)
		std::cout << "key: " << (*rbeg).first << " value : " <<  (*rbeg).second << std::endl;
	std::cout << std::endl;
	std::cout << "ft::map elems: " << std:: endl;
	for(ft::map < int, std::string >::reverse_iterator rbeg = b.rbegin();
		rbeg != b.rend(); rbeg++)
		std::cout << "key: " << (*rbeg).first << " value : " <<  (*rbeg).second << std::endl;
	std::cout << std::endl;
	getchar();
	std::cout <<  "\033c";

	std::cout << RED << "const rbegin, const rend" << RESET << std::endl;

	std::cout << "std::map elems: " << std:: endl;
	for(std::map < int, std::string >::const_reverse_iterator rbeg = a.rbegin();
		rbeg != a.rend(); rbeg++)
		std::cout << "key: " << (*rbeg).first << " value : " <<  (*rbeg).second << std::endl;
	std::cout << std::endl;
	std::cout << "ft::map elems: " << std:: endl;
	for(ft::map < int, std::string >::const_reverse_iterator rbeg = b.rbegin();
		rbeg != b.rend(); rbeg++)
		std::cout << "key: " << (*rbeg).first << " value : " <<  (*rbeg).second << std::endl;
	std::cout << std::endl;
	getchar();
	std::cout <<  "\033c";
}
{
	std::cout << std::endl << GREEN << "*** Capacity ***" << RESET << std::endl;
	std::cout << RED << "empty, size, maxsize" << RESET << std::endl;

	std::map < int, std::string > a;
	ft::map < int, std::string > b;

	print_2m(a, b);
	std::cout << "std::map - empty: " << a.empty() << std::endl;
	std::cout << "ft::map - empty: " << b.empty() << std::endl;


	a.insert(std::pair< int, std::string>(45, "123"));
	a.insert(std::pair< int, std::string>(82, "456"));
	a.insert(std::pair< int, std::string>(12, "79"));
	a.insert(std::pair< int, std::string>(57, "dsaf"));
	a.insert(std::pair< int, std::string>(69, "sdf"));
	a.insert(std::pair< int, std::string>(123, "asd"));
	a.insert(std::pair< int, std::string>(457, "zxc"));
	a.insert(std::pair< int, std::string>(1, "yjyu"));
	a.insert(std::pair< int, std::string>(457, "mi.l8"));
	a.insert(std::pair< int, std::string>(418, "xczz"));
	a.insert(std::pair< int, std::string>(77, "ipi"));
	a.insert( std::pair< int, std::string>(427, "qwr"));

	b.insert(std::pair< int, std::string>(45, "123"));
	b.insert(std::pair< int, std::string>(82, "456"));
	b.insert(std::pair< int, std::string>(12, "79"));
	b.insert(std::pair< int, std::string>(57, "dsaf"));
	b.insert(std::pair< int, std::string>(69, "sdf"));
	b.insert(std::pair< int, std::string>(123, "asd"));
	b.insert(std::pair< int, std::string>(457, "zxc"));
	b.insert(std::pair< int, std::string>(1, "yjyu"));
	b.insert(std::pair< int, std::string>(457, "mi.l8"));
	b.insert(std::pair< int, std::string>(418, "xczz"));
	b.insert(std::pair< int, std::string>(77, "ipi"));
	b.insert(std::pair< int, std::string>(427, "qwr"));

	print_2m(a, b);
	std::cout << "std::map - empty: " << a.empty() << std::endl;
	std::cout << "ft::map - empty: " << b.empty() << std::endl;
	std::cout << "std::map - maxsize: " << a.max_size() << std::endl;
	std::cout << "ft::map - maxsize: " << b.max_size() << std::endl;
	std::cout << std::endl;
	getchar();
	std::cout <<  "\033c";
}
{
	std::cout << std::endl << GREEN << "*** Element access ***" << RESET << std::endl;
	std::cout << RED << "operator[]" << RESET << std::endl;
	
	std::map < int, std::string > a;
	ft::map < int, std::string > b;

	a.insert(std::pair< int, std::string>(45, "123"));
	a.insert(std::pair< int, std::string>(82, "456"));
	a.insert(std::pair< int, std::string>(12, "79"));
	a.insert(std::pair< int, std::string>(57, "dsaf"));
	a.insert(std::pair< int, std::string>(69, "sdf"));
	a.insert(std::pair< int, std::string>(123, "asd"));
	a.insert(std::pair< int, std::string>(457, "zxc"));
	a.insert(std::pair< int, std::string>(1, "yjyu"));
	a.insert(std::pair< int, std::string>(457, "mi.l8"));
	a.insert(std::pair< int, std::string>(418, "xczz"));
	a.insert(std::pair< int, std::string>(77, "ipi"));
	a.insert( std::pair< int, std::string>(427, "qwr"));

	b.insert(std::pair< int, std::string>(45, "123"));
	b.insert(std::pair< int, std::string>(82, "456"));
	b.insert(std::pair< int, std::string>(12, "79"));
	b.insert(std::pair< int, std::string>(57, "dsaf"));
	b.insert(std::pair< int, std::string>(69, "sdf"));
	b.insert(std::pair< int, std::string>(123, "asd"));
	b.insert(std::pair< int, std::string>(457, "zxc"));
	b.insert(std::pair< int, std::string>(1, "yjyu"));
	b.insert(std::pair< int, std::string>(457, "mi.l8"));
	b.insert(std::pair< int, std::string>(418, "xczz"));
	b.insert(std::pair< int, std::string>(77, "ipi"));
	b.insert(std::pair< int, std::string>(427, "qwr"));

	print_2m(a, b);

	std::cout << "std::map element key: 12 " << a[12] << std::endl;
	std::cout << "ft::map element key: 12 " << b[12] << std::endl;
	std::cout << "std::map element key: 427 " << a[427] << std::endl;
	std::cout << "ft::map element key: 427 " << b[427] << std::endl;
	std::cout << "std::map element key: 1200 " << a[1200] << std::endl;
	std::cout << "ft::map element key: 1200 " << b[1200] << std::endl;

	a[1200] = "abcde";
	b[1200] = "abcde";

	std::cout << "std::map element key: 1200 " << a[1200] << std::endl;
	std::cout << "ft::map element key: 1200 " << b[1200] << std::endl;

	std::cout << std::endl;
	print_2m(a, b);
	getchar();
	std::cout <<  "\033c";

}
{
	std::cout << std::endl << GREEN << "*** Modifiers ***" << RESET << std::endl;
	std::cout << RED << "pair<iterator,bool> insert (const value_type& val)" << RESET << std::endl;

	std::map < int, std::string > a;
	ft::map < int, std::string > b;

	print_2m(a, b);

	a.insert(std::pair< int, std::string>(457, "mi.l8"));
	b.insert(std::pair< int, std::string>(457, "mi.l8"));

	print_2m(a, b);

	/*for (int i = 0; i < 1500; i++)
	{
		a.insert(std::pair< int, std::string>(rand(), "mi.l8"));
		b.insert(std::pair< int, std::string>(rand(), "mi.l8"));
	}
	print_2m(a, b);*/
	getchar();
	std::cout <<  "\033c";
}
{
	std::cout << std::endl << RED << "iterator insert (iterator hint, const value_type& val);" << RESET << std::endl;
	
	std::map < int, std::string > a;
	ft::map < int, std::string > b;

	a.insert(std::pair< int, std::string>(45, "123"));
	a.insert(std::pair< int, std::string>(82, "456"));
	a.insert(std::pair< int, std::string>(12, "79"));
	a.insert(std::pair< int, std::string>(57, "dsaf"));
	a.insert(std::pair< int, std::string>(69, "sdf"));
	a.insert(std::pair< int, std::string>(123, "asd"));
	a.insert(std::pair< int, std::string>(457, "zxc"));
	a.insert(std::pair< int, std::string>(1, "yjyu"));
	a.insert(std::pair< int, std::string>(457, "mi.l8"));
	a.insert(std::pair< int, std::string>(418, "xczz"));
	a.insert(std::pair< int, std::string>(77, "ipi"));
	a.insert( std::pair< int, std::string>(427, "qwr"));

	b.insert(std::pair< int, std::string>(45, "123"));
	b.insert(std::pair< int, std::string>(82, "456"));
	b.insert(std::pair< int, std::string>(12, "79"));
	b.insert(std::pair< int, std::string>(57, "dsaf"));
	b.insert(std::pair< int, std::string>(69, "sdf"));
	b.insert(std::pair< int, std::string>(123, "asd"));
	b.insert(std::pair< int, std::string>(457, "zxc"));
	b.insert(std::pair< int, std::string>(1, "yjyu"));
	b.insert(std::pair< int, std::string>(457, "mi.l8"));
	b.insert(std::pair< int, std::string>(418, "xczz"));
	b.insert(std::pair< int, std::string>(77, "ipi"));
	b.insert(std::pair< int, std::string>(427, "qwr"));

	print_2m(a, b);
	std::map < int, std::string>::iterator beg1 = a.begin();
	ft::map < int, std::string>::iterator beg2 = b.begin();
	beg1++;
	beg1++;
	beg1++;
	beg2++;
	beg2++;
	beg2++;
	a.insert(beg1, std::pair< int, std::string >(1267, "gggg"));
	b.insert(beg2, std::pair< int, std::string >(1267, "gggg"));
	print_2m(a, b);
	std::map < int, std::string>::iterator beg12 = a.begin();
	ft::map < int, std::string>::iterator beg22 = b.begin();
	beg12++;
	beg12++;
	beg12++;
	beg22++;
	beg22++;
	beg22++;
	a.insert(beg12, std::pair< int, std::string >(2, "gggg"));
	b.insert(beg22, std::pair< int, std::string >(2, "gggg"));
	print_2m(a, b);
	getchar();
	std::cout <<  "\033c";
}
{
	std::cout << std::endl << RED << "iterator insert (iterator hint, const value_type& val);" << RESET << std::endl;
	
	std::list < std::pair < int, std::string > > c;
	c.push_back(std::pair< int, std::string>(1, "123"));
	c.push_back(std::pair< int, std::string>(2, "456"));
	c.push_back(std::pair< int, std::string>(3, "79"));
	c.push_back(std::pair< int, std::string>(4, "dsaf"));
	c.push_back(std::pair< int, std::string>(5, "sdf"));
	c.push_back(std::pair< int, std::string>(6, "asd"));
	c.push_back(std::pair< int, std::string>(7, "zxc"));
	c.push_back(std::pair< int, std::string>(8, "yjyu"));
	c.push_back(std::pair< int, std::string>(9, "mi.l8"));
	c.push_back(std::pair< int, std::string>(10, "xczz"));
	c.push_back(std::pair< int, std::string>(11, "ipi"));
	c.push_back(std::pair< int, std::string>(12, "qwr"));
	std::map < int, std::string > a;
	ft::map < int, std::string > b;

	a.insert(c.begin(), c.end());
	b.insert(c.begin(), c.end());

	std::cout << "list: " << std::endl;
	for(std::list < std::pair< int, std::string> >::iterator beg = c.begin();
		beg != c.end(); beg++)
		std::cout << "key: " << (*beg).first << " value : " <<  (*beg).second << std::endl;
	std::cout << std::endl;
	print_2m(a, b);
	getchar();
	std::cout <<  "\033c";
}
{
	std::cout << std::endl << RED << "void erase (iterator position);" << RESET << std::endl;

	std::map < int, std::string > a;
	ft::map < int, std::string > b;

	a.insert(std::pair< int, std::string>(45, "123"));
	a.insert(std::pair< int, std::string>(82, "456"));
	a.insert(std::pair< int, std::string>(12, "79"));
	a.insert(std::pair< int, std::string>(57, "dsaf"));
	a.insert(std::pair< int, std::string>(69, "sdf"));
	a.insert(std::pair< int, std::string>(123, "asd"));
	a.insert(std::pair< int, std::string>(457, "zxc"));
	a.insert(std::pair< int, std::string>(1, "yjyu"));
	a.insert(std::pair< int, std::string>(457, "mi.l8"));
	a.insert(std::pair< int, std::string>(418, "xczz"));
	a.insert(std::pair< int, std::string>(77, "ipi"));
	a.insert( std::pair< int, std::string>(427, "qwr"));

	b.insert(std::pair< int, std::string>(45, "123"));
	b.insert(std::pair< int, std::string>(82, "456"));
	b.insert(std::pair< int, std::string>(12, "79"));
	b.insert(std::pair< int, std::string>(57, "dsaf"));
	b.insert(std::pair< int, std::string>(69, "sdf"));
	b.insert(std::pair< int, std::string>(123, "asd"));
	b.insert(std::pair< int, std::string>(457, "zxc"));
	b.insert(std::pair< int, std::string>(1, "yjyu"));
	b.insert(std::pair< int, std::string>(457, "mi.l8"));
	b.insert(std::pair< int, std::string>(418, "xczz"));
	b.insert(std::pair< int, std::string>(77, "ipi"));
	b.insert(std::pair< int, std::string>(427, "qwr"));

	print_2m(a, b);
	std::map < int, std::string>::iterator beg1 = a.begin();
	ft::map < int, std::string>::iterator beg2 = b.begin();
	beg1++;
	beg1++;
	beg1++;
	beg2++;
	beg2++;
	beg2++;
	a.erase(beg1);
	b.erase(beg2);
	print_2m(a, b);
	std::map < int, std::string>::iterator beg12 = a.begin();
	ft::map < int, std::string>::iterator beg22 = b.begin();
	a.erase(beg12);
	b.erase(beg22);
	print_2m(a, b);
	getchar();
	std::cout <<  "\033c";
}
{
	std::cout << std::endl << RED << "size_type erase (const key_type& k)" << RESET << std::endl;

	std::map < int, std::string > a;
	ft::map < int, std::string > b;

	a.insert(std::pair< int, std::string>(45, "123"));
	a.insert(std::pair< int, std::string>(82, "456"));
	a.insert(std::pair< int, std::string>(12, "79"));
	a.insert(std::pair< int, std::string>(57, "dsaf"));
	a.insert(std::pair< int, std::string>(69, "sdf"));
	a.insert(std::pair< int, std::string>(123, "asd"));
	a.insert(std::pair< int, std::string>(457, "zxc"));
	a.insert(std::pair< int, std::string>(1, "yjyu"));
	a.insert(std::pair< int, std::string>(457, "mi.l8"));
	a.insert(std::pair< int, std::string>(418, "xczz"));
	a.insert(std::pair< int, std::string>(77, "ipi"));
	a.insert( std::pair< int, std::string>(427, "qwr"));

	b.insert(std::pair< int, std::string>(45, "123"));
	b.insert(std::pair< int, std::string>(82, "456"));
	b.insert(std::pair< int, std::string>(12, "79"));
	b.insert(std::pair< int, std::string>(57, "dsaf"));
	b.insert(std::pair< int, std::string>(69, "sdf"));
	b.insert(std::pair< int, std::string>(123, "asd"));
	b.insert(std::pair< int, std::string>(457, "zxc"));
	b.insert(std::pair< int, std::string>(1, "yjyu"));
	b.insert(std::pair< int, std::string>(457, "mi.l8"));
	b.insert(std::pair< int, std::string>(418, "xczz"));
	b.insert(std::pair< int, std::string>(77, "ipi"));
	b.insert(std::pair< int, std::string>(427, "qwr"));

	print_2m(a, b);

	std::cout << "После удаления key 45: " << std::endl;
	a.erase(45);
	b.erase(45);
	print_2m(a, b);
	std::cout << "После удаления key 427: " << std::endl;
	a.erase(427);
	b.erase(427);
	print_2m(a, b);
	std::cout << "После удаления key 457: " << std::endl;
	a.erase(457);
	b.erase(457);
	print_2m(a, b);
	getchar();
	std::cout <<  "\033c";

}
{
	std::cout << std::endl << RED << "void erase (itertor first, iterator last)" << RESET << std::endl;

	std::map < int, std::string > a;
	ft::map < int, std::string > b;

	a.insert(std::pair< int, std::string>(45, "123"));
	a.insert(std::pair< int, std::string>(82, "456"));
	a.insert(std::pair< int, std::string>(12, "79"));
	a.insert(std::pair< int, std::string>(57, "dsaf"));
	a.insert(std::pair< int, std::string>(69, "sdf"));
	a.insert(std::pair< int, std::string>(123, "asd"));
	a.insert(std::pair< int, std::string>(457, "zxc"));
	a.insert(std::pair< int, std::string>(1, "yjyu"));
	a.insert(std::pair< int, std::string>(457, "mi.l8"));
	a.insert(std::pair< int, std::string>(418, "xczz"));
	a.insert(std::pair< int, std::string>(77, "ipi"));
	a.insert( std::pair< int, std::string>(427, "qwr"));

	b.insert(std::pair< int, std::string>(45, "123"));
	b.insert(std::pair< int, std::string>(82, "456"));
	b.insert(std::pair< int, std::string>(12, "79"));
	b.insert(std::pair< int, std::string>(57, "dsaf"));
	b.insert(std::pair< int, std::string>(69, "sdf"));
	b.insert(std::pair< int, std::string>(123, "asd"));
	b.insert(std::pair< int, std::string>(457, "zxc"));
	b.insert(std::pair< int, std::string>(1, "yjyu"));
	b.insert(std::pair< int, std::string>(457, "mi.l8"));
	b.insert(std::pair< int, std::string>(418, "xczz"));
	b.insert(std::pair< int, std::string>(77, "ipi"));
	b.insert(std::pair< int, std::string>(427, "qwr"));

	print_2m(a, b);

	a.erase(a.begin(),  --(a.end()));
	b.erase(b.begin(), --(b.end()));

	print_2m(a, b);
	getchar();
	std::cout <<  "\033c";

}
{
	std::cout << std::endl << RED << "void swap (map& x)" << RESET << std::endl;

	std::map < int, std::string > a;
	std::map < int, std::string > aa;
	ft::map < int, std::string > b;
	ft::map < int, std::string > bb;

	std::cout << "До применения: " << std::endl;

	a.insert(std::pair< int, std::string>(45, "123"));
	a.insert(std::pair< int, std::string>(82, "456"));
	a.insert(std::pair< int, std::string>(12, "79"));
	a.insert(std::pair< int, std::string>(57, "dsaf"));
	a.insert(std::pair< int, std::string>(69, "sdf"));
	aa.insert(std::pair< int, std::string>(123, "asd"));
	aa.insert(std::pair< int, std::string>(457, "zxc"));
	aa.insert(std::pair< int, std::string>(1, "yjyu"));
	aa.insert(std::pair< int, std::string>(457, "mi.l8"));
	aa.insert(std::pair< int, std::string>(418, "xczz"));
	aa.insert(std::pair< int, std::string>(77, "ipi"));
	aa.insert( std::pair< int, std::string>(427, "qwr"));

	b.insert(std::pair< int, std::string>(45, "123"));
	b.insert(std::pair< int, std::string>(82, "456"));
	b.insert(std::pair< int, std::string>(12, "79"));
	b.insert(std::pair< int, std::string>(57, "dsaf"));
	b.insert(std::pair< int, std::string>(69, "sdf"));
	bb.insert(std::pair< int, std::string>(123, "asd"));
	bb.insert(std::pair< int, std::string>(457, "zxc"));
	bb.insert(std::pair< int, std::string>(1, "yjyu"));
	bb.insert(std::pair< int, std::string>(457, "mi.l8"));
	bb.insert(std::pair< int, std::string>(418, "xczz"));
	bb.insert(std::pair< int, std::string>(77, "ipi"));
	bb.insert( std::pair< int, std::string>(427, "qwr"));

	print_2m(a, b);
	print_2m(aa, bb);

	std::cout << "После применения: " << std::endl;


	a.swap(aa);
	b.swap(bb);

	print_2m(a, b);
	print_2m(aa, bb);
	getchar();
	std::cout <<  "\033c";
}
{
	
	std::cout << std::endl << RED << "void clear()" << RESET << std::endl;

	std::map < int, std::string > a;
	ft::map < int, std::string > b;

	std::cout << "До применения:" << std::endl;

	a.insert(std::pair< int, std::string>(45, "123"));
	a.insert(std::pair< int, std::string>(82, "456"));
	a.insert(std::pair< int, std::string>(12, "79"));
	a.insert(std::pair< int, std::string>(57, "dsaf"));
	a.insert(std::pair< int, std::string>(69, "sdf"));
	a.insert(std::pair< int, std::string>(123, "asd"));
	a.insert(std::pair< int, std::string>(457, "zxc"));
	a.insert(std::pair< int, std::string>(1, "yjyu"));
	a.insert(std::pair< int, std::string>(457, "mi.l8"));
	a.insert(std::pair< int, std::string>(418, "xczz"));
	a.insert(std::pair< int, std::string>(77, "ipi"));
	a.insert( std::pair< int, std::string>(427, "qwr"));

	b.insert(std::pair< int, std::string>(45, "123"));
	b.insert(std::pair< int, std::string>(82, "456"));
	b.insert(std::pair< int, std::string>(12, "79"));
	b.insert(std::pair< int, std::string>(57, "dsaf"));
	b.insert(std::pair< int, std::string>(69, "sdf"));
	b.insert(std::pair< int, std::string>(123, "asd"));
	b.insert(std::pair< int, std::string>(457, "zxc"));
	b.insert(std::pair< int, std::string>(1, "yjyu"));
	b.insert(std::pair< int, std::string>(457, "mi.l8"));
	b.insert(std::pair< int, std::string>(418, "xczz"));
	b.insert(std::pair< int, std::string>(77, "ipi"));
	b.insert(std::pair< int, std::string>(427, "qwr"));

	print_2m(a, b);

	std::cout << "После применения: " << std::endl;

	a.clear();
	b.clear();

	print_2m(a, b);

	a.insert(std::pair< int, std::string>(45, "123"));
	a.insert(std::pair< int, std::string>(82, "456"));
	a.insert(std::pair< int, std::string>(12, "79"));
	a.insert(std::pair< int, std::string>(57, "dsaf"));
	a.insert(std::pair< int, std::string>(69, "sdf"));
	a.insert(std::pair< int, std::string>(123, "asd"));
	a.insert(std::pair< int, std::string>(457, "zxc"));
	a.insert(std::pair< int, std::string>(1, "yjyu"));
	a.insert(std::pair< int, std::string>(457, "mi.l8"));
	a.insert(std::pair< int, std::string>(418, "xczz"));
	a.insert(std::pair< int, std::string>(77, "ipi"));
	a.insert( std::pair< int, std::string>(427, "qwr"));

	b.insert(std::pair< int, std::string>(45, "123"));
	b.insert(std::pair< int, std::string>(82, "456"));
	b.insert(std::pair< int, std::string>(12, "79"));
	b.insert(std::pair< int, std::string>(57, "dsaf"));
	b.insert(std::pair< int, std::string>(69, "sdf"));
	b.insert(std::pair< int, std::string>(123, "asd"));
	b.insert(std::pair< int, std::string>(457, "zxc"));
	b.insert(std::pair< int, std::string>(1, "yjyu"));
	b.insert(std::pair< int, std::string>(457, "mi.l8"));
	b.insert(std::pair< int, std::string>(418, "xczz"));
	b.insert(std::pair< int, std::string>(77, "ipi"));
	b.insert(std::pair< int, std::string>(427, "qwr"));

	print_2m(a, b);
	getchar();
	std::cout <<  "\033c";

}
{
	std::cout << std::endl << GREEN << "*** Observers ***" << RESET << std::endl;
	std::cout << std::endl << RED << "key_compare" << RESET << std::endl;

	std::map < int, std::string > a;
	ft::map < int, std::string > b;

	a.insert(std::pair< int, std::string>(45, "123"));
	a.insert(std::pair< int, std::string>(82, "456"));
	a.insert(std::pair< int, std::string>(12, "79"));
	a.insert(std::pair< int, std::string>(57, "dsaf"));
	a.insert(std::pair< int, std::string>(69, "sdf"));
	a.insert(std::pair< int, std::string>(123, "asd"));
	a.insert(std::pair< int, std::string>(457, "zxc"));
	a.insert(std::pair< int, std::string>(1, "yjyu"));
	a.insert(std::pair< int, std::string>(457, "mi.l8"));
	a.insert(std::pair< int, std::string>(418, "xczz"));
	a.insert(std::pair< int, std::string>(77, "ipi"));
	a.insert( std::pair< int, std::string>(427, "qwr"));

	b.insert(std::pair< int, std::string>(45, "123"));
	b.insert(std::pair< int, std::string>(82, "456"));
	b.insert(std::pair< int, std::string>(12, "79"));
	b.insert(std::pair< int, std::string>(57, "dsaf"));
	b.insert(std::pair< int, std::string>(69, "sdf"));
	b.insert(std::pair< int, std::string>(123, "asd"));
	b.insert(std::pair< int, std::string>(457, "zxc"));
	b.insert(std::pair< int, std::string>(1, "yjyu"));
	b.insert(std::pair< int, std::string>(457, "mi.l8"));
	b.insert(std::pair< int, std::string>(418, "xczz"));
	b.insert(std::pair< int, std::string>(77, "ipi"));
	b.insert(std::pair< int, std::string>(427, "qwr"));

	std::cout << "std::map: " << std::endl;

	std::cout << a.key_comp()(45, 12) << std::endl;
	std::cout << a.key_comp()(12, 45) << std::endl;

	std::cout << "ft::map: " << std::endl;

	std::cout << b.key_comp()(45, 12) << std::endl;
	std::cout << b.key_comp()(12, 45) << std::endl;
	getchar();
	std::cout <<  "\033c";
}
{
	std::map < int, std::string, Cmp<int> > a;
	ft::map < int, std::string, Cmp <int> > b;

	a.insert(std::pair< int, std::string>(45, "123"));
	a.insert(std::pair< int, std::string>(82, "456"));
	a.insert(std::pair< int, std::string>(12, "79"));
	a.insert(std::pair< int, std::string>(57, "dsaf"));
	a.insert(std::pair< int, std::string>(69, "sdf"));
	a.insert(std::pair< int, std::string>(123, "asd"));
	a.insert(std::pair< int, std::string>(457, "zxc"));
	a.insert(std::pair< int, std::string>(1, "yjyu"));
	a.insert(std::pair< int, std::string>(457, "mi.l8"));
	a.insert(std::pair< int, std::string>(418, "xczz"));
	a.insert(std::pair< int, std::string>(77, "ipi"));
	a.insert(std::pair< int, std::string>(427, "qwr"));

	b.insert(std::pair< int, std::string>(45, "123"));
	b.insert(std::pair< int, std::string>(82, "456"));
	b.insert(std::pair< int, std::string>(12, "79"));
	b.insert(std::pair< int, std::string>(57, "dsaf"));
	b.insert(std::pair< int, std::string>(69, "sdf"));
	b.insert(std::pair< int, std::string>(123, "asd"));
	b.insert(std::pair< int, std::string>(457, "zxc"));
	b.insert(std::pair< int, std::string>(1, "yjyu"));
	b.insert(std::pair< int, std::string>(457, "mi.l8"));
	b.insert(std::pair< int, std::string>(418, "xczz"));
	b.insert(std::pair< int, std::string>(77, "ipi"));
	b.insert(std::pair< int, std::string>(427, "qwr"));

	print_2m(a, b);
	getchar();
	std::cout <<  "\033c";
}
{
	std::cout << std::endl << RED << "value_compare" << RESET << std::endl;
	std::map < int, std::string > a;
	ft::map < int, std::string > b;

	a.insert(std::pair< int, std::string>(45, "123"));
	a.insert(std::pair< int, std::string>(82, "456"));
	a.insert(std::pair< int, std::string>(12, "79"));
	a.insert(std::pair< int, std::string>(57, "dsaf"));
	a.insert(std::pair< int, std::string>(69, "sdf"));
	a.insert(std::pair< int, std::string>(123, "asd"));
	a.insert(std::pair< int, std::string>(457, "zxc"));
	a.insert(std::pair< int, std::string>(1, "yjyu"));
	a.insert(std::pair< int, std::string>(457, "mi.l8"));
	a.insert(std::pair< int, std::string>(418, "xczz"));
	a.insert(std::pair< int, std::string>(77, "ipi"));
	a.insert( std::pair< int, std::string>(427, "qwr"));

	b.insert(std::pair< int, std::string>(45, "123"));
	b.insert(std::pair< int, std::string>(82, "456"));
	b.insert(std::pair< int, std::string>(12, "79"));
	b.insert(std::pair< int, std::string>(57, "dsaf"));
	b.insert(std::pair< int, std::string>(69, "sdf"));
	b.insert(std::pair< int, std::string>(123, "asd"));
	b.insert(std::pair< int, std::string>(457, "zxc"));
	b.insert(std::pair< int, std::string>(1, "yjyu"));
	b.insert(std::pair< int, std::string>(457, "mi.l8"));
	b.insert(std::pair< int, std::string>(418, "xczz"));
	b.insert(std::pair< int, std::string>(77, "ipi"));
	b.insert(std::pair< int, std::string>(427, "qwr"));

	print_2m(a, b);

	std::cout << "std::map: " << std::endl;

	std::cout << a.value_comp()(std::pair< int, std::string>(69, "sdf"), std::pair< int, std::string>(457, "zxc")) << std::endl;
	std::cout << a.value_comp()(std::pair< int, std::string>(69, "sdf"), std::pair< int, std::string>(69, "sdf")) << std::endl;

	std::cout << "ft::map: " << std::endl;

	std::cout << b.value_comp()(std::pair< int, std::string>(69, "sdf"), std::pair< int, std::string>(457, "zxc")) << std::endl;
	std::cout << b.value_comp()(std::pair< int, std::string>(69, "sdf"), std::pair< int, std::string>(69, "sdf")) << std::endl;
	getchar();
	std::cout <<  "\033c";

}
{
	std::map < int, std::string, Cmp<int> > a;
	ft::map < int, std::string, Cmp <int> > b;

	a.insert(std::pair< int, std::string>(45, "123"));
	a.insert(std::pair< int, std::string>(82, "456"));
	a.insert(std::pair< int, std::string>(12, "79"));
	a.insert(std::pair< int, std::string>(57, "dsaf"));
	a.insert(std::pair< int, std::string>(69, "sdf"));
	a.insert(std::pair< int, std::string>(123, "asd"));
	a.insert(std::pair< int, std::string>(457, "zxc"));
	a.insert(std::pair< int, std::string>(1, "yjyu"));
	a.insert(std::pair< int, std::string>(457, "mi.l8"));
	a.insert(std::pair< int, std::string>(418, "xczz"));
	a.insert(std::pair< int, std::string>(77, "ipi"));
	a.insert( std::pair< int, std::string>(427, "qwr"));

	b.insert(std::pair< int, std::string>(45, "123"));
	b.insert(std::pair< int, std::string>(82, "456"));
	b.insert(std::pair< int, std::string>(12, "79"));
	b.insert(std::pair< int, std::string>(57, "dsaf"));
	b.insert(std::pair< int, std::string>(69, "sdf"));
	b.insert(std::pair< int, std::string>(123, "asd"));
	b.insert(std::pair< int, std::string>(457, "zxc"));
	b.insert(std::pair< int, std::string>(1, "yjyu"));
	b.insert(std::pair< int, std::string>(457, "mi.l8"));
	b.insert(std::pair< int, std::string>(418, "xczz"));
	b.insert(std::pair< int, std::string>(77, "ipi"));
	b.insert(std::pair< int, std::string>(427, "qwr"));

	print_2m(a, b);

	std::cout << "std::map: " << std::endl;

	std::cout << a.value_comp()(std::pair< int, std::string>(69, "sdf"), std::pair< int, std::string>(457, "zxc")) << std::endl;
	std::cout << a.value_comp()(std::pair< int, std::string>(69, "sdf"), std::pair< int, std::string>(69, "sdf")) << std::endl;

	std::cout << "ft::map: " << std::endl;

	std::cout << b.value_comp()(std::pair< int, std::string>(69, "sdf"), std::pair< int, std::string>(457, "zxc")) << std::endl;
	std::cout << b.value_comp()(std::pair< int, std::string>(69, "sdf"), std::pair< int, std::string>(69, "sdf")) << std::endl;
	getchar();
	std::cout <<  "\033c";

}
{
	std::cout << std::endl << GREEN << "**** Operations ****" << RESET << std::endl;
	std::cout << RED << "find" << RESET << std::endl;
	std::map < int, std::string > a;
	ft::map < int, std::string > b;

	a.insert(std::pair< int, std::string>(45, "123"));
	a.insert(std::pair< int, std::string>(82, "456"));
	a.insert(std::pair< int, std::string>(12, "79"));
	a.insert(std::pair< int, std::string>(57, "dsaf"));
	a.insert(std::pair< int, std::string>(69, "sdf"));
	a.insert(std::pair< int, std::string>(123, "asd"));
	a.insert(std::pair< int, std::string>(457, "zxc"));
	a.insert(std::pair< int, std::string>(1, "yjyu"));
	a.insert(std::pair< int, std::string>(457, "mi.l8"));
	a.insert(std::pair< int, std::string>(418, "xczz"));
	a.insert(std::pair< int, std::string>(77, "ipi"));
	a.insert( std::pair< int, std::string>(427, "qwr"));

	b.insert(std::pair< int, std::string>(45, "123"));
	b.insert(std::pair< int, std::string>(82, "456"));
	b.insert(std::pair< int, std::string>(12, "79"));
	b.insert(std::pair< int, std::string>(57, "dsaf"));
	b.insert(std::pair< int, std::string>(69, "sdf"));
	b.insert(std::pair< int, std::string>(123, "asd"));
	b.insert(std::pair< int, std::string>(457, "zxc"));
	b.insert(std::pair< int, std::string>(1, "yjyu"));
	b.insert(std::pair< int, std::string>(457, "mi.l8"));
	b.insert(std::pair< int, std::string>(418, "xczz"));
	b.insert(std::pair< int, std::string>(77, "ipi"));
	b.insert(std::pair< int, std::string>(427, "qwr"));

	print_2m(a, b);

	std::cout << "std::map: " << std::endl;

	std::cout << (*a.find(45)).first << std::endl;
	std::cout << (*a.find(57)).first << std::endl;
	std::cout << (*a.find(57)).first << std::endl;
	std::cout << (a.find(570) == a.end()) << std::endl;

	std::cout << "ft::map: " << std::endl;

	std::cout << (*b.find(45)).first << std::endl;
	std::cout << (*b.find(57)).first << std::endl;
	std::cout << (*b.find(57)).first << std::endl;
	std::cout << (b.find(570) == b.end()) << std::endl;
	getchar();
	std::cout <<  "\033c";
}
{
	std::cout << std::endl << RED << "Count" << RESET << std::endl;

	std::map < int, std::string > a;
	ft::map < int, std::string > b;

	a.insert(std::pair< int, std::string>(45, "123"));
	a.insert(std::pair< int, std::string>(82, "456"));
	a.insert(std::pair< int, std::string>(12, "79"));
	a.insert(std::pair< int, std::string>(57, "dsaf"));
	a.insert(std::pair< int, std::string>(69, "sdf"));
	a.insert(std::pair< int, std::string>(123, "asd"));
	a.insert(std::pair< int, std::string>(457, "zxc"));
	a.insert(std::pair< int, std::string>(1, "yjyu"));
	a.insert(std::pair< int, std::string>(457, "mi.l8"));
	a.insert(std::pair< int, std::string>(418, "xczz"));
	a.insert(std::pair< int, std::string>(77, "ipi"));
	a.insert( std::pair< int, std::string>(427, "qwr"));

	b.insert(std::pair< int, std::string>(45, "123"));
	b.insert(std::pair< int, std::string>(82, "456"));
	b.insert(std::pair< int, std::string>(12, "79"));
	b.insert(std::pair< int, std::string>(57, "dsaf"));
	b.insert(std::pair< int, std::string>(69, "sdf"));
	b.insert(std::pair< int, std::string>(123, "asd"));
	b.insert(std::pair< int, std::string>(457, "zxc"));
	b.insert(std::pair< int, std::string>(1, "yjyu"));
	b.insert(std::pair< int, std::string>(457, "mi.l8"));
	b.insert(std::pair< int, std::string>(418, "xczz"));
	b.insert(std::pair< int, std::string>(77, "ipi"));
	b.insert(std::pair< int, std::string>(427, "qwr"));

	print_2m(a, b);

	std::cout << "std::map: " << std::endl;

	std::cout << a.count(57) << std::endl;
	std::cout << a.count(45) << std::endl;
	std::cout << a.count(570)<< std::endl;

	std::cout << "ft::map: " << std::endl;

	std::cout << b.count(57) << std::endl;
	std::cout << a.count(45) << std::endl;
	std::cout << b.count(570)<< std::endl;
	getchar();
	std::cout <<  "\033c";

}
{
	std::cout << std::endl << RED << "lower_bound" << RESET << std::endl;

	std::map < int, std::string > a;
	ft::map < int, std::string > b;

	a.insert(std::pair< int, std::string>(45, "123"));
	a.insert(std::pair< int, std::string>(82, "456"));
	a.insert(std::pair< int, std::string>(12, "79"));
	a.insert(std::pair< int, std::string>(57, "dsaf"));
	a.insert(std::pair< int, std::string>(69, "sdf"));
	a.insert(std::pair< int, std::string>(123, "asd"));
	a.insert(std::pair< int, std::string>(457, "zxc"));
	a.insert(std::pair< int, std::string>(1, "yjyu"));
	a.insert(std::pair< int, std::string>(457, "mi.l8"));
	a.insert(std::pair< int, std::string>(418, "xczz"));
	a.insert(std::pair< int, std::string>(77, "ipi"));
	a.insert( std::pair< int, std::string>(427, "qwr"));

	b.insert(std::pair< int, std::string>(45, "123"));
	b.insert(std::pair< int, std::string>(82, "456"));
	b.insert(std::pair< int, std::string>(12, "79"));
	b.insert(std::pair< int, std::string>(57, "dsaf"));
	b.insert(std::pair< int, std::string>(69, "sdf"));
	b.insert(std::pair< int, std::string>(123, "asd"));
	b.insert(std::pair< int, std::string>(457, "zxc"));
	b.insert(std::pair< int, std::string>(1, "yjyu"));
	b.insert(std::pair< int, std::string>(457, "mi.l8"));
	b.insert(std::pair< int, std::string>(418, "xczz"));
	b.insert(std::pair< int, std::string>(77, "ipi"));
	b.insert(std::pair< int, std::string>(427, "qwr"));

	print_2m(a, b);

	std::cout << "std::map: " << std::endl;
	std::cout << (*a.lower_bound(150)).first << std::endl;
	std::cout << (*a.lower_bound(-150)).first << std::endl;
	std::cout << (*a.lower_bound(46)).first << std::endl;
	std::cout << (*a.lower_bound(457)).first << std::endl;

	std::cout << "ft::map: " << std::endl;
	std::cout << (*b.lower_bound(150)).first << std::endl;
	std::cout << (*b.lower_bound(-150)).first << std::endl;
	std::cout << (*b.lower_bound(46)).first << std::endl;
	std::cout << (*b.lower_bound(457)).first << std::endl;
	getchar();
	std::cout <<  "\033c";

}
{
	std::cout << std::endl << RED << "upper_bound" << RESET << std::endl;

	std::map < int, std::string > a;
	ft::map < int, std::string > b;

	a.insert(std::pair< int, std::string>(45, "123"));
	a.insert(std::pair< int, std::string>(82, "456"));
	a.insert(std::pair< int, std::string>(12, "79"));
	a.insert(std::pair< int, std::string>(57, "dsaf"));
	a.insert(std::pair< int, std::string>(69, "sdf"));
	a.insert(std::pair< int, std::string>(123, "asd"));
	a.insert(std::pair< int, std::string>(457, "zxc"));
	a.insert(std::pair< int, std::string>(1, "yjyu"));
	a.insert(std::pair< int, std::string>(457, "mi.l8"));
	a.insert(std::pair< int, std::string>(418, "xczz"));
	a.insert(std::pair< int, std::string>(77, "ipi"));
	a.insert( std::pair< int, std::string>(427, "qwr"));

	b.insert(std::pair< int, std::string>(45, "123"));
	b.insert(std::pair< int, std::string>(82, "456"));
	b.insert(std::pair< int, std::string>(12, "79"));
	b.insert(std::pair< int, std::string>(57, "dsaf"));
	b.insert(std::pair< int, std::string>(69, "sdf"));
	b.insert(std::pair< int, std::string>(123, "asd"));
	b.insert(std::pair< int, std::string>(457, "zxc"));
	b.insert(std::pair< int, std::string>(1, "yjyu"));
	b.insert(std::pair< int, std::string>(457, "mi.l8"));
	b.insert(std::pair< int, std::string>(418, "xczz"));
	b.insert(std::pair< int, std::string>(77, "ipi"));
	b.insert(std::pair< int, std::string>(427, "qwr"));

	print_2m(a, b);

	std::cout << "std::map: " << std::endl;
	std::cout << (*a.upper_bound(150)).first << std::endl;
	std::cout << (*a.upper_bound(-150)).first << std::endl;
	std::cout << (*a.upper_bound(46)).first << std::endl;
	std::cout << (a.upper_bound(457) == a.end()) << std::endl;
	std::cout << (a.upper_bound(4570) == a.end()) << std::endl;

	std::cout << "ft::map: " << std::endl;
	std::cout << (*b.upper_bound(150)).first << std::endl;
	std::cout << (*b.upper_bound(-150)).first << std::endl;
	std::cout << (*b.upper_bound(46)).first << std::endl;
	std::cout << (b.upper_bound(457) == b.end()) << std::endl;
	std::cout << (b.upper_bound(4570) == b.end()) << std::endl;
	getchar();
	std::cout <<  "\033c";
}
{
	std::cout << std::endl << RED << "equal_range" << RESET << std::endl;

	std::map < int, std::string > a;
	ft::map < int, std::string > b;

	a.insert(std::pair< int, std::string>(45, "123"));
	a.insert(std::pair< int, std::string>(82, "456"));
	a.insert(std::pair< int, std::string>(12, "79"));
	a.insert(std::pair< int, std::string>(57, "dsaf"));
	a.insert(std::pair< int, std::string>(69, "sdf"));
	a.insert(std::pair< int, std::string>(123, "asd"));
	a.insert(std::pair< int, std::string>(457, "zxc"));
	a.insert(std::pair< int, std::string>(1, "yjyu"));
	a.insert(std::pair< int, std::string>(457, "mi.l8"));
	a.insert(std::pair< int, std::string>(418, "xczz"));
	a.insert(std::pair< int, std::string>(77, "ipi"));
	a.insert( std::pair< int, std::string>(427, "qwr"));

	b.insert(std::pair< int, std::string>(45, "123"));
	b.insert(std::pair< int, std::string>(82, "456"));
	b.insert(std::pair< int, std::string>(12, "79"));
	b.insert(std::pair< int, std::string>(57, "dsaf"));
	b.insert(std::pair< int, std::string>(69, "sdf"));
	b.insert(std::pair< int, std::string>(123, "asd"));
	b.insert(std::pair< int, std::string>(457, "zxc"));
	b.insert(std::pair< int, std::string>(1, "yjyu"));
	b.insert(std::pair< int, std::string>(457, "mi.l8"));
	b.insert(std::pair< int, std::string>(418, "xczz"));
	b.insert(std::pair< int, std::string>(77, "ipi"));
	b.insert(std::pair< int, std::string>(427, "qwr"));

	print_2m(a, b);

	std::pair <std::map < int, std::string >::iterator, std::map < int, std::string >::iterator> ret_std;
	std::pair <ft::map < int, std::string >::iterator, ft::map < int, std::string >::iterator> ret_ft;
	ret_std = a.equal_range(123);
	ret_ft = b.equal_range(123);

	std::cout << "Key: 123" << std::endl;
	std::cout << "std::map" << std::endl;
	std::cout << "lower bound points to: ";
	std::cout << ret_std.first->first << " => " << ret_std.first->second << '\n';
	std::cout << "upper bound points to: ";
	std::cout << ret_std.second->first << " => " << ret_std.second->second << '\n';

	std::cout << "ft::map" << std::endl;
	std::cout << "lower bound points to: ";
	std::cout << ret_ft.first->first << " => " << ret_ft.first->second << '\n';
	std::cout << "upper bound points to: ";
	std::cout << ret_ft.second->first << " => " << ret_ft.second->second << '\n';

	ret_std = a.equal_range(1);
	ret_ft = b.equal_range(1);

	std::cout << "Key: 1" << std::endl;
	std::cout << "std::map" << std::endl;
	std::cout << "lower bound points to: ";
	std::cout << ret_std.first->first << " => " << ret_std.first->second << '\n';
	std::cout << "upper bound points to: ";
	std::cout << ret_std.second->first << " => " << ret_std.second->second << '\n';

	std::cout << "ft::map" << std::endl;
	std::cout << "lower bound points to: ";
	std::cout << ret_ft.first->first << " => " << ret_ft.first->second << '\n';
	std::cout << "upper bound points to: ";
	std::cout << ret_ft.second->first << " => " << ret_ft.second->second << '\n';

	ret_std = a.equal_range(457);
	ret_ft = b.equal_range(457);

	std::cout << "Key: 457" << std::endl;
	std::cout << "std::map" << std::endl;
	std::cout << "lower bound points to: ";
	std::cout << ret_std.first->first << " => " << ret_std.first->second << '\n';
	std::cout << "upper bound points to: ";
	std::cout << (ret_std.first == a.end()) << '\n';

	std::cout << "ft::map" << std::endl;
	std::cout << "lower bound points to: ";
	std::cout << ret_ft.first->first << " => " << ret_ft.first->second << '\n';
	std::cout << "upper bound points to: ";
	std::cout << (ret_ft.first == b.end()) << '\n';
	getchar();
	std::cout <<  "\033c";
}
{
	std::cout << std::endl << GREEN << "Non member overload: == != < <= > >=" << RESET << std::endl;

	std::map < int, std::string > a;
	ft::map < int, std::string > b;
	std::map < int, std::string > aa;
	ft::map < int, std::string > bb;

	a.insert(std::pair< int, std::string>(45, "123"));
	a.insert(std::pair< int, std::string>(82, "456"));
	a.insert(std::pair< int, std::string>(12, "79"));
	a.insert(std::pair< int, std::string>(57, "dsaf"));
	a.insert(std::pair< int, std::string>(69, "sdf"));
	a.insert(std::pair< int, std::string>(123, "asd"));
	a.insert(std::pair< int, std::string>(457, "zxc"));
	a.insert(std::pair< int, std::string>(1, "yjyu"));
	a.insert(std::pair< int, std::string>(457, "mi.l8"));
	a.insert(std::pair< int, std::string>(418, "xczz"));
	a.insert(std::pair< int, std::string>(77, "ipi"));
	a.insert( std::pair< int, std::string>(427, "qwr"));

	aa.insert(std::pair< int, std::string>(45, "123"));
	aa.insert(std::pair< int, std::string>(82, "456"));
	aa.insert(std::pair< int, std::string>(12, "79"));
	aa.insert(std::pair< int, std::string>(57, "dsaf"));
	aa.insert(std::pair< int, std::string>(69, "sdf"));
	aa.insert(std::pair< int, std::string>(123, "asd"));
	aa.insert(std::pair< int, std::string>(457, "zxc"));
	aa.insert(std::pair< int, std::string>(1, "yjyu"));
	aa.insert(std::pair< int, std::string>(457, "mi.l8"));
	aa.insert(std::pair< int, std::string>(418, "xczz"));
	aa.insert(std::pair< int, std::string>(77, "ipi"));
	aa.insert( std::pair< int, std::string>(427, "qwr"));

	b.insert(std::pair< int, std::string>(45, "123"));
	b.insert(std::pair< int, std::string>(82, "456"));
	b.insert(std::pair< int, std::string>(12, "79"));
	b.insert(std::pair< int, std::string>(57, "dsaf"));
	b.insert(std::pair< int, std::string>(69, "sdf"));
	b.insert(std::pair< int, std::string>(123, "asd"));
	b.insert(std::pair< int, std::string>(457, "zxc"));
	b.insert(std::pair< int, std::string>(1, "yjyu"));
	b.insert(std::pair< int, std::string>(457, "mi.l8"));
	b.insert(std::pair< int, std::string>(418, "xczz"));
	b.insert(std::pair< int, std::string>(77, "ipi"));
	b.insert(std::pair< int, std::string>(427, "qwr"));

	bb.insert(std::pair< int, std::string>(45, "123"));
	bb.insert(std::pair< int, std::string>(82, "456"));
	bb.insert(std::pair< int, std::string>(12, "79"));
	bb.insert(std::pair< int, std::string>(57, "dsaf"));
	bb.insert(std::pair< int, std::string>(69, "sdf"));
	bb.insert(std::pair< int, std::string>(123, "asd"));
	bb.insert(std::pair< int, std::string>(457, "zxc"));
	bb.insert(std::pair< int, std::string>(1, "yjyu"));
	bb.insert(std::pair< int, std::string>(457, "mi.l8"));
	bb.insert(std::pair< int, std::string>(418, "xczz"));
	bb.insert(std::pair< int, std::string>(77, "ipi"));
	bb.insert(std::pair< int, std::string>(427, "qwr"));

	print_2m(a, b);
	print_2m(aa, bb);


	std::cout << "------------------" << std::endl;
	std::cout << "ft::map  == " << (a == aa) << std::endl;
	std::cout << "std::map == " << (b == bb) << std::endl;
	std::cout << "ft::map  != " << (a != aa) << std::endl;
	std::cout << "std::map != " << (b != bb) << std::endl;
	std::cout << "ft::map  <  " << (a < aa) << std::endl;
	std::cout << "std::map <  " << (b < bb) << std::endl;
	std::cout << "ft::map  <= " << (a <= aa) << std::endl;
	std::cout << "std::map <= " << (b <= bb) << std::endl;
	std::cout << "ft::map  >  " << (a > aa) << std::endl;
	std::cout << "std::map >  " << (b > bb) << std::endl;
	std::cout << "ft::map  >= " << (a >= aa) << std::endl;
	std::cout << "std::map >= " << (b >= bb) << std::endl;
	std::cout << "------------------" << std::endl;
	getchar();
	std::cout <<  "\033c";

}
{
	std::map < int, std::string > a;
	ft::map < int, std::string > b;
	std::map < int, std::string > aa;
	ft::map < int, std::string > bb;

	a.insert(std::pair< int, std::string>(45, "123"));
	a.insert(std::pair< int, std::string>(82, "456"));
	a.insert(std::pair< int, std::string>(12, "79"));
	a.insert(std::pair< int, std::string>(57, "dsaf"));
	a.insert(std::pair< int, std::string>(69, "sdf"));
	a.insert(std::pair< int, std::string>(123, "asd"));
	a.insert(std::pair< int, std::string>(457, "zxc"));
	a.insert(std::pair< int, std::string>(1, "yjyu"));
	a.insert(std::pair< int, std::string>(457, "mi.l8"));
	a.insert(std::pair< int, std::string>(418, "xczz"));
	a.insert(std::pair< int, std::string>(77, "ipi"));
	a.insert( std::pair< int, std::string>(427, "qwr"));

	aa.insert(std::pair< int, std::string>(45, "123"));
	aa.insert(std::pair< int, std::string>(82, "456"));
	aa.insert(std::pair< int, std::string>(13, "79"));
	aa.insert(std::pair< int, std::string>(57, "dsaf"));
	aa.insert(std::pair< int, std::string>(69, "sdf"));
	aa.insert(std::pair< int, std::string>(123, "asd"));
	aa.insert(std::pair< int, std::string>(457, "zxc"));
	aa.insert(std::pair< int, std::string>(1, "yjyu"));
	aa.insert(std::pair< int, std::string>(457, "mi.l8"));
	aa.insert(std::pair< int, std::string>(418, "xczz"));
	aa.insert(std::pair< int, std::string>(77, "ipi"));
	aa.insert( std::pair< int, std::string>(427, "qwr"));

	b.insert(std::pair< int, std::string>(45, "123"));
	b.insert(std::pair< int, std::string>(82, "456"));
	b.insert(std::pair< int, std::string>(12, "79"));
	b.insert(std::pair< int, std::string>(57, "dsaf"));
	b.insert(std::pair< int, std::string>(69, "sdf"));
	b.insert(std::pair< int, std::string>(123, "asd"));
	b.insert(std::pair< int, std::string>(457, "zxc"));
	b.insert(std::pair< int, std::string>(1, "yjyu"));
	b.insert(std::pair< int, std::string>(457, "mi.l8"));
	b.insert(std::pair< int, std::string>(418, "xczz"));
	b.insert(std::pair< int, std::string>(77, "ipi"));
	b.insert(std::pair< int, std::string>(427, "qwr"));

	bb.insert(std::pair< int, std::string>(45, "123"));
	bb.insert(std::pair< int, std::string>(82, "456"));
	bb.insert(std::pair< int, std::string>(13, "79"));
	bb.insert(std::pair< int, std::string>(57, "dsaf"));
	bb.insert(std::pair< int, std::string>(69, "sdf"));
	bb.insert(std::pair< int, std::string>(123, "asd"));
	bb.insert(std::pair< int, std::string>(457, "zxc"));
	bb.insert(std::pair< int, std::string>(1, "yjyu"));
	bb.insert(std::pair< int, std::string>(457, "mi.l8"));
	bb.insert(std::pair< int, std::string>(418, "xczz"));
	bb.insert(std::pair< int, std::string>(77, "ipi"));
	bb.insert(std::pair< int, std::string>(427, "qwr"));

	print_2m(a, b);
	print_2m(aa, bb);

	std::cout << "------------------" << std::endl;
	std::cout << "ft::map  == " << (a == aa) << std::endl;
	std::cout << "std::map == " << (b == bb) << std::endl;
	std::cout << "ft::map  != " << (a != aa) << std::endl;
	std::cout << "std::map != " << (b != bb) << std::endl;
	std::cout << "ft::map  <  " << (a < aa) << std::endl;
	std::cout << "std::map <  " << (b < bb) << std::endl;
	std::cout << "ft::map  <= " << (a <= aa) << std::endl;
	std::cout << "std::map <= " << (b <= bb) << std::endl;
	std::cout << "ft::map  >  " << (a > aa) << std::endl;
	std::cout << "std::map >  " << (b > bb) << std::endl;
	std::cout << "ft::map  >= " << (a >= aa) << std::endl;
	std::cout << "std::map >= " << (b >= bb) << std::endl;
	std::cout << "------------------" << std::endl;
	getchar();
	std::cout <<  "\033c";
}
{
	std::map < int, std::string > a;
	ft::map < int, std::string > b;
	std::map < int, std::string > aa;
	ft::map < int, std::string > bb;

	a.insert(std::pair< int, std::string>(4, "123"));
	a.insert(std::pair< int, std::string>(82, "456"));
	a.insert(std::pair< int, std::string>(12, "79"));
	a.insert(std::pair< int, std::string>(57, "dsaf"));
	a.insert(std::pair< int, std::string>(69, "sdf"));

	aa.insert(std::pair< int, std::string>(450, "123"));
	aa.insert(std::pair< int, std::string>(82, "456"));
	aa.insert(std::pair< int, std::string>(1, "79"));
	aa.insert(std::pair< int, std::string>(57, "dsaf"));
	aa.insert(std::pair< int, std::string>(69, "sdf"));

	b.insert(std::pair< int, std::string>(4, "123"));
	b.insert(std::pair< int, std::string>(82, "456"));
	b.insert(std::pair< int, std::string>(12, "79"));
	b.insert(std::pair< int, std::string>(57, "dsaf"));
	b.insert(std::pair< int, std::string>(69, "sdf"));

	bb.insert(std::pair< int, std::string>(450, "123"));
	bb.insert(std::pair< int, std::string>(82, "456"));
	bb.insert(std::pair< int, std::string>(1, "79"));
	bb.insert(std::pair< int, std::string>(57, "dsaf"));
	bb.insert(std::pair< int, std::string>(69, "sdf"));

	print_2m(a, b);
	print_2m(aa, bb);
	std::cout << "------------------" << std::endl;
	std::cout << "ft::map  == " << (a == aa) << std::endl;
	std::cout << "std::map == " << (b == bb) << std::endl;
	std::cout << "ft::map  != " << (a != aa) << std::endl;
	std::cout << "std::map != " << (b != bb) << std::endl;
	std::cout << "ft::map  <  " << (a < aa) << std::endl;
	std::cout << "std::map <  " << (b < bb) << std::endl;
	std::cout << "ft::map  <= " << (a <= aa) << std::endl;
	std::cout << "std::map <= " << (b <= bb) << std::endl;
	std::cout << "ft::map  >  " << (a > aa) << std::endl;
	std::cout << "std::map >  " << (b > bb) << std::endl;
	std::cout << "ft::map  >= " << (a >= aa) << std::endl;
	std::cout << "std::map >= " << (b >= bb) << std::endl;
	std::cout << "------------------" << std::endl;
	getchar();
	std::cout <<  "\033c";
}
{
	std::map < int, std::string, Cmp <int> > a;
	ft::map < int, std::string, Cmp <int> > b;
	std::map < int, std::string, Cmp <int> > aa;
	ft::map < int, std::string, Cmp <int> > bb;

	a.insert(std::pair< int, std::string>(4, "123"));
	a.insert(std::pair< int, std::string>(82, "456"));
	a.insert(std::pair< int, std::string>(12, "79"));
	a.insert(std::pair< int, std::string>(57, "dsaf"));
	a.insert(std::pair< int, std::string>(69, "sdf"));

	aa.insert(std::pair< int, std::string>(401, "123"));
	aa.insert(std::pair< int, std::string>(82, "456"));
	aa.insert(std::pair< int, std::string>(1, "79"));
	aa.insert(std::pair< int, std::string>(57, "dsaf"));
	aa.insert(std::pair< int, std::string>(69, "sdf"));

	b.insert(std::pair< int, std::string>(4, "123"));
	b.insert(std::pair< int, std::string>(82, "456"));
	b.insert(std::pair< int, std::string>(12, "79"));
	b.insert(std::pair< int, std::string>(57, "dsaf"));
	b.insert(std::pair< int, std::string>(69, "sdf"));

	bb.insert(std::pair< int, std::string>(401, "123"));
	bb.insert(std::pair< int, std::string>(82, "456"));
	bb.insert(std::pair< int, std::string>(1, "79"));
	bb.insert(std::pair< int, std::string>(57, "dsaf"));
	bb.insert(std::pair< int, std::string>(69, "sdf"));

	print_2m(a, b);
	print_2m(aa, bb);
	std::cout << "------------------" << std::endl;
	std::cout << "ft::map  == " << (a == aa) << std::endl;
	std::cout << "std::map == " << (b == bb) << std::endl;
	std::cout << "ft::map  != " << (a != aa) << std::endl;
	std::cout << "std::map != " << (b != bb) << std::endl;
	std::cout << "ft::map  <  " << (a < aa) << std::endl;
	std::cout << "std::map <  " << (b < bb) << std::endl;
	std::cout << "ft::map  <= " << (a <= aa) << std::endl;
	std::cout << "std::map <= " << (b <= bb) << std::endl;
	std::cout << "ft::map  >  " << (a > aa) << std::endl;
	std::cout << "std::map >  " << (b > bb) << std::endl;
	std::cout << "ft::map  >= " << (a >= aa) << std::endl;
	std::cout << "std::map >= " << (b >= bb) << std::endl;
	std::cout << "------------------" << std::endl;
	getchar();
	std::cout <<  "\033c";
}
{
	std::cout << std::endl << GREEN << "SWAP" << RESET << std::endl;
	std::map < int, std::string > a;
	std::map < int, std::string > aa;
	ft::map < int, std::string > b;
	ft::map < int, std::string > bb;

	std::cout << "До применения: " << std::endl;

	a.insert(std::pair< int, std::string>(45, "123"));
	a.insert(std::pair< int, std::string>(82, "456"));
	a.insert(std::pair< int, std::string>(12, "79"));
	a.insert(std::pair< int, std::string>(57, "dsaf"));
	a.insert(std::pair< int, std::string>(69, "sdf"));
	aa.insert(std::pair< int, std::string>(123, "asd"));
	aa.insert(std::pair< int, std::string>(457, "zxc"));
	aa.insert(std::pair< int, std::string>(1, "yjyu"));
	aa.insert(std::pair< int, std::string>(457, "mi.l8"));
	aa.insert(std::pair< int, std::string>(418, "xczz"));
	aa.insert(std::pair< int, std::string>(77, "ipi"));
	aa.insert( std::pair< int, std::string>(427, "qwr"));

	b.insert(std::pair< int, std::string>(45, "123"));
	b.insert(std::pair< int, std::string>(82, "456"));
	b.insert(std::pair< int, std::string>(12, "79"));
	b.insert(std::pair< int, std::string>(57, "dsaf"));
	b.insert(std::pair< int, std::string>(69, "sdf"));
	bb.insert(std::pair< int, std::string>(123, "asd"));
	bb.insert(std::pair< int, std::string>(457, "zxc"));
	bb.insert(std::pair< int, std::string>(1, "yjyu"));
	bb.insert(std::pair< int, std::string>(457, "mi.l8"));
	bb.insert(std::pair< int, std::string>(418, "xczz"));
	bb.insert(std::pair< int, std::string>(77, "ipi"));
	bb.insert( std::pair< int, std::string>(427, "qwr"));

	print_2m(a, b);
	print_2m(aa, bb);

	std::cout << "После применения: " << std::endl;

	swap(a, aa);
	swap(b, bb);

	print_2m(a, b);
	print_2m(aa, bb);

	a.insert(std::pair< int, std::string>(45, "123"));
	a.insert(std::pair< int, std::string>(82, "456"));
	a.insert(std::pair< int, std::string>(12, "79"));
	a.insert(std::pair< int, std::string>(57, "dsaf"));
	a.insert(std::pair< int, std::string>(69, "sdf"));
	aa.insert(std::pair< int, std::string>(123, "asd"));
	aa.insert(std::pair< int, std::string>(457, "zxc"));
	aa.insert(std::pair< int, std::string>(1, "yjyu"));
	aa.insert(std::pair< int, std::string>(457, "mi.l8"));
	aa.insert(std::pair< int, std::string>(418, "xczz"));
	aa.insert(std::pair< int, std::string>(77, "ipi"));
	aa.insert( std::pair< int, std::string>(427, "qwr"));

	b.insert(std::pair< int, std::string>(45, "123"));
	b.insert(std::pair< int, std::string>(82, "456"));
	b.insert(std::pair< int, std::string>(12, "79"));
	b.insert(std::pair< int, std::string>(57, "dsaf"));
	b.insert(std::pair< int, std::string>(69, "sdf"));
	bb.insert(std::pair< int, std::string>(123, "asd"));
	bb.insert(std::pair< int, std::string>(457, "zxc"));
	bb.insert(std::pair< int, std::string>(1, "yjyu"));
	bb.insert(std::pair< int, std::string>(457, "mi.l8"));
	bb.insert(std::pair< int, std::string>(418, "xczz"));
	bb.insert(std::pair< int, std::string>(77, "ipi"));
	bb.insert( std::pair< int, std::string>(427, "qwr"));

	print_2m(a, b);
	print_2m(aa, bb);
	getchar();
	std::cout <<  "\033c";
	return (0);
}
}