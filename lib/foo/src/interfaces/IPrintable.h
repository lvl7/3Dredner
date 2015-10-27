#ifndef _IPRINTABLE_H_
#define _IPRINTABLE_H_

#pragma once

#include <string>

namespace interfaces {
    class IPrintable {
    public:
        virtual std::string print() = 0;
        virtual ~IPrintable() {}
    };
}

#endif