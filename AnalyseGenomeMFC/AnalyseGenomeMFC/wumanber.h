#include <stdint.h>

#include <vector>
#include <string>
#include <set>

typedef std::set<std::string> ResultSetType;
typedef std::pair<unsigned int, int> PrefixIdPairType;
typedef std::vector<PrefixIdPairType> PrefixTableType;

class WuManber
{
    public:
        WuManber();
        ~WuManber();

        std::vector<std::string> Convert(std::string& patString);

        bool Init(const std::vector<std::string>& patterns);

        bool Search(const std::string& str);

    private:
        // minmum length of patterns
        int32_t mMin;
        // SHIFT table
        std::vector<int32_t> mShiftTable;
        // a combination of HASH and PREFIX table
        std::vector<PrefixTableType> mHashTable;
        // patterns
        std::vector<std::string> mPatterns;
        // size of SHIFT and HASH table
        int32_t mTableSize;
        // size of block
        int32_t mBlock;
};
