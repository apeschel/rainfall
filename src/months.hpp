#ifndef MONTHS_HPP
#define MONTHS_HPP

// Is there a way to remove this include?
#include <vector>

namespace months {
    enum names {
        JAN, FEB, MAR, APR, MAY, JUN, JUL,
        AUG, SEP, OCT, NOV, DEC, NUM_MONTHS };

    struct Month {
        enum names name;
        int rainfall; };

    typedef std::vector<struct Month> month_vector;

    std::string to_string(enum names name);
    month_vector get_rainfall(const std::vector<int>& rain_vals);
    month_vector sort_rainfall(month_vector rainfall);
    void print_rainfall(const month_vector& rainfall); }

#endif // MONTHS_HPP
