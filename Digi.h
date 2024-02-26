#pragma once

#include <Rtypes.h>

#include <boost/serialization/access.hpp>


// TODO: use proper digi definition here, this is just a placeholder

class Digi {

public:
    uint32_t time;
    uint16_t channel;
    uint16_t charge;

    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive &ar, const unsigned int /*version*/) {
        ar & time;
        ar & channel;
        ar & charge;
    }

    ClassDefNV(Digi, 1);
};
