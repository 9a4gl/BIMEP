#ifndef BIMEPCOMMON_H
#define BIMEPCOMMON_H

#include <string>
#include <vector>
#include <functional>

// If new point is added, just add on bottom, vector of points contains active one per year
enum class PointID {
    ID_MALA_SUBOTICA,      //!< 1
    ID_DONJI_KRALJEVEC,    //!< 2
    ID_GORICAN,            //!< 3
    ID_KOTORIBA,           //!< 4
    ID_DONJA_DUBRAVA,      //!< 5
    ID_DONJI_VIDOVEC,      //!< 6
    ID_SVETA_MARIJA,       //!< 7
    ID_PRELOG,             //!< 8
    ID_OREHOVICA,          //!< 9
    ID_PUSCINE,            //!< 10
    ID_MACINEC,            //!< 11
    ID_GORNJI_MIHALJEVEC,  //!< 12
    ID_STRIGOVA,           //!< 13
    ID_SV_MARTIN_NA_MURI,  //!< 14
    ID_MURSKO_SREDISCE,    //!< 15
    ID_PODTUREN,           //!< 16
    ID_DOMASINEC,          //!< 17
    ID_CAKOVEC,            //!< 18
    ID_LOPATINEC           //!< 19
};

class BIMEPCandidate;
class BIMEPCandidates;

struct Point {
    PointID     id;
    std::string name;
    int         multi;
};

struct Link {
    PointID from;
    PointID to;
    double  distance;
};

std::ostream& operator<<(std::ostream& os, const Point& point);
const Point getPoint(const PointID id);
std::ostream& operator<<(std::ostream& os, const Link& link);
bool hasLinkFrom(const std::vector<Link>& data, const PointID from);
bool hasLinkTo(const std::vector<Link>& data, const PointID to);
bool hasLinkWith(const std::vector<Link>& data, const PointID id);
bool isLinkAllowed(const std::vector<Link>& data, const PointID id);
size_t getLinkUniqueIdsCount(const std::vector<Link>& data);
std::vector<Link> getLinks(const PointID point);

void findCandidateRecursive(BIMEPCandidates& candidates, std::function<bool(const BIMEPCandidates&, const BIMEPCandidate&)> filter, BIMEPCandidate candidate);
BIMEPCandidates findCandidates(std::function<bool(const BIMEPCandidates&, const BIMEPCandidate&)> filter = [](const BIMEPCandidates&, const BIMEPCandidate&) -> bool { return true; });

#endif // BIMEPCOMMON_H
