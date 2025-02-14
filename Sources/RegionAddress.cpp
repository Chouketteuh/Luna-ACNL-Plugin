#include "RegionAddress.hpp"


namespace CTRPluginFramework
{
    enum Region
    {
        USA,
        EUR
    };

    // Global to keep the current region
    Region   g_region = USA;

    template <typename T>
    RegionAddress<T>::RegionAddress(T usa, T eur) :
    Usa(usa), Eur(eur)
    {
        
    }

    template <typename T>
    T   RegionAddress<T>::operator()(void)
    {
        if (g_region == EUR)
            return (Eur);
        return (Usa);
    }

    template class  RegionAddress<u32>;
}
