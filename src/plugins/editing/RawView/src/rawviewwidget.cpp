/*******************************************************************************

Licensed to the OpenCOR team under one or more contributor license agreements.
See the NOTICE.txt file distributed with this work for additional information
regarding copyright ownership. The OpenCOR team licenses this file to you under
the Apache License, Version 2.0 (the "License"); you may not use this file
except in compliance with the License. You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software distributed
under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
CONDITIONS OF ANY KIND, either express or implied. See the License for the
specific language governing permissions and limitations under the License.

*******************************************************************************/

//==============================================================================
// Raw view widget
//==============================================================================

#include "rawviewwidget.h"

//==============================================================================

#include <QFileInfo>
#include <QTextStream>

//==============================================================================

namespace OpenCOR {
namespace RawView {

//==============================================================================

RawViewWidget::RawViewWidget(const QString &pFileName, QWidget *pParent) :
    QScintillaWidget(pParent),
    mFileName(pFileName)
{
    // Customise ourselves by 'reloading' our file

    fileReloaded();
}

//==============================================================================

void RawViewWidget::fileReloaded()
{
    // The given file has been reloaded, so reload it

    QFile file(mFileName);
    QString fileContents = QString();
    bool fileIsReadOnly = false;

    if (file.open(QIODevice::ReadOnly|QIODevice::Text)) {
        // We could open the file, so retrieve its contents and whether it can
        // be written to

        fileContents = QTextStream(&file).readAll();
        fileIsReadOnly = !(QFileInfo(mFileName).isWritable());

        // We are done with the file, so close it

        file.close();
    }

    setContents(fileContents);
    setReadOnly(fileIsReadOnly);
}

//==============================================================================

void RawViewWidget::fileRenamed(const QString &pFileName)
{
    // The file has been renamed, so update our copy of its name

    mFileName = pFileName;
}

//==============================================================================

}   // namespace RawView
}   // namespace OpenCOR

//==============================================================================
// End of file
//==============================================================================
