#pragma once

#include <algorithm>
#include <iostream>
#include <iterator>
#include <ranges>
#include <string>
#include <vector>

using std::back_inserter;
using std::istream;
using std::istream_iterator;
using std::string;
using std::vector;

namespace ranges = std::ranges;

class Tokenizer
{
public:
    Tokenizer(istream& is)
    {
        tokenize(is);
    }

    void tokenize(istream& is)
    {
        for(istream_iterator<string> i{is}; i != istream_iterator<string>{}; ++i)
        {
            string t;
            ranges::transform(*i, back_inserter<string>(t), ::tolower);
            tokens_.push_back( std::move(t) );
        }
    }

    auto begin()
    {
        return tokens_.begin();
    }
    
    auto end()
    {
        return tokens_.end();
    }

    vector<string> tokens_;
};