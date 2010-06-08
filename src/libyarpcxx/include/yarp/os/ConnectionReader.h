// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-

/*
 * Copyright (C) 2010 Paul Fitzpatrick
 * CopyPolicy: Released under the terms of the GNU GPL v2.0.
 *
 */

#ifndef YARPCXX_ConnectionReader_INC
#define YARPCXX_ConnectionReader_INC

#include <yarp/yarpcxx.h>

#include <yarp/os/ConstString.h>

namespace yarpcxx {
    namespace os {
        class ConnectionReader;
    }
}

class yarpcxx::os::ConnectionReader {
public:
    ConnectionReader(yarpReaderPtr handle) : impl(handle) {}

    bool expectBlock(const char *data, int len) {
        return !yarpReaderExpectBlock(impl,data,len);
    }

    ConstString expectText(int terminatingChar = '\n') {
        ConstString result;
        yarpReaderExpectText(impl,result.getHandle(),terminatingChar);
        return result;
    }

    int expectInt() {
        int x = 0;
        yarpReaderExpectInt(impl,&x);
        return x;
    }

    double expectDouble() {
        double x = 0;
        yarpReaderExpectDouble(impl,&x);
        return x;
    }

    bool isTextMode() {
        return !yarpReaderIsTextMode(impl);
    }
private:
    yarpReaderPtr impl;
};

#endif
