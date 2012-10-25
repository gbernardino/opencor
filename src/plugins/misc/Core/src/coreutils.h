//==============================================================================
// Core utilities
//==============================================================================

#ifndef COREUTILS_H
#define COREUTILS_H

//==============================================================================

#include "coreglobal.h"

//==============================================================================

#include <QString>

//==============================================================================

class QFrame;
class QLabel;
class QWidget;

//==============================================================================

namespace OpenCOR {
namespace Core {

//==============================================================================

QByteArray CORE_EXPORT resourceAsByteArray(const QString &pResource);
bool CORE_EXPORT saveResourceAs(const QString &pResource,
                                const QString &pFilename);

void CORE_EXPORT * instance(const QString &pClassName,
                            void *pDefaultGlobalInstance);

void CORE_EXPORT setFocusTo(QWidget *pWidget);

QString CORE_EXPORT nativeCanonicalFileName(const QString &pFileName);

QFrame CORE_EXPORT * newLineWidget(const bool &pHorizontal,
                                   QWidget *pParent = 0);
QFrame CORE_EXPORT * newLineWidget(QWidget *pParent = 0);

QLabel CORE_EXPORT * newLabel(const QString &pText,
                              const double &pFontPercentage,
                              const bool &pBold, const bool &pItalic,
                              const Qt::Alignment &pAlignment,
                              QWidget *pParent = 0);
QLabel CORE_EXPORT * newLabel(const QString &pText,
                              const double &pFontPercentage,
                              const bool &pBold, const bool &pItalic,
                              QWidget *pParent = 0);
QLabel CORE_EXPORT * newLabel(const QString &pText,
                              const double &pFontPercentage,
                              const bool &pBold, QWidget *pParent = 0);
QLabel CORE_EXPORT * newLabel(const QString &pText,
                              const double &pFontPercentage,
                              QWidget *pParent = 0);
QLabel CORE_EXPORT * newLabel(const QString &pText, QWidget *pParent = 0);

QString CORE_EXPORT copyright();

//==============================================================================

}   // namespace Core
}   // namespace OpenCOR

//==============================================================================

#endif

//==============================================================================
// End of file
//==============================================================================
