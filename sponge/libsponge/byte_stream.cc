#include "byte_stream.hh"
#include <iostream>


// Dummy implementation of a flow-controlled in-memory byte stream.

// For Lab 0, please replace with a real implementation that passes the
// automated checks run by `make check_lab0`.

// You will need to add private members to the class declaration in `byte_stream.hh`

using namespace std;

ByteStream::ByteStream(const size_t capacity)
    : _que(), _capacity(capacity), _read_total(0), _write_total(0), _is_eof(false) {}

size_t ByteStream::write(const string &data) {
    if (this->_is_eof) {
        return 0;
    }
    for (size_t i = 0; i < data.length(); i++) {
        if (this->_que.size() == this->_capacity) {
            return i;
        }
        this->_que.push_back(data[i]);
        this->_write_total++;
    }
    return data.length();
}

//! \param[in] len bytes will be copied from the output side of the buffer
string ByteStream::peek_output(const size_t len) const {
    size_t peek_size = min(len, this->_que.size());
    return string(this->_que.begin(), this->_que.begin() + peek_size);
}

//! \param[in] len bytes will be removed from the output side of the buffer
void ByteStream::pop_output(const size_t len) {
    size_t pop_size = min(len, this->_que.size());
    this->_read_total += len;
    while (pop_size--) {
        this->_que.pop_front();
    }
}

//! Read (i.e., copy and then pop) the next "len" bytes of the stream
//! \param[in] len bytes will be popped and returned
//! \returns a string
std::string ByteStream::read(const size_t len) {
    string str = peek_output(len);
    pop_output(len);
    return str;
}

void ByteStream::end_input() { this->_is_eof = true; }

bool ByteStream::input_ended() const { return this->_is_eof; }

size_t ByteStream::buffer_size() const { return this->_que.size(); }

bool ByteStream::buffer_empty() const { return this->_que.empty(); }

bool ByteStream::eof() const { return this->_is_eof && this->_que.empty(); }

size_t ByteStream::bytes_written() const { return this->_write_total; }

size_t ByteStream::bytes_read() const { return this->_read_total; }

size_t ByteStream::remaining_capacity() const { return this->_capacity - this->_que.size(); }
