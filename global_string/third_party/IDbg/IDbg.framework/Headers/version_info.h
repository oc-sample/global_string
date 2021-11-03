//
//  version_info.h
//  launch_time
//
//  Created by 郑俊明 on 2021/10/30.
//

#ifndef version_info_h
#define version_info_h

#include <string>

#define USING_STRING
//#define USING_ARRAY
//#define USING_STATIC

#ifdef USING_STRING
// duplicate multiple string and initialize
// const std::string kPackageTypeDebug = "debug_string";
const std::string kPackageTypeDebug = "debug_string";

#elif defined(USING_ARRAY)
// duplicate string, store in only read section
const char kPackageTypeDebug[] = "debug_array";
#elif defined(USING_STATIC)
// duplicate pointer
// dynamic lib will duplicate string
static const char* kPackageTypeDebug = "debug_pointer_static";
#else
// best method
extern const char* kPackageTypeDebug; // "debug_pointer_extern"
#endif

void PrintOwner(const char* who);

void ComparDiff();

#endif /* version_info_h */
