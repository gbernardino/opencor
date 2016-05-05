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
// PMR window
//==============================================================================

#pragma once

//==============================================================================

#include "organisationwidget.h"
#include "pmrwindowwidget.h"
#include "pmrwebservice.h"

//==============================================================================

#include <QList>

//==============================================================================

namespace Ui {
    class PmrWindowWindow;
}

//==============================================================================

class QNetworkAccessManager;
class QNetworkReply;

//==============================================================================

namespace OpenCOR {
namespace PMRWindow {

//==============================================================================

class PmrWindowWidget;

//==============================================================================

class PmrWindowWindow : public Core::OrganisationWidget
{
    Q_OBJECT

public:
    explicit PmrWindowWindow(QWidget *pParent);
    ~PmrWindowWindow();

    virtual void retranslateUi();

private:
    Ui::PmrWindowWindow *mGui;

    QString mInformationNoteMessage;

    PMRSupport::PmrWebService *mPmrWebService;

    PmrWindowWidget *mPmrWidget;

public Q_SLOTS:
    void busy(const bool &pBusy);

    void showWarning(const QString &pWhere, const QString &pMessage);
    void showInformation(const QString &pMessage);

    void initializeWidget(const PMRSupport::PmrExposures &pExposures,
                          const QString &pErrorMessage,
                          const bool &pInternetConnectionAvailable);

    void addExposureFiles(const QString &pUrl,
                          QStringList &pExposureFileNames);

private Q_SLOTS:
    void on_filterValue_textChanged(const QString &pText);
    void on_refreshButton_clicked();

    void retrieveExposuresList(const bool &pVisible);

    void cloneWorkspace(const QString &pUrl);
    void showExposureFiles(const QString &pUrl);
};

//==============================================================================

}   // namespace PMRWindow
}   // namespace OpenCOR

//==============================================================================
// End of file
//==============================================================================
