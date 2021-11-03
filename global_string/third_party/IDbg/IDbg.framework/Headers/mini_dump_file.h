//
//  Created by mjzheng on 2021/4/13.
//  Copyright © 2021 mjzheng. All rights reserved.
//

#ifndef IDBG_CORE_MINI_DUMP_FILE_H_
#define IDBG_CORE_MINI_DUMP_FILE_H_

#include <stdint.h>
#include <string>
#include "thread_cpu_info.h"

namespace IDbg {

enum DumpOptions : uint32_t {
    kHeader =  1 << 0,   // 0000 0001
    kStack =  1 << 1,   // 0000 0010
    kImage =  1 << 2,   // 0000 0100
    kFile =  1 << 3,   // 0000 1000
    kDefault = kHeader | kStack | kImage,
};

std::string GenerateMiniDump(DumpOptions options);

std::string FormatThreadStatck(const ThreadStackArray& ls);

void WriteMiniDump(const std::string& dir, DumpOptions options);

}  // namespace IDbg

#endif  // IDBG_CORE_MINI_DUMP_FILE_H_
