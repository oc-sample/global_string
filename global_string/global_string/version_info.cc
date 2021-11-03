//
//  version_info.cpp
//  launch_time
//
//  Created by 郑俊明 on 2021/10/30.
//

#include "version_info.h"
#include <stdio.h>

#ifdef USING_STRING
#elif defined(USING_ARRAY)
#elif defined(USING_STATIC)
#elif defined(USING_DOUBLE_CONST)
#else
const char* kPackageTypeDebug = "debug_pointer_extern";
#endif

void PrintOwner(const char* who) {
#ifdef USING_STRING
    printf("print version %s %x %s\n", kPackageTypeDebug.c_str(), &kPackageTypeDebug, who);
#else
    printf("print version %s %x %x %s\n", kPackageTypeDebug, kPackageTypeDebug, &kPackageTypeDebug, who);
#endif
}

void ComparDiff() {
    static const char* str_pointer = "str_pointer";
    static const char str_array[] = "str_array";
    printf("pointer %s array %s\n", str_pointer, str_array);
}

