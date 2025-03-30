#include "BIMEPCandidates.h"

#include <algorithm>
#include <iostream>
#include <assert.h>

void BIMEPCandidates::addCandidate(const BIMEPCandidate& candidate)
{
    candidate.generateSignature();
    push_back(candidate);
}

void BIMEPCandidates::sort()
{
    std::sort(begin(), end(), [](const BIMEPCandidate& c1, const BIMEPCandidate& c2) -> bool { return c1.getTotalDistance() < c2.getTotalDistance(); });
}

bool BIMEPCandidates::hasCandidateWithSignature(const std::string& signature) const
{
    return std::find_if(begin(), end(), [&](const BIMEPCandidate& candidate) -> bool { return candidate.signature == signature; }) != end();
}

BIMEPCandidates BIMEPCandidates::getStartingFrom(const std::vector<PointID>& startingPoints) const
{
    BIMEPCandidates result;
    for (const BIMEPCandidate& candidate : *this) {
        if (std::find(startingPoints.begin(), startingPoints.end(), candidate.getStartPointID()) != startingPoints.end()) {
            result.addCandidate(candidate);
        }
    }
    result.sort();
    return result;
}

BIMEPCandidates BIMEPCandidates::getEndingAt(const std::vector<PointID>& endingPoints) const
{
    BIMEPCandidates result;
    for (const BIMEPCandidate& candidate : *this) {
        if (std::find(endingPoints.begin(), endingPoints.end(), candidate.getEndPointID()) != endingPoints.end()) {
            result.addCandidate(candidate);
        }
    }
    result.sort();
    return result;
}

BIMEPCandidates BIMEPCandidates::subset(int from, int count) const
{
    BIMEPCandidates result;
    auto it = begin();
    std::advance(it, from);
    for (; it != end() && count > 0; --count) {
        result.addCandidate(*it);
        ++it;
    }
    result.sort();
    return result;
}

BIMEPCandidates BIMEPCandidates::first(int count) const
{
    return subset(0, count);
}

int BIMEPCandidates::removeReversed()
{
    assert(false); // TODO not implemented yet
    return 0;
}

std::ostream& operator<<(std::ostream& os, const BIMEPCandidates& candidates)
{
    std::cout << std::string(57, '-') << std::endl;
    int i = 0;
    for (auto it = candidates.begin(); it != candidates.end(); ++it) {
        os << "#" << ++i << " ";
        os << *it;
        std::cout << std::string(57, '-') << std::endl;
    }
    return os;
}
