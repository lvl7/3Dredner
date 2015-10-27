#ifndef _FOO_H_
#define _FOO_H_

#pragma once

#include <interfaces/IFoo.h>

namespace Application {
    class Foo : public interfaces::IFoo {
    public:
        Foo() = default;
        std::string print() override;
    private:
    };
}

#endif
