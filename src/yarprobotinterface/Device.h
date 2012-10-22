/*
 * Copyright (C) 2012  iCub Facility, Istituto Italiano di Tecnologia
 * Author: Daniele E. Domenichelli <daniele.domenichelli@iit.it>
 *
 * CopyPolicy: Released under the terms of the LGPLv2.1 or later, see LGPL.TXT
 */

#ifndef ROBOTINTERFACE_DEVICE_H
#define ROBOTINTERFACE_DEVICE_H

#include "Types.h"

namespace yarp { namespace dev { class PolyDriver; } }

namespace RobotInterface
{

class Device
{
public:
    explicit Device();
    Device(const std::string &name,
           const std::string &type,
           const ParamList &params = ParamList(),
           const ActionList &actions = ActionList());
    Device(const Device &other);
    Device& operator=(const Device &other);

    virtual ~Device();

    std::string& name();
    std::string& type();
    ParamList& params();
    ActionList& actions();

    const std::string& name() const;
    const std::string& type() const;
    const ParamList& params() const;
    const ActionList& actions() const;

    bool hasParam(const std::string &name) const;
    std::string findParam(const std::string &name) const;

    bool open();
    bool close();

    yarp::dev::PolyDriver *driver() const;
    ThreadList runningThreads() const;

private:
    class Private;
    Private * const mPriv;
};

} // RobotInterface


std::ostringstream& operator<<(std::ostringstream &oss, const RobotInterface::Device &t);
DebugStream::Debug operator<<(DebugStream::Debug dbg, const RobotInterface::Device &t);


#endif // ROBOTINTERFACE_DEVICE_H
