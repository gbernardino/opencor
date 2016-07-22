/*******************************************************************************

Copyright The University of Auckland

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

*******************************************************************************/

//==============================================================================
// Core GUI utilities
//==============================================================================

QMainWindow CORE_EXPORT * mainWindow();

bool CORE_EXPORT aboutToQuit();

void CORE_EXPORT showEnableAction(QAction *pAction, const bool &pVisible,
                                  const bool &pEnabled = true);

QColor CORE_EXPORT baseColor();
QColor CORE_EXPORT borderColor();
QColor CORE_EXPORT highlightColor();
QColor CORE_EXPORT shadowColor();
QColor CORE_EXPORT windowColor();

//==============================================================================
// End of file
//==============================================================================
