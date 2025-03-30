#include "BIMEPCommon.h"
#include "BIMEPCandidates.h"

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <assert.h>

std::ostream& operator<<(std::ostream& os, const Point& point)
{
    os << std::setw(18) << point.name;
    return os;
}

Point& getPoint(const PointID id)
{
    return *std::find_if(points.begin(), points.end(),
                         [&](const Point& point) -> bool { return point.id == id; });
}

std::ostream& operator<<(std::ostream& os, const Link& link)
{
    os << getPoint(link.from) << " > " << getPoint(link.to) << " ";
    os << std::fixed << std::setprecision(2) << std::setw(6) << link.distance;
    return os;
}

bool hasLinkFrom(const std::vector<Link>& data, const PointID from)
{
    return std::find_if(data.begin(), data.end(), [&](const Link& link) -> bool { return link.from == from; }) != data.end();
}

bool hasLinkTo(const std::vector<Link>& data, const PointID to)
{
    return std::find_if(data.begin(), data.end(), [&](const Link& link) -> bool { return link.to == to; }) != data.end();
}

bool hasLinkWith(const std::vector<Link>& data, const PointID id)
{
    return std::find_if(data.begin(), data.end(), [&](const Link& link) -> bool { return link.from == id || link.to == id; }) != data.end();
}

bool isLinkAllowed(const std::vector<Link>& data, const PointID id)
{
    std::vector<PointID> linkPoints;
    for (auto it = data.begin(); it != data.end(); ++it) {
        linkPoints.emplace_back(it->from);
    }
    linkPoints.emplace_back(data.rbegin()->to);
    const Point& point = getPoint(id);
    return std::count(linkPoints.begin(), linkPoints.end(), point.id) < point.multi;
}

size_t getLinkUniqueIdsCount(const std::vector<Link>& data)
{
    std::set<PointID> linkPoints;
    for (auto it = data.begin(); it != data.end(); ++it) {
        linkPoints.insert(it->from);
    }
    linkPoints.insert(data.rbegin()->to);
    return linkPoints.size();
}

std::vector<Link> getLinks(const PointID point)
{
    std::vector<Link> result;
    for (const Link& link : links) {
        if (link.from == point && !hasLinkTo(result, link.to)) {
            result.emplace_back(Link{ link.from, link.to, link.distance });
        }
        else if (link.to == point && !hasLinkTo(result, link.from)) {
            result.emplace_back(Link{ link.to, link.from, link.distance });
        }
    }
    return result;
}

void findCandidateRecursive(BIMEPCandidates& candidates, std::function<bool(const BIMEPCandidates&, const BIMEPCandidate&)> filter, BIMEPCandidate candidate)
{
    const Link lastLink = candidate.back();
    std::vector<Link> links = getLinks(lastLink.to);
    for (const Link& link : links) {
        if (isLinkAllowed(candidate, link.to)) {
            assert(lastLink.to == link.from);
            BIMEPCandidate candidateBranch = candidate;
            candidateBranch.push_back(link);
            if (getLinkUniqueIdsCount(candidateBranch) == points.size()) {
                candidateBranch.generateSignature();
                if (filter(candidates, candidateBranch)) {
                    candidates.addCandidate(candidateBranch);
                }
                continue;
            }
            findCandidateRecursive(candidates, filter, candidateBranch);
        }
    }

}

BIMEPCandidates findCandidates(std::function<bool(const BIMEPCandidates&, const BIMEPCandidate&)> filter)
{
    BIMEPCandidates candidates;
    for (const Point& point : points) {
        std::vector<Link> links = getLinks(point.id);
        for (const Link& link : links) {
            BIMEPCandidate candidate;
            candidate.push_back(link);
            findCandidateRecursive(candidates, filter, candidate);
        }
    }
    candidates.sort();
    return candidates;
}
