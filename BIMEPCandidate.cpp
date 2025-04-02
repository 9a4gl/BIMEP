#include "BIMEPCandidate.h"
#include "BIMEPDefinition.h"

#include <algorithm>
#include <numeric>
#include <ostream>
#include <iomanip>

double BIMEPCandidate::getTotalDistance() const {
    double distance = 0.0;
    for (const Link& link : *this) {
        distance += link.distance;
    }
    return distance;
}

bool BIMEPCandidate::operator<(const BIMEPCandidate& other) const
{
    return getTotalDistance() < other.getTotalDistance();
}

BIMEPCandidate BIMEPCandidate::reversed() const
{
    BIMEPCandidate reversed;
    for (auto it = rbegin(); it != rend(); ++it) {
        const Link& link = *it;
        reversed.emplace_back(Link{ link.to, link.from, link.distance });
    }
    return reversed;
}

const PointID BIMEPCandidate::getStartPointID() const
{
    return begin()->from;
}

const PointID BIMEPCandidate::getEndPointID() const
{
    return rbegin()->to;
}

bool BIMEPCandidate::isStartingFrom(const std::vector<PointID>& startingPoints) const
{
    return std::find(startingPoints.begin(), startingPoints.end(), getStartPointID()) != startingPoints.end();
}

bool BIMEPCandidate::isEndingAt(const std::vector<PointID>& endingPoints) const
{
    return std::find(endingPoints.begin(), endingPoints.end(), getEndPointID()) != endingPoints.end();
}

std::string BIMEPCandidate::pointSignatureId(const PointID pointId)
{
    auto it = std::find_if(BIMEPDefinition::points().begin(), BIMEPDefinition::points().end(), [&](const Point& point) -> bool { return point.id == pointId; });
    const std::string str = std::string("0") + std::to_string(it - BIMEPDefinition::points().begin() + 1);
    return str.substr(str.length() - 2, 2);
}

const BIMEPCandidate& BIMEPCandidate::generateSignature() const
{
    std::vector<std::string> strings;
    for (auto it = begin(); it != end(); ++it) {
        strings.emplace_back(pointSignatureId(it->from));
    }
    strings.emplace_back(pointSignatureId(getEndPointID()));
    signature = std::accumulate(
        std::next(strings.begin()),
        strings.end(),
        strings[0],
        [](std::string a, std::string b) -> std::string { return a + "-" + b; }
        );
    return *this;
}

std::ostream& operator<<(std::ostream& os, const BIMEPCandidate& candidate)
{
    const Link& first = *candidate.begin();
    const Link& last = *candidate.rbegin();
    os << "Link from " << getPoint(first.from).name << " to " << getPoint(last.to).name << ":" << std::endl;
    os << "Signature: [" << candidate.signature << "]" << std::endl;
    os << "Reverse Signature: [" << candidate.reversed().generateSignature().signature << "]" << std::endl;
    double totalDistance = 0.0;
    for (size_t i = 0; i < candidate.size(); ++i) {
        const Link& link = candidate.at(i);
        totalDistance += link.distance;
        os << std::setw(3) << (i + 1) << " " << link << " " << std::setw(6) << totalDistance << std::endl;
    }
    return os;
}
