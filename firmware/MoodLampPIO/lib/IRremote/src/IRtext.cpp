// Copyright 2019-2021 - David Conran (@crankyoldgit)

/// @file IRtext.cpp
/// @warning If you add or remove an entry in this file, you should run:
///   '../tools/generate_irtext_h.sh' to rebuild the `IRtext.h` file.

#include "IRtext.h"
#ifndef UNIT_TEST
#include <Arduino.h>
#endif // UNIT_TEST
#include "IRremoteESP8266.h"

#ifndef PROGMEM
#define PROGMEM // Pretend we have the PROGMEM macro even if we really don't.
#endif

#ifndef FPSTR
#define FPSTR(X) X // Also pretend we have flash-string helper class cast.
#endif

#define IRTEXT_CONST_BLOB_NAME(NAME) \
    NAME##Blob

#define IRTEXT_CONST_BLOB_DECL(NAME) \
    const char IRTEXT_CONST_BLOB_NAME(NAME)[] PROGMEM

#define IRTEXT_CONST_BLOB_PTR(NAME)                         \
    IRTEXT_CONST_PTR(NAME)                                  \
    {                                                       \
        IRTEXT_CONST_PTR_CAST(IRTEXT_CONST_BLOB_NAME(NAME)) \
    }

#define IRTEXT_CONST_STRING(NAME, VALUE)                          \
    static IRTEXT_CONST_BLOB_DECL(NAME){VALUE};                   \
    IRTEXT_CONST_PTR(NAME)                                        \
    PROGMEM                                                       \
    {                                                             \
        IRTEXT_CONST_PTR_CAST(&(IRTEXT_CONST_BLOB_NAME(NAME))[0]) \
    }