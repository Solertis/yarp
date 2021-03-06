/*
* Copyright (C) 2009 RobotCub Consortium
* Author: Lorenzo Natale
* CopyPolicy: Released under the terms of the LGPLv2.1 or later, see LGPL.TXT
*/

#ifndef YARP_OS_OS_H
#define YARP_OS_OS_H

#include <yarp/os/api.h>

#include <cstddef>


namespace yarp {
    namespace os {
        enum
        {
            YARP_SIGTERM,
            YARP_SIGINT
        };

        typedef void(*YarpSignalHandler)(int);
        /**
        * Wrapper for the ACE_OS::signal signal.
        * Attach a function handler to a signal.
        * @param signum signal number (e.g. SIGTERM/SIGINT) to handle
        * @param sighandler handler function
        */
        YARP_OS_API YarpSignalHandler signal(int signum, YarpSignalHandler sighandler);

        /**
        * Wrapper for ACE_OS::exit().
        */
        YARP_OS_API void exit(int v);

        /**
        * Wrapper for ACE_OS::abort().
        */
        YARP_OS_API void abort(bool verbose=false);

        /**
        * Wrapper for ACE_OS::getenv().
        * @param var string that containt the environment variable name
        * @return the value corresponding to the envarionment variable v
        */
        YARP_OS_API const char *getenv(const char *var);

        /**
        * Wrapper for ACE_OS::getppid().
        * @return the process id (pid)
        */
        YARP_OS_API int getpid();

        /**
        * Wrapper for ACE_OS::setprogname().
        * @param progname the program name
        */
        YARP_OS_API void setprogname(const char *progname);

        /**
        * Wrapper for ACE_OS::getprogname().
        * @return the program name
        */
        YARP_OS_API void getprogname(char* progname, size_t size);

        /**
        * Wrapper for ACE_OS::hostname().
        * @return the system hostname
        */
        YARP_OS_API void gethostname(char* hostname, size_t size);

        /**
        * Wrapper for ACE_OS::mkdir(). Create a directory.
        * @param p name of the new directory.
        */
        YARP_OS_API int mkdir(const char *p);

        /**
        * Create a directory and all parent directories needed
        * @param p desired path
        * @param ignoreLevels components of name to ignore. Set to 1 if 
        * last element of path is a filename, for example.
        * @return 0 on success
        */
        YARP_OS_API int mkdir_p(const char *p, int ignoreLevels = 0);

        /**
        * Wrapper for ACE_OS::rmdir(). Remove an empty directory.
        * @param p name of the directory.
        */
        YARP_OS_API int rmdir(const char *p);

        /**
        * Wrapper for ACE_OS::rename(). Changes the name of the file or 
        * directory specified by oldname to newname. 
        * @param oldname old name of the file/directory. 
        * @param newname new name of the file/directory. 
        */
        YARP_OS_API int rename(const char *oldname, const char *newname);

        /**
        * Wrapper for ACE_OS::stat() function.
        */
        YARP_OS_API int stat(const char *path);
    }
}

#endif // YARP_OS_OS_H
