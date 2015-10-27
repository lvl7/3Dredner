#include "gmock/gmock.h"
#include <foo.h>

class FooMock : public MyLib::Ifoo {
public:
    MOCK_METHOD0(print, std::string());
};
