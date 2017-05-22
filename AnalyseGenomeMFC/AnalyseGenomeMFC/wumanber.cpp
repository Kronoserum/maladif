#include <cmath>
#include <iostream>
#include "wumanber.h"

using namespace std;

unsigned int HashCode(const char* str, int len) {
    unsigned int hash = 0;
    while (*str && len > 0)
    {
        hash = (*str++) + (hash << 6) + (hash << 16) - hash;
        --len;
    }
    return (hash & 0x7FFFFFFF);
}

vector<string> WuManber::Convert(string& patString) {
    vector<string> patterns;
    unsigned int cursor = 0;

    while(cursor < patString.size()) {
        string newWord = patString.substr(cursor, 256);
        patterns.push_back(newWord);
        cursor += 257;
    }


    return patterns;
}

bool WuManber::Init(const vector<string>& patterns) {
    int patternSize = patterns.size();

    mMin = patterns[0].length();
    int32_t lenPattern = 0;
    for (int i = 0; i < patternSize; ++i) {
        lenPattern = patterns[i].length();
        if (lenPattern < mMin) {
            mMin = lenPattern;
        }
    }

    int32_t primes[6] = {1003, 10007, 100003, 1000003, 10000019, 100000007};
    vector<int32_t> primeList(&primes[0], &primes[6]);

    int32_t threshold = 10 * mMin;
    for (size_t i = 0; i < primeList.size(); ++i) {
        if (primeList[i] > patternSize && primeList[i] / patternSize > threshold) {
            mTableSize = primeList[i];
            break;
        }
    }

    mPatterns = patterns;
    mHashTable.resize(mTableSize);

    int32_t defaultValue = mMin - mBlock + 1;
    mShiftTable.resize(mTableSize, defaultValue);

    for (int i = 0; i < patternSize; ++i) {
        for (int index = mMin; index >= mBlock; --index) {
            unsigned int hash = HashCode(patterns[i].c_str() + index - mBlock, mBlock) % mTableSize;
            if (mShiftTable[hash] > (mMin - index)) {
                mShiftTable[hash]  = mMin - index;
            }
            if (index == mMin) {
                unsigned int prefixHash = HashCode(patterns[i].c_str(), mBlock);
                mHashTable[hash].push_back(make_pair(prefixHash, i));
            }
        }
    }

    return true;
}

bool WuManber::Search(const string& str) {
    const char* text = str.c_str();
    const int textLength = str.length();

    vector<bool> patFound (mPatterns.size(), false);
    bool found = true;

    int index = mMin - 1;

    uint32_t blockMaxIndex = mBlock - 1;
    uint32_t windowMaxIndex = mMin - 1;

    while (index < textLength) {
        unsigned int blockHash = HashCode(text + index - blockMaxIndex, mBlock);
        blockHash = blockHash % mTableSize;
        int shift = mShiftTable[blockHash];
        if (shift > 0) {
            index += shift;
        } else {
            unsigned int prefixHash = HashCode(text + index - windowMaxIndex, mBlock);

            PrefixTableType &element = mHashTable[blockHash];
            PrefixTableType::iterator iter = element.begin();

            while (element.end() != iter) {
                if (prefixHash == iter->first) {
                    const char* indexTarget = text + index - windowMaxIndex;
                    const char* indexPattern = mPatterns[iter->second].c_str();

                    while (('\0' != *indexTarget) && ('\0' != *indexPattern)) {

                        if (*indexTarget == *indexPattern) {
                            ++indexTarget;
                            ++indexPattern;
                        } else
                            break;
                    }

                    if ('\0' == *indexPattern)
                        patFound[iter->second] = true;
                }
                ++iter;
            }
            ++index;
        }
    }

    for (int i = 0; i < patFound.size(); i++)
        if (!patFound[i]) found = false;

    return found;
}

WuManber::WuManber():mMin(0), mTableSize(0), mBlock(3) {

}

WuManber::~WuManber() {

}
