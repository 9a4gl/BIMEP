// BIMEP2024.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <ostream>
#include <string>
#include <numeric>
#include <algorithm>
#include <functional>
#include <assert.h>

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

struct Point {
    PointID     id;
    std::string name;
    int         multi;
};

std::ostream& operator<<(std::ostream& os, const Point& point)
{
    os << std::setw(18) << point.name;
    return os;
}

std::vector<Point> points = {
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

Point& getPoint(const PointID id) {
    return *std::find_if(points.begin(), points.end(),
        [&](const Point& point) -> bool { return point.id == id; });
}

struct Link {
    PointID from;
    PointID to;
    double  distance;
};

std::ostream& operator<<(std::ostream& os, const Link& link)
{
    os << getPoint(link.from) << " > " << getPoint(link.to) << " ";
    os << std::fixed << std::setprecision(2) << std::setw(6) << link.distance;
    return os;
}

std::vector<Link> links = {
    { PointID::ID_MALA_SUBOTICA, PointID::ID_OREHOVICA, 6.0 },
    { PointID::ID_MALA_SUBOTICA, PointID::ID_CAKOVEC, 8.4 },
    { PointID::ID_MALA_SUBOTICA, PointID::ID_DONJI_KRALJEVEC, 11.3 },
    { PointID::ID_DONJI_KRALJEVEC, PointID::ID_DOMASINEC, 11.0 },
    { PointID::ID_DONJI_KRALJEVEC, PointID::ID_GORICAN, 3.7 },
    { PointID::ID_DONJI_KRALJEVEC, PointID::ID_SVETA_MARIJA, 9 },
    { PointID::ID_DONJI_KRALJEVEC, PointID::ID_PRELOG, 5.0 },
    { PointID::ID_GORICAN, PointID::ID_KOTORIBA, 14.4 },
    { PointID::ID_KOTORIBA, PointID::ID_DONJA_DUBRAVA, 6.0 },
    { PointID::ID_KOTORIBA, PointID::ID_DONJI_VIDOVEC, 4.1 },
    { PointID::ID_DONJA_DUBRAVA, PointID::ID_DONJI_VIDOVEC, 3.8 },
    { PointID::ID_DONJA_DUBRAVA, PointID::ID_SVETA_MARIJA, 6.0 },
    { PointID::ID_DONJI_VIDOVEC, PointID::ID_SVETA_MARIJA, 4.3 },
    { PointID::ID_SVETA_MARIJA, PointID::ID_PRELOG, 11.0 },
    { PointID::ID_PRELOG, PointID::ID_OREHOVICA, 9.0 },
    { PointID::ID_PRELOG, PointID::ID_CAKOVEC, 17.0 },
    { PointID::ID_PRELOG, PointID::ID_MALA_SUBOTICA, 10.2 },
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
    { PointID::ID_DOMASINEC, PointID::ID_MALA_SUBOTICA, 9.5 },
    { PointID::ID_CAKOVEC, PointID::ID_LOPATINEC, 8.0 },
    { PointID::ID_GORICAN, PointID::ID_SVETA_MARIJA, 11.7}
};

bool hasLinkFrom(const std::vector<Link>& data, const PointID from) {
    return std::find_if(data.begin(), data.end(), [&](const Link& link) -> bool { return link.from == from; }) != data.end();
}

bool hasLinkTo(const std::vector<Link>& data, const PointID to) {
    return std::find_if(data.begin(), data.end(), [&](const Link& link) -> bool { return link.to == to; }) != data.end();
}

bool hasLinkWith(const std::vector<Link>& data, const PointID id) {
    return std::find_if(data.begin(), data.end(), [&](const Link& link) -> bool { return link.from == id || link.to == id; }) != data.end();
}

bool isLinkAllowed(const std::vector<Link>& data, const PointID id) {
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

class Candidate : public std::vector<Link> {
    friend std::ostream& operator<<(std::ostream& os, const Candidate& candidate);
public:
    double getTotalDistance() const {
        double distance = 0.0;
        for (const Link& link : *this) {
            distance += link.distance;
        }
        return distance;
    }
    bool operator<(const Candidate& other) const
    {
        return getTotalDistance() < other.getTotalDistance();
    }
    Candidate reversed() const 
    {
        Candidate reversed;
        for (auto it = rbegin(); it != rend(); ++it) {
            const Link& link = *it;
            reversed.emplace_back(Link{ link.to, link.from, link.distance });
        }
        return reversed;
    }
    const PointID getStartPointID() const 
    {
        return begin()->from;
    }
    const PointID getEndPointID() const
    {
        return rbegin()->to;
    }
    bool isStartingFrom(const std::vector<PointID>& startingPoints) const
    {
        return std::find(startingPoints.begin(), startingPoints.end(), getStartPointID()) != startingPoints.end();
    }
    bool isEndingAt(const std::vector<PointID>& endingPoints) const
    {
        return std::find(endingPoints.begin(), endingPoints.end(), getEndPointID()) != endingPoints.end();
    }
    static std::string pointSignatureId(const PointID pointId)
    {
        auto it = std::find_if(points.begin(), points.end(), [&](const Point& point) -> bool { return point.id == pointId; });
        const std::string str = std::string("0") + std::to_string(it - points.begin() + 1);
        return str.substr(str.length() - 2, 2);
    }
    const Candidate& generateSignature() const
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
    mutable std::string signature = "N/A";
};

std::ostream& operator<<(std::ostream& os, const Candidate& candidate)
{
    const Link& first = *candidate.begin();
    const Link& last = *candidate.rbegin();
    os << "Link from " << getPoint(first.from).name << " to " << getPoint(last.to).name << ":" << std::endl;
    os << "Signature: [" << candidate.signature << "]" << std::endl;
    os << "Reverse Signature: [" << candidate.reversed().generateSignature().signature << "]" << std::endl;
    double totalDistance = 0.0;
    for (int i = 0; i < candidate.size(); ++i) {
        const Link& link = candidate.at(i);
        totalDistance += link.distance;
        os << std::setw(3) << (i + 1) << " " << link << " " << std::setw(6) << totalDistance << std::endl;
    }
    return os;
}

class Candidates : public std::vector<Candidate> 
{
    friend std::ostream& operator<<(std::ostream& os, const Candidates& candidates);
public:
    void addCandidate(const Candidate& candidate) 
    {
        candidate.generateSignature();
        push_back(candidate);
    }
    void sort()
    {
        std::sort(begin(), end(), [](const Candidate& c1, const Candidate& c2) -> bool { return c1.getTotalDistance() < c2.getTotalDistance(); });
    }
    bool hasCandidateWithSignature(const std::string& signature) const
    {
        return std::find_if(begin(), end(), [&](const Candidate& candidate) -> bool { return candidate.signature == signature; }) != end();
    }
    Candidates getStartingFrom(const std::vector<PointID>& startingPoints) const 
    {
        Candidates result;
        for (const Candidate& candidate : *this) {
            if (std::find(startingPoints.begin(), startingPoints.end(), candidate.getStartPointID()) != startingPoints.end()) {
                result.addCandidate(candidate);
            }
        }
        result.sort();
        return result;
    }
    Candidates getEndingAt(const std::vector<PointID>& endingPoints) const 
    {
        Candidates result;
        for (const Candidate& candidate : *this) {
            if (std::find(endingPoints.begin(), endingPoints.end(), candidate.getEndPointID()) != endingPoints.end()) {
                result.addCandidate(candidate);
            }
        }
        result.sort();
        return result;
    }
    Candidates subset(int from, int count) const 
    {
        Candidates result;
        auto it = begin();
        std::advance(it, from);
        for (; it != end() && count > 0; --count) {
            result.addCandidate(*it);
            ++it;
        }
        result.sort();
        return result;
    }
    Candidates first(int count = 1) const
    {
        return subset(0, count);
    }
    int removeReversed() 
    {
        assert(false); // TODO not implemented yet
        return 0;
    }
};

std::ostream& operator<<(std::ostream& os, const Candidates& candidates)
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

void findCandidateRecursive(Candidates& candidates, std::function<bool(const Candidates&, const Candidate&)> filter, Candidate candidate)
{
    const Link lastLink = candidate.back();
    std::vector<Link> links = getLinks(lastLink.to);
    for (const Link& link : links) {
        if (isLinkAllowed(candidate, link.to)) {
            assert(lastLink.to == link.from);
            Candidate candidateBranch = candidate;
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

Candidates findCandidates(std::function<bool(const Candidates&, const Candidate&)> filter = [](const Candidates&, const Candidate&) -> bool { return true; })
{
    Candidates candidates;
    for (const Point& point : points) {
        std::vector<Link> links = getLinks(point.id);
        for (const Link& link : links) {
            Candidate candidate;
            candidate.push_back(link);
            findCandidateRecursive(candidates, filter, candidate);
        }
    }
    candidates.sort();
    return candidates;
}

int main()
{
    auto condition = [](const Candidates& candidates, const Candidate& candidate) -> bool {
        return candidate.isStartingFrom({ PointID::ID_PUSCINE }) && 
               candidate.isEndingAt({ PointID::ID_GORNJI_MIHALJEVEC, PointID::ID_MACINEC, PointID::ID_LOPATINEC, PointID::ID_CAKOVEC, PointID::ID_OREHOVICA });
    };

    auto condition2 = [](const Candidates& candidates, const Candidate& candidate) -> bool {
        return candidate.isStartingFrom({ PointID::ID_KOTORIBA }) &&
            candidate.isEndingAt({ PointID::ID_GORICAN, PointID::ID_SVETA_MARIJA, PointID::ID_PRELOG, PointID::ID_DONJI_KRALJEVEC });
        };

    Candidates candidates = findCandidates(/* condition */);

    std::cout << "We have " << candidates.size() << " candidates." << std::endl;
    std::cout << candidates.first(10);
}
