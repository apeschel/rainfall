#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

#include <boost/format.hpp>

#include "months.hpp"

using namespace std;

namespace months {
    static bool rain_cmp(const struct Month& x, const struct Month& y) {
        return (x.rainfall < y.rainfall); }

    string to_string(enum names name) {
        static const string lookup[NUM_MONTHS] = {
            "January",
            "Febuary",
            "March",
            "April",
            "May",
            "June",
            "July",
            "August",
            "September",
            "October",
            "November",
            "December" };

        return lookup[name]; }

    month_vector get_rainfall(const vector<int>& rain_vals) {
        month_vector rainfall;

        for (int i = JAN; i < NUM_MONTHS; i++) {
            enum names name = static_cast<enum names>(i);
            // Anonymous structures would allow the following two lines
            // to be combined, and possibly improve performance slightly.
            struct Month month { name, rain_vals[i] };
            rainfall.push_back(month); }

        return rainfall; }

    // If rainfall is an rvalue, then no copy will be made.
    month_vector sort_rainfall(month_vector rainfall) {
        sort(rainfall.begin(), rainfall.end(), rain_cmp);
        return rainfall; }

    void print_rainfall(const month_vector& rainfall) {
        for (struct Month month: rainfall) {
            cout << boost::format("%12s    %d\n") % to_string(month.name) % month.rainfall; }}}
