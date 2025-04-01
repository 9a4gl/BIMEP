#include "BIMEPDefinition.h"
#include "BIMEPCommon.h"

#include <vector>
#include <assert.h>

BIMEPDefinition* BIMEPDefinition::m_instance = nullptr;

BIMEPDefinition::BIMEPDefinition()
{
    m_points_2024 = {
        { PointID::ID_MALA_SUBOTICA,     "Mala Subotica",       1 }, //!< 1
        { PointID::ID_DONJI_KRALJEVEC,   "Donji Kraljevec",     2 }, //!< 2
        { PointID::ID_GORICAN,           "Gorican",             1 }, //!< 3
        { PointID::ID_KOTORIBA,          "Kotoriba",            1 }, //!< 4
        { PointID::ID_DONJA_DUBRAVA,     "Donja Dubrava",       1 }, //!< 5
        { PointID::ID_DONJI_VIDOVEC,     "Donji Vidovec",       1 }, //!< 6
        { PointID::ID_SVETA_MARIJA,      "Sveta Marija",        2 }, //!< 7
        { PointID::ID_PRELOG,            "Prelog",              1 }, //!< 8
        { PointID::ID_OREHOVICA,         "Orehovica",           1 }, //!< 9
        { PointID::ID_PUSCINE,           "Puscine",             1 }, //!< 10
        { PointID::ID_MACINEC,           "Macinec",             1 }, //!< 11
        { PointID::ID_GORNJI_MIHALJEVEC, "Gornji Mihaljevec",   1 }, //!< 12
        { PointID::ID_STRIGOVA,          "Strigova",            1 }, //!< 13
        { PointID::ID_SV_MARTIN_NA_MURI, "Sv Martin na Muri",   1 }, //!< 14
        { PointID::ID_MURSKO_SREDISCE,   "Mursko Sredisce",     1 }, //!< 15
        { PointID::ID_PODTUREN,          "Podturen",            1 }, //!< 16
        { PointID::ID_DOMASINEC,         "Domasinec",           1 }, //!< 17
        { PointID::ID_CAKOVEC,           "Cakovec",             1 }, //!< 18
        { PointID::ID_LOPATINEC,         "Lopatinec",           1 }  //!< 19
    };
    m_points_2025 = {
        { PointID::ID_DONJI_KRALJEVEC,   "Donji Kraljevec",     2 }, //!< 1
        { PointID::ID_KOTORIBA,          "Kotoriba",            1 }, //!< 2
        { PointID::ID_DONJA_DUBRAVA,     "Donja Dubrava",       2 }, //!< 3
        { PointID::ID_SVETA_MARIJA,      "Sveta Marija",        2 }, //!< 4
        { PointID::ID_PRELOG,            "Prelog",              1 }, //!< 5
        { PointID::ID_OREHOVICA,         "Orehovica",           1 }, //!< 6
        { PointID::ID_PUSCINE,           "Puscine",             1 }, //!< 7
        { PointID::ID_MACINEC,           "Macinec",             1 }, //!< 8
        { PointID::ID_GORNJI_MIHALJEVEC, "Gornji Mihaljevec",   1 }, //!< 9
        { PointID::ID_STRIGOVA,          "Strigova",            1 }, //!< 10
        { PointID::ID_SV_MARTIN_NA_MURI, "Sv Martin na Muri",   1 }, //!< 11
        { PointID::ID_MURSKO_SREDISCE,   "Mursko Sredisce",     1 }, //!< 12
        { PointID::ID_PODTUREN,          "Podturen",            1 }, //!< 13
        { PointID::ID_DOMASINEC,         "Domasinec",           1 }, //!< 14
        { PointID::ID_CAKOVEC,           "Cakovec",             1 }, //!< 15
        { PointID::ID_LOPATINEC,         "Lopatinec",           1 }  //!< 16
        // { PointID::ID_MALA_SUBOTICA,     "Mala Subotica",       1 }, //!< 1
        // { PointID::ID_GORICAN,           "Gorican",             1 }, //!< 3
        // { PointID::ID_DONJI_VIDOVEC,     "Donji Vidovec",       1 }, //!< 6
    };

    m_links = {
        // { PointID::ID_MALA_SUBOTICA, PointID::ID_OREHOVICA, 6.0 },
        // { PointID::ID_MALA_SUBOTICA, PointID::ID_CAKOVEC, 8.4 },
        // { PointID::ID_MALA_SUBOTICA, PointID::ID_DONJI_KRALJEVEC, 11.3 },
        { PointID::ID_DONJI_KRALJEVEC, PointID::ID_DOMASINEC, 11.0 },
        // { PointID::ID_DONJI_KRALJEVEC, PointID::ID_GORICAN, 3.7 },
        { PointID::ID_DONJI_KRALJEVEC, PointID::ID_SVETA_MARIJA, 9 },
        { PointID::ID_DONJI_KRALJEVEC, PointID::ID_PRELOG, 5.0 },
        // { PointID::ID_GORICAN, PointID::ID_KOTORIBA, 14.4 },
        { PointID::ID_KOTORIBA, PointID::ID_DONJA_DUBRAVA, 6.0 },
        // { PointID::ID_KOTORIBA, PointID::ID_DONJI_VIDOVEC, 4.1 },
        // { PointID::ID_DONJA_DUBRAVA, PointID::ID_DONJI_VIDOVEC, 3.8 },
        { PointID::ID_DONJA_DUBRAVA, PointID::ID_SVETA_MARIJA, 6.0 },
        // { PointID::ID_DONJI_VIDOVEC, PointID::ID_SVETA_MARIJA, 4.3 },
        { PointID::ID_SVETA_MARIJA, PointID::ID_PRELOG, 11.0 },
        { PointID::ID_PRELOG, PointID::ID_OREHOVICA, 9.0 },
        { PointID::ID_PRELOG, PointID::ID_CAKOVEC, 17.0 },
        // { PointID::ID_PRELOG, PointID::ID_MALA_SUBOTICA, 10.2 },
        { PointID::ID_OREHOVICA, PointID::ID_CAKOVEC, 11.0 },
        { PointID::ID_OREHOVICA, PointID::ID_PUSCINE, 15.7 },
        { PointID::ID_PUSCINE, PointID::ID_CAKOVEC, 9.5 },
        { PointID::ID_PUSCINE, PointID::ID_MACINEC, 7.0 },
        { PointID::ID_MACINEC, PointID::ID_CAKOVEC, 11.0 },
        { PointID::ID_MACINEC, PointID::ID_GORNJI_MIHALJEVEC, 4.5 },
        { PointID::ID_GORNJI_MIHALJEVEC, PointID::ID_STRIGOVA, 9.5 },
        { PointID::ID_GORNJI_MIHALJEVEC, PointID::ID_LOPATINEC, 8.0 },
        { PointID::ID_STRIGOVA, PointID::ID_LOPATINEC, 13.0 },
        { PointID::ID_STRIGOVA, PointID::ID_SV_MARTIN_NA_MURI, 9.0 },
        { PointID::ID_SV_MARTIN_NA_MURI, PointID::ID_MURSKO_SREDISCE, 7.0},
        { PointID::ID_SV_MARTIN_NA_MURI, PointID::ID_CAKOVEC, 18.0 },
        { PointID::ID_MURSKO_SREDISCE, PointID::ID_PODTUREN, 15.0 },
        { PointID::ID_MURSKO_SREDISCE, PointID::ID_CAKOVEC, 15.0 },
        { PointID::ID_PODTUREN, PointID::ID_DOMASINEC, 5.5 },
        { PointID::ID_PODTUREN, PointID::ID_CAKOVEC, 13.0 },
        { PointID::ID_DOMASINEC, PointID::ID_CAKOVEC, 15.0 },
        // { PointID::ID_DOMASINEC, PointID::ID_MALA_SUBOTICA, 9.5 },
        { PointID::ID_CAKOVEC, PointID::ID_LOPATINEC, 8.0 },
        // { PointID::ID_GORICAN, PointID::ID_SVETA_MARIJA, 11.7}
    };
}

BIMEPDefinition* BIMEPDefinition::create(int year)
{
    assert(m_instance == nullptr);
    m_instance = new BIMEPDefinition();
    m_instance->m_year = year;
    assert(year == 2024 || year == 2025);
    return m_instance;
}

BIMEPDefinition* BIMEPDefinition::get()
{
    return m_instance;
}

const std::vector<Link>& BIMEPDefinition::links()
{
    assert(m_instance);
    return m_instance->m_links;
}

const std::vector<Point>& BIMEPDefinition::points()
{
    assert(m_instance);
    switch (m_instance->m_year) {
    case 2024:
        return m_instance->m_points_2024;
    case 2025:
        return m_instance->m_points_2025;
    }
    assert(false);
    return m_instance->m_points_2024;
}


