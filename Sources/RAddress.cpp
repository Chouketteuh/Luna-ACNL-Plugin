#include "RAddress.hpp"


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
    RAddress<T>::RAddress(T usa, T eur) :
    Usa(usa), Eur(eur)
    {
        
    }

    template <typename T>
    T   RAddress<T>::operator()(void)
    {
        if (g_region == EUR)
            return (Eur);
        return (Usa);
    }

    template class  RAddress<u32>;
}
