#include "cabuf.h"

cabuf::cabuf()
{
	this->input_buf = new char[this->buffer_size];
	this->output_buf = new char[this->buffer_size];

	this->reset_output();
}

cabuf::~cabuf()
{
	this->sync();

	delete[] this->input_buf;
	delete[] this->output_buf;
}

cabuf::int_type cabuf::overflow(int input)
{
	if (input != traits_type::eof())
	{
		*this->pptr() = input;
		this->pbump(1);

		this->sync();
	}
	else return traits_type::eof();
}

int cabuf::sync()
{
	char * start = this->pbase();
	char * end = this->pptr();

	while (start < end)
	{
		this->packer.push_back(*start);
		start++;
	}

	this->reset_output();

	return 0;
}

void cabuf::reset_output()
{
	this->setp(this->output_buf, this->output_buf, this->output_buf + this->buffer_size - 1);	// -1 to keep space for overflow char
}

int cabuf::underflow()
{
	std::cout << "underflow: " << std::endl;

	return EOF;
}