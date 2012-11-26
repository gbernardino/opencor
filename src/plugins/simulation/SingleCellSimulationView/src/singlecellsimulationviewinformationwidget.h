//==============================================================================
// Single cell simulation view information widget
//==============================================================================

#ifndef SINGLECELLSIMULATIONVIEWINFORMATIONWIDGET_H
#define SINGLECELLSIMULATIONVIEWINFORMATIONWIDGET_H

//==============================================================================

#include "widget.h"

//==============================================================================

namespace Ui {
    class SingleCellSimulationViewInformationWidget;
}

//==============================================================================

namespace OpenCOR {

//==============================================================================

namespace Core {
    class CollapsibleWidget;
}   // namespace Core

//==============================================================================

namespace SingleCellSimulationView {

//==============================================================================

class SingleCellSimulationViewInformationSimulationWidget;
class SingleCellSimulationViewInformationSolversWidget;

//==============================================================================

class SingleCellSimulationViewInformationWidget : public Core::Widget
{
    Q_OBJECT

public:
    explicit SingleCellSimulationViewInformationWidget(QWidget *pParent = 0);
    ~SingleCellSimulationViewInformationWidget();

    virtual void retranslateUi();

    virtual void loadSettings(QSettings *pSettings);
    virtual void saveSettings(QSettings *pSettings) const;

    SingleCellSimulationViewInformationSimulationWidget * simulationWidget();
    SingleCellSimulationViewInformationSolversWidget * solversWidget();

private:
    Ui::SingleCellSimulationViewInformationWidget *mGui;

    Core::CollapsibleWidget *mSimulationCollapsibleWidget;
    SingleCellSimulationViewInformationSimulationWidget *mSimulationWidget;

    Core::CollapsibleWidget *mSolversCollapsibleWidget;
    SingleCellSimulationViewInformationSolversWidget *mSolversWidget;

    Core::CollapsibleWidget *mTracesCollapsibleWidget;

    Core::CollapsibleWidget *mParametersCollapsibleWidget;
};

//==============================================================================

}   // namespace SingleCellSimulationView
}   // namespace OpenCOR

//==============================================================================

#endif

//==============================================================================
// End of file
//==============================================================================
