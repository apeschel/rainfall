#include <iostream>
#include <vector>
#include <iostream>
#include <stdlib.h>

#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>

#include "months.hpp"

using namespace std;

#define DEBUG

#ifndef DEBUG
vector<int> gen_rain_vals() {
    string str_in;
    cin >> str_in;

    vector<string> SplitVec;
    boost::split(SplitVec,
                 str_in,
                 boost::is_any_of(","),
                 boost::token_compress_on );

    vector<int> rain_vals;
    for (string str_val: SplitVec) {
        int rain_val = boost::lexical_cast<int>(str_val);
        rain_vals.push_back(rain_val); }

    if (rain_vals.size() == 12) {
        return rain_vals; }
    else {
        cerr << "Invalid Input" << endl;
        exit(-1); }}
#else
vector<int> gen_rain_vals() {
    int vals[12] = { 9,5,8,7,5,6,7,9,9,6,8,10 };
    vector<int> rain_vals(vals, vals + sizeof(vals) / sizeof(*vals));
    return rain_vals; }
#endif // DEBUG

int main(int argc, char *argv[]) {
    using namespace months;
    auto&& rainfall = sort_rainfall(get_rainfall(gen_rain_vals()));
    print_rainfall(rainfall);

    return 0; }
