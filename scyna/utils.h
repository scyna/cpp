#ifndef UTILS_H
#define UTILS_H

#include <stdint.h>

namespace scyna
{
    class Utils
    {
    public:
        static uint64_t calculateID(uint32_t prefix, uint64_t value)
        {
            return ((uint64_t)prefix << 44) + value;
        }

        static std::string publishUrl(const std::string urlPath)
        {
            auto s = "API" + urlPath;
            std::replace(s.begin(), s.end(), '/', '.');
            return s;
        }

        static std::string subscribeUrl(const std::string urlPath)
        {
            auto s = "API" + urlPath;
            std::replace(s.begin(), s.end(), '/', '.');
            return s;
        }
    };

}

#endif