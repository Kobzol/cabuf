#ifndef CABUF_H_
#define CABUF_H_

#include <ios>
#include <iostream>
#include <vector>

class cabuf : public std::streambuf
{
protected:
	char *input_buf;
	char *output_buf;

	const size_t size = 20;

	std::vector<char> packer;

	virtual int_type overflow(int c);
	virtual int underflow();
	virtual int sync();
	
	void reset_output();

public:
	cabuf();
	~cabuf();
};

#endif