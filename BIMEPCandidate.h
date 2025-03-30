#ifndef BIMEPCANDIDATE_H
#define BIMEPCANDIDATE_H

#include <vector>
#include <string>

struct Link;
enum class PointID;

#include "BIMEPCommon.h"

class BIMEPCandidate : public std::vector<Link>
{
    friend std::ostream& operator<<(std::ostream& os, const BIMEPCandidate& candidate);
public:
    double getTotalDistance() const;
    bool operator<(const BIMEPCandidate& other) const;
    BIMEPCandidate reversed() const;
    const PointID getStartPointID() const;
    const PointID getEndPointID() const;
    bool isStartingFrom(const std::vector<PointID>& startingPoints) const;
    bool isEndingAt(const std::vector<PointID>& endingPoints) const;
    static std::string pointSignatureId(const PointID pointId);
    const BIMEPCandidate& generateSignature() const;

    mutable std::string signature = "N/A";
};

#endif // BIMEPCANDIDATE_H
