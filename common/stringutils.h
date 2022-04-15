#ifndef DSAA_STRINGUTILS_H
#define DSAA_STRINGUTILS_H

#include <iostream>

template<class e, class t, int N>
std::basic_istream<e,t>& operator>>(std::basic_istream<e,t>& in, const e(&sliteral)[N]) {
    e buffer[N-1] = {}; //get buffer
    //in >> buffer[0]; //skips whitespace
    if (N>2)
        in.read(buffer+1, N-2); //read the rest
    if (strncmp(buffer, sliteral, N-1)) //if it failed
        in.setstate(std::ios::failbit); //set the state
    return in;
}
template<class e, class t>
std::basic_istream<e,t>& operator>>(std::basic_istream<e,t>& in, const e& cliteral) {
    e buffer(0);  //get buffer
    in >> buffer; //read data
    if (buffer != cliteral) //if it failed
        in.setstate(std::ios::failbit); //set the state
    return in;
}
//redirect mutable char arrays to their normal function
template<class e, class t, int N>
std::basic_istream<e,t>& operator>>(std::basic_istream<e,t>& in, e(&carray)[N]) {
    return std::operator>>(in, carray);
}

#endif //DSAA_STRINGUTILS_H
