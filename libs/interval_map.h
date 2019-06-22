#include <map>
#include <limits>
#include <iostream>
using namespace std;

#ifndef LIBS_INTERVAL_MAP_H_
#define LIBS_INTERVAL_MAP_H_

struct TestKeyType
{
    unsigned int val;
    constexpr TestKeyType(unsigned int val) : val(val) {}
    constexpr bool operator<(const TestKeyType& other) const { return val < other.val; }
};

namespace std {
    template<> class numeric_limits<TestKeyType> {
    public:
        static constexpr TestKeyType lowest() { return TestKeyType(numeric_limits<unsigned int>::lowest()); }
        //static constexpr TestKeyType lowest() { return TestKeyType(-250); }
    };
}

using TestValueType = char;

struct TestFloatKeyType
{
    float val;

    TestFloatKeyType() = default;

    TestFloatKeyType(float val) : val(val) {}
    bool operator< (TestFloatKeyType other) const
    {
        return other.val - val > 1.e-4f;
    }
};

namespace std {
    template<> class numeric_limits<TestFloatKeyType> {
    public:
        static TestFloatKeyType lowest() { return TestFloatKeyType(numeric_limits<float>::lowest()); }
    };
}
template<typename K, typename V>
class interval_map {
public:
	std::map<K,V> m_map;

public:
    // constructor associates whole range of K with val by inserting (K_min, val)
    // into the map
    interval_map( V const& val) {
        m_map.insert(m_map.end(),std::make_pair(std::numeric_limits<K>::lowest(),val));
    }

    // Assign value val to interval [keyBegin, keyEnd).
    // Overwrite previous values in this interval.
    // Conforming to the C++ Standard Library conventions, the interval
    // includes keyBegin, but excludes keyEnd.
    // If !( keyBegin < keyEnd ), this designates an empty interval,
    // and assign must do nothing.
    void assign( K const& keyBegin, K const& keyEnd, V const& val ) {
        if ( !(keyBegin < keyEnd) ){
            return;
        }
        typename std::map<K, V>::iterator iterBegin; /*The new begin with val, can be begin()*/
        typename std::map<K, V>::iterator iterEnd;   /*the new end of val, can be end()*/
        // Search for the lower bound and if necessary include a border element
        // with the value of the old interval
        auto endIter = m_map.lower_bound(keyEnd);
        if (!(endIter->second == val)) {
            // As the intervals are half open we need to take the value of the left element and insert it at keyEnd 
            iterEnd = m_map.insert(endIter, std::make_pair(keyEnd, std::prev(endIter)->second));
        } else {
            iterEnd = endIter;
        }

        // Search for the lower bound and if necessary include the element
        auto beginIter = m_map.lower_bound(keyBegin);
        if ( beginIter != m_map.begin() ) {
            auto prevIter = std::prev(beginIter); //safe when end(), because we always have at least one value
            if (!(prevIter->second == val))
            {
                iterBegin = m_map.insert(beginIter, std::make_pair(keyBegin, val));
            }
            else {
                iterBegin = prevIter;
            }
        } else {
            iterBegin = m_map.insert(beginIter, std::make_pair(keyBegin, val));
        }

        // Update the values within the range [beginIter, endIter)
        while( iterBegin != iterEnd ) {
            iterBegin->second = val;
            ++iterBegin;
        }
        return;
    }

    // look-up of the value associated with key
    V const& operator[]( K const& key ) const {
        return ( --m_map.upper_bound(key) )->second;
    }
};

// Many solutions we receive are incorrect. Consider using a randomized test
// to discover the cases that your implementation does not handle correctly.
// We recommend to implement a test function that tests the functionality of
// the interval_map, for example using a map of unsigned int intervals to char.
#endif /* LIBS_INTERVAL_MAP_H_ */