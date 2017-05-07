/*******************************************************************************

Copyright (C) The University of Auckland

OpenCOR is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

OpenCOR is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

*******************************************************************************/

//==============================================================================
// Compiler engine
//==============================================================================

#pragma once

//==============================================================================

#include "compilerglobal.h"

//==============================================================================

#include <QString>

//==============================================================================

#include "llvmbegin.h"
    #include "llvm/ExecutionEngine/ExecutionEngine.h"
#include "llvmend.h"

//==============================================================================

namespace OpenCOR {
namespace Compiler {

//==============================================================================

class COMPILER_EXPORT CompilerEngine
{
public:
    explicit CompilerEngine();

    bool hasError() const;
    QString error() const;

    bool compileCode(const QString &pCode);

    void * getFunction(const QString &pFunctionName);

private:
    std::unique_ptr<llvm::ExecutionEngine> mExecutionEngine;

    QString mError;
};

//==============================================================================

}   // namespace Compiler
}   // namespace OpenCOR

//==============================================================================
// End of file
//==============================================================================
