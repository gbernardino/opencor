//==============================================================================
// Single cell view graph panel plot widget
//==============================================================================

#ifndef SINGLECELLVIEWGRAPHPANELPLOTWIDGET_H
#define SINGLECELLVIEWGRAPHPANELPLOTWIDGET_H

//==============================================================================

#include "qwt_plot.h"
#include "qwt_plot_curve.h"

//==============================================================================

class QwtPlotDirectPainter;

//==============================================================================

namespace OpenCOR {

//==============================================================================

namespace CellMLSupport {
    class CellmlFileRuntimeParameter;
}   // namespace CellMLSupport

//==============================================================================

namespace SingleCellView {

//==============================================================================

class SingleCellViewGraphPanelPlotGraph : public QwtPlotCurve
{
public:
    explicit SingleCellViewGraphPanelPlotGraph(CellMLSupport::CellmlFileRuntimeParameter *pParameterX = 0,
                                               CellMLSupport::CellmlFileRuntimeParameter *pParameterY = 0);

    bool isValid() const;

    bool isSelected() const;
    void setSelected(const bool &pSelected);

    QString fileName() const;
    void setFileName(const QString &pFileName);

    CellMLSupport::CellmlFileRuntimeParameter * parameterX() const;
    void setParameterX(CellMLSupport::CellmlFileRuntimeParameter *pParameterX);

    CellMLSupport::CellmlFileRuntimeParameter * parameterY() const;
    void setParameterY(CellMLSupport::CellmlFileRuntimeParameter *pParameterY);

private:
    bool mSelected;

    QString mFileName;

    CellMLSupport::CellmlFileRuntimeParameter *mParameterX;
    CellMLSupport::CellmlFileRuntimeParameter *mParameterY;
};

//==============================================================================

class SingleCellViewGraphPanelPlotWidget : public QwtPlot
{
    Q_OBJECT

public:
    explicit SingleCellViewGraphPanelPlotWidget(QWidget *pParent = 0);
    ~SingleCellViewGraphPanelPlotWidget();

    QList<SingleCellViewGraphPanelPlotGraph *> graphs() const;

    bool addGraph(SingleCellViewGraphPanelPlotGraph *pGraph);
    bool removeGraph(SingleCellViewGraphPanelPlotGraph *pGraph);

    void setNeedMinMaxX(const double &pNeedMinX, const double &pNeedMaxX);
    void setNeedMinMaxY(const double &pNeedMinY, const double &pNeedMaxY);

    void updateAxes();

    void drawGraphSegment(SingleCellViewGraphPanelPlotGraph *pGraph,
                          const qulonglong &pFrom, const qulonglong &pTo);

    virtual void drawCanvas(QPainter *pPainter);

    void replotNow();

protected:
    virtual bool eventFilter(QObject *pObject, QEvent *pEvent);
    virtual void mouseMoveEvent(QMouseEvent *pEvent);
    virtual void mousePressEvent(QMouseEvent *pEvent);
    virtual void mouseReleaseEvent(QMouseEvent *pEvent);
    virtual void wheelEvent(QWheelEvent *pEvent);

private:
    enum Action {
        None,
        Pan,
        ShowCoordinates,
        Zoom,
        ZoomRegion
    };

    enum Location {
        TopLeft,
        TopRight,
        BottomLeft,
        BottomRight
    };

    QwtPlotDirectPainter *mDirectPainter;

    QList<SingleCellViewGraphPanelPlotGraph *> mGraphs;

    Action mAction;

    QPointF mOriginPoint;
    QPointF mEndPoint;

    double mMinX;
    double mMaxX;

    double mMinY;
    double mMaxY;

    double mNeedMinX;
    double mNeedMaxX;

    double mNeedMinY;
    double mNeedMaxY;

    QPixmap mCanvasPixmap;

    double mZoomFactorX;
    double mZoomFactorY;

    void handleMouseDoubleClickEvent(QMouseEvent *pEvent);

    void checkLocalAxisValues(const int &pAxis, double &pMin, double &pMax);

    void checkAnyAxesValues(double &pMinX, double &pMaxX,
                            double &pMinY, double &pMaxY);

    void updateZoomFactors();

    double minX() const;
    double maxX() const;

    void setMinMaxX(const double &pMinX, const double &pMaxX);

    double minY() const;
    double maxY() const;

    void setMinMaxY(const double &pMinY, const double &pMaxY);

    double localMinX() const;
    double localMaxX() const;

    void setLocalMinMaxX(const double &pLocalMinX, const double &pLocalMaxX);

    double localMinY() const;
    double localMaxY() const;

    void setLocalMinMaxY(const double &pLocalMinY, const double &pLocalMaxY);

    void checkLocalAxes(const bool &pCanReplot = true,
                        const bool &pForceMinMaxValues = false,
                        const bool &pUpdateMinMaxValues = false);

    double optimisedValue(const double &pValue, const double &pPower,
                          const bool &pLowValue);

    void setLocalAxis(const int &pAxis, const double &pMin, const double &pMax);
    void setLocalAxes(const double &pLocalMinX, const double &pLocalMaxX,
                      const double &pLocalMinY, const double &pLocalMaxY,
                      const bool &pCanReplot = true,
                      const bool &pForceMinMaxValues = false,
                      const bool &pUpdateMinMaxValues = false,
                      const bool &pResetMinMaxValues = false);

    void scaleLocalAxes(const double &pScalingFactorX,
                        const double &pScalingFactorY);

    QPointF mousePositionWithinCanvas(const QPoint &pPoint) const;

    void drawCoordinates(QPainter *pPainter, const QPointF &pCoordinates,
                         const QColor &pBackgroundColor,
                         const QColor &pForegroundColor,
                         const Location &pLocation = TopLeft,
                         const bool &pCanMoveLocation = true);

    QRectF zoomRegion() const;
};

//==============================================================================

}   // namespace SingleCellView
}   // namespace OpenCOR

//==============================================================================

#endif

//==============================================================================
// End of file
//==============================================================================
