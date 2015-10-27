#ifndef _IFOO_H_
#define _IFOO_H_

#pragma once

#include <interfaces/IPrintable.h>

namespace interfaces {
    class IFoo : public IPrintable {
    public:
        virtual ~IFoo() {}
    };

}

#endif