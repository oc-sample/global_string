//
//  Student.m
//  launch_time
//
//  Created by 郑俊明 on 2021/10/30.
//
//#include "version_info.h"
#include <IDbg/version_info.h>

void PrintByStudent() {
    const char* who = "student";
#ifdef USING_STRING
    printf("print version %s %x %s\n", kPackageTypeDebug.c_str(), &kPackageTypeDebug, who);
#else
    printf("print version %s %x %x %s\n", kPackageTypeDebug, kPackageTypeDebug, &kPackageTypeDebug, who);
#endif
}
