#include "BIMEPCandidates.h"
#include "BIMEPDefinition.h"

#include <iostream>

int main()
{
    BIMEPDefinition::create(2024);

    auto condition = [](const BIMEPCandidates& candidates, const BIMEPCandidate& candidate) -> bool {
        return candidate.isStartingFrom({ PointID::ID_PUSCINE }) &&
               candidate.isEndingAt({ PointID::ID_GORNJI_MIHALJEVEC, PointID::ID_MACINEC, PointID::ID_LOPATINEC, PointID::ID_CAKOVEC, PointID::ID_OREHOVICA });
    };

    auto condition2 = [](const BIMEPCandidates& candidates, const BIMEPCandidate& candidate) -> bool {
        return candidate.isStartingFrom({ PointID::ID_KOTORIBA }) &&
               candidate.isEndingAt({ PointID::ID_GORICAN, PointID::ID_SVETA_MARIJA, PointID::ID_PRELOG, PointID::ID_DONJI_KRALJEVEC });
    };

    auto condition3 = [](const BIMEPCandidates& candidates, const BIMEPCandidate& candidate) -> bool {
        return candidate.isStartingFrom({ PointID::ID_LOPATINEC }) &&
               candidate.isEndingAt({
                                     PointID::ID_OREHOVICA, PointID::ID_PUSCINE, PointID::ID_GORNJI_MIHALJEVEC,
                                     PointID::ID_MACINEC, PointID::ID_PRELOG, PointID::ID_MALA_SUBOTICA,
                                     PointID::ID_CAKOVEC, PointID::ID_SVETA_MARIJA, PointID::ID_DONJI_KRALJEVEC });
    };

    BIMEPCandidates candidates = findCandidates(condition3);

    std::cout << "We have " << candidates.size() << " candidates." << std::endl;
    std::cout << candidates.first(10);
}
