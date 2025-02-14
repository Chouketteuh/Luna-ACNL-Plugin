#ifndef REGIONADDRESS_HPP
#define REGIONADDRESS_HPP

#include "types.h"

namespace CTRPluginFramework
{
    template <typename T>
    class RegionAddress
    {
    public:

        // Constructor
        RegionAddress(T usa, T eur);
        ~RegionAddress(){}

        // Return the value according to the current region
        T   operator()(void);

        // Properties
        const T Usa;
        const T Eur;
    };

    using AutoRegion = RegionAddress<u32>;
}

#endif
