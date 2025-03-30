#ifndef BIMEPCANDIDATES_H
#define BIMEPCANDIDATES_H

#include "BIMEPCandidate.h"

enum class PointID;

#include <vector>

class BIMEPCandidates : public std::vector<BIMEPCandidate>
{
    friend std::ostream& operator<<(std::ostream& os, const BIMEPCandidates& candidates);
public:
    void addCandidate(const BIMEPCandidate& candidate);
    void sort();
    bool hasCandidateWithSignature(const std::string& signature) const;
    BIMEPCandidates getStartingFrom(const std::vector<PointID>& startingPoints) const;
    BIMEPCandidates getEndingAt(const std::vector<PointID>& endingPoints) const;
    BIMEPCandidates subset(int from, int count) const;
    BIMEPCandidates first(int count = 1) const;
    int removeReversed();
};

#endif // BIMEPCANDIDATES_H
